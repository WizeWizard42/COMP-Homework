#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
   char* userStr = new char[27];

   for (int i = 0; i < 26; i++)
   {
      userStr[i] = 'A' + i;
   }
   userStr[26] = '\0';

   cout << userStr << endl;

   return 0;
}
