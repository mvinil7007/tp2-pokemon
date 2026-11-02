#include "aquecedor.hpp"

Aquecedor::Aquecedor() {
    _temperatura = 20.0;
}

Aquecedor::~Aquecedor() {
}

void Aquecedor::aquecer() {
    _temperatura += 5.0;
}

void Aquecedor::esfriar() {
    _temperatura -= 5.0;
}

double Aquecedor::getTemperatura() {
    return _temperatura;
}