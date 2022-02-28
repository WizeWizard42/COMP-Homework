/*
*   Prompt the user for a number between 1 and 20.
*   Create an array of that size.
*   Take in that number of ints into an array; and identify the smallest and largest values
*/
#include <iostream>

int main(void)
{
    std::size_t userSize;
    int* userArray = nullptr;

    std::cout << "Enter size of array: " << std::flush;
    std::cin >> userSize;

    userArray = reinterpret_cast<int*>(malloc(sizeof(int) * (userSize)));

    for (std::size_t i = 0; i < userSize; i++)
    {
        std::cin >> userArray[i];
    }

    int min = userArray[0];
    int max = userArray[0];

    for (std::size_t i = 0; i < userSize; i++)
    {
        if (userArray[i] < min)
        {
            min = userArray[i];
        }
        if (userArray[i] > max)
        {
            max = userArray[i];
        }
    }

    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;

    return 0;
}