/*
*   Write a program that takes any number of non-negative integers as input, and outputs the max and average.
*   A negative integer ends the input and is not included in the statistics. Assume the input contains at least one non-negative integer.
*/

#include <iostream>
#include <iomanip>

int main(void)
{
    int userMax = 0;
    double userSum = 0.0;
    int numCount = 0;
    double userAvg = 0.0;

    int currNum;
    std::cin >> currNum;

    userMax = currNum;
    while (currNum >= 0)
    {
        if (currNum > userMax)
        {
            userMax = currNum;
        }
        userSum += currNum;
        numCount++;

        std::cin >> currNum;
    }

    userAvg = userSum / numCount;

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << userMax << " " << userAvg << std::endl;

    return 0;
}