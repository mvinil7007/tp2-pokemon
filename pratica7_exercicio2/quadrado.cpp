#include "quadrado.hpp"

Quadrado::Quadrado(double lado, const std::string& nome, const std::string& cor)
    : _lado(lado), _nome(nome), _cor(cor) {}

std::string Quadrado::get_nome() const { 
    return _nome;
}

std::string Quadrado::get_cor() const {
    return _cor;
}

double Quadrado::get_area() const {
    return _lado * _lado;
}

double Quadrado::get_perimetro() const {
    return 4 * _lado;
}