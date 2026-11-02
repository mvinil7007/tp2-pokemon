#ifndef POKEMONFOGO_HPP
#define POKEMONFOGO_HPP

#include "Pokemon.hpp"

class PokemonFogo : public Pokemon {
public:
    PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif