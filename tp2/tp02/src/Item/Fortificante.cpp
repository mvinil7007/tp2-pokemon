#include "Fortificante.hpp"
#include "Pokemon.hpp"

Fortificante::Fortificante() : Item("Fortificante") {}

// Executa a ação de fortalecer o Pokémon
bool Fortificante::usar(Pokemon& alvo) {
    // Chama o método do Pokémon para ativar o efeito do item
    return alvo.fortalecer();
}