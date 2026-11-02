#include <iostream>

int main() {
    long int value1 = 100000;
    long int value2 = 0;
    // insira seu codigo aqui ...

    // a)
    long *longPtr;
    // b)
    longPtr = &value1;
    // c)
    std::cout << *longPtr << std::endl;
    // d)
    value2 = *longPtr;
    // e)
    std::cout << value2 << std::endl;
    // f)
    std::cout << &value1 << std::endl;
    // g)
    std::cout << longPtr << std::endl;
    // insira aqui a resposta para o item (g) ...
    // Sim, o valor impresso é exatamente o mesmo. Isso acontece 
    // porque longPtr guarda a localização de memória de value1 (&value1), então 
    // imprimir longPtr e &value1 gera a mesma saída.
    return 0;
}
//g++ pratica1-exercicio1.cpp -o pratica1-exercicio1 && ./pratica1-exercicio1
