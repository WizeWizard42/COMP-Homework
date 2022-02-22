#include <iostream>
using std::cout;
using std::endl;

int main(void)
{

    int colors[3];

    std::cin >> colors[0];
    std::cin >> colors[1];
    std::cin >> colors[2];

    int lowest = colors[0];

    for (const int &color : colors)
    {
        if (color < lowest)
        {
            lowest = color;
        }
    }

    for (int &color : colors)
    {
        color -= lowest;
    }

    cout << colors[0] << " " << colors[1] << " " << colors[2] << endl;

    return 0;
}