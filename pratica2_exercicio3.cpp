#include <iostream>
#include <cmath>   // sqrt() e pow(,)

using namespace std;

struct Ponto3D {
    // Dados
    float _x;
    float _y;
    float _z;

    // Operacoes
    void transladar(Ponto3D &deslocamento) {
        // Como a função pertence ao ponto, usamos apenas _x, _y e _z
        _x = deslocamento._x + _x;
        _y = deslocamento._y + _y;
        _z = deslocamento._z + _z;
    }
    
    float distancia(Ponto3D &outro) {
        return sqrt( pow((_x-outro._x),2) + pow((_y-outro._y),2) + pow((_z-outro._z),2) );
    }
    // (x,y,z)
    void imprime() {
        cout << "(" << _x << "," << _y << "," << _z << ")" << endl;
    }
};

int main() {
    
    Ponto3D patual, pdesl , p3;
    cin >> patual._x >> patual._y >> patual._z;
    cin >> pdesl._x >> pdesl._y >> pdesl._z;
    cin >> p3._x >> p3._y >> p3._z;

    cout << endl;
    cout << "Ponto de Origem: ";
    patual.imprime();

    cout << "Deslocamento   : ";
    pdesl.imprime();

    patual.transladar(pdesl);

    cout << "Ponto novo     : ";
    patual.imprime();
    
    float dist = patual.distancia(p3);
    cout << "Distancia entre o pontos atual e p3 é: " << dist << endl;

    return 0;
}