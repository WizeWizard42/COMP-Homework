/*
*   Create a swap function that does not pass by reference, in order to demonstrate that this does not work.
*   Create a swap by reference function.
*/
#include <iostream>

void swapByValueBad(int userNum1, int userNum2);
void swapByRef(int& userNum1, int& userNum2);

int main(void)
{
    int userNum1;
    int userNum2;

    std::cin >> userNum1;
    std::cin >> userNum2;

    swapByValueBad(userNum1, userNum2);
    std::cout << userNum1 << ", " << userNum2 << std::endl;

    swapByRef(userNum1, userNum2);
    std::cout << userNum1 << ", " << userNum2 << std::endl;

    return 0;
}

void swapByValueBad(int userNum1, int userNum2)
{
    int swap = userNum1;
    userNum1 = userNum2;
    userNum2 = swap;
    return;
}

void swapByRef(int& userNum1, int& userNum2)
{
    int swap = userNum1;
    userNum1 = userNum2;
    userNum2 = swap;
    return;
}
