// Constructors can throw exceptions
// Destructors throwing exceptions cause undefined behavior, don't do that.

#include <iostream>
#include <vector>

#include "ap_error.h"

class Foo {
 public:
  Foo() { std::cout << "Foo\n"; }
  ~Foo() { std::cout << "~Foo\n"; }
};

class Bar {
 public:
  Bar() { std::cout << "Bar\n"; }
  ~Bar() { std::cout << "~Bar\n"; }
};

class Vector {
  double* elem;

 public:
  Vector(const unsigned int l) : elem{new double[l]} {
    std::cout << "Vector\n";
  }
  ~Vector() noexcept {
    delete[] elem;
    std::cout << "~Vector\n";
  }
};

class ManyResources {
  double* ptr;
  Vector v;

 public:
  ManyResources() : ptr{nullptr}, v{3} { //It is initialized as nullptr since if the new threw an error we would delete random memory locations
    std::cout << "Manyresources\n";
    try {
      ptr = new double[5];  // new(std::nothrow) double[5] could be better
      AP_ERROR(false) << "Error in ManyResources ctor.\n";
    } catch (...) {
      delete[] ptr;  // <----
      throw; //throws the same error that was catched
    }
  }

  ~ManyResources() noexcept { //The noexcept argument marks a function that is assured not to throw exceptions.
    std::cout << "Manyresources\n";
    delete[] ptr;  // <----
  }
};

int main() {
  Foo f;
  int* raw_ptr = new int[7];
  try {
    // int * raw_ptr=new int[7]; // wrong because raw_ptr would not be visible
    // inside the catch-clause
    
    //Since the ManyResources constructor didn't complete, only the Vector destructor is called 
    //during the stack unwinding phase after the throw.
    ManyResources mr; 
    Bar b;

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

    delete[] raw_ptr;  // <--- try to comment this and run valgrind or use the
                       // sanitize library
    return 1;

  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n" << std::endl;

    delete[] raw_ptr;  // <---
    return 2;
  }

  delete[] raw_ptr;  // <---
  return 0;
}
