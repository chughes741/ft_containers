
#include "algorithm.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

TEST(EqualTest, EqualVectors) {
  std::vector<int> v1(1000);
  std::generate(v1.begin(), v1.end(), std::rand);
  std::vector<int> v2(v1);

  EXPECT_TRUE(ft::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST(EqualTest, UnequalVectors) {
  std::vector<int> v1(1000);
  std::generate(v1.begin(), v1.end(), std::rand);
  std::vector<int> v2(v1);
  v2[v2.size() / 2] -= 1;

  EXPECT_FALSE(ft::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST(EqualTest, EqualMaps) {
  std::map<int, int> m1;
  for (int i = 0; i < 1000; ++i) {
    m1.emplace(std::pair<int, int>(i, std::rand()));
  }
  std::map<int, int> m2(m1);

  EXPECT_TRUE(ft::equal(m1.begin(), m1.end(), m2.begin()));
}

TEST(EqualTest, UnequalMaps) {
  std::map<int, int> m1;
  for (int i = 0; i < 1000; ++i) {
    m1.emplace(std::pair<int, int>(i, std::rand()));
  }
  std::map<int, int> m2(m1);
  m2.erase(1);
  m2.emplace(std::pair<int, int>(-1, std::rand()));

  EXPECT_FALSE(ft::equal(m1.begin(), m1.end(), m2.begin()));
}

TEST(LexicographicalCompareTest, EqualVectors) {
  std::vector<int> v1(1000);
  std::generate(v1.begin(), v1.end(), std::rand);
  std::vector<int> v2(v1);

  EXPECT_FALSE(
      ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
}

TEST(LexicographicalCompareTest, UnequalVectors) {
  std::vector<int> v1(1000);
  std::generate(v1.begin(), v1.end(), std::rand);
  std::vector<int> v2(v1);
  v2[v2.size() / 2] += 1;

  EXPECT_TRUE(
      ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
}

TEST(LexicographicalCompareTest, EqualStrings) {
  std::string s1 = "Hello World!";
  std::string s2 = s1;

  EXPECT_FALSE(
      ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()));
}

TEST(LexicographicalCompareTest, UnequalStrings) {
  std::string s1 = "Hello World!";
  std::string s2 = s1;
  s1.pop_back();

  EXPECT_TRUE(
      ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()));
}
