#include <iostream>
#include "esfera.hpp"

int main(){

    float area,volume;

    Esfera *esfera = new Esfera(2.75);

    raio = esfera->rRaio();
    std::cout << "Raio: " << raio << std::endl;

    area = esfera->calculaAreaEsfera();
    std::cout << area << std::endl;

    volume = esfera->calculaVolumeEsfera();
    std::cout << volume << std::endl;

    delete esfera;

    return 0;
}