/*
*   Write a program that reads a list of integers, and outputs those integers in reverse.
*   The input begins with an integer indicating the number of integers that follow.
*   For coding simplicity, follow each output integer by a comma, including the last one.
*/
#include <iostream>
#include <vector>

int main(void)
{
    int userLength;
    std::cin >> userLength;
    std::vector<int> userNums(userLength);

    for (int i = 0; i < userLength; i++)
    {
        std::cin >> userNums.at(i);
    }

    for (int i = (userLength - 1); i >= 0; i--)
    {
        std::cout << userNums.at(i) << ",";
    }
    std::cout << std::endl;

    return 0;
}
