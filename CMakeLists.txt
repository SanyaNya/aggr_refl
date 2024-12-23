cmake_minimum_required(VERSION 3.20)

project(aggr_refl)

#Require C++23 without compiler extensions
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(aggr_refl INTERFACE)
target_include_directories(aggr_refl INTERFACE ${aggr_refl_SOURCE_DIR}/include)
