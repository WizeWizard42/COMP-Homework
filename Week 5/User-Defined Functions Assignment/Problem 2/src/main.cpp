/*
 * Calculates the cost of membership and sessions for a fitness center.
 * Prints out a menu, prompts user for relevant information and calculates total price, applying discounts where applicable.
 */
#include <iostream>
#include <string>
#include <algorithm>

// Not global variables!
#define SENIOR_DISCOUNT 0.30
#define YEAR_MEMBER_DISCOUNT 0.15
#define SIX_SESSION_DISCOUNT 0.20

// Reads string and converts to uppercase.
void readToUpper(std::string& userInput);

// Prints main menu.
void printMenu();

// Prompts user for membership info and updates parameters.
void promptPrices(double& membershipPrice, double& sessionPrice, bool& isSenior, int& numSessions, int& numMonths);

// Calculates session and membership discounts based on entered info.
void calculateDiscount(bool isSenior, int numSessions, int numMonths, double& sessionDiscount, double& memberDiscount);

// Calculates total price based on base prices and applied discounts.
double calculateTotal(double membershipPrice, double sessionPrice, int numSessions, int numMonths, double sessionDiscount, double memberDiscount);

int main(void)
{
    double totalPrice = 0.0;
    double sessionDiscount = 0.0;
    double memberDiscount = 0.0;
    double membershipPrice = 0.0;
    double sessionPrice = 0.0;
    bool isSenior = false;
    int numSessions = 0;
    int numMonths = 0;

    printMenu();

    promptPrices(membershipPrice, sessionPrice, isSenior, numSessions, numMonths);

    calculateDiscount(isSenior, numSessions, numMonths, sessionDiscount, memberDiscount);

    totalPrice = calculateTotal(membershipPrice, sessionPrice, numSessions, numMonths, sessionDiscount, memberDiscount);

    std::cout << "The membership cost = $" << totalPrice << std::endl;

    return 0;
}

void readToUpper(std::string& userInput)
{
    std::getline(std::cin, userInput);
    std::for_each(userInput.begin(), userInput.end(),
        [](char& c){c = toupper(c);});

    return;
}

void printMenu()
{
    std::cout << "Welcome to Merlin's \"Get Ripped\" center!" << std::endl;
    std::cout << "This program determines the cost of a new membership." << std::endl;
    std::cout << "If you are a senior citizen, then the discount is 30\% of the regular membership price." << std::endl;
    std::cout << "If you buy membership for twelve months and pay today, the discount is 15%." << std::endl;
    std::cout << "If you buy and pay for 6 or more personal training session today, the discount on each session is 20%." << std::endl;
    return;
}

void promptPrices(double& membershipPrice, double& sessionPrice, bool& isSenior, int& numSessions, int& numMonths)
{
    std::string userInput;

    std::cout << "Enter the cost of a regular membership per month: " << std::flush;
    std::cin >> membershipPrice;
    std::cout << std::endl;

    std::cout << "Enter the cost of one personal training session: " << std::flush;
    std::cin >> sessionPrice;
    std::cout << std::endl;

    std::cin.ignore();
    while (true)
    {
        std::cout << "Are you a senior citizen (Y,y/N,n): " << std::flush;
        readToUpper(userInput);
        std::cout << std::endl;

        if (userInput == "Y")
        {
            isSenior = true;
            break;
        }
        else if (userInput == "N")
        {
            isSenior = false;
            break;
        }

        std::cout << "Invalid input. Please try again." << std::endl;
    }

    std::cout << "Enter the number of personal training sessions bought: " << std::flush;
    std::cin >> numSessions;
    std::cout << std::endl;

    std::cout << "Enter the number of month you are paying for: " << std::flush;
    std::cin >> numMonths;
    std::cout << std::endl;
    
    return;
}

void calculateDiscount(bool isSenior, int numSessions, int numMonths, double& sessionDiscount, double& memberDiscount)
{

    if (isSenior)
    {
        memberDiscount += SENIOR_DISCOUNT;
    }
    if (numSessions >= 6)
    {
        sessionDiscount += SIX_SESSION_DISCOUNT;
    }
    if (numMonths >= 12)
    {
        memberDiscount += YEAR_MEMBER_DISCOUNT;
    }

    return;
}

double calculateTotal(double membershipPrice, double sessionPrice, int numSessions, int numMonths, double sessionDiscount, double memberDiscount)
{
    double totalPrice = 0.0;

    double finalMembershipPrice = membershipPrice - (membershipPrice * memberDiscount);
    double finalSessionPrice = sessionPrice - (sessionPrice * sessionDiscount);

    finalMembershipPrice *= numMonths;
    finalSessionPrice *= numSessions;

    totalPrice += finalMembershipPrice;
    totalPrice += finalSessionPrice;

    return totalPrice;
}
