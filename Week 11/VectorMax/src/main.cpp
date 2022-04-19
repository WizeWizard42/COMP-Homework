#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{  
    std::vector<int> userVector(5);

    for (int i = 0; i < 5; i++)
    {
        std::cin >> userVector.at(i);
    }

    auto maxValue = std::max_element(userVector.begin(), userVector.end());

    std::cout << "Max value: " << *maxValue << std::endl;

    return 0;
}