/*
 *  This program implements a function that counts the number of each digit in a given string.
 *  The function returns a pointer to an array that you can access.
 *  Each index contains its respective count, e.g. result[0] -> 5 means the integer 0 appears 5 times.
 */
#include <iostream>
#include <cctype>
#include <string>

int* count(const std::string& s);

int main(void)
{

    int* result = count("SSN is 343 32 4545 and ID 434 34 4323");

    for (int i = 0; i < 10; i++)
    {
        std::cout << i << ": " << result[i] << "\n";
    }
    std::cout << std::flush;

    return 0;
}

int* count(const std::string& s)
{
    int* intCount = new int[10];
    for (int i = 0; i < 10; i++)
    {
        intCount[i] = 0;
    }

    for (char c : s)
    {
        if (std::isdigit(c))
        {
            intCount[c - 48]++; // If c is a digit, subtracting 48 from it gives its respective integer.
        }
    }

    return intCount;
}
