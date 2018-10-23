#include <iostream>

//argc is the number of arguments specified in command line
//argv is the list of arguments speicified in command line, with argv[0] being the name of the executable.
int main(int argc, char* argv[]) { //the only arguments accepted by the main
  for (auto i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  return 0;
}
