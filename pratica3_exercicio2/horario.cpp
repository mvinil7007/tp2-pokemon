#include <iostream>
#include "horario.h"
#include <iomanip>
using namespace std;

Horario::Horario(int h,int m,int s){
    hora = h;
    minuto  = m;
    segundo = s;
}

void Horario::exibeHorarioUniversal(){
    cout << setfill('0') << setw(2) << hora    << ":" << setfill('0') << setw(2) << minuto  << ":"
         << setfill('0') << setw(2) << segundo << endl;
}

void Horario::exibeHorarioPadrao(){
    if (hora > 12){
        cout << setfill('0') << setw(2) << (hora-12) << ":" << setfill('0') << setw(2) << minuto  << ":"
             << setfill('0') << setw(2) << segundo << " PM" << endl;
    }
    else if (hora == 12){
        cout << setfill('0') << setw(2) << hora << ":" << setfill('0') << setw(2) << minuto  << ":"
             << setfill('0') << setw(2) << segundo << " PM" << endl;
    }
    else if (hora == 0){
        cout << setfill('0') << setw(2) << hora+12 << ":" << setfill('0') << setw(2) << minuto  << ":"
             << setfill('0') << setw(2) << segundo << " AM" << endl;
    }
    else
    {
        cout << setfill('0') << setw(2) << hora << ":" << setfill('0') << setw(2) << minuto  << ":"
             << setfill('0') << setw(2) << segundo << " AM" << endl;
    }
}