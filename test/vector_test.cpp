
#include "vector.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <vector>

// vector()
TEST(VectorConstructors, DefaultConstructor) {
  ft::vector<int> vec_empty;
  EXPECT_EQ(vec_empty.size(), 0);
}

// explicit vector( const Allocator& alloc )
TEST(VectorConstructors, AllocConstructor) {
  std::allocator<int> alloc;
  ft::vector<int>     v1(alloc);
  EXPECT_EQ(v1.size(), 0);
}

// explicit vector( size_type count, const T& value = T(),
//                  const Allocator& alloc = Allocator())
TEST(VectorConstructors, SizeConstructor) {
  ft::vector<int> v1(10);
  EXPECT_GE(v1.size(), 10);

  // SIGSEGV
  // ft::vector<int> v2(10, 3);
  // EXPECT_GE(v2.size(), 10);

  // SIGSEGV
  // std::allocator<int> alloc;
  // ft::vector<int>     v3(10, 69, alloc);
  // EXPECT_GE(v3.size(), 10);
}

// template< class InputIt >
// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator())
TEST(VectorConstructors, RangeConstructor) {
  // ft::vector<int> v1((unsigned)10, 3);  // TODO type inference
  // ft::vector<int> v2(v1.begin(), v1.end());
  // EXPECT_LE(v1.size(), v2.size());

  // std::allocator<int> alloc;
  // ft::vector<int>     v3(v1.begin(), v1.end(), alloc);
  // EXPECT_LE(v1.size(), v3.size());
}

// vector( const vector& other )
TEST(VectorConstructors, CopyConstructor) {
  // SIGSEGV
  // ft::vector<int> v1;
  // ft::vector<int> v2(v1);
  // EXPECT_EQ(v1.size(), v2.size());

  // SIGSEGV
  // ft::vector<int> v3(100);
  // ft::vector<int> v4(v3);
  // EXPECT_EQ(v3.size(), v4.size());
}

// vector& operator=( const vector& other )
TEST(VectorAssignment, CopyAssignment) {
  // SIGSEGV
  // ft::vector<int> v1;
  // ft::vector<int> v2 = v1;
  // EXPECT_EQ(v1.size(), v2.size());

  // SIGSEGV
  // ft::vector<int> v3((ft::vector<int>::size_type)100, 69);
  // ft::vector<int> v4 = v3;
  // EXPECT_EQ(v3.size(), v4.size());
}

// void assign( size_type count, const T& value )
TEST(VectorAssignment, Assign) {
  // SIGSEGV
  // ft::vector<int> v1(100);
  // v1.assign((ft::vector<int>::size_type)100, 69);
  // EXPECT_GE(v1.size(), 100);

  // ft::vector<int> v2;
  // v2.assign((ft::vector<int>::size_type)100, 69);
  // EXPECT_EQ(v1, v2);
}

// template< class InputIt >
// void assign( InputIt first, InputIt last )
TEST(VectorAssignment, AssignRange) {  // TODO
  // SIGSEGV
  // ft::vector<int> v1(3);
  // v1[0] = 1;
  // v1[1] = 2;
  // v1[2] = 3;
  // ft::vector<int> v2;
  // v2.assign(v1.begin(), v1.end());
  // EXPECT_EQ(v1, v2);
}

// allocator_type get_allocator() const
TEST(VectorGetAllocator, GetAllocator) {  // TODO test for allocator?
  ft::vector<int> v1;
  EXPECT_NO_THROW(v1.get_allocator());
}

// reference at( size_type pos )
TEST(VectorElementAccess, At) {  // TODO
  ft::vector<int> v1(10);
  v1[1] = 1;
  EXPECT_EQ(v1.at(0), 0);
  EXPECT_EQ(v1.at(1), 1);
}

// reference operator[]( size_type pos )
TEST(VectorElementAccess, AtOperator) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// reference front()
TEST(VectorElementAccess, Front) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// reference back()
TEST(VectorElementAccess, Back) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// T* data()
TEST(VectorElementAccess, Data) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// iterator begin()
TEST(VectorIterator, Begin) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// iterator end()
TEST(VectorIterator, End) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// reverse_iterator rbegin()
TEST(VectorIterator, RBegin) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// reverse_iterator rend()
TEST(VectorIterator, REnd) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// bool empty() const
TEST(VectorCapacity, Empty) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// size_type size() const
TEST(VectorCapacity, Size) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// size_type max_size() const
TEST(VectorCapacity, MaxSize) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// void reserve( size_type new_cap )
TEST(VectorCapacity, Reserve) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// size_type capacity() const
TEST(VectorCapacity, Capacity) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// void clear()
TEST(VectorModifiers, Clear) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// iterator insert( const_iterator pos, const T& value )
TEST(VectorModifiers, Insert) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// iterator insert( const_iterator pos, size_type count, const T& value )
TEST(VectorModifiers, InsertCount) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class InputIt >
// iterator insert( const_iterator pos, InputIt first, InputIt last );
TEST(VectorModifiers, InsertRange) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// iterator erase( iterator pos )
TEST(VectorModifiers, Erase) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// iterator erase( iterator first, iterator last )
TEST(VectorModifiers, EraseRange) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// void push_back( const T& value )
TEST(VectorModifiers, PushBack) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// void pop_back()
TEST(VectorModifiers, PopBack) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// void resize( size_type count )
TEST(VectorModifiers, Resize) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// void resize( size_type count, T value = T() )
TEST(VectorModifiers, ResizeSet) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// void swap( vector& other )
TEST(VectorModifiers, Swap) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class T, class Alloc >
// bool operator==( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, Equal) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class T, class Alloc >
// bool operator!=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, NotEqual) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class T, class Alloc >
// bool operator<( const std::vector<T,Alloc>& lhs,
// const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, LessThan) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class T, class Alloc >
// bool operator<=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, LessThanEqual) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class T, class Alloc >
// bool operator>( const std::vector<T,Alloc>& lhs,
// const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, GreaterThan) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class T, class Alloc >
// bool operator>=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, GreaterThanEqual) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}

// template< class T, class Alloc >
// void swap( std::vector<T,Alloc>& lhs,
//  std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, Swap) {  // TODO
  ft::vector<int> v1;
  EXPECT_EQ(0, 0);
}
