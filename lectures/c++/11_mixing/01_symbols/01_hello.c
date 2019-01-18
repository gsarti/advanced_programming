#include <stdio.h>

// Compilation steps by default:
// source file --- preprocess --> assembly file --- assembler --> machine code
// Linking is language-agnostic. This means code coming from different languages
// can be linked together.
//

int main() {
  printf("hello, world\n");
  return 0;
}
