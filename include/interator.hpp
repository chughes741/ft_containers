
#pragma once
#ifndef INTERATOR_HPP_
#define INTERATOR_HPP_

#include <cstddef>
#include <iterator>

#define ft_noexcept throw()

namespace ft {

//
template <class Iter>
struct iterator_traits {
 public:
  typedef Iter::difference_type   difference_type;
  typedef Iter::value_type        value_type;
  typedef Iter::pointer           pointer;
  typedef Iter::reference         reference;
  typedef Iter::iterator_category iterator_category;
};

//
template <class T>
struct iterator_traits<T*> {
 public:
  typedef std::ptrdiff_t                  difference_type;
  typedef T                               value_type;
  typedef T*                              pointer;
  typedef T&                              reference;
  typedef std::random_access_iterator_tag iterator_category;
};

//
template <class T>
struct iterator_traits<const T*> {
 public:
  typedef std::ptrdiff_t                  difference_type;
  typedef T                               value_type;
  typedef const T*                        pointer;
  typedef const T&                        reference;
  typedef std::random_access_iterator_tag iterator_category;
};

//
template <class Iter>
class reverse_iterator
    : public std::iterator<
          typename iterator_traits<_Iterator>::iterator_category,
          typename iterator_traits<_Iterator>::value_type,
          typename iterator_traits<_Iterator>::difference_type,
          typename iterator_traits<_Iterator>::pointer,
          typename iterator_traits<_Iterator>::reference> {
 protected:
  Iter current = Iter();

 public:
  typedef Iter iterator_type;

  reverse_iterator();
  explicit reverse_iterator(iterator_type x);
  template <class U>
  reverse_iterator(const reverse_iterator<U>& other);
  template <class U>
  reverse_iterator& operator=(const reverse_iterator& other);
  iterator_type     base() const;

  reference         operator*() const;
  pointer           operator->() const;
  /* unspecified */ operator[](difference_type n) const;
  reverse_iterator& operator++();
  reverse_iterator& operator--();
  reverse_iterator  operator++(int);
  reverse_iterator  operator--(int);
  reverse_iterator  operator+(difference_type n) const;
  reverse_iterator  operator-(difference_type n) const;
  reverse_iterator& operator+=(difference_type n);
  reverse_iterator& operator-=(difference_type n);
};

template <class Iter1, class Iter2>
bool operator==(const reverse_iterator<Iter1>& lhs,
                const reverse_iterator<Iter2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class Iter1, class Iter2>
bool operator!=(const reverse_iterator<Iter1>& lhs,
                const reverse_iterator<Iter2>& rhs) {
  return lhs.base() != rhs.base();
}

template <class Iter1, class Iter2>
bool operator<(const reverse_iterator<Iter1>& lhs,
               const reverse_iterator<Iter2>& rhs) {
  return lhs.base() < rhs.base();
}

template <class Iter1, class Iter2>
bool operator<=(const reverse_iterator<Iter1>& lhs,
                const reverse_iterator<Iter2>& rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iter1, class Iter2>
bool operator>(const reverse_iterator<Iter1>& lhs,
               const reverse_iterator<Iter2>& rhs) {
  return lhs.base() > rhs.base();
}

template <class Iter1, class Iter2>
bool operator>=(const reverse_iterator<Iter1>& lhs,
                const reverse_iterator<Iter2>& rhs) {
  return lhs.base >= rhs.base();
}

template <class Iter>
reverse_iterator<Iter> operator+(
    typename reverse_iterator<Iter>::difference_type n,
    const reverse_iterator<Iter>&                    it);

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type operator-(
    const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs);

// base iterator template
template <class Container>
class base_interator {
 public:
  base_interator();
  base_interator(Container::pointer p_arg_, const Container* p_container_);
  Container::value_type&   operator*() const;
  Container::const_pointer operator->() const;
  base_interator&          operator++();
  base_interator           operator++(int);
  base_interator&          operator--();
  base_interator           operator--(int);
  base_interator&          operator+=(const Container::difference_type offset_);
  base_interator(const Interator& other);
  base_interator& operator=(const Interator& rhs);
  ~base_interator();

 private:
};

template <class MyVector>
class VectorConstIterator : public base_interator<MyVector> {
 public:
  VectorConstIterator();
  VectorConstIterator(MyVector::pointer p_arg_, const BaseContainer* p_vector_);
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

}  // namespace ft

#endif  // INTERATOR_HPP_
