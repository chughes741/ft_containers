
#ifndef INTERATOR_HPP_
#define INTERATOR_HPP_

// base iterator template
class BaseInterator {
 public:
  Interator();
  Interator(const Interator &other);
  Interator &operator=(const Interator &rhs);
  ~Interator();

 private:
};

#endif  // INTERATOR_HPP_
