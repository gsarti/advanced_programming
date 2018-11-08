/*

Introduces the concept of shallow copy.

The copy constructor will create a shallow copy as default, because it's cheaper and faster.
Any modification to the copy will also be applied on the original element.

The copy on write pattern implies creating a shallow copy which becomes a deep copy at the moment its values are modified.

Explicit keyword is used to specify that the one-parameter function is a custom ctor and not an overriding of a function converting the type of parameter
in the ctor. Construction are allowed to do this type of conversion only once to extend function behaviors to all numerical types.
*/

#include <iostream>

template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

 public:
  explicit Vector(const std::size_t length)
      : elem{new num[length]{}}, _size{length} {}

  ~Vector() noexcept { delete[] elem; }

  const num& operator[](const std::size_t& i) const noexcept { return elem[i]; }
  num& operator[](const std::size_t& i) noexcept { return elem[i]; }

  std::size_t size() const noexcept { return _size; }

  // range-for
  const num* begin() const noexcept { return elem; }
  num* begin() noexcept { return elem; }

  const num* end() const noexcept { return elem + _size; }
  num* end() noexcept { return elem + _size; }
};

int main() {
  Vector<int> v1{3};
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  std::cout << "v1: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  Vector<int> v2{v1};  // default copy constructor

  std::cout << "v2 after default copy ctor: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v1[0] = 99;

  std::cout << "v2 after v1 has been changed: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v2[1] = -999;

  std::cout << "v1 after v2 has been changed: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
