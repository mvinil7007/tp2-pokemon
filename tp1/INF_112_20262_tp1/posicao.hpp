#ifndef POSICAO_HPP
#define POSICAO_HPP

struct Posicao {
    int linha;
    int coluna;
};

// Retornam a posicao da entrada e da saida do labirinto. Usadas pelo
// explorador.cpp.
Posicao ObterEntrada(const Labirinto& labirinto);
Posicao ObterSaida(const Labirinto& labirinto);

#endif
