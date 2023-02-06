
#pragma once
#ifndef RB_TREE_HPP_
#define RB_TREE_HPP_

#include <functional>  // std::less
#include <memory>      // std::allocator

#include "iterator.hpp"
#include "type_traits.hpp"
// #include "utility.hpp"

#define ft_noexcept throw()

using ft::enable_if;
using ft::is_integral;
using std::bidirectional_iterator_tag;

namespace ft {

template <class MyTree>
class tree_const_iterator {
 public:
  typedef bidirectional_iterator_tag iterator_category;

  typedef typename MyTree::node_ptr        node_ptr;
  typedef typename MyTree::value_type      value_type;
  typedef typename MyTree::difference_type difference_type;
  typedef typename MyTree::pointer         pointer;
  typedef const value_type&                reference;

  node_ptr ptr_;

  tree_const_iterator() ft_noexcept : ptr_() {
  }
  tree_const_iterator(node_ptr n_ptr) ft_noexcept : ptr_(n_ptr) {
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
    ++ptr;
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
  typedef tree_const_iterator<MyTree>      base_iterator;
  typedef bidirectional_iterator_tag       iterator_category;
  typedef typename MyTree::value_type      value_type;
  typedef typename MyTree::difference_type difference_type;
  typedef typename MyTree::pointer         pointer;
  typedef value_type&                      reference;

  tree_iterator() ft_noexcept : base_iterator() {
  }
  tree_iterator(n_ptr) ft_noexcept : base_iterator(n_ptr) {
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

template <class value_type_, class void_ptr_>
struct tree_node {
  typedef tree_node*  node_ptr;
  typedef value_type_ value_type;

  node_ptr   parent_;
  node_ptr   left_;
  node_ptr   right_;
  value_type value_;
  // char color_; // red_ or black_, black_ if head
  // bool nil_; // true only if head node

  // enum red_black_ {
  // red_,
  // black_
  // };

  tree_node() ft_noexcept {
  }
  tree_node(const tree_node& other) ft_noexcept {
  }
  tree_node& operator=(const tree_node& rhs) ft_noexcept {
  }
  template <class Allocator>
  static node_ptr buyHeadNode(Allocator& alloc);
  template <class Allocator>
  static node_ptr buyNode(Allocator& alloc, node_ptr my_head,
                          value_type& value);
  template <class Allocator>
  static void freeNode(Allocator& alloc, node_ptr node) ft_noexcept;
};

template <class value_types_>
class tree_value {  // TODO public: container_base
 public:
  typedef typename value_types_::node_ptr node_ptr;

  typedef typename value_types_::value_type      value_type;
  typedef typename value_types_::size_type       size_type;
  typedef typename value_types_::difference_type difference_type;
  typedef typename value_types_::pointer         pointer;
  typedef typename value_types_::const_pointer   const_pointer;
  typedef value_type&                            reference;
  typedef const value_type&                      const_reference;

  typedef tree_const_iterator<tree_value> const_iterator;

  // enum red_black_ {
  // red_,
  // black_
  // };

 private:
  node_ptr  head_;
  size_type size_;

 public:
  tree_value() ft_noexcept : head_(), size_(0) {
  }
  // Returns rightmost node in subtree node
  static node_ptr max_(node_ptr node) ft_noexcept {
  }
  // Returns leftmost node in subtree node
  static node_ptr min_(node_ptr node) ft_noexcept {
  }
  // Promotes right node to root of subtree
  void leftRotate(node_ptr node) ft_noexcept {
  }
  // Promotes left node to root of subtree
  void rightRotate(node_ptr node) ft_noexcept {
  }
  //
  node_ptr extract(const_iterator where) ft_noexcept {
  }
  //
  node_ptr insert(node_ptr location, node_ptr new_node) ft_noexcept {
  }
  // 
  template <class AlNode>
  void eraseTree(AlNode &alloc, node_ptr root) ft_noexcept {}
  //
  template <class AlNode>
  void eraseHead(AlNode &alloc) ft_noexcept {}
};

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<T>>
class tree {
 public:
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