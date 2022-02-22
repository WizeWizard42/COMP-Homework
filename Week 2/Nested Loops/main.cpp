#include <iostream>

int main(void)
{  
    int userRows;
    int userCols;
    char userChar;

    while (true)
    {
        std::cin >> userRows;
        std::cin >> userCols;

        if (userRows <= 10 || userCols <= 10)
        {
            break;
        }

        std::cout << "Sorry, userRows and userCols can't be more than 10." << std::endl;
    }

    std::cin >> userChar;

    for (int i = 0; i < userRows; i++)
    {
        for (int j = 0; j < userCols; j++)
        {
            std::cout << userChar << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}