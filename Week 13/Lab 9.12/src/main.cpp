/*
 *  (1) Prompt the user for a title for data. Output the title.
 *  (2) Prompt the user for the headers of two columns of a table. Output the column headers.
 *  (3) Prompt the user for data points.
 *      Data points must be in this format: string, int.
 *      Store the information before the comma into a string variable and the information after the comma into an integer.
 *      The user will enter -1 when they have finished entering data points. Output the data points.
 *      Store the string components of the data points in a vector of strings.
 *      Store the integer components of the data points in a vector of integers.
 *  (4) Perform error checking for the data point entries.
 *      If any of the following errors occurs, output an appropriate error message and prompt again for a valid data point.
 *          * If entry has no comma
 *          * If entry has more than one comma
 *          * If entry after the comma is not an integer
 *  (5) Output the information in a formatted table.
 *      The title is right justified with a setw() value of 33.
 *      Column 1 has a setw() value of 20. Column 2 has a setw() value of 23.
 *  (6) Output the information as a formatted histogram. Each name is right justified with a setw() value of 20.
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    string dataTitle;
    cout << "Enter a title for the data:" << endl;
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << endl << endl;

    string col1Head;
    cout << "Enter the column 1 header:" << endl;
    getline(cin, col1Head);
    cout << "You entered: " << col1Head << endl << endl;

    string col2Head;
    cout << "Enter the column 2 header:" << endl;
    getline(cin, col2Head);
    cout << "You entered: " << col2Head << endl << endl;

    vector<string> dataStrings;
    vector<int> dataInts;
    while (true)
    {
        string userInput;
        cout << "Enter a data point (-1 to stop input):" << endl;

        getline(cin, userInput);

        if (userInput == "-1")
        {
            cout << endl;
            break;
        }

        auto iter = userInput.find(',');
        if (iter == userInput.npos)
        {
            cout << "Error: No comma in string." << endl << endl;
            continue;
        }

        if (userInput.find(',', iter + 1) != userInput.npos)
        {
            cout << "Error: Too many commas in input." << endl << endl;
            continue;
        }

        string dataString = userInput.substr(0, iter);
        int dataInt;
        try
        {
            dataInt = stoi(userInput.substr(iter + 1, userInput.size()));
        }
        catch(const invalid_argument& e)
        {
            cout << "Error: Comma not followed by an integer." << endl << endl;
            continue;
        }

        cout << "Data string: " << dataString << endl;
        cout << "Data integer: " << dataInt << endl << endl;

        dataStrings.push_back(dataString);
        dataInts.push_back(dataInt);
    }

    cout << right << setw(33) << dataTitle << endl;
    cout << left << setw(20) << col1Head << "|";
    cout << right << setw(23) << col2Head << endl;
    cout << setw(44) << setfill('-') << "" << endl;
    cout << setfill(' ');

    for (size_t i = 0; i < dataStrings.size(); i++)
    {
        cout << left << setw(20) << dataStrings.at(i) << "|";
        cout << right << setw(23) << dataInts.at(i) << endl;
    }
    cout << endl;

    for (size_t i = 0; i < dataStrings.size(); i++)
    {
        cout << right << setw(20) << dataStrings.at(i) << " ";
        cout << left << setw(dataInts.at(i)) << setfill('*') << "" << endl;
        cout << setfill(' ');
    }

    return 0;
}
