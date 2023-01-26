
#include "vector.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <vector>

TEST(VectorConstructors, DefaultConstructor) {
  ft::vector<int> vec_empty;
  EXPECT_EQ(vec_empty.size(), 0);
}

TEST(VectorConstructors, AllocConstructor) {
  std::allocator<int> alloc;
  ft::vector<int>     v1(alloc);
  EXPECT_EQ(v1.size(), 0);
}

TEST(VectorConstructors, SizeConstructor) {
  ft::vector<int> v1(10);
  EXPECT_GT(v1.size(), 9);

  ft::vector<int> v2((ft::vector<int>::size_type)10, (int)3);
  EXPECT_GT(v2.size(), 9);

  std::allocator<int> alloc;
  ft::vector<int> v3((ft::vector<int>::size_type)10, 69, alloc);
  EXPECT_GT(v3.size(), 9);
}

TEST(VectorConstructors, RangeConstructor) {
  ft::vector<int> v1((ft::vector<int>::size_type)10, 3);
  ft::vector<int> v2(v1.begin(), v1.end());
  EXPECT_EQ(v1.size(), v2.size());  // v1 == v2 ?

  std::allocator<int> alloc;
  ft::vector<int> v3(v1.begin(), v1.end(), alloc);
  EXPECT_EQ(v1.size(), v3.size());  // v1 == v2 ?
}

TEST(VectorConstructors, CopyConstructor) {
  ft::vector<int> v1;
  ft::vector<int> v2(v1);
  EXPECT_EQ(v1.size(), v2.size());  // v1 == v2 ?

  ft::vector<int> v3(100);
  ft::vector<int> v4(v3);
  EXPECT_EQ(v3.size(), v4.size());  // v1 == v2 ?
}

TEST(VectorOperatorOverloads, CopyAssignment) {
  ft::vector<int> v1;
  ft::vector<int> v2 = v1;
  EXPECT_EQ(v1.size(), v2.size());  // v1 == v2 ?

  ft::vector<int> v3((ft::vector<int>::size_type)100, 69);
  ft::vector<int> v4 = v3;
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorAssign, Assign) {
  
}