#include "data.h"

int main() {
    // Instanciação do objeto 1
    Data d1(13, 12, 2021);
    d1.exibirDataFormatoNumero();
    d1.exibirDataPorExtenso();
    d1.obterDataEmSegundos();
    
    // Instanciação do objeto 2
    Data d2(11, 9, 2026);
    d2.exibirDataFormatoNumero();
    d2.exibirDataPorExtenso();
    d2.obterDataEmSegundos();

    return 0;
}