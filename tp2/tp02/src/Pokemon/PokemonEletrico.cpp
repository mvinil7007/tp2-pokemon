#include "PokemonEletrico.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

PokemonEletrico::PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "eletrico") {
    
    if (nome == "Pikachu" || idPokemon == 25) {
        definirGolpe(0, new GolpeDano("Choque do Trovao", 12));
        definirGolpe(1, new GolpeReducaoAtaque("Onda de Choque", 5));
    } 
    else if (nome == "Voltorb" || idPokemon == 100) {
        definirGolpe(0, new GolpeDano("Faisca", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Carga", 8));
    } 
    else if (nome == "Magnemite" || idPokemon == 81) {
        definirGolpe(0, new GolpeDano("Raio Trovao", 11));
        definirGolpe(1, new GolpeDano("Canhao Eletronico", 9));
    } 
    else if (nome == "Electabuzz" || idPokemon == 125) {
        definirGolpe(0, new GolpeDano("Soco do Trovao", 14));
        definirGolpe(1, new GolpeReducaoAtaque("Descarga Eletronica", 6));
    } 
    else {
        // Golpe padrao para outros Pokemons Eletricos
        definirGolpe(0, new GolpeDano("Trovao", 11));
        definirGolpe(1, new GolpeReducaoAtaque("Choque", 5));
    }
}

int PokemonEletrico::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;
    if (tipoAtacante == "agua") {
        multiplicador = 0.75;
    }
    return static_cast<int>(std::round(dano * multiplicador));
}