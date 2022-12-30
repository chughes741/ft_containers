
#include "utility.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <utility>

TEST(PairTest, BasicAssertions) {
  {  // Default constructor and make pair
    ft::pair<bool, bool> ft_val;
    ft_val = ft::make_pair(true, true);
    std::pair<bool, bool> std_val;
    std_val = std::make_pair(true, true);

    EXPECT_EQ(ft_val.first, std_val.first);
    EXPECT_EQ(ft_val.second, std_val.second);
  }
  {  // Default constructor overload with init values
    ft::pair<int, bool>  ft_val(42, false);
    std::pair<int, bool> std_val(24, true);

    EXPECT_NE(ft_val.first, std_val.first);
    EXPECT_NE(ft_val.second, std_val.second);
  }
  {  // Copy constructor and copy assignment
    ft::pair<int, bool> ft_val_1 = ft::make_pair(1, true);
    ft::pair<int, bool> ft_val_2(ft_val_1);
    ft::pair<int, bool> ft_val_3 = ft_val_2;

    EXPECT_EQ(ft_val_2.first, ft_val_2.first);
    EXPECT_EQ(ft_val_3.second, ft_val_3.second);
  }
  {  // Comparison tests
    ft::pair<int, int> ft_val_1(24, 24);
    EXPECT_TRUE(ft_val_1 == ft_val_1);

    ft::pair<int, int> ft_val_2(42, 24);
    EXPECT_TRUE(ft_val_1 < ft_val_2);

    ft::pair<int, int> ft_val_3(42, 42);
    EXPECT_TRUE(ft_val_2 < ft_val_3);
  }
}
