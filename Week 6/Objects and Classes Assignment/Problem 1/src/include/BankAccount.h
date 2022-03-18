#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount
{
    public:
        BankAccount(const std::string& newName, const double amt1, const double amt2);

        std::string GetName() const;
        void SetName(const std::string& newName);

        double GetChecking() const;
        void SetChecking(const double amt);

        double GetSavings() const;
        void SetSavings(const double amt);

        // Deposits to your checking or savings account as long as passed amount is positive.
        void DepositChecking(const double amt);
        void DepositSavings(const double amt);

        // Withdraws from your checking or savings account as long as passed amount is positive.
        void WithdrawChecking(const double amt);
        void WithdrawSavings(const double amt);
        
        // Transfers from your checking to your savings account as long as passed amount is positive.
        void TransferToSavings(const double amt);

    private:
        std::string customerName;
        double savingsBalance;
        double checkingBalance;
};

#endif // BANK_ACCOUNT_H