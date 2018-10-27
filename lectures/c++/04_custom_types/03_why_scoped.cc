#include <iostream>

enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

using namespace std;

int main() {
  cout << nov << endl;
  // cout << dec << endl; //dec is ambiguous if namespace is not used

  return 0;
}
