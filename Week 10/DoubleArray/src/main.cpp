#include <iostream>

int* continueArray(int* array, int size);

int main(void)
{
    int baseNumber = 0;
    int incrementNumber = 0;

    std::cout << "Enter base number: " << std::flush;
    std::cin >> baseNumber;
    std::cout << "Enter increment number: " << std::flush;
    std::cin >> incrementNumber;

    int firstArray[5];

    for (int i = 0; i < 5; i++)
    {
        firstArray[i] = (baseNumber + (incrementNumber * i));
        std::cout << firstArray[i] << ", ";
    }
    std::cout << std::endl << std::endl;

    int* newArray = continueArray(firstArray, 5);

    for (int i = 0; i < 10; i++)
    {
        std::cout << newArray[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}

int* continueArray(int* array, int size)
{
    int newArrayLength = size * 2;

    int baseNumber = array[0];
    int incrementNumber = array[1] - array[0];

    int* newArray = new int[newArrayLength];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    for (int i = size; i < newArrayLength; i++)
    {
        newArray[i] = (baseNumber + (incrementNumber * i));
    }

    return newArray;
}
