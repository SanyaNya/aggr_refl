
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
struct tie_h;

template<>
struct tie_h<0>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    return std::tuple<>{};
  }
};

template<>
struct tie_h<1>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0] = t;
    return std::tuple<decltype(v0)&>{v0};
  }
};

template<>
struct tie_h<2>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&>{v0, v1};
  }
};

template<>
struct tie_h<3>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&>{v0, v1, v2};
  }
};

template<>
struct tie_h<4>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&>{v0, v1, v2, v3};
  }
};

template<>
struct tie_h<5>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&>{v0, v1, v2, v3, v4};
  }
};

template<>
struct tie_h<6>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&>{v0, v1, v2, v3, v4, v5};
  }
};

template<>
struct tie_h<7>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&>{v0, v1, v2, v3, v4, v5, v6};
  }
};

template<>
struct tie_h<8>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&>{v0, v1, v2, v3, v4, v5, v6, v7};
  }
};

template<>
struct tie_h<9>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8};
  }
};

template<>
struct tie_h<10>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9};
  }
};

template<>
struct tie_h<11>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10};
  }
};

template<>
struct tie_h<12>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11};
  }
};

template<>
struct tie_h<13>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12};
  }
};

template<>
struct tie_h<14>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13};
  }
};

template<>
struct tie_h<15>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14};
  }
};

template<>
struct tie_h<16>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15};
  }
};

template<>
struct tie_h<17>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16};
  }
};

template<>
struct tie_h<18>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17};
  }
};

template<>
struct tie_h<19>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18};
  }
};

template<>
struct tie_h<20>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19};
  }
};

template<>
struct tie_h<21>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20};
  }
};

template<>
struct tie_h<22>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21};
  }
};

template<>
struct tie_h<23>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22};
  }
};

template<>
struct tie_h<24>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23};
  }
};

template<>
struct tie_h<25>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24};
  }
};

template<>
struct tie_h<26>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25};
  }
};

template<>
struct tie_h<27>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26};
  }
};

template<>
struct tie_h<28>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27};
  }
};

template<>
struct tie_h<29>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28};
  }
};

template<>
struct tie_h<30>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29};
  }
};

template<>
struct tie_h<31>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30};
  }
};

template<>
struct tie_h<32>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31};
  }
};

template<>
struct tie_h<33>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32};
  }
};

template<>
struct tie_h<34>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33};
  }
};

template<>
struct tie_h<35>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34};
  }
};

template<>
struct tie_h<36>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35};
  }
};

template<>
struct tie_h<37>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36};
  }
};

template<>
struct tie_h<38>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37};
  }
};

template<>
struct tie_h<39>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38};
  }
};

template<>
struct tie_h<40>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39};
  }
};

template<>
struct tie_h<41>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40};
  }
};

template<>
struct tie_h<42>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41};
  }
};

template<>
struct tie_h<43>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42};
  }
};

template<>
struct tie_h<44>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43};
  }
};

template<>
struct tie_h<45>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44};
  }
};

template<>
struct tie_h<46>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45};
  }
};

template<>
struct tie_h<47>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46};
  }
};

template<>
struct tie_h<48>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47};
  }
};

template<>
struct tie_h<49>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48};
  }
};

template<>
struct tie_h<50>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49};
  }
};

template<>
struct tie_h<51>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50};
  }
};

template<>
struct tie_h<52>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51};
  }
};

template<>
struct tie_h<53>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52};
  }
};

template<>
struct tie_h<54>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53};
  }
};

template<>
struct tie_h<55>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54};
  }
};

template<>
struct tie_h<56>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55};
  }
};

template<>
struct tie_h<57>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56};
  }
};

template<>
struct tie_h<58>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57};
  }
};

template<>
struct tie_h<59>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58};
  }
};

template<>
struct tie_h<60>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59};
  }
};

template<>
struct tie_h<61>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60};
  }
};

template<>
struct tie_h<62>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61};
  }
};

template<>
struct tie_h<63>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62};
  }
};

template<>
struct tie_h<64>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63};
  }
};

template<>
struct tie_h<65>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64};
  }
};

template<>
struct tie_h<66>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65};
  }
};

template<>
struct tie_h<67>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66};
  }
};

template<>
struct tie_h<68>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67};
  }
};

template<>
struct tie_h<69>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68};
  }
};

template<>
struct tie_h<70>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69};
  }
};

template<>
struct tie_h<71>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70};
  }
};

template<>
struct tie_h<72>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71};
  }
};

template<>
struct tie_h<73>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72};
  }
};

template<>
struct tie_h<74>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73};
  }
};

template<>
struct tie_h<75>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74};
  }
};

template<>
struct tie_h<76>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75};
  }
};

template<>
struct tie_h<77>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76};
  }
};

template<>
struct tie_h<78>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77};
  }
};

template<>
struct tie_h<79>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78};
  }
};

template<>
struct tie_h<80>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79};
  }
};

template<>
struct tie_h<81>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80};
  }
};

template<>
struct tie_h<82>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81};
  }
};

template<>
struct tie_h<83>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82};
  }
};

template<>
struct tie_h<84>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83};
  }
};

template<>
struct tie_h<85>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84};
  }
};

template<>
struct tie_h<86>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85};
  }
};

template<>
struct tie_h<87>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86};
  }
};

template<>
struct tie_h<88>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87};
  }
};

template<>
struct tie_h<89>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88};
  }
};

template<>
struct tie_h<90>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89};
  }
};

template<>
struct tie_h<91>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90};
  }
};

template<>
struct tie_h<92>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91};
  }
};

template<>
struct tie_h<93>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92};
  }
};

template<>
struct tie_h<94>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93};
  }
};

template<>
struct tie_h<95>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94};
  }
};

template<>
struct tie_h<96>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95};
  }
};

template<>
struct tie_h<97>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96};
  }
};

template<>
struct tie_h<98>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97};
  }
};

template<>
struct tie_h<99>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98};
  }
};

template<>
struct tie_h<100>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99};
  }
};

template<>
struct tie_h<101>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100};
  }
};

template<>
struct tie_h<102>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101};
  }
};

template<>
struct tie_h<103>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102};
  }
};

template<>
struct tie_h<104>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103};
  }
};

template<>
struct tie_h<105>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104};
  }
};

template<>
struct tie_h<106>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105};
  }
};

template<>
struct tie_h<107>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106};
  }
};

template<>
struct tie_h<108>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107};
  }
};

template<>
struct tie_h<109>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108};
  }
};

template<>
struct tie_h<110>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109};
  }
};

template<>
struct tie_h<111>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110};
  }
};

template<>
struct tie_h<112>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111};
  }
};

template<>
struct tie_h<113>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112};
  }
};

template<>
struct tie_h<114>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113};
  }
};

template<>
struct tie_h<115>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114};
  }
};

template<>
struct tie_h<116>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115};
  }
};

template<>
struct tie_h<117>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116};
  }
};

template<>
struct tie_h<118>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117};
  }
};

template<>
struct tie_h<119>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118};
  }
};

template<>
struct tie_h<120>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119};
  }
};

template<>
struct tie_h<121>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120};
  }
};

template<>
struct tie_h<122>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&, decltype(v121)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121};
  }
};

template<>
struct tie_h<123>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&, decltype(v121)&, decltype(v122)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122};
  }
};

template<>
struct tie_h<124>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&, decltype(v121)&, decltype(v122)&, decltype(v123)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123};
  }
};

template<>
struct tie_h<125>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&, decltype(v121)&, decltype(v122)&, decltype(v123)&, decltype(v124)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124};
  }
};

template<>
struct tie_h<126>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124, v125] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&, decltype(v121)&, decltype(v122)&, decltype(v123)&, decltype(v124)&, decltype(v125)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124, v125};
  }
};

template<>
struct tie_h<127>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124, v125, v126] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&, decltype(v121)&, decltype(v122)&, decltype(v123)&, decltype(v124)&, decltype(v125)&, decltype(v126)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124, v125, v126};
  }
};

template<>
struct tie_h<128>
{
  template<typename T>
  static constexpr auto f(T& t) noexcept
  {
    auto&[v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124, v125, v126, v127] = t;
    return std::tuple<decltype(v0)&, decltype(v1)&, decltype(v2)&, decltype(v3)&, decltype(v4)&, decltype(v5)&, decltype(v6)&, decltype(v7)&, decltype(v8)&, decltype(v9)&, decltype(v10)&, decltype(v11)&, decltype(v12)&, decltype(v13)&, decltype(v14)&, decltype(v15)&, decltype(v16)&, decltype(v17)&, decltype(v18)&, decltype(v19)&, decltype(v20)&, decltype(v21)&, decltype(v22)&, decltype(v23)&, decltype(v24)&, decltype(v25)&, decltype(v26)&, decltype(v27)&, decltype(v28)&, decltype(v29)&, decltype(v30)&, decltype(v31)&, decltype(v32)&, decltype(v33)&, decltype(v34)&, decltype(v35)&, decltype(v36)&, decltype(v37)&, decltype(v38)&, decltype(v39)&, decltype(v40)&, decltype(v41)&, decltype(v42)&, decltype(v43)&, decltype(v44)&, decltype(v45)&, decltype(v46)&, decltype(v47)&, decltype(v48)&, decltype(v49)&, decltype(v50)&, decltype(v51)&, decltype(v52)&, decltype(v53)&, decltype(v54)&, decltype(v55)&, decltype(v56)&, decltype(v57)&, decltype(v58)&, decltype(v59)&, decltype(v60)&, decltype(v61)&, decltype(v62)&, decltype(v63)&, decltype(v64)&, decltype(v65)&, decltype(v66)&, decltype(v67)&, decltype(v68)&, decltype(v69)&, decltype(v70)&, decltype(v71)&, decltype(v72)&, decltype(v73)&, decltype(v74)&, decltype(v75)&, decltype(v76)&, decltype(v77)&, decltype(v78)&, decltype(v79)&, decltype(v80)&, decltype(v81)&, decltype(v82)&, decltype(v83)&, decltype(v84)&, decltype(v85)&, decltype(v86)&, decltype(v87)&, decltype(v88)&, decltype(v89)&, decltype(v90)&, decltype(v91)&, decltype(v92)&, decltype(v93)&, decltype(v94)&, decltype(v95)&, decltype(v96)&, decltype(v97)&, decltype(v98)&, decltype(v99)&, decltype(v100)&, decltype(v101)&, decltype(v102)&, decltype(v103)&, decltype(v104)&, decltype(v105)&, decltype(v106)&, decltype(v107)&, decltype(v108)&, decltype(v109)&, decltype(v110)&, decltype(v111)&, decltype(v112)&, decltype(v113)&, decltype(v114)&, decltype(v115)&, decltype(v116)&, decltype(v117)&, decltype(v118)&, decltype(v119)&, decltype(v120)&, decltype(v121)&, decltype(v122)&, decltype(v123)&, decltype(v124)&, decltype(v125)&, decltype(v126)&, decltype(v127)&>{v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68, v69, v70, v71, v72, v73, v74, v75, v76, v77, v78, v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93, v94, v95, v96, v97, v98, v99, v100, v101, v102, v103, v104, v105, v106, v107, v108, v109, v110, v111, v112, v113, v114, v115, v116, v117, v118, v119, v120, v121, v122, v123, v124, v125, v126, v127};
  }
};

} //namespace details

template<typename T>
constexpr auto tie(T& t) noexcept
{
  return details::tie_h<tuple_size_v<T>>::f(t);
}

template<std::size_t I, typename T>
using tuple_element_t =
  std::remove_reference_t<
    std::tuple_element_t<I, decltype(tie(std::declval<T&>()))>>;

} //namespace aggr_refl
