cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")
project(ft_containers VERSION 1.0.0)

set (CMAKE_CXX_STANDARD 98)

find_package(GTest CONFIG REQUIRED)

add_library(
  ft_STL
  SHARED
  include/algorithm.hpp
  include/iterator.hpp
  include/map.hpp
  include/rb_tree.hpp
  include/stack.hpp
  include/type_traits.hpp
  include/utility.hpp
  include/vector.hpp
)
set_target_properties(
  ft_STL
  PROPERTIES LINKER_LANGUAGE CXX
)
target_include_directories(
  ft_STL
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Test executables
enable_testing()

add_executable(algorithm_test src/test/algorithm_test.cpp)
target_link_libraries(
  algorithm_test 
  PUBLIC ft_STL
  GTest::gtest_main
)

add_executable(iterator_test src/test/iterator_test.cpp)
target_link_libraries(
  iterator_test 
  PUBLIC ft_STL
  GTest::gtest_main
)

add_executable(map_test src/test/map_test.cpp)
target_link_libraries(
  map_test 
  PUBLIC ft_STL
  GTest::gtest_main
)

add_executable(rb_tree_test src/test/rb_tree_test.cpp)
target_link_libraries(
  rb_tree_test 
  PUBLIC ft_STL
  GTest::gtest_main
)

add_executable(stack_test src/test/stack_test.cpp)
target_link_libraries(
  stack_test 
  PUBLIC ft_STL
  GTest::gtest_main
)

add_executable(utility_test src/test/utility_test.cpp)
target_link_libraries(
  utility_test 
  PUBLIC ft_STL
  GTest::gtest_main
)

add_executable(vector_test src/test/vector_test.cpp)
target_link_libraries(
  vector_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
