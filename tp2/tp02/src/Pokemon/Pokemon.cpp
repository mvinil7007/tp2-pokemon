#include "Pokemon.hpp"
#include "Golpe.hpp"
#include <algorithm>


Pokemon::Pokemon(std::string nome, int idPokemon, int vida, int ataque, int defesa, std::string tipo)
    : nome(nome), tipo(tipo), idPokemon(idPokemon), vida(vida), vidaMaxima(vida),
      ataque(ataque), defesa(defesa), reducaoProximoAtaque(0), fortalecido(false) {
    golpes[0] = nullptr;
    golpes[1] = nullptr;
}

// libera a memória alocada dinamicamente para os golpes
Pokemon::~Pokemon() {
    delete golpes[0];
    delete golpes[1];
}

std::string Pokemon::getNome() { 
    return nome;
}
int Pokemon::getIdPokemon() {
    return idPokemon;
}
int Pokemon::getVida() { 
    return vida;
}
int Pokemon::getVidaMaxima() {
    return vidaMaxima; 
}
int Pokemon::getAtaque() { 
    return ataque; 
}
int Pokemon::getDefesa() { 
    return defesa; 
}
std::string Pokemon::getTipo() { 
    return tipo; 
}

bool Pokemon::derrotado() {
    return vida == 0;
}

// Retorna o ponteiro do golpe no índice informado (0 ou 1)
Golpe* Pokemon::getGolpe(int indice) {
    if (indice < 0 || indice > 1) 
        return nullptr;
    return golpes[indice];
}

// Associa o golpe ao índice informado, liberando a memória do golpe anterior
void Pokemon::definirGolpe(int indice, Golpe* golpe) {
    if (indice < 0 || indice > 1) {
        delete golpe;
        return;
    }
    delete golpes[indice];
    golpes[indice] = golpe;
}

int Pokemon::perderVida(int quantidade) {
    if (quantidade <= 0) 
        return 0;
    int vidaAnterior = vida;
    vida = std::max(0, vida - quantidade);
    return vidaAnterior - vida;
}

// não cura Pokémon derrotado
int Pokemon::curar(int quantidade) {
    if (quantidade <= 0 || derrotado()) 
        return 0;
    int vidaAnterior = vida;
    vida = std::min(vidaMaxima, vida + quantidade);
    return vida - vidaAnterior;
}

// redução positiva para o próximo golpe recebido
void Pokemon::reduzirAtaque(int quantidade) {
    if (quantidade > 0) {
        reducaoProximoAtaque = quantidade;
    }
}

int Pokemon::consumirReducaoAtaque() {
    int reducao = reducaoProximoAtaque;
    reducaoProximoAtaque = 0;
    return reducao;
}

bool Pokemon::fortalecer() {
    if (derrotado() || fortalecido) return false;
    fortalecido = true;
    return true;
}

double Pokemon::consumirFortalecimento() {
    if (fortalecido) {
        fortalecido = false;
        return 1.1;
    }
    return 1.0;
}