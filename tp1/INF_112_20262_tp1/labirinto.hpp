#ifndef LABIRINTO_HPP
#define LABIRINTO_HPP


struct Labirinto {
    int largura;    // numero de colunas da grade
    int altura;     // numero de linhas da grade
    char** grade;   // grade[linha][coluna]: '#' parede, ' ' passagem, 'E' entrada, 'S' saida
    Posicao entrada;
    Posicao saida;
};

// Cria um labirinto vazio (altura x largura), com toda a borda como parede
// e o interior como passagem. Entrada fica no canto superior esquerdo e
// saida no canto inferior direito.
void CriarLabirinto(Labirinto& labirinto, int largura, int altura);

// Libera toda a memoria alocada dinamicamente para a grade e a struct.
void DestruirLabirinto(Labirinto& labirinto);

// Exibe o labirinto no console (sem cores).
void ImprimirLabirinto(const Labirinto& labirinto);

// Le a partir da entrada padrao (std::cin) o layout do labirinto (linhas de
// '#', ' ', 'E' e 'S') e monta a estrutura Labirinto a partir dele. Use
// redirecionamento de entrada para testar com um arquivo, por exemplo:
// ./main < labirinto_facil.txt
void CarregarLabirinto(Labirinto& labirinto);

// Altera uma unica posicao da grade, transformando-a em parede ou passagem.
void DefinirParede(Labirinto& labirinto, int linha, int coluna, bool parede);

// Constroi um segmento reto de parede (exclusivamente horizontal ou vertical).
void ConstruirParede(Labirinto& labirinto, int linha1, int coluna1, int linha2, int coluna2);

// Realoca a grade para novas dimensoes, preservando o conteudo na area comum.
void RedimensionarLabirinto(Labirinto& labirinto, int novaLargura, int novaAltura);

// Verifica se dois labirintos tem as mesmas dimensoes e o mesmo conteudo.
bool CompararLabirintos(const Labirinto& l1, const Labirinto& l2);

// Informa se a posicao da grade e uma parede. Posicoes fora dos limites
// sao tratadas como parede (bloqueio). Usada pelo explorador.cpp.
bool EhParede(const Labirinto& labirinto, int linha, int coluna);


#endif
