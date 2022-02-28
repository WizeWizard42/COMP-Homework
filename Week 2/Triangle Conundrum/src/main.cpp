#include <iostream>

int main(void)
{
    int userRows;

    while (true) // Input validation
    {
        std::cout << "Please enter rows: " << std::flush;
        std::cin >> userRows;

        if (userRows < 10)
        {
            break;
        }

        std::cout << "userRows cannot be more than 9." << std::endl;
    }

    for (int row = 0; row < userRows; row++)
    {
        for (int j = 0; j < (userRows - (row + 1)); j++) // Print needed spaces for pyramid
        {
            std::cout << "  "; // Need double spaces here
        }

        for (int num = row; num > 0; num--) // Print numbers descending
        {
            std::cout << (num + 1) << " ";
        }

        for (int num = 0; num <= row; num++) // Print numbers ascending
        {
            std::cout << (num + 1) << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}