/*
*   Define a function named SortVector that takes a vector of integers as a parameter.
*   Function SortVector() modifies the vector parameter by sorting the elements in descending order (highest to lowest).
*   Then write a main program that reads a list of integers from input, stores the integers in a vector, calls SortVector(), and outputs the sorted vector.
*   The first input integer indicates how many numbers are in the list. 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // Required for assignment's test harness

void SortVector(vector<int>& myVec);

int main(void)
{
    int vectorSize;

    cin >> vectorSize;
    vector<int> myVec(vectorSize);;

    for (int i = 0; i < vectorSize; i++)
    {
        cin >> myVec.at(i);
    }

    SortVector(myVec);

    for (int i = 0; i < vectorSize; i++)
    {
        cout << myVec.at(i) << ",";
    }
    cout << endl;

    return 0;
}

void SortVector(vector<int>& myVec)
{
    sort(myVec.begin(), myVec.end());
    reverse(myVec.begin(), myVec.end());
    return;
}
