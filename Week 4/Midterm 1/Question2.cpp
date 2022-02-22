#include <iostream>
#include <vector>

int main(void)
{
    int userInput;
    std::vector<int> userFactors;

    std::cout << "Enter a number to output its factors: " << std::flush;
    std::cin >> userInput;
    for (int i = 2; i <= userInput; i++)
    {
        while (userInput % i == 0)
        {
            userFactors.push_back(i);
            userInput /= i;
        }
    }

    for (std::size_t i = 0; i < userFactors.size(); i++)
    {
        std::cout << userFactors.at(i);
        if (i != (userFactors.size() - 1))
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
