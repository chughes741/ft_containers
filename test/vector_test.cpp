
#include "vector.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

// vector()
TEST(VectorConstructors, DefaultConstructor) {
  {  // default constructor - int
    ft::vector<int> v;
    EXPECT_EQ(v.size(), 0);
  }
  {  // default constructor - string
    ft::vector<std::string> v;
    EXPECT_EQ(v.size(), 0);
  }
  {  // default constructor - ft::vector<ft::vector<int>>
    ft::vector<ft::vector<int>> v;
    EXPECT_EQ(v.size(), 0);
  }
  {  // default constructor - std::vector<ft::vector<int>>
    std::vector<ft::vector<int>> v;
    EXPECT_EQ(v.size(), 0);
  }
}

// explicit vector( const Allocator& alloc )
TEST(VectorConstructors, AllocConstructor) {
  {  // constructor
    std::allocator<int> alloc;
    ft::vector<int>     v(alloc);
    EXPECT_EQ(v.size(), 0);
  }
  {  // template
    ft::vector<int, std::allocator<int>> v;
    EXPECT_EQ(v.size(), 0);
  }
}

// explicit vector( size_type count, const T& value = T(),
//                  const Allocator& alloc = Allocator())
TEST(VectorConstructors, SizeConstructor) {
  {  // size only - zero
    ft::vector<int> v(0, 1);
    EXPECT_EQ(v.size(), 0);
  }
  {  // size only - small
    ft::vector<int> v(10);
    EXPECT_GE(v.capacity(), 10);
  }
  {  // size only - large
    ft::vector<int> v(1234567);
    EXPECT_GE(v.capacity(), 1234567);
  }
  {  // size only - too large
     // TODO check if std::vector throws
    const ft::vector<int>::size_type max_size = ft::vector<int>().max_size();
    EXPECT_THROW(ft::vector<int> v(max_size + 1), std::length_error);
  }
  {  // size and count - small
    ft::vector<int> v(10, 4);
    EXPECT_GE(v.capacity(), 10);
  }
  {
    ft::vector<int> v(1234567, 69);
    EXPECT_EQ(v.size(), 1234567);
    EXPECT_GE(v.capacity(), 1234567);
  }
  {  // size, count, and alloc - small
    std::allocator<int> alloc;
    ft::vector<int>     v(10, 4, alloc);
    EXPECT_GE(v.capacity(), 10);
  }
}

// template< class InputIt >
// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator())
TEST(VectorConstructors, RangeConstructor) {
  {
    std::allocator<int> alloc;
    ft::vector<int>     v1(10, 3);
    ft::vector<int>     v2(v1.begin(), v1.end());
    ft::vector<int>     v3(v1.begin(), v1.end(), alloc);

    EXPECT_LE(v1.size(), v2.size());
    EXPECT_LE(v1.size(), v3.size());
  }
}

// vector( const vector& other )
TEST(VectorConstructors, CopyConstructor) {
  {
    ft::vector<int> v1;
    ft::vector<int> v2(v1);
    EXPECT_EQ(v1.size(), v2.size());
  }
  {
    ft::vector<int> v1(100);
    ft::vector<int> v2(v1);
    EXPECT_EQ(v1.size(), v2.size());
  }
  // TODO check for deep/shallow copies
  // TODO check for std::containers compatibility
  // TODO check for input_iterator compatibility
}

// vector& operator=( const vector& other )
TEST(VectorAssignment, CopyAssignment) {
  {
    ft::vector<int> v1;
    ft::vector<int> v2 = v1;
    EXPECT_EQ(v1.size(), v2.size());
  }
  {
    ft::vector<int> v1(100, 69);
    ft::vector<int> v2 = v1;
    EXPECT_EQ(v1.size(), v2.size());
  }
}

// void assign( size_type count, const T& value )
TEST(VectorAssignment, Assign) {
  {
    ft::vector<int> v(100);
    v.assign(100, 69);
    EXPECT_GE(v.size(), 100);
  }
  // TODO check with other <data-types>
}

// template< class InputIt >
// void assign( InputIt first, InputIt last )
TEST(VectorAssignment, AssignRange) {
  {
    ft::vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    ft::vector<int> v2;
    v2.assign(v1.begin(), v1.end());

    EXPECT_EQ(v1, v2);
  }
  // TODO check with other <data-types>
}

// allocator_type get_allocator() const
TEST(VectorGetAllocator, GetAllocator) {
  {
    ft::vector<int> v;
    EXPECT_NO_THROW(v.get_allocator());
    // TODO get_allocator() is noexcept - need better test
  }
}

// reference at( size_type pos )
TEST(VectorElementAccess, At) {
  {
    ft::vector<int> v;
    v.push_back(0);
    v.push_back(1);

    EXPECT_EQ(v.at(0), 0);
    EXPECT_EQ(v.at(1), 1);
    EXPECT_THROW(v.at(2), std::out_of_range);
    EXPECT_THROW(v.at(100), std::out_of_range);
  }
}

