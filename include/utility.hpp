
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
  pair() : first(), second() {}

  // Default constructor overload with initialize values
  pair(const T1& first, const T2& second) : first(first), second(second) {}

  // Copy constructor
  template <class U1, class U2>
  pair(const pair<U1, U2>& pair) : first(pair.first), second(pair.second) {}

  // Copy assignment operator
  pair& operator=(const pair& other) {
    this->first  = other.first;
    this->second = other.second;
    return *this;
  }

  // Data members
  T1 first;
  T2 second;
};

// Creates a pair object, deduces type from arguments
template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 first, T2 second) {
  ft::pair<T1, T2> new_pair = ft::pair<T1, T2>(first, second);
  return new_pair;
}

// equal to operator template for pair
template <class T1, class T2>
bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  return (lhs.first == rhs.first && lhs.second == rhs.second);
}

// not equal to operator template for pair
template <class T1, class T2>
bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  return !(lhs == rhs);
}

// less than operator template for pair
template <class T1, class T2>
bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
  if (lhs.first < rhs.first ||
      (lhs.first == rhs.first && lhs.second < rhs.second)) {
    return true;
  } else {
    return false;
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
