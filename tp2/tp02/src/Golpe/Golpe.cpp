#include "Golpe.hpp"
#include "Pokemon.hpp"
#include <algorithm>
#include <cmath>


Golpe::Golpe(std::string nome, int poder) : nome(nome), poder(poder) {

}

Golpe::~Golpe() {
    
}

std::string Golpe::getNome() {
    return nome;
}

int Golpe::getPoder() {
    return poder;
}

// Calcula o dano final considerando ataque, defesa, reducoes, tipo e fortificante
int Golpe::calcularDano(Pokemon& atacante, Pokemon& alvo, int poder) {
    int danoBase = poder + atacante.getAtaque() - alvo.getDefesa();
    danoBase = std::max(1, danoBase);

    // Aplica reducao de ataque se o atacante estiver sob o efeito do Golpe
    int reducao = atacante.consumirReducaoAtaque();
    if (reducao > 0) {
        danoBase = std::max(0, danoBase - reducao);
    }

    // Ajusta o dano de acordo com o multiplicador de tipo do alvo
    int danoTipo = alvo.calcularDanoRecebido(danoBase, atacante.getTipo());

    // Aplica o fortificante se estiver ativo
    double fortalecimento = atacante.consumirFortalecimento();
    int danoFinal = std::max(1, static_cast<int>(std::round(danoTipo * fortalecimento)));

    return danoFinal;
}