#include <iostream>
#include "contabancaria.hpp"

int main() {

    double valor;
    ContaBancaria conta(" Maria Silva ", 12345, 1000.0);
    
    conta.exibirInformacoes();
    
    std::cin >> valor;
    conta.depositar(valor);
    conta.exibirInformacoes();
    
    if (conta.sacar(valor)) {
        std::cout << " Saque realizado .\n";
    }
    else {
        std::cout << " Saldo insuficiente .\n";
        conta.exibirInformacoes();
    }

    return 0;
}