#include "Cura.hpp"
#include "Pokemon.hpp"


Cura::Cura() : Item("Cura") {
    
}

// Executa a ação de curar o Pokémon
bool Cura::usar(Pokemon& alvo) {
    // Não permite curar se o Pokémon estiver desmaiado ou com vida máxima
    if (alvo.derrotado() || alvo.getVida() >= alvo.getVidaMaxima()) {
        return false;
    }

    // Tenta curar até 20 PV do Pokémon e retorna true se teve sucesso
    return alvo.curar(20) > 0;
}