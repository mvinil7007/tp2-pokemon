#ifndef POKEMONPLANTA_HPP
#define POKEMONPLANTA_HPP

#include "Pokemon.hpp"

// Subclasse de Pokemon do tipo Planta
class PokemonPlanta : public Pokemon {
public:
    PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif