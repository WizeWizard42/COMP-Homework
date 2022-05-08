#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isNumber(const string& str)
{
    for (const char& c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

int DateParser(string month) {
	int monthInt = 0;
	
	if (month == "January")
		monthInt = 1;
	else if (month == "February")
		monthInt = 2;
	else if (month == "March")
		monthInt = 3;
	else if (month == "April")
		monthInt = 4;
	else if (month == "May")
		monthInt = 5;
	else if (month == "June")
		monthInt = 6;
	else if (month == "July")
		monthInt = 7;
	else if (month == "August")
		monthInt = 8;
	else if (month == "September")
		monthInt = 9;
	else if (month == "October")
		monthInt = 10;
	else if (month == "November")
		monthInt = 11;
	else if (month == "December")
		monthInt = 12;
	return monthInt;
}

int main () {
	
	// TODO: Read dates from input, parse the dates to find the ones
	//       in the correct format, and output in m/d/yyyy format

    stringstream parsedDate;
    
    string currEntry;
    getline(cin, currEntry);

    stringstream currStream(currEntry);


    while (currEntry != "-1")
    {
        for (int i = 0; i < 3; i++)
        {
            string currWord;
            currStream >> currWord;

            if (i == 0)
            {
                int monthInt = DateParser(currWord);

                if (monthInt < 1 || monthInt > 12)
                {
                    break;
                }

                parsedDate << monthInt << "/";
            }

            if (i == 1)
            {
                

            }

            if (i == 2)
            {
                if (!isNumber(currWord))
                {
                    break;
                }

                parsedDate << currWord << "\n";
            }
        }

        getline(cin, currEntry);
        currStream.clear();
        currStream << currEntry;
    }
}