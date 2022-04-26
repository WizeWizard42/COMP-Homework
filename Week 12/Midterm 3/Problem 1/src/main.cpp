/*
 *  This program implements three different functions intending to swap the values of variables.
 */
#include <iostream>

// Swaps ints by reference.
void swapRef(int& num1, int& num2);

// Swaps ints by dereferencing pointer.
void swapPtr(int* num1, int* num2);

// Swaps pointer to ints by passing double pointer.
void swapDblPtr(int** num1, int** num2);

int main(void)
{
    int num1;
    int num2;

    std::cout << "Enter your first two values:" << std::endl;

    std::cin >> num1;
    std::cin >> num2;

    swapRef(num1, num2);

    std::cout << num1 << ", " << num2 << std::endl;

    int* numPtr1 = &num1;
    int* numPtr2 = &num2;

    swapPtr(numPtr1, numPtr2);

    std::cout << *numPtr1 << ", " << *numPtr2 << std::endl;

    int** numDblPtr1 = &numPtr1;
    int** numDblPtr2 = &numPtr2;

    swapDblPtr(numDblPtr1, numDblPtr2);

    std::cout << *numDblPtr1 << ", " << *numDblPtr2 << std::endl;

    return 0;
}

void swapRef(int& num1, int& num2)
{
    int swap = num1;
    num1 = num2;
    num2 = swap;
}

void swapPtr(int* num1, int* num2)
{
    int swap = *num1;
    *num1 = *num2;
    *num2 = swap;
}

void swapDblPtr(int** num1, int** num2)
{
    int* swap = *num1;
    *num1 = *num2;
    *num2 = swap;
}
