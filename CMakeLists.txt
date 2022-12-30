cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")
project(ft_containers VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_MAKE_PROGRAM make)

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

add_executable(algorithm_test test/algorithm_test.cpp)
target_link_libraries(
  algorithm_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME algorithm_test
  COMMAND $<TARGET_FILE:algorithm_test>
)

add_executable(iterator_test test/iterator_test.cpp)
target_link_libraries(
  iterator_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME iterator_test
  COMMAND $<TARGET_FILE:iterator_test>
)

add_executable(map_test test/map_test.cpp)
target_link_libraries(
  map_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME map_test
  COMMAND $<TARGET_FILE:map_test>
)

add_executable(rb_tree_test test/rb_tree_test.cpp)
target_link_libraries(
  rb_tree_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME rb_tree_test
  COMMAND $<TARGET_FILE:rb_tree_test>
)

add_executable(stack_test test/stack_test.cpp)
target_link_libraries(
  stack_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME stack_test
  COMMAND $<TARGET_FILE:stack_test>
)

add_executable(utility_test test/utility_test.cpp)
target_link_libraries(
  utility_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME utility_test
  COMMAND $<TARGET_FILE:utility_test>
)

add_executable(vector_test test/vector_test.cpp)
target_link_libraries(
  vector_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME vector_test
  COMMAND $<TARGET_FILE:vector_test>
)
