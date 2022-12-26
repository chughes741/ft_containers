
#pragma once
#ifndef MAP_HPP_
#define MAP_HPP_

#include <cstddef>
#include <iterator>
#include <memory>

#include "algorithm.hpp"
#include "interator.hpp"
#include "pair.hpp"

#define ft_noexcept throw()

namespace ft {

using ft::pair;

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<T>>
class map {
 public:
  typedef Allocator                         allocator_type;
  typedef Key                               key_type;
  typedef T                                 mapped_type;
  typedef Compare                           key_compare;
  typedef pair<const key_type, mapped_type> value_type;

  typedef typename allocator::pointer         pointer;
  typedef typename allocator::const_pointer   const_pointer;
  typedef typename allocator::reference       reference;
  typedef typename allocator::const_reference const_reference;

  typedef typename Base::size_type              size_type;
  typedef typename Base::difference_type        difference_type;
  typedef typename Base::iterator               iterator;
  typedef typename Base::const_iterator         const_iterator;
  typedef typename Base::reverse_iterator       reverse_iterator;
  typedef typename Base::const_reverse_iterator reverse_iterator;

  // class value_compare

  /* Member functions */
  // Default constructor
  map();

  // Default constructor
  explicit map(const Compare& comp, const Allocator& alloc = Allocator());

  // Default range constructor
  template <class InputIt>
  map(InputIt first_, InputIt last_, const Compare& comp = Compare(),
      const Allocator& alloc = Allocator());

  // Default copy constructor
  map(const map& other);

  // Copy assignment operator overload
  map& operator=(const map& other);

  // Default destructor
  ~map();

  // Returns allocator associated with the container
  allocator_type get_allocator() const ft_noexcept;

  /* Element access */
  // Returns a T& of value with key_
  mapped_type& at(const key_type& key_);

  // Returns a const T& of value with key_
  const mapped_type& at(const key_type& key_);

  // Returns value mapped to key_, inserts if it doesn't exist
  mapped_type& operator[](const key_type& key_);

  /* Iterators */
  //
  iterator begin() ft_noexcept;

  //
  const_iterator begin() const ft_noexcept;

  //
  iterator end() ft_noexcept;

  //
  const_iterator end() const ft_noexcept;

  //
  reverse_iterator rbegin() ft_noexcept;

  //
  const_reverse_iterator rbegin() const ft_noexcept;

  //
  reverse_iterator rend() ft_noexcept;

  //
  const_reverse_iterator rend() const ft_noexcept;

  /* Capacity */
  //
  bool empty() const ft_noexcept;

  //
  size_type size() const ft_noexcept;

  //
  size_type max_size() const ft_noexcept;

  /* Modifiers */
  //
  void clear() ft_noexcept;

  //
  pair<iterator, bool> insert(const mapped_type& value_);

  //
  iterator insert(iterator pos_, const mapped_type& value_);

  //
  template <class InputIt>
  void insert(InputIt first_, InputIt last_);

  //
  iterator erase(iterator pos_);

  //
  iterator erase(interator first_, iterator last_);

  //
  size_type erase(const key_type& key_);

  //
  void swap(map& other);

  /* Lookup */
  //
  size_type count(const key_type& key_) const;

  //
  iterator find(const key_type& key_);

  //
  const_iterator find(const key_type& key_) const;

  //
  pair<iterator, iterator> equal_range(const key_type& key_);

  //
  pair<const_iterator, const_iterator> equal_range(const key_type& key_) const;

  //
  iterator lower_bound(const key_type& key_);

  //
  const_iterator lower_bound(const key_type& key_) const;

  //
  iterator upper_bound(const key_type& key_);

  //
  const_iterator upper_bound(const key_type& key_) const;

  /* Observers */
  // TODO
  key_compare key_comp() const;

  // TODO
  map::value_compare value_comp() const;
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs,
               const ft::map<Key, T, Compare, Alloc>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     lhs.end());
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
          ft::map<Key, T, Compare, Alloc>& rhs);

}  // namespace ft

#endif  // MAP_HPP_