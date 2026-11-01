#ifndef GOLPEDANO_HPP
#define GOLPEDANO_HPP

#include "Golpe.hpp"

class GolpeDano : public Golpe {
private:
    int poder; 
public:
    GolpeDano(std::string nome, int poder);
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif