
#include "utility.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <utility>

TEST(PairTest, BasicAssertions) {
  ft::pair<bool, bool> ft_val_1 = ft::make_pair(true, true);
  ft::pair<bool, bool> ft_val_2 = ft::make_pair(true, true);
  std::pair<bool, bool> std_val_1 = std::make_pair(true, true);
  std::pair<bool, bool> std_val_2 = std::make_pair(true, true);

  EXPECT_EQ(ft_val_1.first, std_val_1.first);
  EXPECT_EQ(ft_val_1.second, std_val_1.second);
}
