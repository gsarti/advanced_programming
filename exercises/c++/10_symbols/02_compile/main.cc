#include "foo.h"
#include "utility.h"
#include<iostream>

void print_upper(const std::string& s);
void print_lower(const std::string& s);

int main()
{
  print_lower("EXPECT TO SEE LOWER CASE");
  Foo foo{""};
  print_upper("expect to see upper case");
  std::cout << Foo::f << foo.bar << " " << to_lower(foo.bar) << std::endl;
  return 0;
}
