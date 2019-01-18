#include <string>

#ifndef FOO_H__
#define FOO_H__

extern std::string to_upper(const std::string& os);

struct Foo{
  static double f;
  std::string bar;
  Foo() = delete;
  Foo(const std::string& s) : bar{to_upper(s)} {}
};

double Foo::f;

#endif //FOO_H__
