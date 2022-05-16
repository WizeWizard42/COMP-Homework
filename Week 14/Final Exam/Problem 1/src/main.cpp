/*
 *  Write a program that reads the student information from a tab separated values (tsv) file. The program then creates a text file that records the course grades of the students. Each row of the tsv file contains the Last Name, First Name, Midterm1 score, Midterm2 score, and the Final score of a student. A sample of the student information is provided in StudentInfo.tsv. Assume the number of students is at least 1 and at most 20.
 *  The program performs the following tasks:
 *      Read the file name of the tsv file from the user.
 *      Open the tsv file and read the student information.
 *      Compute the average exam score of each student.
 *      Assign a letter grade to each student based on the average exam score in the following scale:
 *          A: 90 =< x
 *          B: 80 =< x < 90
 *          C: 70 =< x < 80
 *          D: 60 =< x < 70
 *          F: x < 60
 *      Compute the average of each exam.
 *      Output the last names, first names, exam scores, and letter grades of the students into a text file named report.txt.
 *      Output one student per row and separate the values with a tab character.
 *      Output the average of each exam, with two digits after the decimal point, at the end of report.txt.
 *      Hint: Use the setprecision manipulator to format the output.
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

    string fileName;
    string readLine;
        
    cin >> fileName;
    ifstream inFile(fileName);
    ofstream outFile("report.txt");

    getline(inFile, readLine);
    stringstream fileSS(readLine);
    
    // Used later to calculate average scores for each exam
    vector<double> midterm1Scores;
    vector<double> midterm2Scores;
    vector<double> finalScores;

    // While file still has lines to read
    while (inFile.good())
    {
        string lastName, firstName;
        double midterm1Score, midterm2Score, finalScore;
        fileSS >> lastName >> firstName >> midterm1Score >> midterm2Score >> finalScore;

        double avgScore = (midterm1Score + midterm2Score + finalScore) / 3.0; // Average score for student
        char studentGrade;

        if (avgScore >= 90.0)
        {
            studentGrade = 'A';
        }
        else if (avgScore >= 80.0)
        {
            studentGrade = 'B';
        }
        else if (avgScore >= 70.0)
        {
            studentGrade = 'C';
        }
        else if (avgScore >= 60.0)
        {
            studentGrade = 'D';
        }
        else
        {
            studentGrade = 'F';
        }

        outFile << lastName << "\t" << firstName << "\t" << midterm1Score << "\t" << midterm2Score << "\t" << finalScore << "\t" << studentGrade << endl;

        midterm1Scores.push_back(midterm1Score);
        midterm2Scores.push_back(midterm2Score);
        finalScores.push_back(finalScore);

        readLine.clear();
        getline(inFile, readLine);
        fileSS.clear(); // Since badbit gets set when you reach end of line, bits need to be cleared to keep reading
        fileSS.str(readLine);
    }
    outFile << endl;
    
    // Calculates exam averages
    double midterm1Avg = accumulate(midterm1Scores.begin(), midterm1Scores.end(), 0.0) / midterm1Scores.size();
    double midterm2Avg = accumulate(midterm2Scores.begin(), midterm2Scores.end(), 0.0) / midterm2Scores.size();
    double finalAvg = accumulate(finalScores.begin(), finalScores.end(), 0.0) / finalScores.size();

    outFile << fixed << setprecision(2) << "Averages: midterm1 " << midterm1Avg << ", midterm2 " << midterm2Avg << ", final " << finalAvg << endl;

    return 0;
}
