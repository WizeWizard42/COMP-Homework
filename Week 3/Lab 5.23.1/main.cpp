/*
*   Write a program that reads an integer, a list of words, and a character.
*   The integer signifies how many words are in the list.
*   The output of the program is every word in the list that contains the character at least once.
*   For coding simplicity, follow each output word by a comma, even the last one.
*   Add a newline to the end of the last output.
*   Assume at least one word in the list will contain the given character. 
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

int main(void)
{
    int userLength;
    std::cin >> userLength;
    std::vector<std::string> userStrings(userLength);

    for (int i = 0; i < userLength; i++)
    {
        std::cin >> userStrings.at(i);
    }

    char userChar;
    std::cin >> userChar;

    for (std::string& input : userStrings)
    {
        if (std::strchr(input.c_str(), userChar) != NULL)
        {
            std::cout << input << ",";
        }
    }
    std::cout << std::endl;

    return 0;
}
