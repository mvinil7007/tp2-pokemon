#include <string> // necessário para declarar tipo string

struct ContaBancaria{

    // Dados
    std::string nome_titular;
    int numero_conta;
    double saldo_inicial;

    // Construtor
    ContaBancaria(std::string _nome,int _num,double _sal);

    // Métodos
    void depositar(double _v);
    
    bool sacar(double _v);

    void exibirInformacoes();

};