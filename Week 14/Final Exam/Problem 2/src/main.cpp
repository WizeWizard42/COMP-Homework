#include <iostream>

using namespace std;

// Takes pointer to array and size of pointer, returns pointer to array one element larger and elements shifted to the right. Index 0 is set to 0.
int* extendArray(const int* const arr, const int size);

// Demonstration of extendArray, user can input array of any size
int main(void)
{
    int userSize;

    cout << "Enter number of elements: " << flush;
    cin >> userSize;

    int* arr = new int[userSize];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < userSize; i++)
    {
        cin >> arr[i];
    }

    int* newArr = extendArray(arr, userSize);

    cout << "New array elements: ";
    for (int i = 0; i < userSize + 1; i++)
    {
        cout << newArr[i] << ", ";
    }
    cout << endl;
}

int* extendArray(const int* const arr, const int size)
{
    int* ret = new int[size + 1];

    ret[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        ret[i] = arr[i - 1];
    }
    return ret;
}
