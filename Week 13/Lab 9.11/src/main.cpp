#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    
    while (true)
    {
        stringstream commaList;

        string userInput;

        cout << "Enter input string:" << endl;
        getline(cin, userInput);

        if (userInput == "q")
        {
            break;
        }

        if (userInput.find(',') == userInput.npos)
        {
            cout << "Error: No comma in string." << endl << endl;
            continue;
        }

        string substr;
        commaList << userInput;

        cout << "First word: ";
        getline(commaList, substr, ',');
        substr.erase(remove_if(substr.begin(), substr.end(), ::isspace), substr.end());
        cout << substr << endl;

        cout << "Second word: ";
        getline(commaList, substr, ',');
        substr.erase(remove_if(substr.begin(), substr.end(), ::isspace), substr.end());
        cout << substr << endl << endl;

        
    }
    
    return 0;
}