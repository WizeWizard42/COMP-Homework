/*
*   Using two vectors, take in student ID and number of units for seven students.
*   Resize the array for an unspecified number of late adds.
*   Re-sort both arrays by the number of units per student.
*/
#include <iostream>
#include <vector>
#include <string>

int main(void)
{
    int studentCount = 7;
    std::vector<int> studentID(studentCount);
    std::vector<int> studentUnits(studentCount);

    for (int i = 0; i < studentCount; i++) // Enter info for main 7 students
    {
        int userUnits;

        studentID.at(i) = i;

        std::cout << "Enter units taken for student " << i << ": " << std::flush;
        std::cin >> userUnits;
        studentUnits.at(i) = userUnits;
    }

    int userInput;

    std::cout << "How many late adds are there? (0 or less for none): " << std::flush;
    std::cin >> userInput;
    studentCount += (userInput > 0) ? userInput : 0;

    for (int i = 7; i < studentCount; i++) // Enter info for late adds
    {
        int userUnits;

        studentID.push_back(i);

        std::cout << "Enter units taken for student " << i << ": " << std::flush;
        std::cin >> userUnits;
        studentUnits.push_back(userUnits);
    }

    studentID.shrink_to_fit();
    studentUnits.shrink_to_fit();

    bool sortOccurred = true;
    while (sortOccurred) // Bubble Sort
    {
        sortOccurred = false;

        for (int i = 1; i < studentCount; i++)
        {
            if (studentUnits.at(i) < studentUnits.at(i-1))
            {
                sortOccurred = true;

                int swap = studentUnits.at(i-1);
                studentUnits.at(i-1) = studentUnits.at(i);
                studentUnits.at(i) = swap;

                swap = studentID.at(i-1);
                studentID.at(i-1) = studentID.at(i);
                studentID.at(i) = swap;
            }
        }
    }

    for (int i = 0; i < studentCount; i++)
    {
        std::cout << "ID: " << studentID.at(i) << ", Units: " << studentUnits.at(i) << std::endl;
    }

    return 0;
}