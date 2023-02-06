
#pragma once
#ifndef RB_TREE_HPP_
#define RB_TREE_HPP_

#include <functional>  // std::less
#include <memory>      // std::allocator

#include "utility.hpp"

#define ft_noexcept throw()

namespace ft {



template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<T>>
class tree {
 public:
  typedef Key       key_type;
  typedef T         value_type;
  typedef Allocator allocator_type;

  /* Member functions */
  tree();
  explicit tree(const Compare&        comp,
                const allocator_type& alloc = allocator_type());
  template <class InputIt>
  tree(InputIt first, InputIt last, const Compare& comp = Compare(),
       const allocator_type& alloc = allocator_type());
  tree(const tree& other);
  tree& operator=(const tree& other);
  ~tree();
};

}  // namespace ft

#endif  // RB_TREE_HPP_