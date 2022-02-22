/*
*   Write a program that can be used to assign seats for a commercial airplane.
*   The airplane has 13 rows, with six seats in each row.
*   Rows 1 and 2 are first class, rows 3 through 7 are business class, and rows 8 through 13 are economy class.
*
*   User is prompted whether they want to book a seat, then asks for ticket class and coordinates of their desired seat.
*   Input is validated based on ticket class, and seats are booked accordingly.
*/
#include <iostream>
#include <array>
#include <cctype>
#include <string>
#include <algorithm>

const int NUM_ROWS = 13;
const int NUM_COLS = 6;

void readToUpper(std::string& userInput); // Reads line of input, and converts to uppercase.

std::pair<std::array<int, NUM_ROWS>, std::array<std::array<char, NUM_COLS>, NUM_ROWS>> initializeSeatPlan(); // Initializes and returns a seat plan.

void printSeatAssignments(std::pair<std::array<int, NUM_ROWS>, std::array<std::array<char, NUM_COLS>, NUM_ROWS>>& seatPlan); // Prints grid representation of seats, including whether a seat is booked.

void promptUserMenu(std::pair<std::array<int, NUM_ROWS>, std::array<std::array<char, NUM_COLS>, NUM_ROWS>>& seatPlan); // Prompts the user on whether to book a seat, and acts accordingly.

std::pair<int, int> parseSeatLocation(std::string seatLocation); // Parses entered seat coordinates to a more convenient form.

void assignSeat(std::array<std::array<char, NUM_COLS>, NUM_ROWS>& seatGrid, std::string ticketType, std::pair<int, int> seatLocation); // Books entered seat, performing input validation.

bool validateSeat(std::array<std::array<char, NUM_COLS>, NUM_ROWS>& seatGrid, std::string ticketType, std::pair<int, int> seatLocation); // The previously mentioned input validation. Checks whether ticket class is fully booked, input is within bounds, or seat row is appropriate for ticket.

int main(void)
{
    std::pair<std::array<int, NUM_ROWS>, std::array<std::array<char, NUM_COLS>, NUM_ROWS>> seatPlan = initializeSeatPlan();

    promptUserMenu(seatPlan);

    return 0;
}

void readToUpper(std::string& userInput)
{
    std::getline(std::cin, userInput);
    std::for_each(userInput.begin(), userInput.end(),
        [](char& c){c = toupper(c);}); // Lambda functions!

    return;
}

std::pair<std::array<int, NUM_ROWS>, std::array<std::array<char, NUM_COLS>, NUM_ROWS>> initializeSeatPlan()
{
    std::array<int, NUM_ROWS> rowNum;
    std::array<std::array<char, NUM_COLS>, NUM_ROWS> seatGrid;

    for (std::size_t row = 0; row < rowNum.size(); row++)
    {
        rowNum.at(row) = row;
        seatGrid.at(row).fill('*');
    }

    return {rowNum, seatGrid};
}

void printSeatAssignments(std::pair<std::array<int, NUM_ROWS>, std::array<std::array<char, NUM_COLS>, NUM_ROWS>>& seatPlan)
{
    std::array<int, NUM_ROWS> seatRows = seatPlan.first;
    std::array<std::array<char, NUM_COLS>, NUM_ROWS> seatGrid = seatPlan.second;

    std::cout << "     ";
    for (std::size_t col = 0; col < seatGrid.at(0).size(); col++)
    {
        std::cout << "   " << (char)('A' + col);
    }
    std::cout << std::endl;

    for (std::size_t row = 0; row < seatRows.size(); row++)
    {   
        std::cout << "Row " << (row + 1);
        for (std::size_t col = 0; col < seatGrid.at(row).size(); col++)
        {
            if (row >= 9 && col == 0)
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << "   ";
            }
            std::cout << seatGrid.at(row).at(col);
        }

        std::cout << std::endl;
    }

    return;
}

