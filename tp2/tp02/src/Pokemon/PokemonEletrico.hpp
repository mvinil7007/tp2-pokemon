#ifndef POKEMONELETRICO_HPP
#define POKEMONELETRICO_HPP

#include "Pokemon.hpp"

class PokemonEletrico : public Pokemon {
public:
    PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif