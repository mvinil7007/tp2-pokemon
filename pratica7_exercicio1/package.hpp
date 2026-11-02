#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <string>

// lembrete: usar const para métodos get e passagem por refência 
class Package {
private:
    std::string _nome;
    std::string _endereco;
    unsigned int _peso;  //Kg
    unsigned int _custo; //R$
 
public:
    // passagem por referencia para evitar criação desnecessarias de variaveis complexas como strings
    Package(const std::string& nome,const std::string& endereco,unsigned int peso,unsigned int custo);
    // destrutor padrão , pode ser utilizado pelas subclasses
    virtual ~Package() = default;

    virtual double calculateCost() const;

    unsigned int getPeso()  const;
    unsigned int getCusto() const;

};

#endif