
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
#include "type_traits.hpp"

#define ft_noexcept throw()

namespace ft {

using std::random_access_iterator_tag;

template <class MyVector>
class vector_const_iterator {
 public:
  typedef random_access_iterator_tag         iterator_category;
  typedef typename MyVector::value_type      value_type;
  typedef typename MyVector::difference_type difference_type;
  typedef typename MyVector::pointer         pointer;
  typedef const value_type&                  reference;

  pointer ptr_;

  vector_const_iterator() ft_noexcept : ptr_() {
  }
  vector_const_iterator(pointer ptr) ft_noexcept : ptr_(ptr) {
  }
  reference operator*() const ft_noexcept {
    return *ptr_;
  }
  const pointer operator->() const ft_noexcept {
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
  reference operator[](const difference_type offset) const {
    return *(ptr_ + offset);
  }
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
class vector_iterator : public ft::vector_const_iterator<MyVector> {
 public:
  typedef vector_const_iterator<MyVector> base_iterator;

  typedef random_access_iterator_tag         iterator_category;
  typedef typename MyVector::value_type      value_type;
  typedef typename MyVector::difference_type difference_type;
  typedef typename MyVector::pointer         pointer;
  typedef value_type&                        reference;

  vector_iterator(pointer ptr) : base_iterator(ptr){};

  value_type& operator*() const ft_noexcept {
    return const_cast<reference>(base_iterator::operator*());
  }
  const pointer operator->() const ft_noexcept {
    return this->ptr_;
  }
  vector_iterator& operator++() ft_noexcept {
    base_iterator::operator++();
    return *this;
  }
  vector_iterator operator++(int) ft_noexcept {
    vector_iterator temp = *this;
    base_iterator:: operator++();
    return temp;
  }
  vector_iterator& operator--() ft_noexcept {
    base_iterator::operator--();
    return *this;
  }
  vector_iterator operator--(int) {
    vector_iterator temp = *this;
    base_iterator:: operator--();
    return temp;
  }
  vector_iterator& operator+=(const difference_type offset) {
    base_iterator::operator+=(offset);
    return *this;
  }
  vector_iterator operator+(const difference_type offset) const {
    vector_iterator temp = *this;
    temp += offset;
    return temp;
  }
  vector_iterator& operator-=(const difference_type offset) {
    base_iterator::operator-=(offset);
    return *this;
  }
  vector_iterator operator-(const difference_type offset) const {
    vector_iterator temp = *this;
    temp -= offset;
    return temp;
  }
  using base_iterator::operator-;

  value_type& operator[](const difference_type offset) const {
    return const_cast<reference>(base_iterator::operator[](offset));
  }
};

// Vector<T> class template
template <class T, class Allocator = std::allocator<T>>
class vector {
 public:
  typedef Allocator allocator_type;

  typedef T                                        value_type;
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef value_type&                              reference;
  typedef const value_type&                        const_reference;
  typedef typename allocator_type::size_type       size_type;
  typedef typename allocator_type::difference_type difference_type;

  typedef vector_iterator<vector<T>>           iterator;
  typedef vector_const_iterator<vector<T>>     const_iterator;
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
    Reallocate(count, SmartSize(count), value);
  }

  // Range constructor
  template <class InputIt, typename ft::enable_if<ft::is_iterator<InputIt>::value>::type>
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
    clear();
    Reallocate(count, SmartSize(count), value);
  }

  // Replaces the contents with copies of those in the range [first, last)
  template <class InputIt>
  void assign(InputIt first, InputIt last) {
    clear();
    Reallocate(last - first - 1, SmartSize(last - first - 1));
    for (size_type i = 0; i < last - first; ++i) {
      first_[i] = first[i];
    }
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
    return *(last_ - 1);
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
  // iterator insert(const_iterator pos, const value_type& value) {
  iterator insert(iterator pos, const value_type& value) {
    difference_type pos_ = pos - first_;
    reserve(size() + 1);

    pointer new_first_ = first_ + pos_;
    pointer new_last_  = last_;

    for (; new_last_ > new_first_; --new_last_) {
      alloc_.construct(new_last_ + 1, *new_last_);
      alloc_.destroy(new_last_);
    }
    alloc_.construct(new_first_, value);
    return iterator(first_ + pos_);
  }

  // Inserts count copies of the value before pos
  // iterator insert(const_iterator pos, size_type count, const value_type
  // &value) {
  iterator insert(iterator pos, size_type count, const value_type& value) {
    difference_type pos_ = pos - first_;
    reserve(size() + count);

    pointer new_first_ = first_ + pos_;
    pointer new_last_  = last_;

    for (; new_last_ > new_first_; --new_last_) {
      *new_last_ = *(new_last_ + count);
      alloc_.destroy(new_last_);
    }
    for (size_type count_ = 0; count_ < count; ++count_) {
      alloc_.construct(new_first_ + count_, value);
    }
    return iterator(first_ + pos_);
  }

  // Inserts elements from range [first, last) before pos
  template <class InputIt>
  // iterator insert(const_iterator pos, InputIt first, InputIt last) {
  iterator insert(iterator pos, InputIt first, InputIt last) {
    difference_type pos_ = pos - first_;
    reserve(size() + (last - first));

    pointer new_first_ = first_ + pos_;
    pointer new_last_  = last_;

    for (; new_last_ > new_first_; --new_last_) {
      *new_last_ = *(new_last_ + (last - first));
      alloc_.destroy(new_last_);
    }
    for (size_type count_ = 0; count_ < (last - first); ++count_) {
      alloc_.construct(new_first_ + count_, *(first + count_));
    }
    return iterator(first_ + pos_);
  }

  // Removes the element at pos
  iterator erase(iterator pos) {
    for (iterator it = pos; it + 1 != iterator(last_); ++it) {
      *it = *(it + 1);
    }
    alloc_.destroy(last_);
    --last_;
    return pos + 1;
  }

  //  Removes the elements in the range [first, last)
  iterator erase(iterator first, iterator last) {
    for (iterator it = first; it != last; ++it) {
      erase(first);
    }
    return first + 1;
  }

  // Appends the given element value to the end of the container
  void push_back(const value_type& value) {
    Reallocate(size() + 1, SmartSize(size() + 1), value);
  }

  // Removes the last element of the container
  void pop_back() {
    if (size() == 0) return;
    Reallocate(size() - 1, SmartSize(size() - 1));
  }

  // Resizes the container to contain count elements
  void resize(size_type count, value_type value = value_type()) {
    clear();
    Reallocate(count, SmartSize(count), value);
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
  void Reallocate(size_type size, size_type cap = 0,
                  value_type value = value_type()) {
    pointer new_first_ = alloc_.allocate(size, first_);
    pointer new_last_  = new_first_ + size;
    pointer new_end_   = new_first_ + (cap > size ? cap : size);

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
