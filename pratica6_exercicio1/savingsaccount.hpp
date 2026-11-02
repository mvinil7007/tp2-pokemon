#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

class SavingsAccount {
private:
    double _savingsBalance;

public:
    static double _annualInterestRate;

    SavingsAccount(double balance = 0.0);
    ~SavingsAccount();

    double calculateMonthlyInterest();
    static void modifyInterestRate(double newRate);
};

#endif