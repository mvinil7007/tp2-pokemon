#include "PokemonAgua.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

PokemonAgua::PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "agua") {
    
    if (nome == "Squirtle" || idPokemon == 7) {
        definirGolpe(0, new GolpeDano("Jacto de Agua", 11));
        definirGolpe(1, new GolpeReducaoAtaque("Bolhas", 6));
    } 
    else if (nome == "Psyduck" || idPokemon == 54) {
        definirGolpe(0, new GolpeDano("Pistola de Agua", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Confusao", 7));
    } 
    else if (nome == "Poliwag" || idPokemon == 60) {
        definirGolpe(0, new GolpeDano("Pulso de Agua", 11));
        definirGolpe(1, new GolpeCura("Recuperacao de Agua", 4, 8));
    } 
    else {
        // Golpe padrao para outros Pokemons de Agua
        definirGolpe(0, new GolpeDano("Jacto de Agua", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Bolhas", 5));
    }
}

int PokemonAgua::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;
    if (tipoAtacante == "fogo") {
        multiplicador = 0.5;
    } else if (tipoAtacante == "eletrico") {
        multiplicador = 1.5;
    }
    return static_cast<int>(std::round(dano * multiplicador));
}