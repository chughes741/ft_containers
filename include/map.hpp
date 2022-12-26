
#pragma once
#ifndef MAP_HPP_
#define MAP_HPP_

#include <functional>  // std::binary_function, std::less
#include <memory>      // std::allocator

#include "pair.hpp"  // ft::pair

#define ft_noexcept throw()

namespace ft {

using ft::pair;

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
    map::Compare comp_;

    value_compare(Compare c) : comp(c) {}

   public:
    bool operator()(const value_type& lhs, const value_type& rhs) const {
      return comp(lhs.first_(), rhs.first_());
    }
  };

 private:
  typedef ft::RbTree<key_type, value_type, key_compare, allocator_type>
      base_type;

  base_type base;

 public:
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef typename allocator_type::reference       reference;
  typedef typename allocator_type::const_reference const_reference;

  typedef typename base_type::size_type       size_type;
  typedef typename base_type::difference_type difference_type;

  typedef typename base_type::iterator               iterator;
  typedef typename base_type::reverse_iterator       reverse_iterator;
  typedef typename base_type::const_iterator         const_iterator;
  typedef typename base_type::const_reverse_iterator reverse_iterator;

  /* Member functions */
  map() : base() {}
  explicit map(const key_compare&    comp,
               const allocator_type& alloc = allocator_type())
      : base(comp, alloc) {}
  template <class InputIt>
  map(InputIt first, InputIt last, const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type())
      : base(first, last, comp, alloc) {}
  map(const map& other) : base(other.base) {}
  map& operator=(const map& other) {
    this->base = other.base;
    return *this;
  }
  ~map();
  allocator_type get_allocator() const ft_noexcept {
    return allocator_type(base.get_allocator());
  }

  /* Element access */
  mapped_type&       at(const key_type& key);
  const mapped_type& at(const key_type& key);
  mapped_type&       operator[](const key_type& key);

  /* Iterators */
  iterator               begin() ft_noexcept { return base.begin(); }
  const_iterator         begin() const ft_noexcept { return base.begin(); }
  iterator               end() ft_noexcept { return base.end(); }
  const_iterator         end() const ft_noexcept { return base.end(); }
  reverse_iterator       rbegin() ft_noexcept { return base.rbegin(); }
  const_reverse_iterator rbegin() const ft_noexcept { return base.rbegin(); }
  reverse_iterator       rend() ft_noexcept { return base.rend(); }
  const_reverse_iterator rend() const ft_noexcept { return base.rend(); }

  /* Capacity */
  bool      empty() const ft_noexcept { return base.empty(); }
  size_type size() const ft_noexcept { return base.size(); }
  size_type max_size() const ft_noexcept { return max_size(); }

  /* Modifiers */
  void                     clear() ft_noexcept { return base.clear(); }
  ft::pair<iterator, bool> insert(const mapped_type& value) {
    return base.insert(value);
  }
  iterator insert(iterator position, const mapped_type& value) {
    return base.insert(position, value);
  }

  template <class InputIt>
  void insert(InputIt first, InputIt last) {
    return base.insert(first, last);
  }

  iterator erase(iterator position) { return base.erase(position); }
  iterator erase(iterator first, iterator last) {
    return base.erase(first, last);
  }
  size_type erase(const key_type& key) { return base.erase(key); }
  void      swap(map& other) { return base.swap(other); }

  /* Lookup */
  size_type      count(const key_type& key) const { return base.count(key); }
  iterator       find(const key_type& key) { return base.find(key); }
  const_iterator find(const key_type& key) const { return base.find(key); }
  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return base.equal_range(key);
  }
  ft::pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const {
    return base.equal_range(key);
  }
  iterator lower_bound(const key_type& key) { return base.lower_bound(key); }
  const_iterator lower_bound(const key_type& key) const {
    return base.lower_bound(key);
  }
  iterator upper_bound(const key_type& key) { return base.upper_bound(key); }
  const_iterator upper_bound(const key_type& key) const {
    return base.upper_bound(key);
  }

  /* Observers */
  // TODO
  key_compare key_comp() const;

  // TODO
  map::value_compare value_comp() const;

  /* Friends */
  template <class Key, class T, class Compare, class Alloc>
  friend bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
                         const ft::map<Key, T, Compare, Alloc>& rhs);

  template <class Key, class T, class Compare, class Alloc>
  friend bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs,
                        const ft::map<Key, T, Compare, Alloc>& rhs);
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return lhs.base == rhs.base;
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs) {
  return !(lhs.base == rhs.base);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs,
               const ft::map<Key, T, Compare, Alloc>& rhs) {
  return lhs.base < rhs.base;
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