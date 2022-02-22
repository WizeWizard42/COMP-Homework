/*
*   Aggregates and displays rainfall data provided by user.
*   
*   Input Validation:
*   User cannot enter less than 1 year.
*   User cannot enter negative rainfall per month.
*/

#define forever for (;;) // :)

#include <iostream>

int main(void)
{
    int userYears = 0;
    int totalMonths = 0;
    double userRainfall = 0.0;
    double totalRainfall = 0.0;
    double avgRainfall = 0.0;

    forever // :))
    {
        std::cout << "Enter number of years: " << std::flush;
        std::cin >> userYears;

        if (userYears > 0)
        {
            break;
        }

        std::cout << "Invalid input. Number of years must be 1 or greater." << std::endl;
    }

    for (int year = 0; year < userYears; year++)
    {
        for (int month = 0; month < 12; month++)
        {
            forever // Now I'm just being consistent!
            {
                std::cout << "Enter rainfall (inches) for month " << (month + 1) << ": " << std::flush;
                std::cin >> userRainfall;

                if (userRainfall >= 0.0)
                {
                    totalRainfall += userRainfall;
                    break;
                }

                std::cout << "Invalid input. Rainfall for month most be non-negative." << std::endl;
            }
        }
    }

    totalMonths = userYears * 12;
    avgRainfall = totalRainfall / totalMonths;

    std::cout << "Total months: " << totalMonths << std::endl;
    std::cout << "Total rainfall: " << totalRainfall << " inches" << std::endl;
    std::cout << "Avg. rainfall per month: " << avgRainfall << " inches" << std::endl;

    return 0;
}