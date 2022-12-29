
#pragma once
#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#define ft_noexcept throw()

namespace ft {

template <class InputIter1, class InputIter2>
bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2){};

template <class InputIter1, class InputIter2, class BinaryPredicate>
bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2,
           BinaryPredicate p){};

template <class InputIter1, class InputIter2>
bool lexicographical_compare(InputIter1 first1, InputIter1 last1,
                             InputIter2 first2, InputIter2 last2){};

template <class InputIter1, class InputIter2, class Compare>
bool lexicographical_compare(InputIter1 first1, InputIter2 last1,
                             InputIter2 first2, InputIter2 last2,
                             Compare comp){};

}  // namespace ft

#endif  // ALGORITHM_HPP_