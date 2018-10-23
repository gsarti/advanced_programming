#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);

int main() {
  int a{8};
  int* pi{&a};

  char** ppc; //pointer to a pointer of char

  int* ap[7]; //an array of seven elements, with each element being a pointer to int (equivalent to int**)

  void* pv{pi}; //uninitialized pointer
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment because we don't know the size
  int* pi2{static_cast<int*>(pv)}; //cast is needed before its usage

  //Void pointers can be initialized to whatever
  pv = ppc;
  pv = ap;
  pv = pi;


  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;  // error, why?
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr, not good for readability

  // pi = NULL; // please don't do this, can cause compile errors

  double* da{new double[5]{}};
  delete[] da;  // dangling pointer = a pointer pointing to a memory location which as been liberated
  da = nullptr; //reset the pointer after freeing the memory

  //If a variable can have no value, use pointer et nullptr in that case
  //else, it is safe to use references
  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;
  //same as
  if (pi)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";
  //same as
  if (!pi)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[], use std::string when possible
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  int (*fp)(const char*); //pointer to a function which returns an integer and takes a char* argument. Parenthesis are MANDATORY
  fp = func1;

  fp("hello");

  fp = &func2; //same as = func2
  fp("world");

  // fp = func3; // error: wrong signature, returns void
  auto xx = func3;

  xx("auto");

  decltype(&func3) x = func3; //similar to auto
  x("decltype");

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
