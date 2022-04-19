#include <iostream>

int main(void)
{
    int x = 10;
    int* xptr = &x;

    std::cout << x << std::endl;
    *xptr = 42;
    std::cout << x << std::endl;

    return 0;
}
