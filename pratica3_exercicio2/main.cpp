#include "horario.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Teste 1: Horario da Tarde (Exemplo 1) ---" << endl;
    Horario h1(13, 35, 15);      // Instanciação do objeto 1
    h1.exibeHorarioUniversal();  // Chamada da função 1
    h1.exibeHorarioPadrao();     // Chamada da função 2

    cout << "\n--- Teste 2: Caso do Meio-dia   ---" << endl;
    Horario h2(12, 0, 0);        // Instanciação do objeto 2
    h2.exibeHorarioUniversal();
    h2.exibeHorarioPadrao();

    cout << "\n--- Teste 3: Caso da Meia-noite ---" << endl;
    Horario h3(0, 5, 9);         // Instanciação do objeto 3
    h3.exibeHorarioUniversal();
    h3.exibeHorarioPadrao();
    
    cout << "\n--- Teste 4: Horario da Manha   ---" << endl;
    Horario h4(8, 15, 30);       // Instanciação do objeto 4
    h4.exibeHorarioUniversal();
    h4.exibeHorarioPadrao();

    return 0;
}
