#include <iostream>

struct X {
  char member;
};

int main() {
  X x1;                 // default ctor = leaves member variables of built-in types in uninitialized state, but ctors for custom types are called.
  X x2{x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4{};               // default ctor calling {} to each member = member variables are initialized to their defaults.
  x4 = x3;              // copy assignment
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment
  std::cout << x5.member << std::endl;  // what do you expect??
  return 0;
}
