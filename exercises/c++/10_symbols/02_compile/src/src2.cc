#include <iostream>

namespace src2 {
  std::string greetings(){
    std::string s{"Good afternoon\n"};
    return s;
  }
}

extern std::string to_lower(const std::string& os);

void print_lower(const std::string& s){
  std::cout << to_lower(src2::greetings()) << to_lower(s) << std::endl;
}

