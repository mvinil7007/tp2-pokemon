#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP

#include "forma2D.hpp"

class Triangulo : public Forma2D {
private:
    double _l1;
    double _l2;
    double _l3_base;
    double _altura;
    std::string _nome;
    std::string _cor;

public:
    // Construtor 1: Escaleno (3 lados diferentes)
    Triangulo(double l1, double l2, double l3_base, double altura, const std::string& nome, const std::string& cor);
    
    // Construtor 2: Isósceles (2 lados iguais)
    Triangulo(double l1_l2, double l3_base, double altura, const std::string& nome, const std::string& cor);
    
    // Construtor 3: Equilátero (3 lados iguais)
    Triangulo(double l1_base, double altura, const std::string& nome, const std::string& cor);

    std::string get_nome() const override;
    std::string get_cor() const override;
    double get_area() const override;
    double get_perimetro() const override;
};

#endif