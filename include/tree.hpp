
#pragma once

#include <functional>  // std::less
#include <memory>      // std::allocator

#include "iterator.hpp"
#include "type_traits.hpp"
#include "utility.hpp"

#define ft_noexcept throw()

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
  tree_node(const value_type& value) ft_noexcept : parent_(NULL),
                                                   left_(NULL),
                                                   right_(NULL),
                                                   value_(value) {
  }
};

template <class Key, class Compare = std::less<Key>,
          class Allocator = std::allocator<Key>>
class tree {
 public:
  typedef Key                                      value_type;
  typedef Compare                                  value_compare;
  typedef Allocator                                allocator_type;
  typedef typename allocator_type::size_type       size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef value_type&                              reference;
  typedef const value_type&                        const_reference;
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef tree_iterator<tree<value_type>>          iterator;
  typedef tree_const_iterator<tree<value_type>>    const_iterator;
  typedef ft::reverse_iterator<iterator>           reverse_iterator;
  typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;

  typedef std::allocator<tree_node<Key>>   node_allocator;
  typedef tree_node<Key>                   node_type;
  typedef typename node_type::node_pointer node_pointer;

 private:
  allocator_type value_alloc_;
  node_allocator node_alloc_;
  value_compare  compare_;
  node_pointer   root_;
  size_type      size_;

 public:
  // Default constructor
  tree()
      : value_alloc_(allocator_type()),
        node_alloc_(node_allocator()),
        compare_(value_compare()),
        root_(NULL),
        size_(0) {
  }

  // Compare/Allocator constructor
  explicit tree(const Compare& comp, const Allocator& alloc = Allocator())
      : value_alloc_(alloc),
        node_alloc_(node_allocator()),
        compare_(comp),
        root_(NULL),
        size_(0) {
  }

  // Range constructor
  // template <class InputIt>
  // tree(InputIt first, InputIt last, const Compare& comp = Compare(),
  //  const Allocator& alloc = Allocator()) {
  // }

  // Copy constructor
  tree(const tree& other)
      : value_alloc_(other.value_alloc_),
        node_alloc_(other.node_alloc_),
        compare_(other.compare_),
        root_(NULL),
        size_(0) {
  }

  // Copy assignment
  tree& operator=(const tree& other) {
    if (*this == other) return *this;
    return *this;
  }

  // Destructor
  ~tree() {
  }

  // At operator
  reference operator[](const_reference key) {
    return const_cast<reference>(key);
  }

  // Returns iterator to the first element
  iterator begin() ft_noexcept {
    return iterator(root_);
  }
  const_iterator begin() const ft_noexcept {
    return const_iterator(root_);
  }

  // Returns iterator to one past the last element
  iterator end() ft_noexcept {
    return iterator(root_);  // TODO not the root
  }
  const_iterator end() const ft_noexcept {
    return const_iterator(root_);  // TODO not the root
  }

  // Returns a reverse iterator to last element
  reverse_iterator rbegin() ft_noexcept {
    return reverse_iterator(root_);  // TODO not the root
  }
  const_reverse_iterator rbegin() const ft_noexcept {
    return const_reverse_iterator(root_);  // TODO not the root
  }

  // Returns a reverse iterator to the first element
  reverse_iterator rend() ft_noexcept {
    return reverse_iterator(root_);
  }
  const_reverse_iterator rend() const ft_noexcept {
    return const_reverse_iterator(root_);
  }

  // True if tree is empty
  bool empty() const ft_noexcept {
    return size_ ? false : true;
  }

  // Returns number of elements in the tree
  size_type size() const ft_noexcept {
    return size_;
  }

  // Returns theorhetical maximum size of the tree
  size_type max_size() const ft_noexcept {
    return value_alloc_.max_size();
  }

  // Erases all elements in tree
  void clear() ft_noexcept {
  }

  // Inserts a new node into the tree
  void insert(const value_type& value) {
    node_pointer position = FindInsertPosition(value);
  }

  //
  value_compare& value_comp() {
    return compare_;
  }

  //
  const value_compare& value_comp() const {
    return compare_;
  }

 private:
  // Allocates a new node
  node_pointer BuyNode(const_reference value) {
    node_pointer new_node = new node_type(value);
    return new_node;
  }

  // Returns parent node of value or NULL if it doesn't exist
  node_pointer FindInsertPosition(const_reference value) {
    (void)value;
    return NULL;
  }
};

}  // namespace ft
