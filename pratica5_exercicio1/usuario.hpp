#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
    private:
        std::string _nome;
        int _id;

    public:
        Usuario(std::string nome, int id);
        ~Usuario();
        std::string get_nome();
        int get_id();
        
        void exibirInformacoes();
};

#endif