#include "PokemonPlanta.hpp"
#include <algorithm>
#include <cmath>

PokemonPlanta::PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "planta") {}

int PokemonPlanta::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;
    if (tipoAtacante == "fogo") {
        multiplicador = 1.25;
    } else if (tipoAtacante == "agua") {
        multiplicador = 0.75;
    }
    return static_cast<int>(std::round(dano * multiplicador));
}