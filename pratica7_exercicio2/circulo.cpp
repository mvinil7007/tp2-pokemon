#include "circulo.hpp"
#include <cmath>

Circulo::Circulo(double raio, const std::string& nome, const std::string& cor)
    : _raio(raio), _nome(nome), _cor(cor) {}

std::string Circulo::get_nome() const { 
    return _nome;
}

std::string Circulo::get_cor() const { 
    return _cor;
}

double Circulo::get_area() const { 
    return M_PI * _raio * _raio; 
}

double Circulo::get_perimetro() const { 
    return 2 * M_PI * _raio; 
}