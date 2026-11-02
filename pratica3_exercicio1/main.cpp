// main.cpp tem apenas a função principal 
// importamos o modulo "contador.h" com as funções

#include <iostream>
#include "contador.h"

using namespace std;

int main() {
    cout << "--- Iniciando o Contador ---" << endl;
    Contador c(1); // Instanciação com valor inicial 1
    
    c.incrementar();
    cout << "Apos incrementar: ";
    c.imprimirValor();
    
    c.resetarValor();
    cout << "Apos resetar    : ";
    c.imprimirValor();
    
    c.decrementar();
    cout << "Apos decrementar: ";
    c.imprimirValor();

    return 0;
}