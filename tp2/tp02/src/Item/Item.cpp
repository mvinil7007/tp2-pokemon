#include "Item.hpp"


Item::Item(std::string nome) : nome(nome) {

}


Item::~Item() {

}


std::string Item::getNome() {
    return nome;
}