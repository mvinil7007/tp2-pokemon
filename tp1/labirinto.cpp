#include <iostream>
#include <vector>     // para criação de um array dinâmico
#include <string>
#include <algorithm>  // para utilizar max() e min()
#include "labirinto.hpp"

// Função 1 - Criar um labirinto alocando cada posição na memória heap

void CriarLabirinto(Labirinto& labirinto, int largura, int altura){

    // Validação de dimensões mínimas (o labirinto deve ser 3x3 ou superior)

    if (largura < 3 || altura < 3) {
        std::cerr << "Erro: Dimensoes invalidas. O labirinto deve ser pelo menos 3x3." << std::endl;
        return; 
    }

    // Adicionar dimensões corretas

    labirinto.largura = largura;
    labirinto.altura  = altura;

    // Alocação dinâmica da matriz, usada para guardar cada caractere no labirinto dinamicamente
    // para liberar esse espaço da memória depois.

    labirinto.grade = new char*[altura];        // cria um espaço na heap para um vetor de i ponteiros
    for (int i = 0; i < altura; i++)
        labirinto.grade[i] = new char[largura]; // para cada ponteiro i é criado na heap um vetor de char com j posições

    // Preenchimento do labirinto (Bordas = '#', Interior = ' ')

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            // Se for a primeira ou última linha, ou primeira ou última coluna, vira parede
            if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1)
                labirinto.grade[i][j] = '#';
            else
                labirinto.grade[i][j] = ' ';
        }
    }

    // Configuração da Entrada (E) e Saída (S) 

    labirinto.entrada.linha = 1;
    labirinto.entrada.coluna = 1;
    labirinto.grade[1][1] = 'E';

    labirinto.saida.linha = altura - 2;
    labirinto.saida.coluna = largura - 2;
    labirinto.grade[altura - 2][largura - 2] = 'S';
    
}

// Função 2 - Destruir as variáveis criadas dinamicamente usando delete

void DestruirLabirinto(Labirinto& labirinto) {

    // Verifica se a grade realmente existe antes de tentar deletar
    // Somente aciona a condição caso o ponteiro grade esteja guardando algum endereço/valor de ponteiro
    if (labirinto.grade != nullptr) {  
        
        // Libera cada linha alocada no for de CriarLabirinto, grade[i][j] é deletado

        for (int i = 0; i < labirinto.altura; i++)
            delete[] labirinto.grade[i];
        
        // Libera o vetor principal de ponteiros, grade[i] é deletado

        delete[] labirinto.grade;

        // Agora só resta o ponteiro que está na memória stack

        // Reseta os valores por segurança

        labirinto.grade = nullptr;
        labirinto.largura = 0;
        labirinto.altura = 0;
    }
}

// Função 3 - Imprimir cada elemento do labirinto utilizando o comando for

void ImprimirLabirinto(const Labirinto& labirinto) {

    // Acessa os valores armazenados na memória heap
    // grade -> grade[i] -> grade[i][j]

    for (int i = 0; i < labirinto.altura; i++) {
        for (int j = 0; j < labirinto.largura; j++)
            std::cout << labirinto.grade[i][j];
        
        std::cout << std::endl;
    }
}

// Função 4 - Primeira função utilizada, calcula qual a linha com mais posições e a quantidade de colunas
//            do arquivo de texto, com isso aloca dinamicamente cada caractere como uma matriz

void CarregarLabirinto(Labirinto& labirinto) {


    std::vector<std::string> linhasTemporarias; // cria um vetor vazio (tamanho 0 inicialmente) que vai guardar cada linha de texto lida
    std::string linhaLida;                      // cada linha de texto é uma posição da lista
    int larguraMaxima = 0;

    // Lê da entrada padrão (cin) linha por linha até o fim

    while(getline(std::cin, linhaLida)) { // linhaLida armazena a entrada de texto até encontrar uma quebra de linha (\n)

        // Remove o caractere \r invisível, no caso de o arquivo de texto vir do Windows,
        // o que bagunça a execução das funções e a impressão do labirinto
        // caso a string não seja vazia e o último caractere seja \r

        if (!linhaLida.empty() && linhaLida.back() == '\r')
            linhaLida.pop_back(); // pop_back() vai ignorar o \r da sequência

        // Ignora a linha se ela não tiver nenhum conteúdo
        if (linhaLida.empty())
            continue; 
        
        // push_back insere linhaLida em um espaço sobrando no vetor 
        // caso o vetor atinja seu máximo, cria um vetor maior, deleta o vetor anterior (dinamicamente) e copia os dados
        // ex: (l1) -> (?, ?) -> (l1, ?) -> (l1, l2)

        linhasTemporarias.push_back(linhaLida);
                                    
        // Atualiza a largura máxima se a linha atual for maior
        // length() retorna a quantidade de caracteres da string (número de colunas)

        if (linhaLida.length() > larguraMaxima)
            larguraMaxima = linhaLida.length();
    }

    // size() retorna o tamanho do vetor (número de linhas)

    labirinto.altura  = linhasTemporarias.size();
    labirinto.largura = larguraMaxima;

    // Alocação dinâmica da grade

    labirinto.grade = new char*[labirinto.altura];        // grade[i] : acessa vetor de ponteiros criado na heap
    for (int i = 0; i < labirinto.altura; i++)
        labirinto.grade[i] = new char[labirinto.largura]; // grade[i][j] : acessa vetor de chars criado na heap

    int contagemE = 0;
    int contagemS = 0;

    for (int i = 0; i < labirinto.altura; i++)
        for (int j = 0; j < labirinto.largura; j++) {
            
            // Completa as posições faltantes com parede '#' se a linha for curta 
            // linhasTemporarias[i].length() -> tamanho da linha [i]
            // linhasTemporarias[i][j] -> retorna o char da posição

            if (j < linhasTemporarias[i].length()) { 
                labirinto.grade[i][j] = linhasTemporarias[i][j];
                
                // Registra as posições da Entrada e Saída

                if (labirinto.grade[i][j] == 'E') {
                    labirinto.entrada.linha = i;
                    labirinto.entrada.coluna = j;
                    contagemE++; 
                }
                else if (labirinto.grade[i][j] == 'S') {
                    labirinto.saida.linha = i;
                    labirinto.saida.coluna = j;
                    contagemS++;
                }
            }

            // Caso j passe do tamanho da linha temporária, preenche com "#" para a posição i, j
            else
                labirinto.grade[i][j] = '#';
    }

    // Mensagem de erro se não houver exatamente 1 'E' e 1 'S'

    if (contagemE != 1 || contagemS != 1) 
        std::cerr << "Erro: O labirinto deve conter exatamente uma entrada (E) e uma saida (S)." << std::endl;
}

// Função 5 - Altera uma única posição da grade, transformando-a em parede ou em passagem.

void DefinirParede(Labirinto& labirinto, int linha, int coluna, bool parede) {

    // Verifica se a linha e a coluna existem dentro da matriz

    if(LimiteValido(labirinto, linha, coluna)){
        // Altera a posição baseada na variável 'parede'
        if (parede == true)
            labirinto.grade[linha][coluna] = '#';
        else
            labirinto.grade[linha][coluna] = ' ';
    }
    // Se as coordenadas estiverem fora dos limites, exibe a mensagem de erro
    else 
        std::cerr << "Erro: Coordenadas fora dos limites em DefinirParede." << std::endl;
}

// Função 6 - Constrói um segmento reto de parede, que pode ser exclusivamente horizontal ou vertical

