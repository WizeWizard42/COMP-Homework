/*
*   Ask a user for an int.
*   Create a vector of that size.
*   Intake a series of numbers into the vector. Find the average!
*/
#include <iostream>
#include <vector>

int main(void)
{
    std::size_t userSize;
    
    std::cout << "Enter array size: " << std::flush;
    std::cin >> userSize;

    std::vector<int> userArray(userSize);

    for (std::size_t i = 0; i < userSize; i++)
    {
        std::cin >> userArray.at(i);
    }

    double userAvg = 0.0;std::size_t i = 0; i < userSize;
    for (int userNum : userArray)
    {
        userAvg += userNum;
    }
    userAvg /= userSize;

    std::cout << "Average: " << userAvg << std::endl;

    return 0;
}
