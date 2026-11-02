#include "PokemonAgua.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

PokemonAgua::PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "agua") {
    // Alocação dinâmica de golpes específicos e polimórficos de acordo com o Pokémon instanciado
    if (nome == "Squirtle" || idPokemon == 7) {
        definirGolpe(0, new GolpeDano("Jato de Água", 11));
        definirGolpe(1, new GolpeReducaoAtaque("Bolhas", 6));
    } 
    else if (nome == "Psyduck" || idPokemon == 54) {
        definirGolpe(0, new GolpeDano("Pistola de Água", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Confusão", 7));
    } 
    else if (nome == "Poliwag" || idPokemon == 60) {
        definirGolpe(0, new GolpeDano("Pulso de Água", 11));
        definirGolpe(1, new GolpeCura("Recuperação de Água", 4, 8));
    } 
    else {
        // Golpe padrão para outros Pokémons do tipo Água
        definirGolpe(0, new GolpeDano("Jato de Água", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Bolhas", 5));
    }
}

// Regra elemental: resistente a Fogo (0.5x) e vulnerável a Elétrico (1.5x)
int PokemonAgua::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;
    if (tipoAtacante == "fogo") {
        multiplicador = 0.5;
    } else if (tipoAtacante == "eletrico") {
        multiplicador = 1.5;
    }
    return static_cast<int>(std::round(dano * multiplicador));
}