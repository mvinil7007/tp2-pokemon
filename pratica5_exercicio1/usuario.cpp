#include <iostream>
#include "usuario.hpp"

Usuario::Usuario(std::string nome, int id) {
    _nome = nome;
    _id = id;
}

std::string Usuario::get_nome() { 
    return _nome; 
}

int Usuario::get_id() { 
    return _id; 
}

void Usuario::exibirInformacoes() {
    std::cout << "Nome: " << _nome << std::endl;
    std::cout << "ID: " << _id << std::endl;
}