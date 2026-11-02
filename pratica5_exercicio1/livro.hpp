#ifndef LIVRO_HPP
#define LIVRO_HPP
#include <string>

class Livro{
    private:
        std::string _titulo;
        std::string _autor;
        std::string _isbn;
    public:
        Livro(std::string titulo,std::string autor, std::string isbn);
        ~Livro();
        std::string get_titulo();
        std::string get_autor();
        std::string get_isbn();
        void exibirInformacoes();
};

#endif