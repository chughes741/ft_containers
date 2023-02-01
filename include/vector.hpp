
#pragma once
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>  // RBS
#include <iterator>  // std::iterator
#include <memory>    // std::uninitialized_fill
#include <stdexcept>
#include <string>

#include "algorithm.hpp"
#include "iterator.hpp"

#define ft_noexcept throw()

namespace ft {

template <class MyVector>
class vector_const_iterator {
 public:
  typedef std::random_access_iterator_tag    iterator_category;
  typedef typename MyVector::value_type      value_type;
  typedef typename MyVector::difference_type difference_type;
  typedef typename MyVector::pointer         pointer;
  typedef typename MyVector::const_pointer   const_pointer;
  typedef typename MyVector::reference       reference;
  typedef typename MyVector::const_reference const_reference;

  const_pointer ptr_;

  vector_const_iterator() ft_noexcept : ptr_() {
  }
  vector_const_iterator(pointer ptr) ft_noexcept : ptr_(ptr) {
  }
  const value_type& operator*() const ft_noexcept {
    return *ptr_;
  }
  const_pointer operator->() const ft_noexcept {
    return ptr_;
  }
  vector_const_iterator& operator++() ft_noexcept {
    ++ptr_;
    return *this;
  }
  vector_const_iterator operator++(int) ft_noexcept {
    vector_const_iterator temp = *this;
    ++ptr_;
    return temp;
  }
  vector_const_iterator& operator--() ft_noexcept {
    --ptr_;
    return *this;
  }
  vector_const_iterator operator--(int) {
    vector_const_iterator temp = *this;
    --ptr_;
    return temp;
  }
  vector_const_iterator& operator+=(const difference_type offset) {
    ptr_ += offset;
    return *this;
  }
  vector_const_iterator operator+(const difference_type offset) const {
    vector_const_iterator temp = *this;
    temp += offset;
    return temp;
  }
  vector_const_iterator& operator-=(const difference_type offset) {
    ptr_ -= offset;
    return *this;
  }
  vector_const_iterator operator-(const difference_type offset) const {
    vector_const_iterator temp = *this;
    temp -= offset;
    return temp;
  }
  difference_type operator-(const vector_const_iterator& rhs) const {
    return ptr_ - rhs.ptr_;
  }
  value_type& operator[](const difference_type offset) const {
    return *(ptr_ + offset);
  }

  // friend bool operator==(const vector_const_iterator<MyVector>& lhs,
  //  const vector_const_iterator<MyVector>& rhs);
  // friend bool operator<(const vector_const_iterator<MyVector>& lhs,
  // const vector_const_iterator<MyVector>& rhs);
};

template <class MyVector>
bool operator==(const ft::vector_const_iterator<MyVector>& lhs,
                const ft::vector_const_iterator<MyVector>& rhs) {
  return lhs.ptr_ == rhs.ptr_;
}

template <class MyVector>
bool operator!=(const ft::vector_const_iterator<MyVector>& lhs,
                const ft::vector_const_iterator<MyVector>& rhs) {
  return !(lhs == rhs);
}

template <class MyVector>
bool operator<(const ft::vector_const_iterator<MyVector>& lhs,
               const ft::vector_const_iterator<MyVector>& rhs) {
  return lhs.ptr_ < rhs.ptr_;
}

template <class MyVector>
bool operator>(const ft::vector_const_iterator<MyVector>& lhs,
               const ft::vector_const_iterator<MyVector>& rhs) {
  return rhs < lhs;
}

template <class MyVector>
bool operator<=(const ft::vector_const_iterator<MyVector>& lhs,
                const ft::vector_const_iterator<MyVector>& rhs) {
  return !(rhs < lhs);
}

template <class MyVector>
bool operator>=(const ft::vector_const_iterator<MyVector>& lhs,
                const ft::vector_const_iterator<MyVector>& rhs) {
  return !(lhs < rhs);
}

template <class MyVector>
class vector_iterator {  //: public ft::vector_const_iterator<MyVector> {
 public:
  typedef std::random_access_iterator_tag    iterator_category;
  typedef typename MyVector::value_type      value_type;
  typedef typename MyVector::difference_type difference_type;
  typedef typename MyVector::pointer         pointer;
  typedef typename MyVector::const_pointer   const_pointer;
  typedef typename MyVector::reference       reference;
  typedef typename MyVector::const_reference const_reference;

  pointer ptr_;

  vector_iterator() ft_noexcept : ptr_() {
  }
  vector_iterator(pointer ptr) ft_noexcept : ptr_(ptr) {
  }
  value_type& operator*() const ft_noexcept {
    return *ptr_;
  }
  const_pointer operator->() const ft_noexcept {
    return ptr_;
  }
  vector_iterator& operator++() ft_noexcept {
    ++ptr_;
    return *this;
  }
  vector_iterator operator++(int) ft_noexcept {
    vector_iterator temp = *this;
    ++ptr_;
    return temp;
  }
  vector_iterator& operator--() ft_noexcept {
    --ptr_;
    return *this;
  }
  vector_iterator operator--(int) {
    vector_iterator temp = *this;
    --ptr_;
    return temp;
  }
  vector_iterator& operator+=(const difference_type offset) {
    ptr_ += offset;
    return *this;
  }
  vector_iterator operator+(const difference_type offset) const {
    vector_iterator temp = *this;
    temp += offset;
    return temp;
  }
  vector_iterator& operator-=(const difference_type offset) {
    ptr_ -= offset;
    return *this;
  }
  vector_iterator operator-(const difference_type offset) const {
    vector_iterator temp = *this;
    temp -= offset;
    return temp;
  }
  difference_type operator-(const vector_iterator& rhs) const {
    return ptr_ - rhs.ptr_;
  }
  value_type& operator[](const difference_type offset) const {
    return *(ptr_ + offset);
  }

  // friend bool operator==(const vector_iterator<MyVector>& lhs,
  //  const vector_iterator<MyVector>& rhs);
  // friend bool operator<(const vector_iterator<MyVector>& lhs,
  // const vector_iterator<MyVector>& rhs);
};

template <class MyVector>
bool operator==(const ft::vector_iterator<MyVector>& lhs,
                const ft::vector_iterator<MyVector>& rhs) {
  return lhs.ptr_ == rhs.ptr_;
}

template <class MyVector>
bool operator!=(const ft::vector_iterator<MyVector>& lhs,
                const ft::vector_iterator<MyVector>& rhs) {
  return !(lhs == rhs);
}

template <class MyVector>
bool operator<(const ft::vector_iterator<MyVector>& lhs,
               const ft::vector_iterator<MyVector>& rhs) {
  return lhs.ptr_ < rhs.ptr_;
}

template <class MyVector>
bool operator>(const ft::vector_iterator<MyVector>& lhs,
               const ft::vector_iterator<MyVector>& rhs) {
  return rhs < lhs;
}

template <class MyVector>
bool operator<=(const ft::vector_iterator<MyVector>& lhs,
                const ft::vector_iterator<MyVector>& rhs) {
  return !(rhs < lhs);
}

template <class MyVector>
bool operator>=(const ft::vector_iterator<MyVector>& lhs,
                const ft::vector_iterator<MyVector>& rhs) {
  return !(lhs < rhs);
}

// Vector<T> class template
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

  typedef ft::vector_iterator<vector<T>>       iterator;
  typedef ft::vector_const_iterator<vector<T>> const_iterator;
  typedef ft::reverse_iterator<iterator>       reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  allocator_type alloc_;
  pointer        first_ = NULL;
  pointer        last_  = NULL;
  pointer        end_   = NULL;

 public:
  // Default constructor
  vector() ft_noexcept : alloc_(Allocator()),
                         first_(alloc_.allocate(0)),
                         last_(first_),
                         end_(first_) {
  }

  // Constructor with allocator override
  explicit vector(const Allocator& alloc) ft_noexcept
      : alloc_(alloc),
        first_(alloc_.allocate(0)),
        last_(first_),
        end_(first_) {
  }

  // Constructor with size and default value
  explicit vector(size_type count, const value_type& value = value_type(),
                  const Allocator& alloc = Allocator())
      : alloc_(alloc), first_(alloc_.allocate(0)), last_(first_), end_(last_) {
    Reallocate(SmartSize(count), value);
  }

  // Range constructor
  template <class InputIt>
  vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
      : alloc_(alloc) {
    first_ = alloc_.allocate(SmartSize(last - first));
    last_  = first_ + (last - first);
    end_   = first_ + SmartSize(last - first);
    std::copy(first, last, iterator(first_));
  }

  // Copy constructor
  vector(const vector& other) : alloc_(other.alloc_) {
    first_ = alloc_.allocate(SmartSize(other.last_ - other.first_));
    last_  = first_ + (other.last_ - other.first_);
    end_   = first_ + SmartSize(other.last_ - other.first_);
    std::copy(other.begin(), other.end(), begin());
  }

  // Copy assignment operator overload
  vector& operator=(const vector& rhs) {
    if (*this == rhs) {
      return *this;
    }
    clear();
    Reallocate(rhs.size());
    std::copy(rhs.begin(), rhs.end(), begin());
    return *this;
  }

  // Destructor
  ~vector() ft_noexcept {
    for (size_type i = 0; i < (end_ - last_); ++i) {
      alloc_.destroy(first_ + i);
    }
    alloc_.deallocate(first_, last_ - first_);
  }

  // Replaces the contents with count copies of value value
  void assign(size_type count, const value_type& value) {
    resize(count);
    std::fill(begin(), end(), value);
  }

  // Replaces the contents with copies of those in the range [first, last)
  template <class InputIt>
  void assign(InputIt first, InputIt last) {
    resize((first - last));
    std::copy(first, last, begin());
  }

  // Returns copy of the allocator<T>
  allocator_type get_allocator() const ft_noexcept {
    return alloc_;
  }

  // Returns value of the element at(index), checks range
  value_type& at(size_type position) {
    RangeCheck(position);
    return *(first_ + position);
  }

  // Returns value of the element at(index), checks range
  const value_type& at(size_type position) const {
    return at(position);
  }

  // Returns value of the element at [index], does not check range
  value_type& operator[](size_type position) {
    return *(this->first_ + position);
  }

  // Returns value of the element at [index], does not check range
  const value_type& operator[](size_type position) const {
    return (*this)[position];
  }

  // Returns value of the first element in the array
  value_type& front() {
    return *(this->first_);
  }

  // Returns value of the first element in the array
  const value_type& front() const {
    return front();
  }

  // Returns value of the last element in the array
  value_type& back() {
    return *(this->last_);
  }

  // Returns value of the last element in the array
  const value_type& back() const {
    return back();
  }

  // Returns a raw pointer to the start of the underlying array
  value_type* data() ft_noexcept {
    return this->first_;
  }

  // Returns a raw pointer to the start of the underlying array
  const value_type* data() const ft_noexcept {
    return &(this->first_);
  }

  // Returns a iterator to the start of the vector
  iterator begin() ft_noexcept {
    return iterator(first_);
  }

  // Returns a iterator to the start of the vector
  const_iterator begin() const ft_noexcept {
    return const_iterator(first_);
  }

  // Returns a iterator to the end of the vector
  iterator end() ft_noexcept {
    return iterator(last_ + 1);
  }

  // Returns a iterator to the end of the vector
  const_iterator end() const ft_noexcept {
    return const_iterator(last_ + 1);
  }

  // Returns a reverse iterator to the start of the reversed vector
  reverse_iterator rbegin() ft_noexcept {
    return reverse_iterator(this->last_, this);
  }

  // Returns a reverse iterator to the start of the reversed vector
  const_reverse_iterator rbegin() const ft_noexcept {
    return const_reverse_iterator(this->last_, this);
  }

  // Returns a reverse iterator to the end of the reversed vector
  reverse_iterator rend() ft_noexcept {
    return reverse_iterator(this->first_ - 1, this);
  }

  // Returns a reverse iterator to the end of the reversed vector
  const_reverse_iterator rend() const ft_noexcept {
    return const_reverse_iterator(this->first_ - 1, this);
  }

  // Returns true if there are no elements in use
  bool empty() const ft_noexcept {
    return this->size() == 0 ? true : false;
  }

  // Returns the number of elements currently in use
  size_type size() const ft_noexcept {
    return (this->last_ - this->first_);
  }

  // Returns the max allowable size of the array
  size_type max_size() const ft_noexcept {
    return alloc_.max_size();
  }

  // Increases the reserved capacity of the array
  void reserve(size_type new_cap) {
    if (new_cap > this->size()) {
      Reallocate(new_cap);
    }
  }

  // Returns the number of elements that have space allocated for them
  size_type capacity() const {
    return end_ - first_;
  }

  // Erases all elements from the container. After this call, size() is zero.
  void clear() ft_noexcept {
    Reallocate(0);
  }

