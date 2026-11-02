// explorador.cpp
// Programa fornecido pelo professor. NAO faz parte do codigo do aluno.
// Implementa ExplorarLabirinto, que recebe um Labirinto ja pronto (montado
// pelo aluno em seu main.cpp) e tenta encontrar um caminho da entrada ate a
// saida usando busca em largura (BFS).

#include "explorador.hpp"
#include <iostream>

void ExplorarLabirinto(const Labirinto& labirinto) {
    int totalCelulas = labirinto.altura * labirinto.largura;

    // Matriz de visitados, alocada dinamicamente
    bool** visitado = new bool*[labirinto.altura];
    for (int i = 0; i < labirinto.altura; i++) {
        visitado[i] = new bool[labirinto.largura];
        for (int j = 0; j < labirinto.largura; j++) {
            visitado[i][j] = false;
        }
    }

    // Matrizes para reconstruir o caminho: guardam de onde cada posicao veio
    int** veioDeLinha = new int*[labirinto.altura];
    int** veioDeColuna = new int*[labirinto.altura];
    for (int i = 0; i < labirinto.altura; i++) {
        veioDeLinha[i] = new int[labirinto.largura];
        veioDeColuna[i] = new int[labirinto.largura];
        for (int j = 0; j < labirinto.largura; j++) {
            veioDeLinha[i][j] = -1;
            veioDeColuna[i][j] = -1;
        }
    }

    // Fila.
    // Cada posicao entra na fila no maximo uma vez, entao um vetor de
    // tamanho totalCelulas e suficiente.
    Posicao* fila = new Posicao[totalCelulas];
    int inicioFila = 0;
    int fimFila = 0;

    Posicao entrada = ObterEntrada(labirinto);
    Posicao saida = ObterSaida(labirinto);

    fila[fimFila] = entrada;
    fimFila++;
    visitado[entrada.linha][entrada.coluna] = true;

    const int deltaLinha[] = {-1, 1, 0, 0};
    const int deltaColuna[] = {0, 0, -1, 1};

    int tentativas = 0; // Contador para quantas posicoes foram de fato exploradas
    bool encontrou = false;

    while (inicioFila < fimFila && !encontrou) {
        Posicao atual = fila[inicioFila];
        inicioFila++;
        tentativas++;

        if (atual.linha == saida.linha && atual.coluna == saida.coluna) {
            encontrou = true;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int novaLinha = atual.linha + deltaLinha[d];
            int novaColuna = atual.coluna + deltaColuna[d];

            bool dentroDosLimites = novaLinha >= 0 && novaLinha < labirinto.altura &&
                                     novaColuna >= 0 && novaColuna < labirinto.largura;

            if (dentroDosLimites && !visitado[novaLinha][novaColuna] &&
                !EhParede(labirinto, novaLinha, novaColuna)) {
                visitado[novaLinha][novaColuna] = true;
                veioDeLinha[novaLinha][novaColuna] = atual.linha;
                veioDeColuna[novaLinha][novaColuna] = atual.coluna;
                fila[fimFila].linha = novaLinha;
                fila[fimFila].coluna = novaColuna;
                fimFila++;
            }
        }
    }

    // Marca as posicoes do caminho encontrado (se houver) em uma matriz
    // booleana propria, usada apenas para saber o que imprimir.
    bool** ehCaminho = new bool*[labirinto.altura];
    for (int i = 0; i < labirinto.altura; i++) {
        ehCaminho[i] = new bool[labirinto.largura];
        for (int j = 0; j < labirinto.largura; j++) {
            ehCaminho[i][j] = false;
        }
    }

    int tamanhoCaminho = 0;
    if (encontrou) {
        int linhaAtual = saida.linha;
        int colunaAtual = saida.coluna;
        while (!(linhaAtual == entrada.linha && colunaAtual == entrada.coluna)) {
            ehCaminho[linhaAtual][colunaAtual] = true;
            tamanhoCaminho++;

            int linhaAnterior = veioDeLinha[linhaAtual][colunaAtual];
            int colunaAnterior = veioDeColuna[linhaAtual][colunaAtual];
            linhaAtual = linhaAnterior;
            colunaAtual = colunaAnterior;
        }
        ehCaminho[entrada.linha][entrada.coluna] = true;
        tamanhoCaminho++;
    }

    // Imprime o labirinto com o caminho marcado.
    std::cout << "Resultado da exploracao:" << std::endl;
    for (int i = 0; i < labirinto.altura; i++) {
        for (int j = 0; j < labirinto.largura; j++) {
            if (EhParede(labirinto, i, j)) {
                std::cout << '#';
            } else if (i == entrada.linha && j == entrada.coluna) {
                std::cout << 'E';
            } else if (i == saida.linha && j == saida.coluna) {
                std::cout << 'S';
            } else if (ehCaminho[i][j]) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    if (encontrou) {
        std::cout << "Caminho encontrado com " << tamanhoCaminho << " passos." << std::endl;
    } else {
        std::cout << "Nenhum caminho encontrado entre a entrada e a saida." << std::endl;
    }
    std::cout << "Tentativas (posicoes exploradas na busca): " << tentativas << std::endl;

    // Libera toda a memoria alocada pelo explorador
    for (int i = 0; i < labirinto.altura; i++) {
        delete[] visitado[i];
        delete[] veioDeLinha[i];
        delete[] veioDeColuna[i];
        delete[] ehCaminho[i];
    }
    delete[] visitado;
    delete[] veioDeLinha;
    delete[] veioDeColuna;
    delete[] ehCaminho;
    delete[] fila;
}
