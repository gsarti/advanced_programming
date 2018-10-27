/**
    Advanced Programming 2018-2019
    Purpose: Add range-for loops for vector custom class

    @author Gabriele Sarti
    @version 27/10/18
*/

#include <iostream>
#include <string>

template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}

  const std::size_t size() const { return _size; }
  num* begin() const { return &elem[0]; }
  num* end() const { return &elem[_size]; }

  num& operator[](const std::size_t i) { return elem[i]; }

  ~Vector() { delete[] elem; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    unsigned int count = 0;
    for (T i : v)
        os << "v[" << count++ << "] = " << i << std::endl;
    return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333; 

  std::cout << *pv << std::endl;

  Vector<double>& rv{v};

  rv[5] = 555;

  std::cout << rv << std::endl;

  return 0;
}
