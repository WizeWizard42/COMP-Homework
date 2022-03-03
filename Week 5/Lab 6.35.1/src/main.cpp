/*
*   Write a program that reads a list of integers, and outputs whether the list contains all multiples of 10, no multiples of 10, or mixed values.
*   Define a function named IsVectorMult10 that takes a vector as a parameter, representing the list, and returns a boolean that represents whether the list contains all multiples of ten.
*   Define a function named IsVectorNoMult10 that takes a vector as a parameter, representing the list, and returns a boolean that represents whether the list contains no multiples of ten.
*   Then, write a main program that takes an integer, representing the size of the list, followed by the list values.
*   The first integer is not in the list. 
*/
#include <iostream>
#include <vector>

using namespace std; // Required for assignment's test harness

bool IsVectorMult10(vector<int> myVec); // True if all elements are multiples of 10, false otherwise.

bool IsVectorNoMult10(vector<int> myVec); // True if zero elements are multiples of 10, false otherwise.

int main(void)
{
    int vectorSize;
    
    cin >> vectorSize;
    vector<int> myVec(vectorSize);

    for (int i = 0; i < vectorSize; i++)
    {
        cin >> myVec.at(i);
    }

    bool isMult10 = IsVectorMult10(myVec);
    bool isNotMult10 = IsVectorNoMult10(myVec);

    if (isMult10)
    {
        cout << "all multiples of 10" << endl;
    }
    else if (!isMult10 && !isNotMult10)
    {
        cout << "mixed values" << endl;
    }
    else
    {
        cout << "no multiples of 10" << endl;
    }

    return 0;
}

bool IsVectorMult10(vector<int> myVec)
{
    for (size_t i = 0; i < myVec.size(); i++)
    {
        if (myVec.at(i) % 10 != 0)
        {
            return false;
        }
    }

    return true;
}

bool IsVectorNoMult10(vector<int> myVec)
{
    for (size_t i = 0; i < myVec.size(); i++)
    {
        if (myVec.at(i) % 10 == 0)
        {
            return false;
        }
    }

    return true;
}
