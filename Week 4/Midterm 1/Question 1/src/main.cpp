#include <iostream>
#include <array>
#include <algorithm>

void readToUpper(std::string& userInput);

const int ANSWER_KEY_LENGTH = 20;

int main(void)
{
    std::array<char, ANSWER_KEY_LENGTH> answerKey = {
        'A', 'D', 'B', 'B', 'C',
        'B', 'A', 'B', 'C', 'D',
        'A', 'C', 'D', 'B', 'D',
        'C', 'C', 'A', 'D', 'B'
    };

    std::array<char, ANSWER_KEY_LENGTH> userAnswers;
    std::array<bool, ANSWER_KEY_LENGTH> answerMap;
    int correctAnswers = 0;

    std::string userInput;

    for (int i = 0; i < ANSWER_KEY_LENGTH; i++)
    {
        std::cout << "Enter your answer for question " << (i + 1) << ": " << std::flush;

        readToUpper(userInput);
        userAnswers.at(i) = userInput.at(0);

        answerMap.at(i) = false;

        if (userAnswers.at(i) == answerKey.at(i))
        {
            correctAnswers++;
            answerMap.at(i) = true;
        }
    }

    if (correctAnswers >= 15)
    {
        std::cout << "You passed the exam!" << std::endl;
    }
    else
    {
        std::cout << "Sorry, you failed the exam." << std::endl;
    }

    std::cout << "Number of correct answers: " << correctAnswers << std::endl;
    std::cout << "Number of incorrect answers: " << (ANSWER_KEY_LENGTH - correctAnswers) << std::endl;

    std::cout << "Question numbers with incorrect answers: " << std::endl;
    for (int i = 0; i < ANSWER_KEY_LENGTH; i++)
    {
        if (!answerMap.at(i))
        {
            std::cout << (i + 1);

            if (i == (ANSWER_KEY_LENGTH - 1))
            {
                std::cout << ".";
            }
            else
            {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;

    return 0;
}

void readToUpper(std::string& userInput)
{
    std::getline(std::cin, userInput);
    std::for_each(userInput.begin(), userInput.end(),
        [](char& c){c = toupper(c);});

    return;
}
