/*
*   Write a program that removes all non alpha characters from the given input.
*/

#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
    std::string userString;
    getline(std::cin, userString);

    for (long unsigned int i = 0; i < userString.size(); i++)
    {
        if (!isalpha(userString.at(i)))
        {
            userString.erase(i, 1);
            i--;
        }
    }

    std::cout << userString << std::endl;

    return 0;
}