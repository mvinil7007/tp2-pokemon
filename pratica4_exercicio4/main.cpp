#include <iostream>
#include <string>
#include "aluno.hpp" 

int main() {
    
    std::string nome;
    int matricula;
    int numMaterias;
    double nota;

    std::cout << "Digite o nome do aluno: ";
    std::getline(std::cin, nome);
    
    std::cout << "Digite a matricula do aluno: ";
    std::cin >> matricula;

    std::cout << "Digite o numero de materias cursadas: ";
    std::cin >> numMaterias;

    // Criacao do objeto Aluno
    Aluno aluno(nome, matricula, numMaterias);

    std::cout << "\n=== Cadastro de Notas ===\n";
    for (int i = 0; i < numMaterias; ++i) {
        std::cout << "Digite a nota da materia " << (i + 1) << ": ";
        std::cin >> nota;
        aluno.adicionarNota(nota);
    }

    // Calcular a media do aluno
    aluno.calcularMediaAluno();

    // Imprimir as informacoes do aluno
    std::cout << "\n=== Informacoes do Aluno ===\n";
    aluno.imprimeInformacoesAluno();

    return 0;
}