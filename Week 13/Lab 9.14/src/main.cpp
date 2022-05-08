
/*
 *  Write a program that reads the name of a text file containing a list of photo file names.
 *  The program then reads the photo file names from the text file, replaces the "_photo.jpg" portion of the file names with "_info.txt", and outputs the modified file names.
 *  Assume the unchanged portion of the photo file names contains only letters and numbers, and the text file stores one photo file name per line.
 *  If the text file is empty, the program produces no output.
 */

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
    string fileName;
    getline(cin, fileName);

    fstream file(fileName);

    if (!file.is_open())
    {
        cout << "Failed to open" << endl;
        return 0;
    }

    while (true)
    {
        string fileLine;
        getline(file, fileLine);

        if (!file.good())
        {
            break;
        }

        auto iter = fileLine.find("_photo.jpg");

        if (iter != fileLine.npos)
        {
            fileLine.replace(iter, 10, "_info.txt"); // 10 is length of "_photo.jpg"
        }

        cout << fileLine << endl;
    }

    return 0;
}
