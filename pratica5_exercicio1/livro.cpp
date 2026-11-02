#include <iostream>
#include "livro.hpp"

Livro::Livro(std::string titulo, std::string autor, std::string isbn) {
    _titulo = titulo;
    _autor  = autor;
    _isbn   = isbn;
}

std::string Livro::get_titulo() { 
    return _titulo; 
}

std::string Livro::get_autor() { 
    return _autor; 
}

std::string Livro::get_isbn() { 
    return _isbn; 
}

void Livro::exibirInformacoes() {
    std::cout << "Título: " << _titulo << std::endl;
    std::cout << "Autor: "  << _autor << std::endl;
    std::cout << "ISBN: "   << _isbn << std::endl;
}