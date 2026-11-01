#ifndef GOLPE_HPP
#define GOLPE_HPP

#include <string>

class Pokemon;

class Golpe {
protected:
    std::string nome;
    int poder;
    
    // Metodo que calcula o dano respeitando as regras de tipo de ataque e alvo
    int calcularDano(Pokemon& atacante, Pokemon& alvo, int poder);

public:
    Golpe(std::string nome, int poder = 0);
    virtual ~Golpe();

    std::string getNome();
    int getPoder();
    // Metodo abstrato para aplicar o golpe 
    virtual std::string aplicar(Pokemon& atacante, Pokemon& alvo) = 0;
};

#endif