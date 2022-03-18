#include <iostream>
#include <string>

#include "include/BankAccount.h" // Header file is in "include" subdirectory

BankAccount::BankAccount(const std::string& newName, const double amt1, const double amt2)
{
    customerName = newName;
    checkingBalance = amt1;
    savingsBalance = amt2;
}

std::string BankAccount::GetName() const
{
    return customerName;
}
void BankAccount::SetName(const std::string& newName)
{
    customerName = newName;
}

double BankAccount::GetChecking() const
{
    return checkingBalance;
}
void BankAccount::SetChecking(const double amt)
{
    checkingBalance = amt;
}

double BankAccount::GetSavings() const
{
    return savingsBalance;
}
void BankAccount::SetSavings(const double amt)
{
    savingsBalance = amt;
}

void BankAccount::DepositChecking(const double amt)
{
    if (amt <= 0)
    {
        std::cout << "Error: Amount entered is not positive." << std::endl;
        return;
    }
    SetChecking(GetChecking() + amt);
}
void BankAccount::DepositSavings(const double amt)
{
    if (amt <= 0)
    {
        std::cout << "Error: Amount entered is not positive." << std::endl;
        return;
    }
    SetSavings(GetSavings() + amt);
}

void BankAccount::WithdrawChecking(const double amt)
{
    if (amt <= 0)
    {
        std::cout << "Error: Amount entered is not positive." << std::endl;
        return;
    }
    SetChecking(GetChecking() - amt);
}
void BankAccount::WithdrawSavings(const double amt)
{
    if (amt <= 0)
    {
        std::cout << "Error: Amount entered is not positive." << std::endl;
        return;
    }
    SetSavings(GetSavings() - amt);
}

void BankAccount::TransferToSavings(const double amt)
{
    if (amt <= 0)
    {
        std::cout << "Error: Amount entered is not positive." << std::endl;
        return;
    }
    SetChecking(GetChecking() - amt);
    SetSavings(GetSavings() + amt);
}
