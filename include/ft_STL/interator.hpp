
#pragma once
#ifndef INTERATOR_HPP_
#define INTERATOR_HPP_

#include <cstddef>   //TODO check
#include <iterator>  // std::iterator
#include <memory>    // std::addressof

#define ft_noexcept throw()

namespace ft {

template <class Iter>
struct iterator_traits {
 public:
  typedef Iter::difference_type   difference_type;
  typedef Iter::value_type        value_type;
  typedef Iter::pointer           pointer;
  typedef Iter::reference         reference;
  typedef Iter::iterator_category iterator_category;
};

template <class T>
struct iterator_traits<T*> {
 public:
  typedef std::ptrdiff_t                  difference_type;
  typedef T                               value_type;
  typedef T*                              pointer;
  typedef T&                              reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T*> {
 public:
  typedef std::ptrdiff_t                  difference_type;
  typedef T                               value_type;
  typedef const T*                        pointer;
  typedef const T&                        reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <class Iter>
class reverse_iterator
    : public std::iterator<ft::iterator_traits<Iter>::iterator_category,
                           ft::iterator_traits<Iter>::value_type,
                           ft::iterator_traits<Iter>::difference_type,
                           ft::iterator_traits<Iter>::pointer,
                           ft::iterator_traits<Iter>::reference> {
 public:
  typedef Iter iterator_type;

 protected:
  Iter current = Iter();

 public:
  reverse_iterator() : current() {}
  explicit reverse_iterator(iterator_type x) : current(x) {}
  template <class U>
  reverse_iterator(const reverse_iterator<U>& other) : current(other) {}
  template <class U>
  reverse_iterator& operator=(const reverse_iterator& other) {
    if (*this != other) {
      this->current = other.current;
    }
    return *this;
  }
  iterator_type base() const {
    return this->current;  // TODO this->current - 1?
  }

  reference operator*() const {
    Iter temp = this->current;
    return *--temp;
  }
  pointer           operator->() const { return std::addressof(operator*()); }
  /* unspecified */ operator[](difference_type n) const {
    return base()[-n - 1];
  }
  reverse_iterator& operator++() {
    --current;
    return *this;
  }
  reverse_iterator& operator--() {
    ++current;
    return *this;
  }
  reverse_iterator operator++(int) {
    reverse_iterator<Iter> temp = reverse_iterator(this);
    --current;
    return temp;
  }
  reverse_iterator operator--(int) {
    reverse_iterator<Iter> temp = reverse_iterator(this);
    ++current;
    return temp;
  }
  reverse_iterator operator+(difference_type n) const {
    reverse_iterator<Iter> result = reverse_iterator(this);
    result.current -= n;
    return result;
  }
  reverse_iterator operator-(difference_type n) const {
    reverse_iterator<Iter> result = reverse_iterator(this);
    result.current += n;
    return result;
  }
  reverse_iterator& operator+=(difference_type n) {
    current -= n;
    return *this;
  }
  reverse_iterator& operator-=(difference_type n) {
    current += n;
    return *this;
  }

  template <class Iter1, class Iter2>
  friend bool operator==(const reverse_iterator<Iter1>& lhs,
                         const reverse_iterator<Iter2>& rhs);

  template <class Iter1, class Iter2>
  friend bool operator<(const reverse_iterator<Iter1>& lhs,
                        const reverse_iterator<Iter2>& rhs);
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
  return lhs.base() >= rhs.base();
}

template <class Iter>
reverse_iterator<Iter> operator+(
    typename reverse_iterator<Iter>::difference_type n,
    const reverse_iterator<Iter>&                    it) {
  reverse_iterator<Iter> rit = it + n;
  return rit;
}

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type operator-(
    const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
  return lhs.base() - rhs.base();
}

}  // namespace ft

#endif  // INTERATOR_HPP_
