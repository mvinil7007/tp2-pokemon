#include "PokemonFogo.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

PokemonFogo::PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "fogo") {
    
    if (nome == "Charmander" || idPokemon == 4) {
        definirGolpe(0, new GolpeDano("Lanca-Chamas", 12));
        definirGolpe(1, new GolpeReducaoAtaque("Brasas", 6));
    } 
    else if (nome == "Vulpix" || idPokemon == 37) {
        definirGolpe(0, new GolpeDano("Giro de Fogo", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Fogo Fatuo", 7));
    } 
    else if (nome == "Ponyta" || idPokemon == 77) {
        definirGolpe(0, new GolpeDano("Roda de Fogo", 13));
        definirGolpe(1, new GolpeDano("Chama Rapida", 8));
    } 
    else {
        // Golpe padrao para outros Pokemons de Fogo
        definirGolpe(0, new GolpeDano("Chama Basica", 10));
        definirGolpe(1, new GolpeReducaoAtaque("Fumaca", 5));
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