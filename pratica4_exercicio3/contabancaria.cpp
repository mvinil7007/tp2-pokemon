#include <iostream>
#include <string>
#include "contabancaria.hpp"


ContaBancaria::ContaBancaria(std::string _nome,int _num,double _sal){
    nome_titular  = _nome;
    numero_conta  = _num;
    saldo_inicial = _sal;
}

void ContaBancaria::depositar(double _v){
    if(_v>=0)
        saldo_inicial += _v;
}

bool ContaBancaria::sacar(double _v){
    if(saldo_inicial >=_v){
        saldo_inicial -= _v;
        return true;
    }
    else
        return false;    
}

void ContaBancaria::exibirInformacoes(){
    std::cout << "---- Informações da conta ----\n"
              << "Nome : " << nome_titular <<  "\n"
              << "Conta: " << numero_conta <<  "\n"
              << "Saldo: " << saldo_inicial << std::endl;
}