// reference operator[]( size_type pos )
TEST(VectorElementAccess, AtOperator) {
  {
    ft::vector<int> v(10);
    v[1] = 1;

    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
  }
}

// reference front()
TEST(VectorElementAccess, Front) {
  {
    ft::vector<int> v(10, 3);
    v[0] = 1;
    EXPECT_EQ(v.front(), 1);
  }
}

// reference back()
TEST(VectorElementAccess, Back) {
  {
    ft::vector<int> v(10, 2);
    EXPECT_EQ(v.back(), 2);
  }
}

// T* data()
TEST(VectorElementAccess, Data) {
  {
    ft::vector<int> v(10, 3);
    EXPECT_EQ(*v.data(), 3);
  }
}

// iterator begin()
TEST(VectorIterator, Begin) {
  {
    ft::vector<int> v(10);
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;

    EXPECT_EQ(*(v.begin()), 0);
    EXPECT_EQ(*(v.begin() + 1), 1);
    EXPECT_EQ(*(v.begin() + 2), 2);
    EXPECT_EQ(*(v.begin() + 3), 3);
  }
}

// iterator end()
TEST(VectorIterator, End) {
  {
    ft::vector<int> v;
    EXPECT_EQ(v.begin() + 1, v.end());
  }
  {
    ft::vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    EXPECT_EQ(v.begin() + 4, v.end());
  }
}

// reverse_iterator rbegin()
TEST(VectorIterator, RBegin) {
  {
    ft::vector<int> v;
    EXPECT_EQ(v.rbegin() + 1, v.rend());
  }
  {
    ft::vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    EXPECT_EQ(v.rbegin() + 4, v.rend());
  }
}

// reverse_iterator rend()
TEST(VectorIterator, REnd) {
  {
    ft::vector<int> v;
    EXPECT_EQ(v.rbegin() + 1, v.rend());
  }
  {
    ft::vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    EXPECT_EQ(v.rbegin() + 4, v.rend());
  }
}

// bool empty() const
TEST(VectorCapacity, Empty) {
  {
    ft::vector<int> v;
    EXPECT_TRUE(v.empty());

    v.push_back(1);
    v.pop_back();
    EXPECT_TRUE(v.empty());
  }
}

// size_type size() const
TEST(VectorCapacity, Size) {
  {
    ft::vector<int> v(100, 1);
    EXPECT_GE(v.size(), 100);

    v.push_back(3);
    EXPECT_GE(v.size(), 101);
  }
}

// size_type max_size() const
TEST(VectorCapacity, MaxSize) {
  {
    ft::vector<int>  v1;
    std::vector<int> v2;
    EXPECT_EQ(v1.max_size(), v2.max_size());
  }
}

// void reserve( size_type new_cap )
TEST(VectorCapacity, Reserve) {
  {
    ft::vector<int> v;
    v.reserve(69);
    EXPECT_EQ(v.capacity(), 69);

    v.reserve(1);
    EXPECT_EQ(v.capacity(), 69);
  }
  {
    ft::vector<int>                  v;
    const ft::vector<int>::size_type max_size = v.max_size();
    EXPECT_THROW(v.reserve(max_size + 1), std::length_error);
  }
}

// size_type capacity() const
TEST(VectorCapacity, Capacity) {
  {
    ft::vector<int> v(10);
    EXPECT_GE(v.capacity(), 10);

    v.reserve(69);
    EXPECT_EQ(v.capacity(), 69);
  }
}

// void clear()
TEST(VectorModifiers, Clear) {
  {
    ft::vector<int> v(10, 3);
    v.clear();
    EXPECT_EQ(v.size(), 0);
  }
}

// iterator insert( const_iterator pos, const T& value )
TEST(VectorModifiers, Insert) {
  {  // TODO check if insert throws when at max size
    ft::vector<int> v(10, 3);
    v.insert(v.begin(), 1);
    EXPECT_EQ(v.front(), 1);
  }
}

// iterator insert( const_iterator pos, size_type count, const T& value )
TEST(VectorModifiers, InsertCount) {
  {  // TODO check if insert throws when at max size
    ft::vector<int> v(10, 3);
    v.insert(v.begin(), 5, 1);
    EXPECT_GE(v.size(), 15);

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[4], 1);
    EXPECT_NE(v[6], 1);
  }
}

// template< class InputIt >
// iterator insert( const_iterator pos, InputIt first, InputIt last );
TEST(VectorModifiers, InsertRange) {
  {  // TODO check if insert throws when at max size
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 1);
    v1.insert(v1.begin(), v2.begin(), v2.end());

    EXPECT_GE(v1.size(), 20);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[9], 1);
  }
}

