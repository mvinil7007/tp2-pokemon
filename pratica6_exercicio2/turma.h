#ifndef INF112_TURMA_H
#define INF112_TURMA_H

#include <string>

class Turma {
private:
    std::string _codigo;
    int _ano;

public:
    Turma(std::string _codigo = "", int _ano = 0);
    ~Turma();

    std::string getCodigo() const;
    int getAno() const;
    void setCodigo(std::string c);
    void setAno(int a);
};

#endif