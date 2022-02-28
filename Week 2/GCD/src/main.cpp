#include <iostream>

int main(void)
{
    int userNum1;
    int userNum2;
    int gcd;

    std::cin >> userNum1;
    std::cin >> userNum2;

    
    // Newton's Method (alternative)

    /*
    *   while (userNum1 != userNum2)
    *   {
    *       if (userNum1 > userNum2)
    *       {
    *           userNum1 -= userNum2;
    *       }
    *       else
    *       {
    *           userNum2 -= userNum1;
    *       }
    *   }
    */
    
    for (int i = 1; i <= userNum1; i++)
    {
        if ((userNum1 % i) == 0 && (userNum2 % i) == 0)
        {
            gcd = i;
        }
    }

    std::cout << gcd << std::endl;

    return 0;
}