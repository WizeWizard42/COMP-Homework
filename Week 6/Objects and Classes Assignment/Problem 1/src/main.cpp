/*
 * This program defines and implements a BankAccount class. 
 * This class stores a user's money in separate savings and checking accounts.
 * Users can withdraw and deposit from both accounts, as well as directly set the balance of either account.
 */
#include <iostream>
#include <string>

#include "include/BankAccount.h" // Header file is in "include" subdirectory

int main(void)
{
    std::string userName = "Merlin Newcomb";
    double checkingBalance = 500.0;
    double savingsBalance = 1000.0;

    BankAccount account(userName, checkingBalance, savingsBalance);

    std::cout << "Your name: " << account.GetName() << std::endl;
    std::cout << "Your checking balance: $" << account.GetChecking() << std::endl;
    std::cout << "Your savings balance: $" << account.GetSavings() << std::endl;

    // Unit tests
    BankAccount workingAccount = account;

    // DepositChecking/WithdrawChecking and DepositSavings/WithdrawSavings do literally the same thing, so no real need to test both
    workingAccount.DepositChecking(125.0);
    if (workingAccount.GetChecking() != 625.0)
    {
        std::cout << "DepositChecking(125.0) Failed. Expected 625, got: " << workingAccount.GetChecking() << std::endl;
    }

    workingAccount.DepositChecking(-0.27);
    if (workingAccount.GetChecking() != 625.0)
    {
        std::cout << "DepositChecking(-0.27) Failed. Expected 625, got: " << workingAccount.GetChecking() << std::endl;
    }

    workingAccount.SetChecking(-97.24);
    if (workingAccount.GetChecking() != -97.24)
    {
        std::cout << "SetChecking(-97.24) Failed. Expected -97.24, got: " << workingAccount.GetChecking() << std::endl;
    }

    workingAccount.DepositChecking(997.24);
    if (workingAccount.GetChecking() != 900.0)
    {
        std::cout << "DepositChecking(997.24) Failed. Expected 900, got: " << workingAccount.GetChecking() << std::endl;
    }

    workingAccount.WithdrawChecking(50.0);
    if (workingAccount.GetChecking() != 850.0)
    {
        std::cout << "WithdrawChecking(50.0) Failed. Expected 850, got: " << workingAccount.GetChecking() << std::endl;
    }

    workingAccount.WithdrawChecking(0.0);
    if (workingAccount.GetChecking() != 850.0)
    {
        std::cout << "WithdrawChecking(0.0) Failed. Expected 850, got: " << workingAccount.GetChecking() << std::endl;
    }

    workingAccount.TransferToSavings(125.0);
    if (workingAccount.GetChecking() != 725.0 && workingAccount.GetSavings() != 1125.0)
    {
        std::cout << "TransferToSavings(125.0) Failed. Expected 725 and 1125, got "
        << workingAccount.GetChecking() << " and " << workingAccount.GetSavings() << std::endl;
    }

    workingAccount.TransferToSavings(-9999.0);
    if (workingAccount.GetChecking() != 725.0 && workingAccount.GetSavings() != 1125.0)
    {
        std::cout << "TransferToSavings(-9999.0) Failed. Expected 725 and 1125, got "
        << workingAccount.GetChecking() << " and " << workingAccount.GetSavings() << std::endl;
    }

    workingAccount.SetSavings(542.91);
    if (workingAccount.GetSavings() != 542.91)
    {
        std::cout << "SetSavings(542.91) Failed. Expected 542.91, got: " << workingAccount.GetSavings() << std::endl;
    }
}