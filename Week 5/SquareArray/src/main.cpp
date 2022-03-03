/*
*   Take in an array of five elements.
*   Pass that array to a void function that squares every value in the array.
*   Print array in main.
*/
#include <iostream>
#include <vector>
#include <algorithm>

const int VECTOR_LENGTH = 5;

void squareArray(std::vector<int>& userArray);

int main(void)
{
    std::vector<int> userArray(VECTOR_LENGTH);

    for (int i = 0; i < VECTOR_LENGTH; i++)
    {
        std::cin >> userArray.at(i);
    }

    squareArray(userArray);

    std::for_each(userArray.begin(), userArray.end(),
    [](int v){
        std::cout << v << std::endl;
    });

    return 0;
}

void squareArray(std::vector<int>& userArray)
{
    std::for_each(userArray.begin(), userArray.end(),
    [](int& v){
        v *= v;
    });
    return;
}
