/**
    Advanced Programming 2018-2019
    Purpose: Avoid repetition in input words

    @author Gabriele Sarti
    @version 27/10/18
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::string word;
    std::vector<std::string> words;

    std::cout << "Please insert a list of words." << std::endl;
    std::cout << "(Enter) -> Insert next word" << std::endl;
    std::cout << "(Ctrl + D) -> Finish" << std::endl;

    while(std::getline(std::cin,word))
    {
        words.push_back(word);
    }

    std::sort( words.begin(), words.end() );
    words.erase( unique( words.begin(), words.end() ), words.end() );

    std::cout << "Here is the list without repetition:" << std::endl;

    for (std::string w : words)
    {
        std::cout << w << std::endl;
    }

    return 0;
}