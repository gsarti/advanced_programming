#include <iostream>

// if parent ctor and dtor aren't virtual, they will be called when instantiating a child object
// if the virtual keyword isn't specified on parent dtor, if a child class implements the RAII (Resource Acquisition Is Initialization) pattern
// through the use of pointers, the memory 

struct Base {
  Base() { std::cout << "Base\n"; }
  ~Base() { std::cout << "~Base\n"; }
};

struct Derived : public Base { // We use the keyword "final" to specify that the class shouldn't be inherited
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};

int main() {
  { Derived d; }

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p; // onlu

  return 0;
}
