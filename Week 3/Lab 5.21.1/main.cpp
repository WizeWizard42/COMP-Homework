/*
*   Adjust the values by dividing all values by the largest value.
*   The input begins with an integer indicating the number of floating-point values that follow.
*   Output each floating-point value with two digits after the decimal point.
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main(void)
{
    int userLength;
    std::cin >> userLength;
    std::vector<double> userNums(userLength);

    int max;
    for (int i = 0; i < userLength; i++)
    {
        std::cin >> userNums.at(i);

        if (i == 0 || userNums.at(i) > max)
        {
            max = userNums.at(i);
        }
    }

    std::for_each(userNums.begin(), userNums.end(), // Divides all elements by largest element. Lambdas are awesome.
        [max](double& num) { num /= max; });

    std::cout << std::fixed << std::setprecision(2);
    for (double num : userNums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
