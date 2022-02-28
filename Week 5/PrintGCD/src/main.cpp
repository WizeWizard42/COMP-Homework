/*
*  Take in two ints.
*  Make a function that identifies a greatest common divisor from those two inputs and returns the GCD.
*  make a print function that outputs that value to the screen.
*  Additionally if you finish early: make an odd-or-even function that tests each of the inputs
*/
#include <iostream>

int getGCD(int userNum1, int userNum2);

void printGCD(int userNum1, int userNum2);

bool isEven(int userNum);

int main()
{
    int userNum1;
    int userNum2;

    std::cin >> userNum1;
    std::cin >> userNum2;

    printGCD(userNum1, userNum2);

    return 0;
}


int getGCD(int userNum1, int userNum2)
{
    int workingNum1 = userNum1;
    int workingNum2 = userNum2;

    int resultGCD = 1;

    for (int i = 2; i <= workingNum1; i++)
    {
        if (workingNum1 % i == 0 && workingNum2 % i == 0)
        {
            resultGCD *= i;
            workingNum1 /= i;
            workingNum2 /= i;

            i--;
        }
    }

    return resultGCD;
}

void printGCD(int userNum1, int userNum2)
{
    int resultGCD = getGCD(userNum1, userNum2);

    std::cout << "Result GCD: " << resultGCD << std::endl;
    return;
}

bool isEven(int userNum)
{
    return (userNum % 2 == 0);
}
