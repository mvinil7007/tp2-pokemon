#include <iostream>
#include "emprestimo.hpp"

// Referências devem ser inicializadas na lista de inicialização
Emprestimo::Emprestimo(Livro& livro,Usuario& usuario,std::string dataEmprestimo)
    : _livro(livro), _usuario(usuario) {
    _dataEmprestimo = dataEmprestimo;
}

Livro& Emprestimo::get_livro() { 
    return _livro; 
}

Usuario& Emprestimo::get_usuario() { 
    return _usuario; 
}

std::string Emprestimo::get_dataEmprestimo() { 
    return _dataEmprestimo; 
}

void Emprestimo::exibirResumo() {
    std::cout << "[ Informações do Livro ]"   << std::endl;
    _livro.exibirInformacoes();
    std::cout << "[ Informações do Usuário ]" << std::endl;
    _usuario.exibirInformacoes();
    std::cout << "Data do Empréstimo: " << _dataEmprestimo << std::endl;
}