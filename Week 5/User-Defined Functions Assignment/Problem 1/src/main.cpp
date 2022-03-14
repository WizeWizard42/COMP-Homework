/*
*   This program takes an integer from terminal input, reverses it, and prints out the resulting number.
*   If non-integer input is given, behavior is undefined.
*/
#include <iostream>
#include <string>
#include <algorithm>

// Reverses the digits of the integer.
// ex: Input is -123, output is -321
int reverseDigit(int userNum); 

int main(void)
{
    int userNum;

    std::cout << "Enter your integer: " << std::flush;
    std::cin >> userNum;

    userNum = reverseDigit(userNum);

    std::cout << "Your reversed integer: " << userNum << std::endl;

    return 0;
}

int reverseDigit(int userNum)
{
    std::string workingNum = std::to_string(userNum); // Work with integer as string to make everyone's life easier

    if (workingNum.at(0) == '-') // Check if integer is negative
    {
        std::reverse(++workingNum.begin(), workingNum.end()); // Start 1 element past beginning because of '-' character
    }
    else
    {
        std::reverse(workingNum.begin(), workingNum.end());
    }

    int resultNum = std::stoi(workingNum); // Convert back to integer and return

    return resultNum;
}
