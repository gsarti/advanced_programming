/**
    Advanced Programming 2018-2019
    Purpose: Try different types of errors in C++

    @author Gabriele Sarti
    @version 6/10/18
*/

//#include <iostream>
 
 
int func1(int variable)
{
    return variable;
}

//Tried different types of errors.
int main()
{
  //Typos in function name 
  //std::c0ut << "Hello" << std::endl;

  //Typos in variable name
  //intgr a = 1;

  //Forget to put ;
  //int a

  //Forget to include iostream
  //std::cout << "Hello" << std::endl;

  //Illegal naming
  //int double {0};

  //Pass wrong arguments
  //func1("Hello");
  
  return 0;
}