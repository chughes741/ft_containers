
#include "stack.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <stack>
#include <vector>

using std::vector;  // Change to ft::vector when it's tested

TEST(StackTest, ConstructorAndCopyConstructor) {
  vector<int> vec;

  ft::stack<int, vector<int>>  ft_stack_1(vec);
  std::stack<int, vector<int>> std_stack(vec);

  EXPECT_EQ(ft_stack_1.size(), std_stack.size());

  ft::stack<int, vector<int>> ft_stack_2(ft_stack_1);
  EXPECT_EQ(ft_stack_1.size(), ft_stack_2.size());
}

TEST(StackTest, CopyAssignmentAndOperators) {
  vector<int> vec_1(10);
  for (vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); ++it) {
    *it = 24;
  }
  vector<int> vec_2(vec_1);
  vec_2.push_back(42);

  ft::stack<int, vector<int>> stack_1(vec_1);
  ft::stack<int, vector<int>> stack_2 = stack_1;
  ft::stack<int, vector<int>> stack_3(vec_2);

  EXPECT_EQ(stack_1.size(), stack_2.size());
  EXPECT_TRUE(stack_1 == stack_2);
  EXPECT_TRUE(stack_1 < stack_3);
}

TEST(StackTest, TopPushPop) {
  vector<int> vec_1(10);
  for (vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); ++it) {
    *it = rand();
  }
  vector<int>                  vec_2(vec_1);
  ft::stack<int, vector<int>>  stack_1(vec_1);
  std::stack<int, vector<int>> stack_2(vec_2);

  EXPECT_EQ(stack_1.top(), stack_2.top());

  stack_1.pop();
  stack_2.pop();
  EXPECT_EQ(stack_1.top(), stack_2.top());

  stack_1.push(42);
  stack_2.push(42);
  EXPECT_EQ(stack_1.top(), stack_2.top());
}