void promptUserMenu(std::pair<std::array<int, NUM_ROWS>, std::array<std::array<char, NUM_COLS>, NUM_ROWS>>& seatPlan)
{
    std::string userInput;
    std::string userTicketType;
    std::string userSeatLocation;

    std::pair<int, int> parsedSeatLocation;

    std::cout << "Welcome, User!" << std::endl;
    std::cout << std::endl;
    while (true)
    {
        printSeatAssignments(seatPlan);

        std::cout << "Reserve A Seat? (y/N): " << std::flush;

        readToUpper(userInput);

        if (userInput != "Y")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        std::cout << "Please enter ticket type. Options are First (F/f), Business (B/b), and Economy (E/e): " << std::flush;
        readToUpper(userTicketType);

        std::cout << "Please enter seat location. Format is \"1-13A-F\": " << std::flush;
        readToUpper(userSeatLocation);

        std::cout << std::endl;

        parsedSeatLocation = parseSeatLocation(userSeatLocation);

        assignSeat(seatPlan.second, userTicketType, parsedSeatLocation);
    }

    return;
}

std::pair<int, int> parseSeatLocation(std::string seatLocation)
{
    std::pair<int, int> parsedLocation;

    if (seatLocation.size() == 2 && isdigit(seatLocation.at(0)) && isalpha(seatLocation.at(1)))
    {
        parsedLocation.first = (seatLocation.at(0) - '0' - 1);
        parsedLocation.second = (seatLocation.at(1) - 'A');
    }
    else if (seatLocation.size() == 3 && isdigit(seatLocation.at(0)) && isdigit(seatLocation.at(1)) && isalpha(seatLocation.at(2)))
    {
        parsedLocation.first = ((((seatLocation.at(0) - '0') * 10) + (seatLocation.at(1) - '0')) - 1); // You don't want to know how long it took to figure this out
        parsedLocation.second = (seatLocation.at(2) - 'A');
    }
    else
    {
        std::cout << "Invalid input. Please enter coordinates in the form \"1-13A-F\"." << std::endl;
        parsedLocation.first = -1;
        parsedLocation.second = -1;
    }
    return parsedLocation;
}

void assignSeat(std::array<std::array<char, NUM_COLS>, NUM_ROWS>& seatGrid, std::string ticketType, std::pair<int, int> seatLocation)
{
    bool isValid = validateSeat(seatGrid, ticketType, seatLocation);

    if (isValid)
    {
        std::cout << "Successfully booked!" << std::endl;
        seatGrid.at(seatLocation.first).at(seatLocation.second) = 'X';
    }

    return;
}

bool validateSeat(std::array<std::array<char, NUM_COLS>, NUM_ROWS>& seatGrid, std::string ticketType, std::pair<int, int> seatLocation)
{
    bool seatFound = false;

    if (ticketType == "F")
    {
        for (int row = 0; row < 2; row++)
        {
            if (std::find(std::begin(seatGrid.at(row)), std::end(seatGrid.at(row)), '*') != std::end(seatGrid.at(row)))
            {
                seatFound = true;
            }
        }
        if (seatLocation.first < 0 || seatLocation.first > 1)
        {
            std::cout << "Invalid row for first-class ticket." << std::endl;
            return false;
        }
    }

    if (ticketType == "B")
    {
        for (int row = 2; row < 7; row++)
        {
            if (std::find(std::begin(seatGrid.at(row)), std::end(seatGrid.at(row)), '*') != std::end(seatGrid.at(row)))
            {
                seatFound = true;
            }
        }
        if (seatLocation.first < 2 || seatLocation.first > 6)
        {
            std::cout << "Invalid row for business-class ticket." << std::endl;
            return false;
        }
    }

    if (ticketType == "E")
    {
        for (int row = 7; row < 13; row++)
        {
            if (std::find(std::begin(seatGrid.at(row)), std::end(seatGrid.at(row)), '*') != std::end(seatGrid.at(row)))
            {
                seatFound = true;
            }
        }
        if (seatLocation.first < 7 || seatLocation.first > 12)
        {
            std::cout << "Invalid row for economy-class ticket." << std::endl;
            return false;
        }
    }

    if (!seatFound)
    {
        std::cout << "Sorry, all seats for your class are booked/you chose an invalid class. Please choose another class." << std::endl;
        return false;
    }

    if (seatLocation.second < 0 || seatLocation.second > 5)
    {
        std::cout << "Out-of-bounds column. Please enter a letter ranging A-F." << std::endl;
        return false;
    }

    if (seatGrid.at(seatLocation.first).at(seatLocation.second) != '*')
    {
        std::cout << "Sorry, this seat is already booked. Please try another." << std::endl;
        return false;
    }

    return true;
}
