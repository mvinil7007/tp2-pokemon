#include "GolpeDano.hpp"
#include "Pokemon.hpp"

// subclasse de Golpe voltada exclusivamente para causação de dano direto.

GolpeDano::GolpeDano(std::string nome, int poder) : Golpe(nome, poder), poder(poder) {
    
}

// Aplica o dano no alvo e retorna a mensagem
std::string GolpeDano::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int dano = calcularDano(atacante, alvo, poder);
    int vidaPerdida = alvo.perderVida(dano);

    return atacante.getNome() + " usou " + getNome() + " causando " + std::to_string(vidaPerdida) + " de dano.";
}