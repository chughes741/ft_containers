
#pragma once
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstddef>
#include <iterator>
#include <memory>

#define ft_noexcept throw()

namespace ft {

template <class MyVector>
class VectorConstIterator {
 public:
  VectorConstIterator();
  VectorConstIterator(MyVector::pointer      p_arg_,
                      const _Container_base* p_vector_);
  MyVector::value_type&   operator*() const;
  MyVector::const_pointer operator->() const;
  VectorConstIterator&    operator++();
  VectorConstIterator     operator++(int);
  VectorConstIterator&    operator--();
  VectorConstIterator     operator--(int);
  VectorConstIterator&    operator+=(const MyVector::difference_type offset_);
  VectorConstIterator  operator+(const MyVector::difference_type offset_) const;
  VectorConstIterator  operator+(const MyVector::difference_type offset_,
                                VectorConstIterator             next_);
  VectorConstIterator& operator-=(const MyVector::difference_type offset_);
  VectorConstIterator  operator-(const MyVector::difference_type offset_) const;
  MyVector::difference_type operator-(const VectorConstIterator& rhs) const;
  MyVector::value_type&     operator[](
      const MyVector::difference_type offset_) const;
  bool operator==(const VectorConstIterator& rhs) const;
  bool operator!=(const VectorConstIterator& rhs) const;
  bool operator<(const VectorConstIterator& rhs) const;
  bool operator>(const VectorConstIterator& rhs) const;
  bool operator<=(const VectorConstIterator& rhs) const;
  bool operator>=(const VectorConstIterator& rhs) const;

  MyVector::pointer ptr_;
};

template <class MyVector>
class VectorIterator : public VectorConstIterator<MyVector> {
 public:
  MyVector::value_type& operator*() const;
  MyVector::pointer     operator->() const;
  VectorIterator&       operator++();
  VectorIterator        operator++(int);
  VectorIterator&       operator--();
  VectorIterator        operator--(int);
  VectorIterator&       operator+=(const MyVector::difference_type offset_);
  VectorIterator  operator+(const MyVector::difference_type offset_) const;
  VectorIterator  operator+(const MyVector::difference_type offset_,
                           VectorIterator                  next_);
  VectorIterator& operator-=(const MyVector::difference_type offset_);
  VectorIterator  operator-(const MyVector::difference_type offset_) const;
  VectorIterator  operator-(const MyVector::difference_type offset_,
                           VectorIterator                  next_);
  VectorIterator  operator-(const MyVector::difference_type offset_) const;
  MyVector::value_type& operator[](
      const MyVector::difference_type offset_) const;
};

template <class ValueTypes>
class VectorValue {
 public:
  VectorValue();
  VectorValue(ValueTypes::pointer first_, ValueTypes::pointer last_,
              ValueTypes::pointer end_);
  void SwapValue(VectorValue& rhs);
  void TakeContents(VectorValue& rhs);

  ValueTypes::pointer my_first_;
  ValueTypes::pointer my_last_;
  ValueTypes::pointer my_end_;
};

template <class T, class Allocator = std::allocator<T>>
class vector {
 public:
  typedef Allocator allocator_type;

  typedef T                                        value_type;
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef typename allocator_type::reference       reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::size_type       size_type;
  typedef typename allocator_type::difference_type difference_type;

  typedef VectorIterator<T>                     iterator;
  typedef VectorConstIterator<T>                const_iterator;
  typedef std::reverse_iterator<iterator>       reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  /* Member functions */
  // Default constructor
  vector() ft_noexcept;

  // Default constructor overload with different allocator
  explicit vector(const Allocator& alloc_) ft_noexcept;

  // Default constructor overload with init size and init value
  explicit vector(size_type count_, const value_type& value_ = value_type(),
                  const Allocator& alloc_ = Allocator());

  // Default range constructor template
  template <class InputIt>
  vector(InputIt first_, InputIt last_, const Allocator& alloc_ = Allocator());

  // Default copy constructor
  vector(const vector& other_);

  // Copy assignment operator overload
  vector& operator=(const vector& right_);

  // Default destructor
  ~vector();

  // Replaces contents with count copy of value
  void assign(size_type count_, const value_type& value_);

  // Replaces elements with copies of those in [first, last)
  void assign(_Iter first_, _Iter last_);

  // Returns allocator associated with the container
  allocator_type get_allocator() const ft_noexcept;

  /* Element access */
  // Returns a T& to the element at pos_, with bound checks
  value_type& at(size_type pos_);

  // Returns a const T& to the element at pos_, with bound checks
  const value_type& at(size_type pos_) const;

  // Returns a T& to the element at pos_, no bound checks
  value_type& operator[](size_type pos_);

  // Returns a cont_reference to the element at pos_, no bound checks
  const value_type& operator[](size_type pos_) const;

  // Returns a T& to the first element in the container
  value_type& front();

  // Returns a const T& to the first element in the container
  const value_type& front() const;

  // Returns a T& to the last element in the container
  value_type& back();

  // Returns a const T& to the last element in the container
  const value_type& back() const;

  // Returns a Allocator::pointer to the underlying array serving as element
  // storage
  value_type* data() ft_noexcept;

  // Returns a Allocator::const_pointer to the underlying array serving as
  // element storage
  const value_type* data() const ft_noexcept;

  /* Capacity */
  // Checks if the container is empty
  bool empty() const ft_noexcept;

  // Returns the number of elements in the container
  size_type size() const ft_noexcept;

  // Returns the maximum number of elements of the container, sys dependant
  size_type max_size() const ft_noexcept;

  // Increases the capacity of the vector, will not shrink it
  void reserve(size_type new_cap_);

  // Returns the number of elements the container can currently hold
  size_type capacity() const;

  /* Modifiers */
  // Clears the contents of the container
  void clear() ft_noexcept;

  // Inserts value_ before pos_
  iterator insert(const_iterator pos_, const value_type& value_);

  // Inserts count_ copy of value_ before pos_
  iterator insert(const_iterator pos_, size_type count_,
                  const value_type& value_);

  // Inserts [first_, last_) before pos_
  template <class InputIt>
  iterator insert(const_iterator pos_, InputIt first_, InputIt last_);

  // Erases the element at pos_
  iterator erase(iterator pos_);

  // Erases the elements in [first_, last_)
  iterator erase(iterator first_, iterator last_);

  // Adds element to end of the vector
  void push_back(const value_type& value_);

  // Removes element from the end of the vector
  void pop_back();

  // Changes the number of elements stored
  void resize(size_type count_, value_type value_ = value_type());

  // Swaps the contents of two vectors
  void swap(vector& other);
};

// equal to overload for vector
template <class T, class Alloc>
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

// not equal to overload for vector
template <class T, class Alloc>
bool operator!=(const vector<T, Alloc>& lsh, const vector<T, Alloc>& rsh);

// less than overload for vector
template <class T, class Alloc>
bool operator<(const vector<T, Alloc>& lsh, const vector<T, Alloc>& rhs);

// greater than overload for vector
template <class T, class Alloc>
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

// less than or equal to overload for vector
template <class T, class Alloc>
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

// greater than or equal to overload for vector
template <class T, class Alloc>
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

// Uses the std::swap algorithm to swap two vectors
template <class T, class Alloc>
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs);

}  // namespace ft

#endif  // VECTOR_HPP_
