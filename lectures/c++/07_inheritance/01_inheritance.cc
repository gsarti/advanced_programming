#include "ap_error.h"
#include <iostream>

// A child class is always bigger in memory than the parent class
// If the parent class functions are simply hidden by same-name-functions from child class,
// the parent class function will still be called when referencing the base class through 
// runtime polymorphism

struct Animal {
  unsigned int age;
  double weight;

  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR(weight >= 0) << "invalid weight: " << weight << std::endl;
  }

  Animal() noexcept : Animal{0, 0} {}  // delegating constructor

  void speak() const noexcept { std::cout << "Unknown\n"; }
  void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }
};

struct Dog : public Animal {
  void speak() const noexcept { std::cout << "Bau\n"; }
  Dog() noexcept = default; //simply uses the Animal base constructor
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

struct Snake : public Animal {
  bool dangerous;
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  Snake(const bool b) noexcept : Animal{}, dangerous{b} {}
  void info() const noexcept {
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept { std::cout << "ssss\n"; }
};

inline void newline() noexcept {
  std::cout << std::endl;
}

// run-time (dynamic) polymorphism
// Polymorphism = a class can be seen as a different one
// Achieved by using a reference or a pointer to the base class
void print_animal(const Animal& a) noexcept {
  std::cout << "through ref\n";
  a.info();
  a.speak();
}

// compile-time (static) polymorphism
// The behavior of the function is defined after compilation
template <class T>
void print_animal_template(const T& a) noexcept {
  std::cout << "through template\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Dog d;
    d.info();
    d.speak();

    newline();

    Dog d1{0, 0.6};
    d1.info();
    d1.speak();

    newline();

    Snake s{true};
    s.info();
    s.speak();

    newline();

    Animal* p = new Snake{1, 2.3, false};
    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    newline();

    print_animal(s); //doesn't work, it calls the function of the class animal instead of the one in Snake class

    newline();

    print_animal_template(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
