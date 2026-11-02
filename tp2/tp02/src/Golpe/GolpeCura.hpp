#ifndef GOLPECURA_HPP
#define GOLPECURA_HPP

#include "Golpe.hpp"

// Subclasse de Golpe que causa dano ao alvo e drena/recupera vida para o atacante.
class GolpeCura : public Golpe {
private:
    int poder;      
    int quantidade; 

public:
    GolpeCura(std::string nome, int poder, int quantidade);
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif