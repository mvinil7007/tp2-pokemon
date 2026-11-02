#include "PokemonEletrico.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

PokemonEletrico::PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "eletrico") {
    
    if (nome == "Pikachu" || idPokemon == 25) {
        definirGolpe(0, new GolpeDano("Choque do Trovão", 12));
        definirGolpe(1, new GolpeReducaoAtaque("Onda de Choque", 5));
    } 
    else if (nome == "Voltorb" || idPokemon == 100) {
        definirGolpe(0, new GolpeDano("Faísca", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Carga", 8));
    } 
    else if (nome == "Magnemite" || idPokemon == 81) {
        definirGolpe(0, new GolpeDano("Raio Trovão", 11));
        definirGolpe(1, new GolpeDano("Canhão Eletrônico", 9));
    } 
    else if (nome == "Electabuzz" || idPokemon == 125) {
        definirGolpe(0, new GolpeDano("Soco do Trovão", 14));
        definirGolpe(1, new GolpeReducaoAtaque("Descarga Elétrica", 6));
    } 
    else {
        // Golpe padrão para outros Pokémons do tipo Elétrico
        definirGolpe(0, new GolpeDano("Trovão", 11));
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