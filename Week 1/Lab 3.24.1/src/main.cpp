#include <iostream>

bool isPrimaryHighway(const int &highwayNumber);
bool isAuxiliaryHighway(const int &highwayNumber);

int main() {
    int highwayNumber;
   
    std::cin >> highwayNumber;

    bool isEven = ((highwayNumber % 2) == 0) ? true : false;

    if (isPrimaryHighway(highwayNumber))
    {
        std::cout << "I-" << highwayNumber << " is primary, going ";

        if (isEven)
        {
            std::cout << "east/west.";
        }
        else
        {
            std::cout << "north/south.";
        }
    }
    else if (isAuxiliaryHighway(highwayNumber))
    {
        std::cout << "I-" << highwayNumber << " is auxiliary, serving I-"
            << (highwayNumber % 100)
            << ", going ";

        if (isEven)
        {
            std::cout << "east/west.";
        }
        else
        {
            std::cout << "north/south.";
        }
    }
    else
    {
        std::cout << highwayNumber << " is not a valid interstate highway number.";
    }

    std::cout << std::endl;

    return 0;
}


bool isPrimaryHighway(const int &highwayNumber)
{
    if ((highwayNumber >= 1) && (highwayNumber <= 99))
    {
        return true;
    }
    return false;
}

bool isAuxiliaryHighway(const int &highwayNumber)
{
    if ((highwayNumber >= 100) && (highwayNumber <= 999) && isPrimaryHighway(highwayNumber % 100))
    {
        return true;
    }
    return false;
}