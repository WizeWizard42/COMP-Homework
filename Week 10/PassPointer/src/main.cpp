#include <iostream>

void PassByPointer(int* x, int* y);

void ChangePointer(int*& x, int*& y);

int main(void)
{
    int* x = new int;
    int* y = new int;

    *x = 5;
    *y = 2;

    std::cout << *x << " " << *y << std::endl; 
    PassByPointer(x, y);
    std::cout << *x << " " << *y << std::endl; 
    std::cout << std::endl;

    *x = 5;
    *y = 2;

    std::cout << *x << " " << *y << std::endl; 
    ChangePointer(x, y);
    std::cout << *x << " " << *y << std::endl; 

    return 0;
}

void PassByPointer(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ChangePointer(int*& x, int*& y)
{
    int* temp = x;
    x = y;
    y = temp;
}
