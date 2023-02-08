
#pragma once

#include <functional>  // std::binary_function, std::less
#include <memory>      // std::allocator

#include "tree.hpp"     // ft::rb_tree
#include "utility.hpp"  // ft::pair

#define ft_noexcept throw()

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<T>>
class map {
 public:
  typedef Key                                   key_type;
  typedef T                                     mapped_type;
  typedef ft::pair<const key_type, mapped_type> value_type;
  typedef Compare                               key_compare;
  typedef Allocator                             allocator_type;

  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
   public:
    friend class map<Key, T, Compare, Allocator>;

   protected:
    Compare comp;

    value_compare(Compare c) : comp(c) {
    }

   public:
    bool operator()(const value_type& lhs, const value_type& rhs) const {
      return comp(lhs.first_, rhs.first_);
    }
  };

 private:
  typedef ft::rb_tree<key_type, value_type, key_compare, allocator_type>
      base_type;

  base_type base_;

 public:
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef typename allocator_type::reference       reference;
  typedef typename allocator_type::const_reference const_reference;

  typedef typename base_type::size_type              size_type;
  typedef typename base_type::difference_type        difference_type;
  typedef typename base_type::iterator               iterator;
  typedef typename base_type::reverse_iterator       reverse_iterator;
  typedef typename base_type::const_iterator         const_iterator;
  typedef typename base_type::const_reverse_iterator const_reverse_iterator;

  /* Member functions */
  map() : base_() {
  }
  explicit map(const key_compare&    comp,
               const allocator_type& alloc = allocator_type())
      : base_(comp, alloc) {
  }
  template <class InputIt>
  map(InputIt first, InputIt last, const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type())
      : base_(first, last, comp, alloc) {
  }
  map(const map& other) : base_(other.base_) {
  }
  map& operator=(const map& other) {
    this->base_ = other.base_;
    return *this;
  }
  allocator_type get_allocator() const ft_noexcept {
    return allocator_type(base_.get_allocator());
  }
  ~map() {
  }

  /* Element access */
  mapped_type&       at(const key_type& key);
  const mapped_type& at(const key_type& key) const;
  mapped_type&       operator[](const key_type& key);

  /* Iterators */
  iterator begin() ft_noexcept {
    return base_.begin();
  }
  const_iterator begin() const ft_noexcept {
    return base_.begin();
  }
  iterator end() ft_noexcept {
    return base_.end();
  }
  const_iterator end() const ft_noexcept {
    return base_.end();
  }
  reverse_iterator rbegin() ft_noexcept {
    return base_.rbegin();
  }
  const_reverse_iterator rbegin() const ft_noexcept {
    return base_.rbegin();
  }
  reverse_iterator rend() ft_noexcept {
    return base_.rend();
  }
  const_reverse_iterator rend() const ft_noexcept {
    return base_.rend();
  }

  /* Capacity */
  bool empty() const ft_noexcept {
    return base_.empty();
  }
  size_type size() const ft_noexcept {
    return base_.size();
  }
  size_type max_size() const ft_noexcept {
    return max_size();
  }

  /* Modifiers */
  void clear() ft_noexcept {
    base_.clear();
  }
  ft::pair<iterator, bool> insert(const mapped_type& value) {
    iterator position = base_.find(value);
    if (position == base_.end()) {
      return ft::make_pair(base_.insert(), true);
    } else {
      return ft::make_pair(position, false);
    }
  }
  iterator insert(iterator position, const mapped_type& value) {
    return base_.insert(position, value);
  }
  template <class InputIt>
  void insert(InputIt first, InputIt last) {
    base_.insert(first, last);
  }
  iterator erase(iterator position) {
    return base_.erase(position);
  }
  iterator erase(iterator first, iterator last) {
    return base_.erase(first, last);
  }
  size_type erase(const key_type& key) {
    return base_.erase(key);
  }
  void swap(map& other) {
    base_.swap(other);
  }

  /* Lookup */
  size_type count(const key_type& key) const {
    return base_.count(key);
  }
  iterator find(const key_type& key) {
    return base_.find(key);
  }
  const_iterator find(const key_type& key) const {
    return base_.find(key);
  }
  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return base_.equal_range(key);
  }
  ft::pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const {
    return base_.equal_range(key);
  }
  iterator lower_bound(const key_type& key) {
    return base_.lower_bound(key);
  }
  const_iterator lower_bound(const key_type& key) const {
    return base_.lower_bound(key);
  }
  iterator upper_bound(const key_type& key) {
    return base_.upper_bound(key);
  }
  const_iterator upper_bound(const key_type& key) const {
    return base_.upper_bound(key);
  }

  /* Observers */
  key_compare key_comp() const {
    return Compare();
  }
  map::value_compare value_comp() const {
    return value_compare(base_.key_comp());
  }

  /* Friends */
  friend bool operator==(const ft::map<Key, T, Compare, Allocator>& lhs,
                         const ft::map<Key, T, Compare, Allocator>& rhs);

  friend bool operator<(const ft::map<Key, T, Compare, Allocator>& lhs,
                        const ft::map<Key, T, Compare, Allocator>& rhs);
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return lhs.base_ == rhs.base_;
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return !(lhs.base_ == rhs.base_);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs,
               const ft::map<Key, T, Compare, Alloc>& rhs) {
  return lhs.base_ < rhs.base_;
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs,
               const ft::map<Key, T, Compare, Alloc>& rhs) {
  return rhs < lhs;
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key, T, Compare, Alloc>& lhs,
          ft::map<Key, T, Compare, Alloc>& rhs) {
  return lhs.swap(rhs);
}

}  // namespace ft
