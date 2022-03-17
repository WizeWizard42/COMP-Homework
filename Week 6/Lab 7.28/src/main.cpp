/*
 * Given two integers as user inputs that represent the number of drinks to buy and the number of bottles to restock.
 * Create a VendingMachine object that performs the following operations:
 * 
 * Purchases input number of drinks
 * Restocks input number of bottles
 * Reports inventory
 */
#include <iostream>

#include "include/VendingMachine.h"

int main(void)
{
    VendingMachine sodaMachine;

    int bottlesToBuy;
    int bottlesToStock;

    std::cin >> bottlesToBuy;
    std::cin >> bottlesToStock;

    sodaMachine.Purchase(bottlesToBuy);
    sodaMachine.Restock(bottlesToStock);
    sodaMachine.Report();

    return 0;
}
