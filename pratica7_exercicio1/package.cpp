#include "package.hpp"

Package::Package(const std::string& nome,const std::string& endereco,unsigned int peso,unsigned int custo)
 : _nome(nome) , _endereco(endereco) , _peso(peso), _custo(custo) {

}

double Package::calculateCost() const {
    // equivale ao:   (double)(_peso * _custo);
    return static_cast<double>(_peso * _custo);
}

unsigned int Package::getPeso() const {
    return _peso;
}

unsigned int Package::getCusto() const {
    return _custo;
}