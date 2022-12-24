
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstddef>

namespace ft {

// std::vector meets the requirements of Container, AllocatorAwareContainer,
//  SequenceContainer, and ReversibleContainer.
// T must meet the requirements of CopyAssignable and CopyConstructible.
// An allocator that is used to acquire/release memory and to construct/destroy
//  the elements in that memory. The type must meet the requirements of
//  Allocator. The behavior is undefined if Allocator::value_type is not the
//  same as T.
template <class T, class Allocator = std::allocator<T>>
class Vector {
 public:
  using value_type      = T;
  using allocator_type  = Allocator;
  using size_type       = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference       = value_type &;
  using const_reference = const value_type &;
  using pointer         = Allocator::pointer;
  using const_pointer   = Allocator::const_pointer;
  // using iterator =
  // using const_iterator =
  // using reverse_iterator =
  // using const_reverse_iterator =

  Vector();
  Vector(const Vector &other);
  Vector &operator=(const Vector &rhs);
  ~Vector();

  allocator_type get_allocator() const;

  // Element access
  reference       at(size_type pos);
  const_reference at(size_type pos) const;
  reference       operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  reference       front();
  const_reference front() const;
  reference       back();
  const_reference back() const;
  T              *data();
  const T        *data() const;

  // Iterators
  iterator               begin();
  const_iterator         begin() const;
  iterator               end();
  const_iterator         end() const;
  reverse_iterator       rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator       rend();
  const_reverse_iterator rend() const;

  // Capacity
  bool      empty() const;
  size_type size() const;
  size_type max_size() const;
  void      reserve(size_type new_cap);
  size_type capacity() const;

  // Modifiers
  void     clear();
  iterator insert(const_iterator pos, const T &value);
  // Check iterators for C++98
  iterator erase(iterator pos);
  iterator erase(iterator first, iterator last);
  void     push_back(const T &value);
  void     pop_back();
  void     resize(size_type count, T value = T());
  void     resize(size_type count, T value = T());
};

template <class T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool operator!=(const std::vector<T, Alloc> &lhs,
                const std::vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool operator<(const std::vector<T, Alloc> &lhs,
               const std::vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool operator<=(const std::vector<T, Alloc> &lhs,
                const std::vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool operator>(const std::vector<T, Alloc> &lhs,
               const std::vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool operator>=(const std::vector<T, Alloc> &lhs,
                const std::vector<T, Alloc> &rhs);

template <class T, class Alloc>
void swap(std::vector<T, Alloc> &lhs, std::vector<T, Alloc> &rhs);
}  // namespace ft

#endif  // VECTOR_HPP_
