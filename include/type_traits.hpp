
#pragma once
#ifndef TYPE_TRAITS_HPP_
#define TYPE_TRAITS_HPP_

#define ft_noexcept throw()

#include <type_traits>

#include "iterator.hpp"

namespace ft {

using ft::iterator_traits;

template <class T, T value>
struct integral_constant {
  typedef integral_constant<T, value> type;
  typedef T                           value_type;

  static const T value_ = value;

  operator value_type() const ft_noexcept {
    return value;
  }
};

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

template <class T>
struct is_integral_helper : public false_type {};
template <>
struct is_integral_helper<bool> : public true_type {};
template <>
struct is_integral_helper<char> : public true_type {};
template <>
struct is_integral_helper<signed char> : public true_type {};
template <>
struct is_integral_helper<unsigned char> : public true_type {};
template <>
struct is_integral_helper<wchar_t> : public true_type {};
template <>
struct is_integral_helper<short> : public true_type {};
template <>
struct is_integral_helper<unsigned short> : public true_type {};
template <>
struct is_integral_helper<int> : public true_type {};
template <>
struct is_integral_helper<unsigned int> : public true_type {};
template <>
struct is_integral_helper<long int> : public true_type {};
template <>
struct is_integral_helper<unsigned long int> : public true_type {};

template <class T>
struct remove_cv {
  typedef T type;
};
template <class T>
struct remove_cv<const T> {
  typedef T type;
};
template <class T>
struct remove_cv<volatile T> {
  typedef T type;
};
template <class T>
struct remove_cv<const volatile T> {
  typedef T type;
};

template <class T>
struct is_integral : is_integral_helper<remove_cv<T>>::type {};

template <bool B, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {
  typedef T type;
};

template <class Iter, bool = false>
struct is_iterator : public false_type {
};

template <class Iter>
struct is_iterator<Iter> : public true_type {
  typedef Iter value;
};

template <typename T>
struct is_iterator<T*> : public true_type {
  typedef T* value;
};


}  // namespace ft

#endif  // TYPE_TRAITS_H
