#include <iostream>

using std::cout;
using std::endl;

bool arrayIsSame (int len, int* arr);

int main(void)
{
    int modelEntries[3][2];
    char* modelNames[3] = {"colonial", "single-story", "split-entry"};
    int modelPerSqFt[3];

    cout << "Colonial base price: " << std::flush;
    std::cin >> modelEntries[0][0];
    cout << "Colonial square feet: " << std::flush;
    std::cin >> modelEntries[0][1];

    cout << "Single-story base price: " << std::flush;
    std::cin >> modelEntries[1][0];
    cout << "Single-story square feet: " << std::flush;
    std::cin >> modelEntries[1][1];

    cout << "Split-entry base price: " << std::flush;
    std::cin >> modelEntries[2][0];
    cout << "Split-entry square feet: " << std::flush;
    std::cin >> modelEntries[2][1];

    int lowest = 0;
    int nextLowest = 1;

    for (int i = 0; i < 3; i++)
    {
        modelPerSqFt[i] = modelEntries[i][0] / modelEntries[i][1];
    }

    for (int i = 1; i < 3; i++)
    {
        if (modelPerSqFt[i] < modelPerSqFt[lowest])
        {
            nextLowest = lowest;
            lowest = i;
        }
        else if (modelPerSqFt[i] < modelPerSqFt[nextLowest])
        {
            nextLowest = i;
        }
    }

    if (arrayIsSame(3, modelPerSqFt))
    {
        cout << "The price per square foot of all three models are the same." << endl;
    }

    else if (modelPerSqFt[lowest] == modelPerSqFt[nextLowest])
    {
        cout << "The price per square foot of the " << 
        modelNames[lowest] << " and " << 
        modelNames[nextLowest] << " models tie for the least." << endl;
    }

    else
    {
        cout << "The price per square foot of the " <<
        modelNames[lowest] << " model is the least." << endl;
    }

    return 0;
}

bool arrayIsSame (int len, int* arr)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] != arr[i+1])
        {
            return false;
        }
    }
    return true;
}
