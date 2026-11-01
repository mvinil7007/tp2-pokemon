#ifndef CURA_HPP
#define CURA_HPP

#include "Item.hpp"


class Cura : public Item {
public:
    Cura(); 
    
    // Aplica a cura de vida no Pokémon alvo
    bool usar(Pokemon& alvo) override;
};

#endif