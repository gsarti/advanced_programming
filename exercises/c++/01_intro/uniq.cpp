/**
    Advanced Programming 2018-2019
    Purpose: A simple implementation of the uniq -c UNIX command

    @author Gabriele Sarti
    @version 6/10/18
*/

#include <iostream>
#include <sstream>


int main()
{
  std::string line;
  std::string previous_line = "";
  std::ostringstream result;

  int count = 1;
  while(std::getline(std::cin,line))
  {
    if(line == previous_line)
        count++;
    else if (previous_line != "") //We only write non-empty lines
    {
        result << count << " " << previous_line << "\n";
        count = 1;
    }
    previous_line = line;
  }
  result << count << " " << previous_line << "\n";
  std::cout << result.str() << std::endl;
}