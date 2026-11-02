#ifndef QUADRADO_HPP
#define QUADRADO_HPP

#include "forma2D.hpp"

class Quadrado : public Forma2D {
private:
    double _lado;
    std::string _nome;
    std::string _cor;

public:
    Quadrado(double lado, const std::string& nome, const std::string& cor);

    std::string get_nome() const override;
    std::string get_cor() const override;
    double get_area() const override;
    double get_perimetro() const override;
};

#endif