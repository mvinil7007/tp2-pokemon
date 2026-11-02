#ifndef ESFERA_HPP
#define ESFERA_HPP

#include "forma3D.hpp"

class Esfera : public Forma3D {
private:
    double _raio;
    std::string _nome;
    std::string _cor;

public:
    Esfera(double raio, const std::string& nome, const std::string& cor);

    std::string get_nome() const override;
    std::string get_cor() const override;
    double get_volume() const override;
};

#endif