#ifndef FORTIFICANTE_HPP
#define FORTIFICANTE_HPP

#include "Item.hpp"

class Fortificante : public Item {
public:
    Fortificante(); 
    
    // Aplica o efeito de fortalecimento no Pokémon alvo
    bool usar(Pokemon& alvo) override;
};

#endif