#include "esfera.hpp"
#include <cmath>

Esfera::Esfera(double raio, const std::string& nome, const std::string& cor)
    : _raio(raio), _nome(nome), _cor(cor) {}

std::string Esfera::get_nome() const {
    return _nome;
}
std::string Esfera::get_cor() const {
    return _cor;
}
double Esfera::get_volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(_raio, 3);
}