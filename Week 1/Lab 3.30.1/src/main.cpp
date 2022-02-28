#include <iostream>
#include <string>

int main(void)
{
    std::string userString;

    std::cout << "Enter text:" << std::endl;

    std::getline(std::cin, userString);

    std::cout << "You entered: " << userString << std::endl;

    if (userString.find("BFF") != std::string::npos)
    {
        std::cout << "BFF: best friend forever" << std::endl;
    }
    if (userString.find("IDK") != std::string::npos)
    {
        std::cout << "IDK: I don't know" << std::endl;
    }
    if (userString.find("JK") != std::string::npos)
    {
        std::cout << "JK: just kidding" << std::endl;
    }
    if (userString.find("TMI") != std::string::npos)
    {
        std::cout << "TMI: too much information" << std::endl;
    }
    if (userString.find("TTYL") != std::string::npos)
    {
        std::cout << "TTYL: talk to you later" << std::endl;
    }

    return 0;
}