#include "GolpeReducaoAtaque.hpp"
#include "Pokemon.hpp"

GolpeReducaoAtaque::GolpeReducaoAtaque(std::string nome, int poder) 
    : Golpe(nome, poder), poder(poder) {
    
}

// Aplica dano no alvo e reduz o ataque dele se continuar vivo
std::string GolpeReducaoAtaque::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int dano = calcularDano(atacante, alvo, poder);
    int vidaPerdida = alvo.perderVida(dano);

    std::string msg = atacante.getNome() + " usou " + getNome() + " causando " + std::to_string(vidaPerdida) + " de dano.";

    // Aplica a reducao de 8 pontos no alvo caso ele nao tenha desmaiado
    if (!alvo.derrotado()) {
        alvo.reduzirAtaque(8);
        msg += " O ataque de " + alvo.getNome() + " foi reduzido!";
    }

    return msg;
}