#ifndef GOLPECURA_HPP
#define GOLPECURA_HPP

#include "Golpe.hpp"


class GolpeCura : public Golpe {
private:
    int poder;      
    int quantidade; 

public:
    GolpeCura(std::string nome, int poder, int quantidade);
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif