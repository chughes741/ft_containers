
#pragma once
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

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

  vector_const_iterator() ft_noexcept : ptr_() {}
  vector_const_iterator(pointer ptr) ft_noexcept : ptr_(ptr) {}
  const value_type&      operator*() const ft_noexcept { return *ptr_; }
  const_pointer          operator->() const ft_noexcept { return ptr_; }
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

  friend bool operator==(const vector_const_iterator<MyVector>& lhs,
                         const vector_const_iterator<MyVector>& rhs);

  friend bool operator<(const vector_const_iterator<MyVector>& lhs,
                        const vector_const_iterator<MyVector>& rhs);
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
  typedef typename ft::vector_const_iterator<MyVector>::iterator_category
      iterator_category;
  typedef typename ft::vector_const_iterator<MyVector>::value_type value_type;
  typedef typename ft::vector_const_iterator<MyVector>::difference_type
                                                                difference_type;
  typedef typename ft::vector_const_iterator<MyVector>::pointer pointer;
  typedef
      typename ft::vector_const_iterator<MyVector>::const_pointer const_pointer;
  typedef typename ft::vector_const_iterator<MyVector>::reference reference;
  typedef typename ft::vector_const_iterator<MyVector>::const_reference
      const_reference;

  pointer ptr_;

  vector_iterator() ft_noexcept : ptr_() {}
  vector_iterator(pointer ptr) ft_noexcept : ptr_(ptr) {}
  value_type&      operator*() const ft_noexcept { return *ptr_; }
  const_pointer    operator->() const ft_noexcept { return ptr_; }
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

  friend bool operator==(const vector_iterator<MyVector>& lhs,
                         const vector_iterator<MyVector>& rhs);

  friend bool operator<(const vector_iterator<MyVector>& lhs,
                        const vector_iterator<MyVector>& rhs);
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
  vector() ft_noexcept : alloc_(Allocator()),
                         first_(alloc_.allocate(0)),
                         last_(first_),
                         end_(first_) {}
  explicit vector(const Allocator& alloc) ft_noexcept
      : alloc_(alloc),
        first_(alloc_.allocate(0)),
        last_(first_),
        end_(first_) {}
  explicit vector(size_type count, const value_type& value = value_type(),
                  const Allocator& alloc = Allocator())
      : alloc_(alloc),
        first_(alloc_.allocate(count * sizeof(value_type))),
        last_(first_ + count * sizeof(value_type)),
        end_(last_) {
    std::uninitialized_fill(this->begin(), this->end(), value_type());
  }
  template <class InputIt>
  vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
      : alloc_(alloc) {
    first_ = alloc_.allocate(last - first);
    last_  = first_ + (last - first);
    std::copy(first, last, first_);
  }
  vector(const vector& other) {
    *this = vector(other.begin(), other.end() - 1);
  }
  vector& operator=(const vector& rhs) {
    if (*this == rhs) {
      return *this;
    }
    if (this->capacity() < rhs.capacity()) {
      this->resize(rhs.capacity());
    }
    std::fill(this->begin(), this->end(), value_type());
    std::copy(rhs.begin(), rhs.end(), this->begin());
    return *this;
  }
  ~vector() ft_noexcept { alloc_.deallocate(first_, last_ - first_); }
  void assign(size_type count, const value_type& value) {
    this->resize(count);
    std::fill(this->begin(), this->end(), value);
  }
  template <class InputIt>
  void assign(InputIt first, InputIt last) {
    this->resize((first - last) / sizeof(size_type));
    std::copy(first, last, this->begin());
  }
  allocator_type get_allocator() const ft_noexcept { return alloc_; }

  value_type& at(size_type position) {
    RangeCheck(position);
    return this[position];
  }
  const value_type& at(size_type position) const {
    RangeCheck(position);
    return this[position];
  }
  value_type& operator[](size_type position) {
    return *(this->first_ + position);
  }
  const value_type& operator[](size_type position) const {
    return (*this)[position];
  }
  value_type&       front() { return *(this->first_); }
  const value_type& front() const { return *(this->first_); }
  value_type&       back() { return *(this->last_); }
  const value_type& back() const { return *(this->last_); }
  value_type*       data() ft_noexcept { return &(this->first_); }
  const value_type* data() const ft_noexcept { return &(this->first_); }

  iterator         begin() ft_noexcept { return iterator(first_); }
  const_iterator   begin() const ft_noexcept { return const_iterator(first_); }
  iterator         end() ft_noexcept { return iterator(last_ + 1); }
  const_iterator   end() const ft_noexcept { return const_iterator(last_ + 1); }
  reverse_iterator rbegin() ft_noexcept {
    return reverse_iterator(this->first_, this);
  }
  const_reverse_iterator rbegin() const ft_noexcept {
    return const_reverse_iterator(this->first_, this);
  }
  reverse_iterator rend() ft_noexcept {
    return reverse_iterator(this->last_ + 1, this);
  }
  const_reverse_iterator rend() const ft_noexcept {
    return const_reverse_iterator(this->last + 1, this);
  }

  bool empty() const ft_noexcept { return this->size() == 0 ? true : false; }
  size_type size() const ft_noexcept {
    return (this->last_ - this->first_) / sizeof(size_type);
  }
  size_type max_size() const ft_noexcept { return allocator_type::max_size(); }
  void      reserve(size_type new_cap) {
         if (new_cap > this->size()) {
           pointer new_first_ = alloc_.allocate(new_cap, this->first_);
           std::copy(this->begin(), this->end(), iterator(new_first_, this));

           this->last_ = new_first_ + this->size;
           this->end_  = new_first_ + (new_cap * sizeof(size_type));
           alloc_.deallocate(this->first_);
           this->first_ = new_first_;
    }
  }
  size_type capacity() const { return end_ - first_; }

  void     clear() ft_noexcept {}
  iterator insert(const_iterator pos_, const value_type& value_) {}
  iterator insert(const_iterator pos_, size_type count_,
                  const value_type& value_) {}
  template <class InputIt>
  iterator insert(const_iterator pos_, InputIt first_, InputIt last_) {}
  iterator erase(iterator pos_) {}
  iterator erase(iterator first_, iterator last_) {}
  void     push_back(const value_type& value_) {}
  void     pop_back() {}
  void     resize(size_type count_, value_type value_ = value_type()) {}
  void     swap(vector& other) {}

  friend bool operator==(const ft::vector<T, Allocator>& lhs,
                         const ft::vector<T, Allocator>& rhs);
  friend bool operator<(const ft::vector<T, Allocator>& lhs,
                        const ft::vector<T, Allocator>& rhs);

 private:
  void RangeCheck(size_type pos) {
    if (pos > this->size()) {
      std::string message = " pos (which is " + pos +
                            ") >= this->size() (which is " + this->size() +
                            ")\n";
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
void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs) {}

}  // namespace ft

#endif  // VECTOR_HPP_
