#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
void insertSorted(std::vector<T>& userVector, T item);

int main(void)
{
    std::vector<int> userVector = {10, 20, 30, 40, 50, 60};

    while (true)
    {
        std::string userCommand;
        int userInput;

        std::cout << "Enter your command (insert, delete, or quit): " << std::flush;
        std::cin >> userCommand;

        if (userCommand == "quit")
        {
            break;
        }

        if (userCommand == "insert")
        {
            std::cout << "Enter int to insert (must be between 10 and 60): " << std::flush;
            std::cin >> userInput;

            while (userInput < 10 || userInput > 60)
            {
                std::cout << "Out of range. Please enter an int between 10 and 60." << std::endl;
                std::cout << "Enter int to insert (must be between 10 and 60): " << std::flush;
                std::cin >> userInput;
            }

            insertSorted(userVector, userInput);
        }

        if (userCommand == "delete")
        {
            std::cout << "Enter int to remove: " << std::flush;
            std::cin >> userInput;

            auto it = std::find(userVector.begin(), userVector.end(), userInput);

            while (it == userVector.end())
            {
                std::cout << "Integer not found. Please enter a valid int." << std::endl;
                std::cout << "Enter int to remove: " << std::flush;
                std::cin >> userInput;

                it = std::find(userVector.begin(), userVector.end(), userInput);
            }

            userVector.erase(it);
        }
    }

    for (auto item : userVector)
    {
        std::cout << item << std::endl;
    }

    return 0;
}

template <typename T>
void insertSorted(std::vector<T>& userVector, T item)
{
    userVector.insert(std::upper_bound(userVector.begin(), userVector.end(), item), item);
}
