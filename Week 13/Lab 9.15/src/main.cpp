/*
 *  Write a program that reads the student information from a tab separated values (tsv) file.
 *  The program then creates a text file that records the course grades of the students.
 *  Each row of the tsv file contains the Last Name, First Name, Midterm1 score, Midterm2 score, and the Final score of a student.
 *  A sample of the student information is provided in StudentInfo.tsv. Assume the number of students is at least 1 and at most 20.
 * 
 *  The program performs the following tasks:
 *      Reads the file name of the tsv file from the user.
 *      Opens the tsv file and read the student information.
 *      Computes the average exam score of each student.
 *      Assigns a letter grade to each student based on the average exam score in the following scale:
 *          A: 90 =< x
 *          B: 80 =< x < 90
 *          C: 70 =< x < 80
 *          D: 60 =< x < 70
 *          F: x < 60
 *      Computes the average of each exam.
 *      Outputs the last names, first names, exam scores, and letter grades of the students into a text file named report.txt.
 *      Outputs one student per row and separate the values with a tab character.
 *      Outputs the average of each exam, with two digits after the decimal point, at the end of report.txt.
 */
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

int main(void)
{
    string fileName;
    getline(cin, fileName);

    fstream file(fileName);

    ofstream outFile("report.txt");

    if (!file.is_open())
    {
        cout << "File failed to open." << endl;
        return -1;
    }

    vector<double> midterm1Grades;
    vector<double> midterm2Grades;
    vector<double> finalGrades;

    while (true)
    {
        string fileLine;
        getline(file, fileLine);

        if (!file.good())
        {
            break;
        }

        istringstream oSS(fileLine);
        string firstName, lastName;
        double midterm1, midterm2, finalScore;

        double averageScore;
        char studentGrade;

        oSS >> firstName >> lastName >> midterm1 >> midterm2 >> finalScore;

        averageScore = (midterm1 + midterm2 + finalScore) / 3;

        if (averageScore >= 90.0)
        {
            studentGrade = 'A';
        }
        else if (averageScore >= 80.0)
        {
            studentGrade = 'B';
        }
        else if (averageScore >= 70.0)
        {
            studentGrade = 'C';
        }
        else if (averageScore >= 60.0)
        {
            studentGrade = 'D';
        }
        else
        {
            studentGrade = 'F';
        }

        outFile << fileLine << "\t" << studentGrade << endl;

        midterm1Grades.push_back(midterm1);
        midterm2Grades.push_back(midterm2);
        finalGrades.push_back(finalScore);
    }
   
    outFile << endl;

    double midterm1Avg = accumulate(midterm1Grades.begin(), midterm1Grades.end(), 0.0) / midterm1Grades.size();
    double midterm2Avg = accumulate(midterm2Grades.begin(), midterm2Grades.end(), 0.0) / midterm2Grades.size();
    double finalAvg = accumulate(finalGrades.begin(), finalGrades.end(), 0.0) / finalGrades.size();

    outFile << fixed << setprecision(2) << "Averages: midterm1 " << midterm1Avg << ", midterm2 " << midterm2Avg << ", final " << finalAvg << endl;

    return 0;
}
