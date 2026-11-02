#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

// Declaração antecipada para evitar inclusão circular com Pokemon
class Pokemon;

// Classe base abstrata para os itens consumíveis utilizados durante a batalha.
class Item {
protected:
    std::string nome;

public:
    Item(std::string nome);
    virtual ~Item(); // Destrutor virtual para desalocar subclasses corretamente

    std::string getNome();
    
    // Método abstrato para aplicar o efeito do item no Pokémon
    virtual bool usar(Pokemon& alvo) = 0;
};

#endif