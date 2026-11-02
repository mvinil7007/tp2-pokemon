#include <iostream>
#include "esfera.hpp"

Esfera::Esfera(float _r){
    _raio = _r;
}

Esfera::~Esfera(*ptr){
    // Destrutor vazio, pois não há alocação dinâmica dentro da struct
}

float Esfera::rRaio(){
    return _raio;
}

float Esfera::calculaAreaEsfera(){
    return 4.0*3.1415*rRaio()*rRaio();
}

float Esfera::calculaVolumeEsfera(){
    return (4.0/3.0)*3.1415*rRaio()*rRaio()*rRaio();
}

