#include "listavetorint.hpp"
#include <iostream>


ListaVetorInteiros::ListaVetorInteiros() {

    _elementos = new int[TAMANHO_INICIAL]();
    _num_elementos_inseridos = 0;
    // implementação
    _capacidade = TAMANHO_INICIAL;
    _inicio = 0;
}

void ListaVetorInteiros::inserir_elemento(int elemento) {

    if (_inicio + _num_elementos_inseridos == _capacidade){
        int *new_data = new int[_capacidade * 2];

        for (int i = 0; i < _num_elementos_inseridos ; i++)
            new_data[i] = _elementos[_inicio + i];

    delete[] _elementos;
    _elementos = new_data;
    _capacidade = _capacidade * 2;
    _inicio = 0;
    }

    _elementos[_inicio + _num_elementos_inseridos] = elemento;
    _num_elementos_inseridos++;

}

void ListaVetorInteiros::imprimir() {

    for (int i = 0; i < _num_elementos_inseridos; i++)
        std::cout << _elementos[_inicio + i] << " ";
    std::cout << std::endl;
}

ListaVetorInteiros::~ListaVetorInteiros() {
    
    delete[] _elementos;
}

//implementação das funções

void ListaVetorInteiros::remover_primeiro(){

    _inicio++;
    _num_elementos_inseridos--;
}

void ListaVetorInteiros::remover_ultimo(){

    _num_elementos_inseridos--;
}

void ListaVetorInteiros::inverte(){

    int _inicio_invert = _inicio;
    int _fim_invert = _inicio + _num_elementos_inseridos - 1;

    // Troca os elementos das pontas até se cruzarem no meio
    while (_inicio_invert < _fim_invert) {
        int _temp = _elementos[_inicio_invert];
        _elementos[_inicio_invert] = _elementos[_fim_invert];
        _elementos[_fim_invert] = _temp;
        
        _inicio_invert++;
        _fim_invert--;
    }
}