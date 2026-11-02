#include <iostream>
#include "aquecedor2.hpp"

// 1º Construtor: Sem parâmetros
Aquecedor::Aquecedor() {
    _temperaturaMinima = 10.0;
    _temperaturaMaxima = 40.0;
    _fatorIncremento = 5.0;
    _temperatura = 20.0; 
}

// 2º Construtor: Recebe apenas a temperatura inicial (fator = 5)
Aquecedor::Aquecedor(double temperaturaInicial) {
    _temperaturaMinima = 10.0;
    _temperaturaMaxima = 40.0;
    _fatorIncremento = 5.0;
    
    if (temperaturaInicial >= _temperaturaMinima && temperaturaInicial <= _temperaturaMaxima)
        _temperatura = temperaturaInicial;
    else
        std::cout << "Erro: Temperatura inicial fora dos limites. Definindo para 20.0." << std::endl;
        _temperatura = 20.0;
}

// 3º Construtor: Recebe temperatura inicial e fator de incremento
Aquecedor::Aquecedor(double temperaturaInicial, double fatorIncremento) {
    _temperaturaMinima = 10.0;
    _temperaturaMaxima = 40.0;
    _fatorIncremento = fatorIncremento;
    
    if (temperaturaInicial >= _temperaturaMinima && temperaturaInicial <= _temperaturaMaxima)
        _temperatura = temperaturaInicial;
    else 
        std::cout << "Erro: Temperatura inicial fora dos limites. Definindo para 20.0." << std::endl;
        _temperatura = 20.0;

}

void Aquecedor::aquecer() {
    // Verifica se a adição do fator não ultrapassa o máximo
    if ((_temperatura + _fatorIncremento) <= _temperaturaMaxima)
        _temperatura += _fatorIncremento;
    else
        std::cout << "Erro ao aquecer: A temperatura maxima de " << _temperaturaMaxima << " graus seria ultrapassada." << std::endl;
}

void Aquecedor::esfriar() {
    // Verifica se a subtração do fator não desce abaixo do mínimo
    if ((_temperatura - _fatorIncremento) >= _temperaturaMinima) 
        _temperatura -= _fatorIncremento;
    else 
        std::cout << "Erro ao esfriar: A temperatura minima de " << _temperaturaMinima << " graus seria ultrapassada." << std::endl;
}

double Aquecedor::getTemperatura() {
    return _temperatura;
}

void Aquecedor::setFatorDeIncrementoDaTemperatura(double fator) {
    if (fator > 0.0)
        _fatorIncremento = fator;
    else 
        std::cout << "Erro: O fator de incremento tem de ser um valor positivo." << std::endl;
}