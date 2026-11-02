#include "savingsaccount.hpp"

// Inicialização do membro estático
double SavingsAccount::_annualInterestRate = 0.0;

SavingsAccount::SavingsAccount(double balance) {
    _savingsBalance = balance;
}

SavingsAccount::~SavingsAccount() {
    //...vazio...
}

double SavingsAccount::calculateMonthlyInterest() {
    double monthlyInterest = (_savingsBalance * (_annualInterestRate/100.0)) / 12;
    _savingsBalance += monthlyInterest;
    return _savingsBalance; 
}

void SavingsAccount::modifyInterestRate(double newRate) {
    _annualInterestRate = newRate;
}