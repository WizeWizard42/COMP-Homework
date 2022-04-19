#include <iostream>

int main(void)
{
    int x = 10;

    int* xptr = &x;

    std::cout << xptr << std::endl;
    std::cout << *xptr << std::endl;

    return 0;
}
