
#include "utility.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <utility>

TEST(PairTest, ConstructorsAndMakePair) {
  ft::pair<bool, bool> ft_val_1;
  ft_val_1 = ft::make_pair(true, true);
  std::pair<bool, bool> std_val_1;
  std_val_1 = std::make_pair(true, true);

  EXPECT_EQ(ft_val_1.first, std_val_1.first);
  EXPECT_EQ(ft_val_1.second, std_val_1.second);

  ft::pair<int, bool>  ft_val_2(42, false);
  std::pair<int, bool> std_val_2(24, true);

  EXPECT_NE(ft_val_2.first, std_val_2.first);
  EXPECT_NE(ft_val_2.second, std_val_2.second);
}

TEST(PairTest, CopyConstructorAndAssignment) {
  ft::pair<int, bool> ft_val_1 = ft::make_pair(1, true);
  ft::pair<int, bool> ft_val_2(ft_val_1);
  ft::pair<int, bool> ft_val_3 = ft_val_2;

  EXPECT_EQ(ft_val_2.first, ft_val_2.first);
  EXPECT_EQ(ft_val_3.second, ft_val_3.second);
}

TEST(PairTest, Comparisons) {
  ft::pair<int, int> ft_val_1(24, 24);
  EXPECT_TRUE(ft_val_1 == ft_val_1);

  ft::pair<int, int> ft_val_2(42, 24);
  EXPECT_TRUE(ft_val_1 < ft_val_2);

  ft::pair<int, int> ft_val_3(42, 42);
  EXPECT_TRUE(ft_val_2 < ft_val_3);
}
