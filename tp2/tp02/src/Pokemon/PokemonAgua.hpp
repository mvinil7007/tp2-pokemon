#ifndef POKEMONAGUA_HPP
#define POKEMONAGUA_HPP

#include "Pokemon.hpp"

class PokemonAgua : public Pokemon {
public:
    PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    // Implementação das fraquezas e resistências elementais do tipo Água
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif