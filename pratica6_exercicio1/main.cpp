#include <iostream>
#include <iomanip>
#include "savingsaccount.hpp"

int main(void) {
    
    // mostrar sempre 2 casas decimais
    std::cout << std::fixed << std::setprecision(2);

    // Main. Criando duas contas.
    SavingsAccount saver1 = SavingsAccount(2000);
    SavingsAccount saver2 = SavingsAccount(3000);

    // Imprimindo o monthly balance
    std::cout << "Balanço mensal:\n";
    std::cout << saver1.calculateMonthlyInterest() << std::endl;
    std::cout << saver2.calculateMonthlyInterest() << std::endl;
    // Alterando atributo static publico 
    SavingsAccount::_annualInterestRate = 3.00; 

    // Imprimindo o monthly balance. Tem que mudar para as duas classes.
    std::cout << "\nBalanço mensal para Taxa anual de 3%:\n";
    std::cout << saver1.calculateMonthlyInterest() << std::endl;
    std::cout << saver2.calculateMonthlyInterest() << std::endl;
    
    // mudar para 4% 
    SavingsAccount::modifyInterestRate(4.00);
    
    std::cout << "\nApos mudar para 4%:\n";
    std::cout << saver1.calculateMonthlyInterest() << std::endl;
    std::cout << saver2.calculateMonthlyInterest() << std::endl;

    return 0;
}