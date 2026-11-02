#include "Animal.h"
#include <vector>
#include <cstdlib>

unsigned int Animal::_next_id=1;

Animal::~Animal() {
}

unsigned int Animal::get_new_id(){
    _next_id++;
    return _next_id-1;
}


void popula(std::vector<Animal*>& fazenda, Animal* A, unsigned int max_populacao){
    // Condição de paragem da recursão
    if (fazenda.size() >= max_populacao) {
        return;
    }
    
    fazenda.push_back(A->reproduz());
    
    // Escolhe o próximo animal aleatoriamente para continuar a reprodução
    int escolhido = rand() % fazenda.size();
    popula(fazenda, fazenda[escolhido], max_populacao);
}