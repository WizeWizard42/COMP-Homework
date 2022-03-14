/*
*   This program contains a function for computing any nth number in the Fibonacci sequence.
*   Inputs less than zero return -1.
*   An input of 0 returns 0. The sequence starts with 0, 1.
*/
#include <iostream>

using namespace std; // Required for test harness

// Returns nth number in the Fibonacci sequence.
int Fibonacci(int n);

int main() {
   int startNum;
      
   cin >> startNum;
   cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;

   return 0;
}

int Fibonacci(int n)
{
    int lastNum = 0;
    int currNum = 1;
    int swap;

    if (n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1)
    {
        return lastNum;
    }
    if (n == 2)
    {
        return currNum;
    }

    for (int i = 1; i < n; i++)
    {
        swap = lastNum;
        lastNum = currNum;
        currNum = lastNum + swap;
    }

    return currNum;
}