void ConstruirParede(Labirinto& labirinto, int linha1, int coluna1, int linha2, int coluna2) {

    // Garante que os pontos inicial e final estão dentro da matriz

    if (!LimiteValido(labirinto, linha1, coluna1) || !LimiteValido(labirinto, linha2, coluna2)){
        std::cerr << "Erro: Coordenadas fora dos limites em ConstruirParede." << std::endl;
        return;
    }
    
    // Para ser reta, as linhas ou as colunas devem ser iguais

    if (linha1 != linha2 && coluna1 != coluna2) {
        std::cerr << "Erro: O segmento de parede nao e perfeitamente horizontal ou vertical." << std::endl;
        return;
    }

    // Caso a linha1 seja maior que a linha2 ou
    // aconteça o mesmo com as colunas, fazer o for do ponto menor ao ponto maior

    int inicioLinha  = std::min(linha1, linha2);
    int fimLinha     = std::max(linha1, linha2);
    int inicioColuna = std::min(coluna1, coluna2);
    int fimColuna    = std::max(coluna1, coluna2);

    // Desenha a parede
    for (int i = inicioLinha; i <= fimLinha; i++) {
        for (int j = inicioColuna; j <= fimColuna; j++)
            labirinto.grade[i][j] = '#';
    }
}

// Função 7 - Adicionar uma nova área no labirinto

void RedimensionarLabirinto(Labirinto& labirinto, int novaLargura, int novaAltura) {

    // Cria a matriz nova maior na memória heap
    
    char** novaGrade = new char*[novaAltura];
    for (int i = 0; i < novaAltura; i++)
        novaGrade[i] = new char[novaLargura];

    // Preenche a matriz nova com os dados da antiga

    for (int i = 0; i < novaAltura; i++) {
        for (int j = 0; j < novaLargura; j++) {
            
            // Se estiver dentro dos limites do labirinto antigo, copia os dados antigos
            if (i < labirinto.altura && j < labirinto.largura)
                novaGrade[i][j] = labirinto.grade[i][j]; 

            // Se for a área nova, preenche os espaços com '#' nas bordas, caso contrário com espaço em branco
            else {
                if (i == 0 || i == novaAltura - 1 || j == 0 || j == novaLargura - 1)
                    novaGrade[i][j] = '#'; 
                else 
                    novaGrade[i][j] = ' '; 
            }
        }
    }

    // Deleta o labirinto antigo para não vazar memória (Memory Leak)

    if (labirinto.grade != nullptr) {
        for (int i = 0; i < labirinto.altura; i++)
            delete[] labirinto.grade[i];
        
        delete[] labirinto.grade;
    }

    // Atualiza a struct com a nova grade e os novos tamanhos

    labirinto.grade = novaGrade;
    labirinto.largura = novaLargura;
    labirinto.altura = novaAltura;
}

// Função 8 - Comparar e retornar se são iguais (true) ou diferentes (false)

bool CompararLabirintos(const Labirinto& l1, const Labirinto& l2) {

    // Verifica se as dimensões são diferentes

    if (l1.altura != l2.altura || l1.largura != l2.largura)
        return false;

    // Percorre as grades comparando posição por posição.
    // Se achar uma única diferença, os labirintos não são iguais. 
    for (int i = 0; i < l1.altura; i++)
        for (int j = 0; j < l1.largura; j++)
            if (l1.grade[i][j] != l2.grade[i][j])
                return false;

    // Se passou por tudo e não achou diferenças, os labirintos são idênticos.
    return true;
}

// Função 9 - Informa se a posição da grade corresponde a uma parede
//            Esta é a função usada pelo explorador.cpp para decidir se pode se mover para aquela posição.

bool EhParede(const Labirinto& labirinto, int linha, int coluna) {

    // Valida se as coordenadas estão dentro dos limites do labirinto, retorna verdadeiro se for '#'
    if(LimiteValido(labirinto, linha, coluna))
        return labirinto.grade[linha][coluna] == '#';
    
    // Caso não faça parte do labirinto
    std::cerr << "Erro: Coordenadas fora dos limites em EhParede." << std::endl;
    return true;
}

// Função 10 - Retornam, respectivamente, a posição da entrada e da saída do labirinto

Posicao ObterEntrada(const Labirinto& labirinto) {
    return labirinto.entrada;
}

Posicao ObterSaida(const Labirinto& labirinto) {
    return labirinto.saida;
}

// Função extra - Auxiliar para validar coordenadas no labirinto

bool LimiteValido(const Labirinto& labirinto, int linha, int coluna) {
    return (linha >= 0 && linha < labirinto.altura && coluna >= 0 && coluna < labirinto.largura);
}