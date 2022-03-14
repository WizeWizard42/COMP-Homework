#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std; // Required for test harness

string PromptString();

void PrintMenu();

void ExecuteMenu(const char userChoice, string& userString);

int GetNumOfNonWSCharacters(const string& userString);

int GetNumOfWords(const string& userString);

int FindText(const string& userWord, const string& userString);

void ReplaceExclamation(string& userString);

void ShortenSpace(string& userString);

int main(void)
{

    string userString = PromptString();

    while (true)
    {
        char userChoice;
        PrintMenu();

        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> userChoice;

        if (userChoice == 'q')
        {
            break;
        }

        ExecuteMenu(userChoice, userString);
    }
    
    return 0;
}


string PromptString()
{
    string userString;

    cout << "Enter a sample text:" << endl;
    getline(cin, userString);
    cout << endl;

    cout << "You entered: " << flush;
    cout << userString << endl;
    cout << endl;
    return userString;
}

void PrintMenu()
{
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
    return;
}

void ExecuteMenu(const char userChoice, string& userString)
{
    switch(userChoice)
    {
        case 'c':
            cout << "Number of non-whitespace characters: "
                << GetNumOfNonWSCharacters(userString) << endl << endl;
            break;
        case 'w':
            cout << "Number of words: " << GetNumOfWords(userString) << endl << endl;
            break;
        case 'f':
            {
                string userWord;
                cout << "Enter a word or phrase to be found:" << endl;
                cin.ignore();
                getline(cin, userWord);
                cout << "\"" << userWord << "\" instances: "
                    << FindText(userWord, userString) << endl << endl;
            }
            break;
        case 'r':
            ReplaceExclamation(userString);
            cout << "Edited text: " << userString << endl << endl;
            break;
        case 's':
            ShortenSpace(userString);
            cout << "Edited text: " << userString << endl << endl;
            break;
    }

    return;
}

int GetNumOfNonWSCharacters(const string& userString)
{
    int numNonWSChars = 0;

    for (const char c : userString)
    {
        if (!isspace(c))
        {
            numNonWSChars++;
        }
    }
    return numNonWSChars;
}

int GetNumOfWords(const string& userString)
{
    int numWords = 0;
    string workingString = userString;
    ShortenSpace(workingString);

    istringstream iss(workingString);
    string word;

    while (getline(iss, word, ' '))
    {
        numWords++;
    }
    return numWords;
}

int FindText(const string& userWord, const string& userString)
{
    int numWords = 0;
    
    auto iter = find(userString.begin(), userString.end(), userWord);

    while (iter != userString.end()) // Something's going wrong here, no idea why
    {
        numWords++;
        iter = find(++iter, userString.end(), userWord);
    }

    return numWords;
}

void ReplaceExclamation(string& userString)
{
    for (char& c : userString)
    {
        if (c == '!')
        {
            c = '.';
        }
    }
    return;
}

void ShortenSpace(string& userString)
{
    for (size_t i = 0; i < userString.size(); i++)
    {
        int numSpaces = 0;
        if (userString.at(i) == ' ')
        {
            for (size_t j = i; userString.at(j) == ' '; j++)
            {
                numSpaces++;
            }
        }

        if (numSpaces >= 2)
        {
            userString.erase(i, numSpaces-1);
        }
    }

    return;
}
