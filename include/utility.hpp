
#pragma once
#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <algorithm>

namespace ft {

// Class declaration
template <class T1, class T2>
struct pair {
 public:
  // Default constructor
  pair() : first_(), second_() {}

  // Default constructor overload with initialize values
  pair(const T1& first, const T2& second) : first_(first), second_(second) {}

  // Copy constructor
  template <class U1, class U2>
  pair(const pair<U1, U2>& pair) : first_(pair.first_), second_(pair.second_) {}

  // Copy assignment operator
  pair& operator=(const pair& other) {
    this->first_  = other.first_;
    this->second_ = other.second_;
    return *this;
  }

  // Data members
  T1 first_;
  T2 second_;

  template <class T1, class T2>
  friend bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);

  template <class T1, class T2>
  friend bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
};

// Creates a pair object, deduces type from arguments
template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 first, T2 second) {
  ft::pair<T1, T2> new_pair = ft::pair(first, second);
  return new_pair;
}

// equal to operator template for pair
template <class T1, class T2>
bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  return (lhs.first_ == rhs.first_ && lhs.second_ == rhs.second_);
}

// not equal to operator template for pair
template <class T1, class T2>
bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  return !(lhs == rhs);
}

// less than operator template for pair
template <class T1, class T2>
bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  if (lhs.first_ == rhs.first_) {
    return lhs.second_ < rhs.second_;
  } else {
    return lhs.first_ < rhs.second_;
  }
}

// greater than operator template for pair
template <class T1, class T2>
bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  return rhs < lhs;
}

// less than or equal to operator template for pair
template <class T1, class T2>
bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  return !(rhs < lhs);
}

// greater than or equal to template for pair
template <class T1, class T2>
bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  return !(lhs < rhs);
}

}  // namespace ft

#endif  // UTILITY_HPP_
