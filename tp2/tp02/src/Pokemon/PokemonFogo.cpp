#include "PokemonFogo.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>
#include <cctype>

PokemonFogo::PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "fogo") {
    
    // Converte o nome para minúsculas para garantir a correspondência
    std::string n = nome;
    for (char &c : n) c = std::tolower(c);

    if (n.find("vulpix") != std::string::npos || idPokemon == 37) {
        definirGolpe(0, new GolpeDano("Giro de Fogo", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Fogo Fátuo", 7));
    } 
    else if (n.find("ponyta") != std::string::npos || idPokemon == 77) {
        definirGolpe(0, new GolpeDano("Roda de Fogo", 13));
        definirGolpe(1, new GolpeDano("Chama Rápida", 8));
    } 
    else if (n.find("growlithe") != std::string::npos || idPokemon == 58) {
        definirGolpe(0, new GolpeDano("Explosão de Chamas", 11));
        definirGolpe(1, new GolpeReducaoAtaque("Mordida de Fogo", 7));
    }
    else {
        // Charmander e padrão para Pokémons do tipo Fogo
        definirGolpe(0, new GolpeDano("Lança-Chamas", 12));
        definirGolpe(1, new GolpeReducaoAtaque("Brasas", 6));
    }
}

int PokemonFogo::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;
    if (tipoAtacante == "agua") 
        mult = 2.0;
    else if (tipoAtacante == "planta")
        mult = 0.5;

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}