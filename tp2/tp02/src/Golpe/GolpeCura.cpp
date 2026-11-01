#include "GolpeCura.hpp"
#include "Pokemon.hpp"

GolpeCura::GolpeCura(std::string nome, int poder, int quantidade) 
    : Golpe(nome, poder), poder(poder), quantidade(quantidade) {

}

// Aplica dano no alvo, cura o atacante e retorna a mensagem
std::string GolpeCura::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int dano = calcularDano(atacante, alvo, poder);
    int vidaPerdida = alvo.perderVida(dano);
    int vidaRecuperada = atacante.curar(quantidade);

    return atacante.getNome() + " usou " + getNome() + " causando " + std::to_string(vidaPerdida) +
           " de dano e recuperou " + std::to_string(vidaRecuperada) + " PV.";
}