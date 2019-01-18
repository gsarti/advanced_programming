#include <iostream>

namespace src1
  {
    std::string greetings(){
    std::string s{"Welcome\n"};
    return s;
  }
}

extern std::string to_upper(const std::string& os);

void print_upper(const std::string& s){
  std::cout << to_upper(src1::greetings() + s) << std::endl;
}


