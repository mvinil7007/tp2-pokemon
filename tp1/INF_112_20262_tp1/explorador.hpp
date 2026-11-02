#ifndef EXPLORADOR_HPP
#define EXPLORADOR_HPP

#include "labirinto.hpp"

// Recebe um labirinto ja carregado/construido pelo aluno e tenta encontrar
// um caminho da entrada ate a saida. Imprime o labirinto com o caminho
// encontrado marcado com '*', e informa quantas posicoes foram exploradas
// durante a busca (tentativas) ate a saida ser encontrada (ou ate esgotar
// as possibilidades, caso nao exista solucao).
//
// Quanto mais complexo (maior, com mais ramificacoes) for o labirinto
// construido, maior tende a ser o numero de tentativas!
//
// Utiliza exclusivamente a interface publica definida em labirinto.hpp.
void ExplorarLabirinto(const Labirinto& labirinto);

#endif
