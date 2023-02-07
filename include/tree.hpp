
#pragma once
#ifndef RB_TREE_HPP_
#define RB_TREE_HPP_

#include <functional>  // std::less
#include <memory>      // std::allocator

#include "iterator.hpp"
#include "type_traits.hpp"
#include "utility.hpp"

#define ft_noexcept throw()

using ft::pair;
using std::bidirectional_iterator_tag;

namespace ft {

template <class MyTree>
class tree_const_iterator {
 public:
  typedef bidirectional_iterator_tag iterator_category;

  typedef typename MyTree::node_pointer    node_pointer;
  typedef typename MyTree::value_type      value_type;
  typedef typename MyTree::difference_type difference_type;
  typedef typename MyTree::pointer         pointer;
  typedef const value_type&                reference;

  node_pointer ptr_;

  tree_const_iterator() ft_noexcept : ptr_() {
  }
  tree_const_iterator(node_pointer n_ptr) ft_noexcept : ptr_(n_ptr) {
  }
  reference operator*() const ft_noexcept {
    return *ptr_;
  }
  pointer operator->() const ft_noexcept {
    return ptr_;  // TODO pointer_traits<pointer>::pointer_to(**this);
  }
  tree_const_iterator operator++() ft_noexcept {
    ++ptr_;
    return *this;
  }
  tree_const_iterator operator++(int) ft_noexcept {
    tree_const_iterator temp = *this;
    ++ptr_;
    return temp;
  }
  tree_const_iterator operator--() ft_noexcept {
    --ptr_;
    return *this;
  }
  tree_const_iterator operator--(int) ft_noexcept {
    tree_const_iterator temp = *this;
    --ptr_;
    return temp;
  }
  bool operator==(const tree_const_iterator& rhs) const ft_noexcept {
    return ptr_ == rhs.ptr_;
  }
  bool operator!=(const tree_const_iterator& rhs) const ft_noexcept {
    return !(*this == rhs);
  }
};

template <class MyTree>
class tree_iterator : public tree_const_iterator<MyTree> {
 public:
  typedef tree_const_iterator<MyTree>               base_iterator;
  typedef typename base_iterator::iterator_category iterator_category;
  typedef typename base_iterator::value_type        value_type;
  typedef typename base_iterator::difference_type   difference_type;
  typedef typename base_iterator::pointer           pointer;
  typedef typename base_iterator::value_type&       reference;
  typedef typename base_iterator::node_pointer      node_pointer;

  tree_iterator() ft_noexcept : base_iterator() {
  }
  tree_iterator(node_pointer n_ptr) ft_noexcept : base_iterator(n_ptr) {
  }
  reference operator*() const ft_noexcept {
    return const_cast<reference>(base_iterator::operator*());
  }
  pointer operator->() const ft_noexcept {
    return this->ptr_;  // TODO pointer_traits<pointer>::pointer_to(**this);
  }
  tree_iterator operator++() ft_noexcept {
    base_iterator::operator++();
    return *this;
  }
  tree_iterator operator++(int) ft_noexcept {
    tree_iterator  temp = *this;
    base_iterator::operator++();
    return temp;
  }
  tree_iterator operator--() ft_noexcept {
    base_iterator::operator--();
    return *this;
  }
  tree_iterator operator--(int) ft_noexcept {
    tree_iterator  temp = *this;
    base_iterator::operator--();
    return *this;
  }
};

template <typename T>
struct tree_node {
  typedef T          value_type;
  typedef tree_node* node_pointer;

  node_pointer parent_;
  node_pointer left_;
  node_pointer right_;
  value_type   value_;

  tree_node() ft_noexcept : parent_(NULL),
                            left_(NULL),
                            right_(NULL),
                            value_(NULL) {
  }
};

template <class T, class Compare, class Allocator>
class tree {
 public:
  typedef T                                        value_type;
  typedef Compare                                  value_compare;
  typedef Allocator                                allocator_type;
  typedef typename allocator_type::size_type       size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef value_type&                              reference;
  typedef const value_type&                        const_reference;
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef tree_iterator<value_type>                iterator;
  typedef tree_const_iterator<value_type>          const_iterator;

 private:
  typedef std::allocator<tree_node<T>>        node_allocator;
  typedef typename tree_node<T>::node_pointer node_pointer;

 public:
  allocator_type value_alloc_;
  node_allocator node_alloc_;
  value_compare  compare_;
  node_pointer   root_;
  size_type      size_;

  // Default constructor
  tree()
      : value_alloc_(allocator_type()),
        node_alloc_(node_allocator()),
        compare_(value_compare()),
        root_(NULL),
        size_(0) {
  }

  // Destructor
  ~tree() {
  }

  // Inserts a new node into the tree
  void insert(const value_type& value) {
    node_pointer position = find_insert_position(value);
  }

  // Returns parent node of value
  node_pointer find_insert_position(const value_type& value) {
    node_pointer node = root_;
    while (node) {
      // value < node->value
      if (value_comp()(value, node->value)) {
        if (node->left_ == NULL) return node;
        node = node->left_;
      } else {
        if (node->right_ == NULL) return node;
        node = node->right_;
      }
    }
  }

  //
  value_compare& value_comp() {
    return compare_;
  }

  //
  const value_compare& value_comp() const {
    return compare_;
  }
};

}  // namespace ft

#endif  // RB_TREE_HPP_