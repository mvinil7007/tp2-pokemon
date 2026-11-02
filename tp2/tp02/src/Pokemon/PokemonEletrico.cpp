#include "PokemonEletrico.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include <algorithm>
#include <cmath>

PokemonEletrico::PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "eletrico") {
    definirGolpe(0, new GolpeDano("Choque do Trovao", 12));
    definirGolpe(1, new GolpeReducaoAtaque("Onda de Choque", 6));
}

int PokemonEletrico::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;
    if (tipoAtacante == "agua")
        mult = 0.5;

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}