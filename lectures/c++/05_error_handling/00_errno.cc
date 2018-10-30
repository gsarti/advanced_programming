#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(-9);
  std::cout << d << " " << errno << std::endl; // returns -nan 33
  return 0;
}
