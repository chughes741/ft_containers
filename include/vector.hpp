
#pragma once
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstddef>
#include <iterator>
#include <memory>

namespace ft {

template <class MyVector>
class VectorConstIterator : public _Iterator_base {
 public:
  using iterator_category = random_access_iterator_tag;
  using value_type        = typename MyVector::value_type;
  using difference_type   = typename MyVector::difference_type;
  using pointer           = typename MyVector::const_pointer;
  using reference         = const value_type&;

  using Ptr = typename MyVector::pointer;

  VectorConstIterator();
  VectorConstIterator(Ptr p_arg_, const _Container_base* p_vector_);
  reference            operator*() const;
  pointer              operator->() const;
  VectorConstIterator& operator++();
  VectorConstIterator  operator++(int);
  VectorConstIterator& operator--();
  VectorConstIterator  operator--(int);
  VectorConstIterator& operator+=(const difference_type offset_);
  VectorConstIterator  operator+(const difference_type offset_) const;
  VectorConstIterator  operator+(const difference_type offset_,
                                VectorConstIterator   next_);
  VectorConstIterator& operator-=(const difference_type offset_);
  VectorConstIterator  operator-(const difference_type offset_) const;
  difference_type      operator-(const VectorConstIterator& rhs) const;
  reference            operator[](const difference_type offset_) const;
  bool                 operator==(const VectorConstIterator& rhs) const;
  bool                 operator!=(const VectorConstIterator& rhs) const;
  bool                 operator<(const VectorConstIterator& rhs) const;
  bool                 operator>(const VectorConstIterator& rhs) const;
  bool                 operator<=(const VectorConstIterator& rhs) const;
  bool                 operator>=(const VectorConstIterator& rhs) const;

  Ptr ptr_;
};

template <class MyVector>
class VectorIterator : public VectorConstIterator<MyVector> {
 public:
  using _Mybase           = VectorConstIterator<MyVector>;
  using iterator_category = random_access_iterator_tag;
  using value_type        = typename MyVector::value_type;
  using difference_type   = typename MyVector::difference_type;
  using pointer           = typename MyVector::pointer;
  using reference         = value_type&;
  using _Mybase::_Mybase;

  reference       operator*() const;
  pointer         operator->() const;
  VectorIterator& operator++();
  VectorIterator  operator++(int);
  VectorIterator& operator--();
  VectorIterator  operator--(int);
  VectorIterator& operator+=(const difference_type offset_);
  VectorIterator  operator+(const difference_type offset_) const;
  VectorIterator operator+(const difference_type offset_, VectorIterator next_);
  VectorIterator& operator-=(const difference_type offset_);
  VectorIterator  operator-(const difference_type offset_) const;
  VectorIterator operator-(const difference_type offset_, VectorIterator next_);
  VectorIterator operator-(const difference_type offset_) const;
  reference      operator[](const difference_type offset_) const;
};

template <class ValueType, class SizeType, class DifferenceType, class Pointer,
          class ConstPointer, class Reference, class ConstReference>
struct VectorIteratorTypes {
  using value_type      = ValueType;
  using size_type       = SizeType;
  using difference_type = DifferenceType;
  using pointer         = Pointer;
  using const_pointer   = ConstPointer;
};

template <class ValueTypes>
class VectorValue : public _Container_base {
 public:
  using value_type      = typename ValueTypes::value_type;
  using size_type       = typename ValueTypes::size_type;
  using difference_type = typename ValueTypes::difference_type;
  using pointer         = typename ValueTypes::pointer;
  using const_pointer   = typename ValueTypes::const_pointer;
  using reference       = value_type&;
  using const_reference = const value_type&;

  VectorValue();
  VectorValue(pointer first_, pointer last_, pointer end_);
  void SwapValue(VectorValue& rhs);
  void TakeContents(VectorValue& rhs);

  pointer my_first_;
  pointer my_last_;
  pointer my_end_;
};

template <class T, class Allocator = std::allocator<T>>
class vector {
 public:
  using value_type      = T;
  using allocator_type  = Allocator;
  using pointer         = typename Allocator::pointer;
  using const_pointer   = typename Allocator::const_pointer;
  using reference       = value_type&;
  using const_reference = const value_type&;
  using size_type       = typename std::size_t;
  using difference_type = typename std::ptrdiff_t;

  using iterator               = VectorIterator<T>;
  using const_iterator         = VectorConstIterator<T>;
  using reverse_iterator       = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  vector();
  explicit vector(const Allocator& alloc_);
  explicit vector(size_type count_, const T& value_ = T(),
                  const Allocator& alloc_ = Allocator());
  template <class InputIt>
  vector(InputIt first_, InputIt last_, const Allocator& alloc_ = Allocator());
  vector(const vector& other_);
  vector& operator=(const vector& right_);
  ~vector();

  void     push_back(const T& value_);
  iterator insert(const_iterator pos_, const T& value_);
  iterator insert(const_iterator pos_, size_type count_, const T& value_);
  template <class _Iter>
  iterator insert(const_iterator pos_, _Iter first_, _Iter last_);
  void     assign(size_type count_, const T& value_);
  template <class _Iter, enable_if_t<_Is_iterator_v<_Iter>, int> = 0>
  void            assign(_Iter first_, _Iter last_);
  void            resize(size_type count_);
  void            resize(size_type count_, T value_ = T());
  void            reserve(size_type new_cap_);
  void            pop_back();
  iterator        erase(iterator pos_);
  iterator        erase(iterator first_, iterator last_);
  void            clear();
  void            swap(vector& other);
  T*              data();
  const T*        data() const;
  bool            empty() const;
  size_type       size() const;
  size_type       max_size() const;
  size_type       capacity() const;
  reference       operator[](size_type pos_);
  const_reference operator[](size_type pos_) const;
  reference       at(size_type pos_);
  const_reference at(size_type pos_) const;
  reference       front();
  const_reference front() const;
  reference       back();
  const_reference back() const;
  allocator_type  get_allocator() const;
};

template <class T, class Alloc>
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc>& lsh, const vector<T, Alloc>& rsh);

template <class T, class Alloc>
bool operator<(const vector<T, Alloc>& lsh, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs);

}  // namespace ft

#endif  // VECTOR_HPP_
