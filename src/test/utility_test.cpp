
#include "utility.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <utility>

TEST(PairTest, BasicAssertions) {
  ft::pair<bool, bool> ft_val_1 = ft::make_pair(true, true);
  std::pair<bool, bool> std_val_1 = std::make_pair(true, true);

  EXPECT_EQ(ft_val_1.first, std_val_1.first);
  EXPECT_EQ(ft_val_1.second, std_val_1.second);

  ft::pair<int, bool> ft_val_2 = ft::make_pair(42, false);
  std::pair<int, bool> std_val_2 = std::make_pair(24, true);

  EXPECT_NE(ft_val_2.first, std_val_2.first);
  EXPECT_NE(ft_val_2.second, std_val_2.second);
}
