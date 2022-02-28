#include <iostream>

int main(void)
{
    int x = 0;
    int y = 0;

    while (x < 5)
    {
        std::cout << ++x << std::endl;
    }
    std::cout << std::endl;
    while (y < 5)
    {
        std::cout << y++ << std::endl;
    }

    return 0;
}