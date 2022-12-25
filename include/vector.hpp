
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
class VectorValue : public _Container_base {
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
  /* Member functions */
  // Default constructor
  vector();

  // Default constructor overload with different allocator
  explicit vector(const Allocator& alloc_);  // TODO check if needed

  // Default constructor overload with init size and init value
  explicit vector(std::size_t count_, const T& value_ = T(),
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
  void assign(std::size_t count_, const T& value_);

  // Replaces elements with copies of those in [first, last)
  void assign(_Iter first_, _Iter last_);

  // Returns allocator associated with the container
  Allocator get_allocator() const;

  /* Element access */
  // Returns a T& to the element at pos_, with bound checks
  T& at(std::size_t pos_);

  // Returns a const T& to the element at pos_, with bound checks
  const T& at(std::size_t pos_) const;

  // Returns a T& to the element at pos_, no bound checks
  T& operator[](std::size_t pos_);

  // Returns a cont_reference to the element at pos_, no bound checks
  const T& operator[](std::size_t pos_) const;

  // Returns a T& to the first element in the container
  T& front();

  // Returns a const T& to the first element in the container
  const T& front() const;

  // Returns a T& to the last element in the container
  T& back();

  // Returns a const T& to the last element in the container
  const T& back() const;

  // Returns a Allocator::pointer to the underlying array serving as element
  // storage
  T* data();

  // Returns a Allocator::const_pointer to the underlying array serving as
  // element storage
  const T* data() const;

  /* Capacity */
  // Checks if the container is empty
  bool empty() const;

  // Returns the number of elements in the container
  std::size_t size() const;

  // Returns the maximum number of elements of the container, sys dependant
  std::size_t max_size() const;

  // Increases the capacity of the vector, will not shrink it
  void reserve(std::size_t new_cap_);

  // Returns the number of elements the container can currently hold
  std::size_t capacity() const;

  /* Modifiers */
  // Clears the contents of the container
  void clear();

  // Inserts value_ before pos_
  VectorIterator<T> insert(VectorConstIterator<T> pos_, const T& value_);

  // Inserts count_ copy of value_ before pos_
  VectorIterator<T> insert(VectorConstIterator<T> pos_, std::size_t count_,
                           const T& value_);

  // Inserts [first_, last_) before pos_
  template <class InputIt>
  VectorIterator<T> insert(VectorConstIterator<T> pos_, InputIt first_,
                           InputIt last_);

  // Erases the element at pos_
  VectorIterator<T> erase(VectorIterator<T> pos_);

  // Erases the elements in [first_, last_)
  VectorIterator<T> erase(VectorIterator<T> first_, VectorIterator<T> last_);

  // Adds element to end of the vector
  void push_back(const T& value_);

  // Removes element from the end of the vector
  void pop_back();

  // Changes the number of elements stored
  void resize(std::size_t count_, T value_ = T());

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
