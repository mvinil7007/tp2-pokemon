#include <iostream>
#include "contador.h" // importar o modulo criado

// Implementação do construtor
Contador::Contador(int v) {
    valor = v;
    // v é atribuido em valor, o qual é um dado da struct Contador
}

// Implementação do método incrementar
void Contador::incrementar() {
    valor++;
}

// Implementação do método decrementar
void Contador::decrementar() {
    if (valor > 0)
        valor--;
}

// Implementação do método imprimirValor
void Contador::imprimirValor() {
    std::cout << valor << std::endl;
}

// Implementação do método resetarValor
void Contador::resetarValor() {
    valor = 0;
}