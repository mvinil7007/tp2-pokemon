#ifndef CUBO_HPP
#define CUBO_HPP

#include "forma3D.hpp"

class Cubo : public Forma3D {
private:
    double _lado;
    std::string _nome;
    std::string _cor;

public:
    Cubo(double lado, const std::string& nome, const std::string& cor);

    std::string get_nome() const override;
    std::string get_cor() const override;
    double get_volume() const override;
};

#endif