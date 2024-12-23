
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
struct field_count_is : std::false_type{};

template<typename T, std::size_t ... Is>
struct field_count_is<
  T, 
  std::index_sequence<Is...>, 
  std::void_t<decltype(T{{any_type{Is}}...})>> 
    : std::true_type{};

template<typename T, std::size_t N>
constexpr bool field_count_n = field_count_is<T, std::make_index_sequence<N>>::value;

template<typename T, std::size_t N = 0, bool = field_count_n<T, N>>
struct field_count : field_count<T, N+1> {};

template<typename T, std::size_t N>
struct field_count<T, N, false> : std::integral_constant<std::size_t, N-1> {};

} //namespace details

template<typename T>
  requires std::is_aggregate_v<T>
constexpr std::size_t field_count_v = details::field_count<T>::value;

namespace details
{

template<std::size_t N>
struct struct_tie_h;

template<>
struct struct_tie_h<0>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    return std::tuple<>{};
  }
};

template<>
struct struct_tie_h<1>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0] = t;
    return std::tuple<decltype(v0)&>{v0};
  }
};

template<>
struct struct_tie_h<2>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&>{v0, v1};
  }
};

template<>
struct struct_tie_h<3>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&>{v0, v1, v2};
  }
};

} //namespace details

template<typename T>
  requires std::is_aggregate_v<T>
constexpr auto struct_tie(T& t) noexcept
{
  return details::struct_tie_h<field_count_v<T>>::f(t);
}

} //namespace aggr_refl
