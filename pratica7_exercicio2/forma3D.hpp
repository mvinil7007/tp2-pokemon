// interface
#ifndef FORMA3D_HPP
#define FORMA3D_HPP

#include "forma.hpp"

class Forma3D : public Forma {
public:
    virtual double get_volume() const = 0;
};

#endif