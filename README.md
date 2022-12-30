![Testing](https://github.com/chughes741/ft_containers/actions/workflows/cmake.yml/badge.svg)

# ft_containers
In this project, I have implemented some containers, iterators, and algorithms following the C++98 standard, using the STL as reference.


## Containers, Iterators, and Algorithms
- `vector` (without `bool` specialization)
- `map` (build on a red-black tree)
- `stack` (adapting vector by default)
- `pair`
- `reverse_iterator`
- `iterator_traits`
- `enable_if`
- `is_integral` 
- `equal` and `lexicographical_compare`

### vector
```cpp
template <class T, class Allocator = std::allocator<T>>
class vector;
```

> A vector is a sequence container that encapsulates dynamic size arrays.[^1]

> The elements are stored contiguously, which means that elements can be accessed not only through iterators, but also using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an element of an array.[^1]

> The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted. The total amount of allocated memory can be queried using capacity() function.[^1]

### map
```cpp
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<T>>
class map;
```
> A map is a sorted associative container that contains key-value pairs with unique keys. Keys are sorted by using the comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. Maps are usually implemented as red-black trees.[^1]

> Everywhere the standard library uses the Compare requirements, uniqueness is determined by using the equivalence relation. In imprecise terms, two objects `a` and `b` are considered equivalent (not unique) if neither compares less than the other: `!comp(a, b) && !comp(b, a).`[^1]

### stack
```cpp
template <class T, class Container = ft::vector<T>>
class stack;
```
> The stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.[^1]

> The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.[^1]

### pair
```cpp
template <class T1, class T2>
struct pair;
```
> pair is a class template that provides a way to store two heterogeneous objects as a single unit. A pair is a specific case of a tuple with two elements.[^1]

> If neither T1 nor T2 is a possibly cv-qualified class type with non-trivial destructor, or array thereof, the destructor of pair is trivial.[^1]

### iterators
```cpp
template <class Iter>
class reverse_iterator;
```

```cpp
template <class Iter>
struct iterator_traits;
```

### algorithm
```cpp
template <class InputIter1, class InputIter2>
bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2);
```
```cpp
template <class InputIter1, class InputIter2, class BinaryPredicate>
bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2,
           BinaryPredicate p);
```
```cpp
template <class InputIter1, class InputIter2>
bool lexicographical_compare(InputIter1 first1, InputIter1 last1,
                             InputIter2 first2, InputIter2 last2);
```
```cpp
template <class InputIter1, class InputIter2, class Compare>
bool lexicographical_compare(InputIter1 first1, InputIter2 last1,
                             InputIter2 first2, InputIter2 last2,
                             Compare comp);
```


## Build System and Testing
- CMake [^2]
- vcpkg [^3]
- googletest (gtest) [^4]
- GitHub Actions


[^1]:  [cppreference.com](https://en.cppreference.com/w/)
[^2]:  [CMake](https://cmake.org/)
[^3]:  [vcpkg](https://vcpkg.io/en/index.html)
[^4]:  [googletest](https://github.com/google/googletest)