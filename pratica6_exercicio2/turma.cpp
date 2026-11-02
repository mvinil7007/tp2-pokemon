#include "turma.h"

// Construtor usando lista de inicialização
Turma::Turma(std::string codigo, int ano) : _codigo(codigo), _ano(ano) {

}
Turma::~Turma() {
    // ...vazio...
}

std::string Turma::getCodigo() const{
    return _codigo;
}

int  Turma::getAno() const { 
    return _ano;
}

void Turma::setCodigo(std::string c) {
    _codigo = c;
}

void Turma::setAno(int a) {
    _ano = a;
}