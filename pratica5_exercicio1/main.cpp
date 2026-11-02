#include <iostream>
#include "livro.hpp"
#include "usuario.hpp"
#include "emprestimo.hpp"

int main() {

    Livro livro1("1984", "George Orwell", "9780451524935");
    Usuario usuario1("Joao da Silva", 101);

    Emprestimo emprestimo1(livro1, usuario1, "16/09/2025");

    std::cout << "=== Resumo do Emprestimo ===" << std::endl;
    emprestimo1.exibirResumo();
    return 0;

}