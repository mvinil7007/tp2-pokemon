#include "Treinador.hpp"
#include "Pokemon.hpp"
#include "PokemonFogo.hpp"
#include "PokemonAgua.hpp"
#include "PokemonPlanta.hpp"
#include "PokemonEletrico.hpp"
#include "Cura.hpp"
#include "Fortificante.hpp"

#include <fstream>
#include <iostream>

Treinador::Treinador(std::string nome, int pokemons[3]) : nome(nome), pokemonAtivoIndex(0) {
    for (int indice = 0; indice < 3; indice++)
        equipe[indice] = nullptr;

    std::ifstream arquivo("../pokemons.txt");

    int id, vida, ataque, defesa;
    std::string tipo, nomePokemon;
    while (arquivo >> id >> tipo >> nomePokemon >> vida >> ataque >> defesa) {
        for (int indice = 0; indice < 3; indice++) {
            if (pokemons[indice] != id || equipe[indice] != nullptr) 
                continue;

            if (tipo == "fogo") {
                equipe[indice] = new PokemonFogo(nomePokemon, id, vida, ataque, defesa);
            } 
            else if (tipo == "agua") {
                equipe[indice] = new PokemonAgua(nomePokemon, id, vida, ataque, defesa);
            }
            else if (tipo == "planta") {
                equipe[indice] = new PokemonPlanta(nomePokemon, id, vida, ataque, defesa);
            }
            else if (tipo == "eletrico") {
                equipe[indice] = new PokemonEletrico(nomePokemon, id, vida, ataque, defesa);
            }
        }
    }
    arquivo.close();

    // Inicializa a mochila com os dois itens padrão
    itens[0] = new Cura();
    itens[1] = new Fortificante();
}


Treinador::~Treinador() {
    for (int i = 0; i < 3; i++) {
        delete equipe[i];
        equipe[i] = nullptr;
    }
    for (int i = 0; i < 2; i++) {
        delete itens[i];
        itens[i] = nullptr;
    }
}

std::string Treinador::getNome() const {
    return nome;
}

Pokemon* Treinador::getAtivo() const {
    if (pokemonAtivoIndex < 0 || pokemonAtivoIndex >= 3) 
        return nullptr;
    return equipe[pokemonAtivoIndex];
}

Pokemon* Treinador::getPokemon(int indice) const {
    if (indice < 0 || indice >= 3) 
        return nullptr;
    return equipe[indice];
}

int Treinador::getIndiceAtivo() const {
    return pokemonAtivoIndex;
}

Item* Treinador::getItem(int indice) const {
    if (indice < 0 || indice >= 2)
        return nullptr;
    return itens[indice];
}

// Alterna o Pokémon ativo caso o índice seja válido e o Pokémon não esteja derrotado
bool Treinador::trocar(int indice) {
    if (indice < 0 || indice >= 3) 
        return false;
    if (equipe[indice] == nullptr || equipe[indice]->derrotado() || indice == pokemonAtivoIndex) {
        return false;
    }
    pokemonAtivoIndex = indice;
    return true;
}

// Aplica um item ao Pokémon e remove-o da mochila se for consumido com sucesso
bool Treinador::usarItem(int indiceItem, int indiceAlvo) {
    if (indiceItem < 0 || indiceItem >= 2 || itens[indiceItem] == nullptr) {
        return false;
    }
    Pokemon* alvo = getPokemon(indiceAlvo);
    if (alvo == nullptr) 
        return false;
    return usarItem(indiceItem, *alvo);
}

bool Treinador::usarItem(int indiceItem, Pokemon& alvo) {
    if (indiceItem < 0 || indiceItem >= 2 || itens[indiceItem] == nullptr) {
        return false;
    }

    if (itens[indiceItem]->usar(alvo)) {
        delete itens[indiceItem];
        itens[indiceItem] = nullptr; // Marca o item como consumido
        return true;
    }
    return false;
}

// Verifica se todos os Pokémons da equipa foram derrotados
bool Treinador::perdeu() const {
    for (int i = 0; i < 3; i++) {
        if (equipe[i] != nullptr && !equipe[i]->derrotado()) {
            return false;
        }
    }
    return true;
}