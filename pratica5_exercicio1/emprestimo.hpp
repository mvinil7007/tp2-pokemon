#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <string>
#include "livro.hpp"
#include "usuario.hpp"

class Emprestimo {
    private:
        Livro& _livro;
        Usuario& _usuario;
        std::string _dataEmprestimo;

    public:
        Emprestimo(Livro& livro,Usuario& usuario, std::string dataEmprestimo);
        ~Emprestimo();
        Livro& get_livro();
        Usuario& get_usuario();
        std::string get_dataEmprestimo();
        
        void exibirResumo();
};

#endif