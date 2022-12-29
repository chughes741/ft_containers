
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
class rb_tree {
 public:
  typedef Key       key_type;
  typedef T         value_type;
  typedef Allocator allocator_type;

  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef typename allocator_type::reference       reference;
  typedef typename allocator_type::const_reference const_reference;

  typedef typename allocator_type::size_type       size_type;
  typedef typename allocator_type::difference_type difference_type;

  typedef typename allocator_type::iterator         iterator;
  typedef typename allocator_type::const_iterator   const_iterator;
  typedef typename allocator_type::reverse_iterator reverse_iterator;
  typedef
      typename allocator_type::const_reverse_iterator const_reverse_iterator;

  /* Member functions */
  rb_tree();
  explicit rb_tree(const Compare&        comp,
                   const allocator_type& alloc = allocator_type());
  template <class InputIt>
  rb_tree(InputIt first, InputIt last, const Compare& comp = Compare(),
          const allocator_type& alloc = allocator_type());
  rb_tree(const rb_tree& other);
  rb_tree& operator=(const rb_tree& other);
  ~rb_tree();
  allocator_type get_allocator() const ft_noexcept;

  /* Element access */
  value_type& at(const key_type& key);  // TODO should rb_tree have kv pairs?
  const value_type& at(const key_type& key) const;
  value_type&       operator[](const key_type& key);

  /* Iterators */
  iterator               begin() ft_noexcept;
  const_iterator         begin() const ft_noexcept;
  iterator               end() ft_noexcept;
  const_iterator         end() const ft_noexcept;
  reverse_iterator       rbegin() ft_noexcept;
  const_reverse_iterator rbegin() const ft_noexcept;
  reverse_iterator       rend() ft_noexcept;
  const_reverse_iterator rend() const ft_noexcept;

  /* Capacity */
  bool      empty() const ft_noexcept;
  size_type size() const ft_noexcept;
  size_type max_size() const ft_noexcept;

  /* Modifiers */
  void                     clear() ft_noexcept;
  ft::pair<iterator, bool> insert(const value_type& value);  // TODO check types
  iterator insert(iterator position, const value_type& value);  // TODO ^
  template <class InputIt>
  void      insert(InputIt first, InputIt last);
  iterator  erase(iterator position);
  iterator  erase(iterator first, iterator last);
  size_type erase(const value_type& value);  // TODO check types

  /* Lookup */
  size_type                    count(const value_type& value);
  iterator                     find(const value_type& value);
  const_iterator               find(const value_type& value) const;
  ft::pair<iterator, iterator> equal_range(
      const value_type& value);  // TODO check type
  ft::pair<const_iterator, const_iterator> equal_range(
      const value_type& value) const;  // TODO ^
  iterator       lower_bound(const value_type& value);
  const_iterator lower_bound(const value_type& value) const;
  iterator       upper_bound(const value_type& value);
  const_iterator upper_bound(const value_type& value) const;

  /* Friends */
  friend bool operator==(const rb_tree<Key, T, Compare, Allocator>& lhs,
                         const rb_tree<Key, T, Compare, Allocator>& rhs);

  friend bool operator<(const rb_tree<Key, T, Compare, Allocator>& lhs,
                        const rb_tree<Key, T, Compare, Allocator>& rhs);
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::rb_tree<Key, T, Compare, Alloc>& lhs,
                const ft::rb_tree<Key, T, Compare, Alloc>& rhs) {}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::rb_tree<Key, T, Compare, Alloc>& lhs,
                const ft::rb_tree<Key, T, Compare, Alloc>& rhs) {
  return !(lhs.base == rhs.base);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::rb_tree<Key, T, Compare, Alloc>& lhs,
               const ft::rb_tree<Key, T, Compare, Alloc>& rhs) {}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::rb_tree<Key, T, Compare, Alloc>& lhs,
               const ft::rb_tree<Key, T, Compare, Alloc>& rhs) {
  return rhs < lhs;
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::rb_tree<Key, T, Compare, Alloc>& lhs,
                const ft::rb_tree<Key, T, Compare, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::rb_tree<Key, T, Compare, Alloc>& lhs,
                const ft::rb_tree<Key, T, Compare, Alloc>& rhs) {
  return !(lhs < rhs);
}

}  // namespace ft

#endif  // RB_TREE_HPP_