  // Inserts value before pos
  iterator insert(const_iterator pos, const value_type& value) {
    Reallocate(size() + 1);
    for (iterator it = last_; it >= pos; --it) {
      *(it + 1) = *it;
    }
    pos = value;
    return pos ;
  }

  // Inserts count copies of the value before pos
  iterator insert(const_iterator pos, size_type count,
                  const value_type& value) {
    for (; count; --count) {
      insert(pos, value);
    }
    return pos;
  }

  // Inserts elements from range [first, last) before pos
  template <class InputIt>
  iterator insert(const_iterator pos, InputIt first, InputIt last) {
    for (iterator it = first, pos_ = pos ; it != last; ++it, ++pos_) {
      insert(pos_, *it);
    }
    return pos;
  }

  // Removes the element at pos
  iterator erase(iterator pos) {
    alloc_.destroy(pos);
    alloc_.construct(pos);
    for (iterator it = pos; it + 1 != last_; ++it) {
      *it = *(it + 1);
    }
    alloc_.destroy(last_);
    --last_;
    return pos + 1;
  }

  //  Removes the elements in the range [first, last)
  iterator erase(iterator first, iterator last) {
    for (iterator it = first; first != last; ++it) {
      erase(it);
    }
    return first + 1;
  }

  // Appends the given element value to the end of the container
  void push_back(const value_type& value) {
    Reallocate(SmartSize(this->size() + 1));
    *last_ = value;
  }

  // Removes the last element of the container
  void pop_back() {
    Reallocate(SmartSize(this->size() - 1));
  }

  // Resizes the container to contain count elements
  void resize(size_type count, value_type value = value_type()) {
    Reallocate(count, value);
  }

  // Swaps underlying array between two vectors
  void swap(vector& other) {
    pointer temp_first_ = first_;
    pointer temp_last_  = last_;
    pointer temp_end_   = end_;

    first_ = other.first_;
    last_  = other.last_;
    end_   = other.end_;

    other.first_ = temp_first_;
    other.last_  = temp_last_;
    other.end_   = temp_end_;
  }

  // Helper functions
 private:
  // Returns next 2^n larger than size
  size_type SmartSize(size_type size) {
    size_type smart_size = size == 0 ? 0 : 1;
    while (smart_size < size && smart_size < (this->max_size() / 2)) {
      smart_size *= 2;
    }
    if (smart_size < size) smart_size = this->max_size();
    return smart_size;
  };

  // Reallocated the vectors array
  void Reallocate(size_type size, value_type value = value_type()) {
    pointer new_first_ = alloc_.allocate(size, first_);
    pointer new_last_ =
        new_first_ + (this->size() < size ? this->size() : size);
    pointer new_end_ = new_first_ + size;

    for (size_type i = 0; i < size; ++i) {
      alloc_.construct(new_first_ + i, value);
    }

    for (size_type i = 0; i < size && i < this->size(); ++i) {
      new_first_[i] = first_[i];
    }

    for (size_type i = 0; i < this->size(); ++i) {
      alloc_.destroy(&first_[i]);
    }

    alloc_.deallocate(first_, end_ - first_);
    first_ = new_first_;
    last_  = new_last_;
    end_   = new_end_;
  }

  // Checks if new_size will fit in currently allocated memory
  bool CheckSize(size_type new_size) {
    return !(new_size > end_ - first_);
  }

  // Checks if pos is iside the array, throws std::out_of_range
  void RangeCheck(size_type pos) {
    if (pos > this->size()) {
      std::string message = " pos (";
      message.append(std::to_string(pos));
      message.append(") >= this->size() (which is ");
      message.append(std::to_string(this->size()));
      message.append(")\n");
      throw std::out_of_range(message);
    }
  }
};

template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs,
                const ft::vector<T, Alloc>& rhs) {
  return (lhs.size() == rhs.size() &&
          ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
             ? true
             : false;
}

template <class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc>& lhs,
                const ft::vector<T, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<(const ft::vector<T, Alloc>& lhs,
               const ft::vector<T, Alloc>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
}

template <class T, class Alloc>
bool operator>(const ft::vector<T, Alloc>& lhs,
               const ft::vector<T, Alloc>& rhs) {
  return rhs < lhs;
}

template <class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc>& lhs,
                const ft::vector<T, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc>& lhs,
                const ft::vector<T, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <class T, class Alloc>
void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs) {
  lhs.swap(rhs);
}

}  // namespace ft

#endif  // VECTOR_HPP_
