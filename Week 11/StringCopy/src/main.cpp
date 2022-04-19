#include <iostream>
#include <cstring>
#include <string>

char* stringcopy(char* dest, const char* source);

int main(void)
{
    char source[] = "HelloWorld";
    char dest[] = "test";

    stringcopy(dest, source);

    std::cout << dest << std::endl;

    return 0;
}

char* stringcopy(char* dest, const char* source)
{
    int destLen = strlen(dest);
    int sourceLen = strlen(source);

    if (destLen < sourceLen)
    {
        dest = new char[sourceLen];
    }

    int i = 0;
    for (i = 0; i < sourceLen; i++)
    {
        dest[i] = source[i];
    }
    dest[i] = '\0';

    return dest;
}
