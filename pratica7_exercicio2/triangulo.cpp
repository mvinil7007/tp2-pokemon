#include "triangulo.hpp"

// Escaleno
Triangulo::Triangulo(double l1, double l2, double l3_base, double altura, const std::string& nome, const std::string& cor)
    : _l1(l1), _l2(l2), _l3_base(l3_base), _altura(altura), _nome(nome), _cor(cor) {}

// Isósceles (l1 e l2 são iguais)
Triangulo::Triangulo(double l1_l2, double l3_base, double altura, const std::string& nome, const std::string& cor)
    : _l1(l1_l2), _l2(l1_l2), _l3_base(l3_base), _altura(altura), _nome(nome), _cor(cor) {}

// Equilátero (todos os lados são iguais)
Triangulo::Triangulo(double l1_base, double altura, const std::string& nome, const std::string& cor)
    : _l1(l1_base), _l2(l1_base), _l3_base(l1_base), _altura(altura), _nome(nome), _cor(cor) {}

std::string Triangulo::get_nome() const { 
    return _nome;
}

std::string Triangulo::get_cor() const { 
    return _cor;
}

double Triangulo::get_area() const { 
    return (_l3_base * _altura) / 2.0;
}

double Triangulo::get_perimetro() const { 
    return _l1 + _l2 + _l3_base;
}