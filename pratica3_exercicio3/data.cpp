#include <iostream>
#include "data.h"
#include <iomanip>
using namespace std;

Data::Data(int d,int m,int a){
    dia = d;
    mes = m;
    ano = a;
}

void Data::exibirDataFormatoNumero(){
    cout <<  setfill('0') << setw(2) << dia << "/" <<  setfill('0') << setw(2) << mes << "/" << ano << endl;
}

void Data::exibirDataPorExtenso(){
    // lista com meses por extenso
    string meses[12] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", 
        "Maio", "Junho", "Julho", "Agosto", 
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    cout << setfill('0') << setw(2) << dia << " de "  << meses[mes-1] << " de " << ano << endl;
    
}

void Data::obterDataEmSegundos(){
    //data inicial 01/01/1970 -> 11/09/2026
    long long int anos,meses,dias;
    anos  = ano - 1970;
    meses = mes - 1; 
    dias  = dia - 1;

    long long int segundos;
    segundos = (anos*365*24*60*60) + (meses*30*24*60*60) + (dias*24*60*60);
    cout << "Tempo[s]: " << segundos << endl;
    cout << endl;
}
