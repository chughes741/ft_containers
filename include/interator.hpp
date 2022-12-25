
#ifndef INTERATOR_HPP_
#define INTERATOR_HPP_


#define ft_noexcept throw()

namespace ft {

// base iterator template
template <class Container>
class BaseInterator {
 public:
  BaseInterator();
  BaseInterator(Container::pointer p_arg_, const Container* p_container_);
  Container::value_type& operator*() const;
  Container::const_pointer operator->() const;
  BaseInterator& operator++();
  BaseInterator operator++(int);
  BaseInterator& operator--();
  BaseInterator operator--(int);
  BaseInterator& operator+=(const Container::difference_type offset_);
  BaseInterator(const Interator &other);
  BaseInterator &operator=(const Interator &rhs);
  ~BaseInterator();

 private:
};

template <class MyVector>
class VectorConstIterator : public BaseInterator<MyVector> {
 public:
  VectorConstIterator();
  VectorConstIterator(MyVector::pointer      p_arg_,
                      const BaseContainer* p_vector_);
  MyVector::value_type&   operator*() const;
  MyVector::const_pointer operator->() const;
  VectorConstIterator&    operator++();
  VectorConstIterator     operator++(int);
  VectorConstIterator&    operator--();
  VectorConstIterator     operator--(int);
  VectorConstIterator&    operator+=(const MyVector::difference_type offset_);
  VectorConstIterator  operator+(const MyVector::difference_type offset_) const;
  VectorConstIterator  operator+(const MyVector::difference_type offset_,
                                VectorConstIterator             next_);
  VectorConstIterator& operator-=(const MyVector::difference_type offset_);
  VectorConstIterator  operator-(const MyVector::difference_type offset_) const;
  MyVector::difference_type operator-(const VectorConstIterator& rhs) const;
  MyVector::value_type&     operator[](
      const MyVector::difference_type offset_) const;
  bool operator==(const VectorConstIterator& rhs) const;
  bool operator!=(const VectorConstIterator& rhs) const;
  bool operator<(const VectorConstIterator& rhs) const;
  bool operator>(const VectorConstIterator& rhs) const;
  bool operator<=(const VectorConstIterator& rhs) const;
  bool operator>=(const VectorConstIterator& rhs) const;

  MyVector::pointer ptr_;
};

template <class MyVector>
class VectorIterator : public VectorConstIterator<MyVector> {
 public:
  MyVector::value_type& operator*() const;
  MyVector::pointer     operator->() const;
  VectorIterator&       operator++();
  VectorIterator        operator++(int);
  VectorIterator&       operator--();
  VectorIterator        operator--(int);
  VectorIterator&       operator+=(const MyVector::difference_type offset_);
  VectorIterator  operator+(const MyVector::difference_type offset_) const;
  VectorIterator  operator+(const MyVector::difference_type offset_,
                           VectorIterator                  next_);
  VectorIterator& operator-=(const MyVector::difference_type offset_);
  VectorIterator  operator-(const MyVector::difference_type offset_) const;
  VectorIterator  operator-(const MyVector::difference_type offset_,
                           VectorIterator                  next_);
  VectorIterator  operator-(const MyVector::difference_type offset_) const;
  MyVector::value_type& operator[](
      const MyVector::difference_type offset_) const;
};

} // namespace ft

#endif  // INTERATOR_HPP_
