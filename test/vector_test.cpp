
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

  ft::vector<int> v2((unsigned)10, 3);  // TODO type inference
  EXPECT_GE(v2.size(), 10);

  std::allocator<int> alloc;
  ft::vector<int>     v3((unsigned)10, 69, alloc);  // TODO type inference
  EXPECT_GE(v3.size(), 10);
}

// template< class InputIt >
// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator())
TEST(VectorConstructors, RangeConstructor) {
  ft::vector<int> v1((unsigned)10, 3);  // TODO type inference
  ft::vector<int> v2(v1.begin(), v1.end());
  EXPECT_LE(v1.size(), v2.size());

  std::allocator<int> alloc;
  ft::vector<int>     v3(v1.begin(), v1.end(), alloc);
  EXPECT_LE(v1.size(), v3.size());
}

// vector( const vector& other )
TEST(VectorConstructors, CopyConstructor) {
  ft::vector<int> v1;
  ft::vector<int> v2(v1);
  EXPECT_EQ(v1.size(), v2.size());

  ft::vector<int> v3(100);
  ft::vector<int> v4(v3);
  EXPECT_EQ(v3.size(), v4.size());
}

// vector& operator=( const vector& other )
TEST(VectorAssignment, CopyAssignment) {
  ft::vector<int> v1;
  ft::vector<int> v2 = v1;
  EXPECT_EQ(v1.size(), v2.size());

  ft::vector<int> v3((unsigned)100, 69);  // TODO type inference
  ft::vector<int> v4 = v3;
  EXPECT_EQ(v3.size(), v4.size());
}

// void assign( size_type count, const T& value )
TEST(VectorAssignment, Assign) {
  ft::vector<int> v1(100);
  // SIGSEGV
  // v1.assign((unsigned)100, 69);  // TODO type inference
  EXPECT_GE(v1.size(), 100);

  ft::vector<int> v2;
  v2.assign((unsigned)100, 69);  // TODO type inference
  EXPECT_EQ(v1, v2);
}

// template< class InputIt >
// void assign( InputIt first, InputIt last )
TEST(VectorAssignment, AssignRange) {  // TODO
  ft::vector<int> v1(3);
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  ft::vector<int> v2;
  // SIGSEGV
  // v2.assign(v1.begin(), v1.end());
  EXPECT_EQ(v1, v2);
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
TEST(VectorElementAccess, AtOperator) {
  ft::vector<int> v1(10);
  v1[1] = 1;
  EXPECT_EQ(v1[0], 0);
  EXPECT_EQ(v1[1], 1);
}

// reference front()
TEST(VectorElementAccess, Front) {
  ft::vector<int> v1((unsigned)10, 3);  // TODO type inference
  v1[0] = 1;
  EXPECT_EQ(v1.front(), 1);
}

// reference back()
TEST(VectorElementAccess, Back) {
  ft::vector<int> v1((unsigned)3, 1);  // TODO type inference
  v1[2] = 2;
  EXPECT_EQ(v1.back(), 2);
}

// T* data()
TEST(VectorElementAccess, Data) {
  ft::vector<int> v1(10);
  // EXPECT_EQ(v1.data(), v1.begin()); // TODO how to check this?
}

// iterator begin()
TEST(VectorIterator, Begin) {
  ft::vector<int> v1(10);
  v1[1] = 1;
  v1[2] = 2;
  v1[3] = 3;
  EXPECT_EQ(*(v1.begin()), 0);
  EXPECT_EQ(*(v1.begin() + 1), 1);
  EXPECT_EQ(*(v1.begin() + 2), 2);
  EXPECT_EQ(*(v1.begin() + 3), 3);
}

// iterator end()
TEST(VectorIterator, End) {
  ft::vector<int> v1;
  EXPECT_EQ(v1.begin() + 1, v1.end());

  ft::vector<int> v2(3);
  v2[0] = 1;
  v2[1] = 2;
  v2[2] = 3;
  EXPECT_EQ(v2.begin() + 4, v2.end());
}

// reverse_iterator rbegin()
TEST(VectorIterator, RBegin) {  // TODO
  ft::vector<int> v1;
  // EXPECT_EQ(v1.rbegin(), v1.rend());

  // ft::vector<int> v2(3);
  // v2[0] = 1;
  // v2[1] = 2;
  // v2[2] = 3;
  // EXPECT_EQ(v2.rbegin() + 4, v2.rend());
}

// reverse_iterator rend()
TEST(VectorIterator, REnd) {  // TODO
  ft::vector<int> v1;
  // EXPECT_EQ(v1.rbegin(), v1.rend());

  // ft::vector<int> v2(3);
  // v2[0] = 1;
  // v2[1] = 2;
  // v2[2] = 3;
  // EXPECT_EQ(v2.rbegin() + 4, v2.rend());
}

// bool empty() const
TEST(VectorCapacity, Empty) {
  ft::vector<int> v1;
  EXPECT_TRUE(v1.empty());
  v1.push_back(1);
  v1.pop_back();
  EXPECT_TRUE(v1.empty());
}

// size_type size() const
TEST(VectorCapacity, Size) {
  ft::vector<int> v1((unsigned)100, 1);  // TODO type inference
  EXPECT_EQ(v1.size(), 100);
  v1.push_back(3);
  EXPECT_EQ(v1.size(), 101);
}

// size_type max_size() const
TEST(VectorCapacity, MaxSize) {
  ft::vector<int>  v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.max_size(), v2.max_size());
}

// void reserve( size_type new_cap )
TEST(VectorCapacity, Reserve) {
  ft::vector<int> v1;
  v1.reserve(69);
  EXPECT_EQ(v1.capacity(), 69);
  v1.reserve(1);
  EXPECT_EQ(v1.capacity(), 69);
}

// size_type capacity() const
TEST(VectorCapacity, Capacity) {
  ft::vector<int> v1(10);
  EXPECT_GE(v1.capacity(), 10);
  v1.reserve(69);
  EXPECT_EQ(v1.capacity(), 69);
}

// void clear()
TEST(VectorModifiers, Clear) {
  ft::vector<int> v1((unsigned)10, 3);  // TODO type inference
  v1.clear();
  EXPECT_EQ(v1.begin(), v1.end());
  EXPECT_EQ(v1.size(), 0);
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
