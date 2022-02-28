/*
*   Branches Assignment
*   
*   Calculates total price of hotel stay given:
*   Room price
*   Amount of rooms booked
*   Days booked
*   Sales tax
*
*   Applies discounts based on amount of rooms booked:
*   10+ : 10% off
*   20+ : 20% off
*   30+ : 30% off
*
*   If rooms are booked for 3+ days, 5% off.
*/

#include <iostream>
#include <iomanip>

int main(void)
{
    const double TEN_ROOM_DISCOUNT = 0.10;
    const double TWENTY_ROOM_DISCOUNT = 0.20;
    const double THIRTY_ROOM_DISCOUNT = 0.30;
    const double THREE_DAY_DISCOUNT = 0.05;

    double totalCostPreTax = 0.0;
    double totalCostPostTax = 0.0;
    double totalDiscount = 0.0;
    double finalTax = 0.0;
    
    double roomPrice = 0.0;
    double salesTax = 0.0;
    int daysBooked = 0;
    int roomsBooked = 0;

    // Take user input

    std::cout << "Please enter room price: $" << std::flush;
    std::cin >> roomPrice;

    std::cout << "Please enter number of rooms to book: " << std::flush;
    std::cin >> roomsBooked;

    std::cout << "Please enter duration of stay in days: " << std::flush;
    std::cin >> daysBooked;

    std::cout << "Please enter sales tax (percent): " << std::flush;
    std::cin >> salesTax;
    salesTax /= 100.0; // Convert from percent to decimal

    std::cout << std::endl << std::endl; // Spacing to make it look nicer

    // Calculate price
    totalCostPreTax = roomPrice * roomsBooked * daysBooked;

    // Calculate discount
    if (daysBooked >= 3)
    {
        totalDiscount += THREE_DAY_DISCOUNT;
    }

    if (roomsBooked >= 30)
    {
        totalDiscount += THIRTY_ROOM_DISCOUNT;
    }
    else if (roomsBooked >= 20)
    {
        totalDiscount += TWENTY_ROOM_DISCOUNT;
    }
    else if (roomsBooked >= 10)
    {
        totalDiscount += TEN_ROOM_DISCOUNT;
    }

    // Apply discount
    totalCostPreTax -= totalCostPreTax * totalDiscount;

    // Calculate and apply tax
    finalTax = totalCostPreTax * salesTax;
    totalCostPostTax = totalCostPreTax + finalTax;

    // Display info and final price
    std::cout << std::setprecision(2) << std::fixed; // Make sure prices are being completely printed
    std::cout << "Single Room Price: $" << roomPrice << std::endl;
    std::cout << std::setprecision(6) << std::defaultfloat; // Not these values, back to defaults
    std::cout << "Discount: " << (totalDiscount * 100.0) << "%" << std::endl;
    std::cout << "Rooms Booked: " << roomsBooked << std::endl;
    std::cout << "Days Booked: " << daysBooked << std::endl; 
    std::cout << std::setprecision(2) << std::fixed; // Back to prices
    std::cout << "Total Cost (w/o tax): $" << totalCostPreTax << std::endl;
    std::cout << "Tax: $" << finalTax << std::endl;
    std::cout << "Total Cost (with tax): $" << totalCostPostTax << std::endl;

    return 0;
}