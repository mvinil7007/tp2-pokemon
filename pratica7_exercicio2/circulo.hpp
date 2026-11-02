#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include "forma2D.hpp"

class Circulo : public Forma2D {
private:
    double _raio;
    std::string _nome;
    std::string _cor;

public:
    Circulo(double raio, const std::string& nome, const std::string& cor);

    std::string get_nome() const override;
    std::string get_cor() const override;
    double get_area() const override;
    double get_perimetro() const override;
};

#endif