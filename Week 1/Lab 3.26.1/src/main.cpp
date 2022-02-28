#include <iostream>

int main(void)
{
    int userChange;
    int currentCoins;

    std::cin >> userChange;

    if (userChange <= 0)
    {
        std::cout << "No change" << std::endl;
        return 0;
    }

    currentCoins = userChange / 100;
    if (currentCoins > 0)
    {
        std::cout << currentCoins;

        if (currentCoins == 1)
        {
            std::cout << " Dollar";
        }
        else
        {
            std::cout << " Dollars";
        }

        std::cout << std::endl;
    }
    userChange %= 100;

    currentCoins = userChange / 25;
    if (currentCoins > 0)
    {
        std::cout << currentCoins;

        if (currentCoins == 1)
        {
            std::cout << " Quarter";
        }
        else
        {
            std::cout << " Quarters";
        }

        std::cout << std::endl;
    }
    userChange %= 25;

    currentCoins = userChange / 10;
    if (currentCoins > 0)
    {
        std::cout << currentCoins;

        if (currentCoins == 1)
        {
            std::cout << " Dime";
        }
        else
        {
            std::cout << " Dimes";
        }

        std::cout << std::endl;
    }
    userChange %= 10;

    currentCoins = userChange / 5;
    if (currentCoins > 0)
    {
        std::cout << currentCoins;

        if (currentCoins == 1)
        {
            std::cout << " Nickel";
        }
        else
        {
            std::cout << " Nickels";
        }

        std::cout << std::endl;
    }
    userChange %= 5;

    if (userChange > 0)
    {
        std::cout << userChange;

        if (userChange == 1)
        {
            std::cout << " Penny";
        }
        else
        {
            std::cout << " Pennies";
        }

        std::cout << std::endl;
    }

    return 0;
}
