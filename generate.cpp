#include <iostream>
#include <fstream>
#include <format>

constexpr std::string_view begin = R"(
#pragma once

#include <type_traits>
#include <tuple>

namespace aggr_refl
{

namespace details
{

struct any_type
{
  constexpr any_type(std::size_t) noexcept;

  template<typename T>
  constexpr operator T() noexcept;
};

template<typename T, typename IS, typename = void>
struct tuple_size_is : std::false_type{};

template<typename T, std::size_t ... Is>
struct tuple_size_is<
  T, 
  std::index_sequence<Is...>, 
  std::void_t<decltype(T{{any_type{Is}}...})>> 
    : std::true_type{};

template<typename T, std::size_t N>
constexpr bool tuple_size_n = tuple_size_is<T, std::make_index_sequence<N>>::value;

template<typename T, std::size_t N = 0, bool = tuple_size_n<T, N>>
struct tuple_size : tuple_size<T, N+1> {};

template<typename T, std::size_t N>
struct tuple_size<T, N, false> : std::integral_constant<std::size_t, N-1>
{
  static_assert(N != 0, "T is not aggregate initializable");
};

} //namespace details

template<typename T>
constexpr std::size_t tuple_size_v = details::tuple_size<T>::value;

namespace details
{

template<std::size_t N>
struct tie_h
{
  static_assert(false, "Number of fields exceeded");
};

template<>
struct tie_h<0>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    return std::tuple<>{};
  }
};
)";

constexpr std::string_view tie = R"(
template<>
struct tie_h<{0}>
{{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {{
    auto&[{1}] = t;
    return std::tuple<{2}>{{{1}}};
  }}
}};
)";

constexpr std::string_view end = R"(
} //namespace details

template<typename T>
constexpr auto tie(T& t) noexcept
{
  return details::tie_h<tuple_size_v<T>>::f(t);
}

template<std::size_t I, typename T>
constexpr auto& get(T& t) noexcept
{
  return std::get<I>(tie(t));
}

template<std::size_t I, typename T>
using tuple_element_t =
  std::remove_reference_t<
    std::tuple_element_t<I, decltype(tie(std::declval<T&>()))>>;

} //namespace aggr_refl
)";

constexpr unsigned MAX_FIELDS = 128;

int main()
{
  std::ofstream of("aggregate_reflection.hpp");

  of << begin;

  std::string vars = "v0";
  std::string decltype_vars = "decltype(v0)&";
  for(unsigned i = 0; i != MAX_FIELDS; ++i)
  {
    of << std::format(tie, i+1, vars, decltype_vars);
    vars += std::format(", v{}", i+1);
    decltype_vars += std::format(", decltype(v{})&", i+1);
  }

  of << end;
}
