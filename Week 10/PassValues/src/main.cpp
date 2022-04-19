#include <iostream>

void PassByValue(int x, int y);

void PassByReference(int& x, int& y);

int main(void)
{
    int x = 5;
    int y = 2;

    std::cout << x << " " << y << std::endl; 
    PassByValue(x, y);
    std::cout << x << " " << y << std::endl; 
    std::cout << std::endl;

    x = 5;
    y = 2;

    std::cout << x << " " << y << std::endl; 
    PassByReference(x, y);
    std::cout << x << " " << y << std::endl; 

    return 0;
}

void PassByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void PassByReference(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
