#include <iostream>
#include <string>

struct S {
  int a;
  double b;
  std::string s;  // default ctor of string set s to empty string
  S() = default;         // defines the default behavior for 
  S(const S&) = delete;  // cannot use a copy ctor. This will allow the use of singleton patterns through the use of the move constructor.
};

int main() {
  S s1;  // calls default constructor for s (custom type) but not for a and b (built-in types)

  S s2{1, 2.3, "alberto"};  // if there are no custom ctors I can
                            // directly initialize the members. Note
                            // that I need access (i.e. they must be
                            // public)
  // it is called aggregate initialization (see
  // https://en.cppreference.com/w/cpp/language/aggregate_initialization)
  // Aggregate initialization can be applied only on public members. In order to delete it, put all the member variables as private.

  S s3{};  // calls {} on each member, same as S s3 { {}, {}, {} };

  std::cout << s1.a << "--" << s1.b << "--" << s1.s << "\n";
  std::cout << s2.a << "--" << s2.b << "--" << s2.s << "\n";
  std::cout << s3.a << "--" << s3.b << "--" << s3.s << "\n";

  // S s4(s2); // compiler error

  return 0;
}
