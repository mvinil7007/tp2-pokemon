#ifndef GOLPEREDUCAOATAQUE_HPP
#define GOLPEREDUCAOATAQUE_HPP

#include "Golpe.hpp"


class GolpeReducaoAtaque : public Golpe {
private:
    int poder;

public:
    GolpeReducaoAtaque(std::string nome, int poder);
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif