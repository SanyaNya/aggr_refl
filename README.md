# Aggregate reflection

tuple_size_v, tuple_element_t get, convert to tuple functions for aggregates

### Showcase
~~~cpp
#include <string>
#include <iostream>
#include <aggr_refl/aggregate_reflection.hpp>

struct S
{
  int x;
  float q[2];
  const char* s;
  std::string s2;
};

int main()
{
    S s{1, {1.1, 1.2}, "2", "3"};

    static_assert(aggr_refl::tuple_size_v<S> == 4);

    static_assert(std::is_same_v<
        decltype(aggr_refl::tie(s)), 
        std::tuple<int&, float(&)[2], const char*&, std::string&>>);

    static_assert(std::is_same_v<aggr_refl::tuple_element_t<0, S>, int>);
    std::cout << "aggr_refl::get<0>(s) = " << aggr_refl::get<0>(s) << "\n";

    static_assert(std::is_same_v<aggr_refl::tuple_element_t<1, S>, float[2]>);
    std::cout << "aggr_refl::get<1>(s)[0] = " << aggr_refl::get<1>(s)[0] << "\n";
    std::cout << "aggr_refl::get<1>(s)[1] = " << aggr_refl::get<1>(s)[1] << "\n";

    static_assert(std::is_same_v<aggr_refl::tuple_element_t<2, S>, const char*>);
    std::cout << "aggr_refl::get<2>(s) = " << aggr_refl::get<2>(s) << "\n";

    static_assert(std::is_same_v<aggr_refl::tuple_element_t<3, S>, std::string>);
    std::cout << "aggr_refl::get<3>(s) = " << aggr_refl::get<3>(s) << "\n";
}

//Prints:
// aggr_refl::get<0>(s) = 1
// aggr_refl::get<1>(s)[0] = 1.1
// aggr_refl::get<1>(s)[1] = 1.2
// aggr_refl::get<2>(s) = 2
// aggr_refl::get<3>(s) = 3
~~~

#### Requirements: C++23

### Using with cmake
~~~cmake
include(FetchContent)

FetchContent_Declare(
  aggr_refl
  GIT_REPOSITORY https://github.com/SanyaNya/aggr_refl
  GIT_TAG v1.1.1)

FetchContent_MakeAvailable(aggr_refl)

target_link_libraries(your_target aggr_refl)
~~~
