#include "PokemonPlanta.hpp"
#include "GolpeDano.hpp"
#include "GolpeCura.hpp"
#include "GolpeReducaoAtaque.hpp"
#include <algorithm>
#include <cmath>

PokemonPlanta::PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "planta") {
    
    if (nome == "Bulbasaur" || idPokemon == 1) {
        definirGolpe(0, new GolpeDano("Chicote de Cipo", 10));
        definirGolpe(1, new GolpeCura("Semente de Vampiro", 4, 8));
    } 
    else if (nome == "Oddish" || idPokemon == 43) {
        definirGolpe(0, new GolpeDano("Folha Navalha", 11));
        definirGolpe(1, new GolpeCura("Absorcao", 5, 10));
    } 
    else if (nome == "Bellsprout" || idPokemon == 69) {
        definirGolpe(0, new GolpeDano("Chicote de Cipo", 12));
        definirGolpe(1, new GolpeReducaoAtaque("Po de Sono", 5));
    } 
    else {
        // Golpes padrao para outros Pokemons do tipo Planta
        definirGolpe(0, new GolpeDano("Folha Navalha", 10));
        definirGolpe(1, new GolpeCura("Absorcao", 5, 8));
    }
}

int PokemonPlanta::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;
    if (tipoAtacante == "fogo") {
        multiplicador = 1.25;
    } else if (tipoAtacante == "agua") {
        multiplicador = 0.75;
    }
    return static_cast<int>(std::round(dano * multiplicador));
}