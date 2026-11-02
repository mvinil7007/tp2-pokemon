#ifndef GOLPEREDUCAOATAQUE_HPP
#define GOLPEREDUCAOATAQUE_HPP

#include "Golpe.hpp"

// subclasse de Golpe que aplica dano e reduz o atributo de ataque do alvo.
class GolpeReducaoAtaque : public Golpe {
private:
    int poder;

public:
    GolpeReducaoAtaque(std::string nome, int poder);
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif