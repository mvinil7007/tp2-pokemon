#include <iostream>
#include <string>
#include "aluno.hpp"

Aluno::Aluno(std::string _nome, int _matricula, int _num_materias) {
    nome = _nome;
    matricula = _matricula;
    total_materias = _num_materias;
    notas_inseridas = 0;
    
    media_notas = 0.0;
    
    // armazenar dinamicamente
    notas = new double[total_materias]; 
}

Aluno::~Aluno() {
    delete[] notas;
}

void Aluno::adicionarNota(double nota) {
    
    if (notas_inseridas < total_materias) {
        notas[notas_inseridas] = nota;
        notas_inseridas++; 
    }
    else
        std::cout << "Todas as notas já foram inseridas!\n";
}

void Aluno::calcularMediaAluno() {
    
    double soma = 0.0;
    for (int i = 0; i < total_materias; i++) {
        soma += notas[i];
    }
    
    media_notas = soma / (1.0*total_materias);
}

void Aluno::imprimeInformacoesAluno() {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matricula: " << matricula << "\n";
    std::cout << "Notas cadastradas: \n";
    
    for(int i = 0; i < notas_inseridas; i++) {
        std::cout << "  - Nota " << (i+1) << ": " << notas[i] << "\n";
    }
    
    std::cout << "Media Final: " << media_notas << std::endl;
}