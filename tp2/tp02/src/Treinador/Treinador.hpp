#ifndef TREINADOR_HPP
#define TREINADOR_HPP

#include <string>
#include "Pokemon.hpp"
#include "Item.hpp"


class Treinador {
private:
    std::string nome;
    Pokemon* equipe[3];     // Equipa fixa de 3 Pokémons
    Item* itens[2];         // Mochila com os itens (Cura e Fortificante)
    int pokemonAtivoIndex;  // Índice do Pokémon em campo

public:
   
    Treinador(std::string nome, int pokemons[3]);
    ~Treinador();

    std::string getNome() const;
    Pokemon* getAtivo() const;
    Pokemon* getPokemon(int indice) const;
    int getIndiceAtivo() const;
    Item* getItem(int indice) const;

    // Ações de batalha
    bool trocar(int indice);
    bool usarItem(int indiceItem, int indiceAlvo);
    bool usarItem(int indiceItem, Pokemon& alvo);
    bool perdeu() const;
};

#endif