// iterator erase( iterator pos )
TEST(VectorModifiers, Erase) {
  {
    ft::vector<int> v(1, 0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.erase(v.begin());

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
  }
}

// iterator erase( iterator first, iterator last )
TEST(VectorModifiers, EraseRange) {
  {
    ft::vector<int> v(10, 3);
    v.erase(v.begin(), v.end() - 1);
    EXPECT_EQ(v.size(), 0);
  }
}

// void push_back( const T& value )
TEST(VectorModifiers, PushBack) {
  {  // int - simple
    ft::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
  }
  {  // int - 1000 pushes
    ft::vector<int> v;
    EXPECT_NO_THROW(for (ft::vector<int>::size_type i = 0; i < 1000;
                         ++i) { v.push_back(3); });
  }
}

// void pop_back()
TEST(VectorModifiers, PopBack) {
  {
    ft::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.pop_back();

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.back(), 1);
  }
}

// void resize( size_type count )
TEST(VectorModifiers, Resize) {
  {
    ft::vector<int> v(10, 3);
    v.resize(3);
    EXPECT_EQ(v.size(), 3);
  }
  {
    const ft::vector<int>::size_type max_size = ft::vector<int>().max_size();
    ft::vector<int>                  v;
    EXPECT_THROW(v.resize(max_size + 1), std::length_error);
  }
}

// void resize( size_type count, T value = T() )
TEST(VectorModifiers, ResizeSet) {
  {
    ft::vector<int> v(10, 3);
    v.resize(3, 10);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 10);
    EXPECT_EQ(v[2], 10);
  }
  {
    const ft::vector<int>::size_type max_size = ft::vector<int>().max_size();
    ft::vector<int>                  v;
    EXPECT_THROW(v.resize(max_size + 1, 3), std::length_error);
  }
}

// void swap( vector& other )
TEST(VectorModifiers, Swap) {
  {
    ft::vector<int> v1(5, 20);
    ft::vector<int> v2(3, 10);

    ft::vector<int>::iterator it1 = v1.begin();
    ft::vector<int>::iterator it2 = v2.begin();

    int &ref1 = v1.front();
    int &ref2 = v2.front();

    v1.swap(v2);

    EXPECT_EQ(*it1, 20);
    EXPECT_EQ(*it2, 10);
    EXPECT_EQ(ref1, 20);
    EXPECT_EQ(ref2, 10);
    EXPECT_EQ(v1.size(), 3);
    EXPECT_EQ(v2.size(), 5);
    EXPECT_EQ(v1.front(), 10);
    EXPECT_EQ(v2.front(), 20);
  }
}

// template< class T, class Alloc >
// bool operator==( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, Equal) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(3, 3);

    EXPECT_TRUE(v1 == v1);
    EXPECT_FALSE(v1 == v2);
  }
}

// template< class T, class Alloc >
// bool operator!=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, NotEqual) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(3, 3);

    EXPECT_FALSE(v1 != v1);
    EXPECT_TRUE(v1 != v2);
  }
}

// template< class T, class Alloc >
// bool operator<( const std::vector<T,Alloc>& lhs,
// const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, LessThan) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 5);
    ft::vector<int> v3(3, 3);

    EXPECT_TRUE(v1 < v2);
    EXPECT_FALSE(v2 < v3);
  }
}

// template< class T, class Alloc >
// bool operator<=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, LessThanEqual) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 5);

    EXPECT_TRUE(v1 <= v2);
    EXPECT_FALSE(v2 <= v1);
  }
}

// template< class T, class Alloc >
// bool operator>( const std::vector<T,Alloc>& lhs,
// const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, GreaterThan) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 5);
    ft::vector<int> v3(3, 3);

    EXPECT_FALSE(v1 > v2);
    EXPECT_TRUE(v2 > v3);
  }
}

// template< class T, class Alloc >
// bool operator>=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, GreaterThanEqual) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 5);

    EXPECT_FALSE(v1 >= v2);
    EXPECT_TRUE(v2 >= v1);
  }
}

// template< class T, class Alloc >
// void swap( std::vector<T,Alloc>& lhs,
//  std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, Swap) {
  {
    ft::vector<int> v1(5, 20);
    ft::vector<int> v2(3, 10);

    ft::vector<int>::iterator it1 = v1.begin();
    ft::vector<int>::iterator it2 = v2.begin();

    int &ref1 = v1.front();
    int &ref2 = v2.front();

    ft::swap(v1, v2);

    EXPECT_EQ(*it1, 20);
    EXPECT_EQ(*it2, 10);
    EXPECT_EQ(ref1, 20);
    EXPECT_EQ(ref2, 10);
    EXPECT_EQ(v1.size(), 3);
    EXPECT_EQ(v2.size(), 5);
    EXPECT_EQ(v1.front(), 10);
    EXPECT_EQ(v2.front(), 20);
  }
}
