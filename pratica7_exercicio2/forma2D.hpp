// interface
#ifndef FORMA2D_HPP
#define FORMA2D_HPP

#include "forma.hpp"

class Forma2D : public Forma {
public:
    virtual double get_area() const = 0;
    virtual double get_perimetro() const = 0;
};

#endif 