
#pragma once
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <string>

#include "algorithm.hpp"
#include "interator.hpp"

#define ft_noexcept throw()

namespace ft {

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

  /* Member data */
 private:
  allocator_type alloc_;
  pointer        first_ = NULL;
  pointer        last_  = NULL;
  pointer        end_   = NULL;

 public:
  /* Member functions */
  // Default constructor
  vector() ft_noexcept : alloc_(Allocator()),
                         first_(alloc_.allocate(0)),
                         last_(first_),
                         end_(first_) {}

  // Default constructor overload with different allocator
  explicit vector(const Allocator& alloc) ft_noexcept
      : alloc_(alloc),
        first_(alloc_.allocate(0)),
        last_(first_),
        end_(first_) {}

  // Default constructor overload with init size and init value
  explicit vector(size_type count, const value_type& value = value_type(),
                  const Allocator& alloc = Allocator())
      : alloc_(alloc),
        first_(alloc_.allocate(count * sizeof(value_type))),
        last_(first_ + count * sizeof(value_type)),
        end_(last_) {
    std::unitialized_fill(this->begin(), this->end(), value_type());
  }

  // Default range constructor template
  template <class InputIt>
  vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
      : alloc_(alloc) {
    first_ = alloc_.allocate(last - first);
    last_  = first_ + last - first;
    std::copy(first, last, first_);
  }

  // Default copy constructor
  vector(const vector& other) {
    *this = vector(other.begin(), other.end() - 1);
  }

  // Copy assignment operator overload
  vector& operator=(const vector& rhs) {
    if (*this == rhs) {
      return *this;
    }
    if (this->capacity < rhs.capacity()) {
      this->resize(rhs.capacity());
    }
    std::fill(this->begin(), this->end(), value_type());
    std::copy(rhs.begin(), rhs.end(), this->begin());
    return *this;
  }

  // Default destructor
  ~vector() ft_noexcept { alloc_.deallocate(first_, last_ - first_); }

  // Replaces contents with count copy of value
  void assign(size_type count, const value_type& value) {
    this->resize(count);
    std::fill(this->begin(), this->end(), value);
  }

  // Replaces elements with copies of those in [first, last)
  template <class InputIt>
  void assign(InputIt first, InputIt last) {
    this->resize((first - last) / sizeof(size_type));
    std::copy(first, last, this->begin());
  }

  // Returns allocator associated with the container
  allocator_type get_allocator() const ft_noexcept { return alloc_; }

  /* Element access */
  // Returns a T& to the element at pos_, with bound checks
  value_type& at(size_type position) {
    RangeCheck(position);
    return this[position];
  }

  // Returns a const T& to the element at pos_, with bound checks
  const value_type& at(size_type position) const {
    RangeCheck(position);
    return this[position];
  }

  // Returns a T& to the element at pos_, no bound checks
  value_type& operator[](size_type position) {
    return *(this->first_ + position);
  }

  // Returns a cont_reference to the element at pos_, no bound checks
  const value_type& operator[](size_type position) const this[position];

  // Returns a T& to the first element in the container
  value_type& front() { return *(this->first_); }

  // Returns a const T& to the first element in the container
  const value_type& front() const { return *(this->first_); }

  // Returns a T& to the last element in the container
  value_type& back() { return *(this->last_); }

  // Returns a const T& to the last element in the container
  const value_type& back() const { return *(this->last_); }

  // Returns a Allocator::pointer to the underlying array serving as element
  // storage
  value_type* data() ft_noexcept { return &(this->first_); }  // TODO

  // Returns a Allocator::const_pointer to the underlying array serving as
  // element storage
  const value_type* data() const ft_noexcept { return &(this->first_); }

  /* Iterators */
  //
  iterator begin() ft_noexcept { return iterator(this->first_, this); }

  //
  const_iterator begin() const ft_noexcept {
    return const_iterator(this->first_, this);
  }

  //
  iterator end() ft_noexcept { return iterator(this->last_ + 1, this); }

  //
  const_iterator end() const ft_noexcept {
    return const_iterator(this->last_ + 1, this);
  }

  //
  reverse_iterator rbegin() ft_noexcept {
    return reverse_iterator(this->first_, this);
  }

  //
  const_reverse_iterator rbegin() const ft_noexcept {
    return const_reverse_iterator(this->first_, this);
  }

  //
  reverse_iterator rend() ft_noexcept {
    return reverse_iterator(this->last_ + 1, this);
  }

  //
  const_reverse_iterator rend() const ft_noexcept {
    return const_reverse_iterator(this->last + 1, this);
  }

  /* Capacity */
  // Checks if the container is empty
  bool empty() const ft_noexcept { return this->size() == 0 ? true : false; }

  // Returns the number of elements in the container
  size_type size() const ft_noexcept {
    return (this->last_ - this->first_) / sizeof(size_type);
  }

  // Returns the maximum number of elements of the container, sys dependant
  size_type max_size() const ft_noexcept { return allocator_type::max_size(); }

  // Increases the capacity of the vector, will not shrink it
  void reserve(size_type new_cap) {
    if (new_cap > this->size()) {
      pointer new_first_ = alloc_.allocate(new_cap, this->first_);
      std::copy(this->begin(), this->end(), iterator(new_first_, this));

      this->last_ = new_first_ + this->size;
      this->end_  = new_first_ + (new_cap * sizeof(size_type));
      alloc_.deallocate(this->first_);
      this->first_ = new_first_;
    }
  }

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

 private:
  // Checks if pos is out of range of the vector
  void RangeCheck(size_type pos) {
    if (pos > this->size()) {
      std::string message = " pos (which is " + pos +
                            ") >= this->size() (which is " + this->size() +
                            ")\n";
      throw std::out_of_range(message)
    }
  }
};

// equal to overload for vector
template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs,
                const ft::vector<T, Alloc>& rhs) {
  return (lhs.size() == rhs.size() &&
          ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
             ? true
             : false;
}

// not equal to overload for vector
template <class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc>& lsh,
                const ft::vector<T, Alloc>& rsh) {
  return !(lhs == rhs);
}

// less than overload for vector
template <class T, class Alloc>
bool operator<(const ft::vector<T, Alloc>& lsh,
               const ft::vector<T, Alloc>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
}

// greater than overload for vector
template <class T, class Alloc>
bool operator>(const ft::vector<T, Alloc>& lhs,
               const ft::vector<T, Alloc>& rhs) {
  return rhs < lhs;
}

// less than or equal to overload for vector
template <class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc>& lhs,
                const ft::vector<T, Alloc>& rhs) {
  return !(rhs < lhs);
}

// greater than or equal to overload for vector
template <class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc>& lhs,
                const ft::vector<T, Alloc>& rhs) {
  return !(lhs < rhs);
}

// Uses the std::swap algorithm to swap two vectors
template <class T, class Alloc>
void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs);

}  // namespace ft

#endif  // VECTOR_HPP_
