#include "cubo.hpp"
#include <cmath>

Cubo::Cubo(double lado, const std::string& nome, const std::string& cor)
    : _lado(lado), _nome(nome), _cor(cor) {

}

std::string Cubo::get_nome() const {
    return _nome;
}

std::string Cubo::get_cor() const {
    return _cor;
}

double Cubo::get_volume() const {
    return std::pow(_lado, 3);
}