/**
    Advanced Programming 2018-2019
    Purpose: Read from LittleWomen.txt and count words instances.

    @author Gabriele Sarti
    @version 27/10/18
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/**
    Imports words from a text file

    @param filename the name of the file containing the list of values
    @return an std::vector containing all the values
*/
const std::vector<std::string> import_words(std::string filename)
{
    std::string value;
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> values;

    while (file >> value)
    {
        values.push_back(value);
    }

    return values;
}

/**
    Allows the removing of special chars from a string

    @param str the reference to the string to be modified
    @param chars_to_remove a string containing all the chars to be removed
    @return nothing, the str reference is modified
*/
void remove_chars( std::string &str, std::string chars_to_remove ) 
{
   for ( unsigned int i = 0; i < chars_to_remove.size(); ++i ) 
   {
      str.erase( remove(str.begin(), str.end(), chars_to_remove[i]), str.end() );
   }
}

int main()
{
    std::vector<std::string> words = import_words("LittleWomen.txt");
    std::cout << words.size() << std::endl;
    std::sort(words.begin(), words.end());
    std::string current_word = words[0];
    unsigned int count = 0;
    for(std::string word : words)
    {
        remove_chars(word, "?!.,':\"");
        if (word == current_word)
            ++count;
        else
        {
            std::cout << "\"" << current_word << "\" : " << count << " instances found" << std::endl;
            current_word = word;
            count = 1;
        }
    }
    return 0;
}

