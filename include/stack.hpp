
#pragma once
#ifndef STACK_HPP_
#define STACK_HPP_

#include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T>>
class stack {
 public:
  typedef Container                           container_type;
  typedef typename Container::value_type      value_type;
  typedef typename Container::size_type       size_type;
  typedef typename Container::reference       reference;
  typedef typename Container::const_reference const_reference;

  explicit stack(const Container& cont = Container()) : c(cont) {
  }
  stack(const stack& other) : c(other.c) {
  }
  ~stack() {
  }
  stack& operator=(const stack& other) {
    c = other.c;
  }
  reference top() {
    return this->c.back();
  }
  const_reference top() const {
    return this->c.back();
  }
  bool empty() const {
    return this->c.empty();
  }
  size_type size() const {
    return this->c.size();
  }
  void push(const value_type& value) {
    this->c.push_back(value);
  }
  void pop() {
    this->c.pop_back();
  }

 protected:
  Container c;

  template <class T1, class Container1>
  friend bool operator==(const ft::stack<T1, Container1>& lhs,
                         const ft::stack<T1, Container1>& rhs);
  template <class T1, class Container1>
  friend bool operator<(const ft::stack<T1, Container1>& lhs,
                        const ft::stack<T1, Container1>& rhs);
};

template <class T1, class Container1>
bool operator==(const ft::stack<T1, Container1>& lhs,
                const ft::stack<T1, Container1>& rhs) {
  return lhs.c == rhs.c;
}

template <class T1, class Container1>
bool operator!=(const ft::stack<T1, Container1>& lhs,
                const ft::stack<T1, Container1>& rhs) {
  return !(lhs == rhs);
}

template <class T1, class Container1>
bool operator<(const ft::stack<T1, Container1>& lhs,
               const ft::stack<T1, Container1>& rhs) {
  return lhs.c < rhs.c;
}

template <class T1, class Container1>
bool operator>(const ft::stack<T1, Container1>& lhs,
               const ft::stack<T1, Container1>& rhs) {
  return rhs < lhs;
}

template <class T1, class Container1>
bool operator<=(const ft::stack<T1, Container1>& lhs,
                const ft::stack<T1, Container1>& rhs) {
  return !(rhs < lhs);
}

template <class T1, class Container1>
bool operator>=(const ft::stack<T1, Container1>& lhs,
                const ft::stack<T1, Container1>& rhs) {
  return !(lhs < rhs);
}

}  // namespace ft

#endif  // STACK_HPP_
