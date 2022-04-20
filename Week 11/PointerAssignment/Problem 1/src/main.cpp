/*
 *  Write a program that dynamically allocates an array large enough to hold a user-defined number of test scores.
 *  Once all the scores are entered, the array should be passed to a function that sorts them in ascending order.
 *  Another function should be called that calculates the average score.
 *  The program should display the sorted list of scores and averages with appropriate headings.
 *  Use pointer notation rather than array notation whenever possible.
 * 
 *  Input validation: Do not accepts negative numbers from test scores.
 */
#include <iostream>
#include <algorithm>
#include <numeric>

// Returns the average of a C array of ints, rounded down.
int getAverage(int* userScores, int size);

int main(void)
{
    int userLen = 0;

    std::cout << "Enter number of test scores: " << std::flush;
    std::cin >> userLen;

    int* userScores = new int[userLen];

    for (int i = 0; i < userLen; i++)
    {
        int userInput = 0;

        while (true)
        {
            std::cout << "Score #" << (i + 1) << ": " << std::flush;
            std::cin >> userInput;

            if (userInput >= 0)
            {
                userScores[i] = userInput;
                break;
            }

            std::cout << "Invalid score. Please input non-negative integer." << std::endl;
        }
        
    }

    std::sort(userScores, userScores + userLen); // An STL function that sorts an array.

    int userAvg = getAverage(userScores, userLen);

    for (int i = 0; i < userLen; i++)
    {
        std::cout << userScores[i] << " ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "Average of scores: " << userAvg << std::endl;

    delete userScores;

    return 0;
}

int getAverage(int* userScores, int size)
{
    return std::reduce(userScores, userScores + size) / size;
}
