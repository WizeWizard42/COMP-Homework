/*
*   Given integer coefficients of two linear equations with variables x and y,
*   use brute force to find an integer solution for x and y in the range -10 to 10.
*/

#include <iostream>

int main(void)
{
    int equation1[3]; // Each element is coefficient, in terms of ax + by = c
    int equation2[3];

    for (int i = 0; i < 3; i++)
    {
        std::cin >> equation1[i];
    }
    for (int i = 0; i < 3; i++)
    {
        std::cin >> equation2[i];
    }

    for (int x = -10; x <= 10; x++)
    {
        for (int y = -10; y <= 10; y++)
        {
            if (((equation1[0] * x) + (equation1[1] * y)) == equation1[2] && // There's probably a better way to evaluate this that I don't know here
            ((equation2[0] * x) + (equation2[1] * y)) == equation2[2])
            {
                std::cout << "x = " << x << ", y = " << y << std::endl;
                return 0; // Nothing else for the program to do
            }
        }
    }
    std::cout << "There is no solution" << std::endl;

    return 0;
}