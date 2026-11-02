#include <iostream>
using namespace std;

struct Jogador {
    int pontos;
    int x, y;
};

void leDadosJogador(Jogador *p) {
    // p->pontos = (*p).pontos 
    cin >> p->pontos >> p->x >> p->y;
}
int main() {
    Jogador j[5];
    for (int i=0;i<5;i++)
        // ao ponteiro é dado o endereço, jogador *p = &j[i]
        // &j[i] == &j[i].pontos
        leDadosJogador(&j[i]);
    
    for (int i=0;i<5;i++)
        cout << j[i].pontos << " "<< j[i].x << " " << j[i].y << endl;
    return 0;
}