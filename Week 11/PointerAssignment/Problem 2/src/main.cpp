/*
 *  Write a function that accepts an int array and the array's size as arguments.
 *  The function should create a new array that is twice the size of the argument array.
 *  The function should copy the contents of the argument array to the new array and initialize the unused elments of the second array with 0.
 *  The function should return a pointer to the new array.
 */
#include <iostream>

// Doubles passed array's size, fills the rest of the array with 0.
int* continueArray(int* array, int size);

// Creates array and fills based on a base number and increments, prints out original and doubled array.
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

    int* newArray = new int[newArrayLength];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    for (int i = size; i < newArrayLength; i++)
    {
        newArray[i] = 0;
    }

    return newArray;
}
