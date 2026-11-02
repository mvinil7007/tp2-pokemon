# include <iostream>
# include "labirinto.hpp"
# include "explorador.hpp"

int main(){

    Labirinto labirinto;

    // PASSO 1: Carregar um labirinto pela entrada padrao (cin).
    // Execute com redirecionamento , por exemplo : ./ main < labirinto_facil.txt

    CarregarLabirinto(labirinto);
    std::cout << "Labirinto Carregado:\n" << std::endl;
    ImprimirLabirinto(labirinto);
    std::cout << std::endl;

    // Guardamos as dimensoes originais : a area nova fica sempre isolada
    // da area original apos o redimensionamento .

    int alturaOriginal  = labirinto.altura;
    int larguraOriginal = labirinto.largura;

    // PASSO 2: Aumentar o labirinto

    RedimensionarLabirinto(labirinto , larguraOriginal + 4 , alturaOriginal + 3);
    std::cout << "Labirinto Redimensionado:\n" << std::endl;
    ImprimirLabirinto(labirinto);
    std::cout << std::endl;

    // PASSO 3: Abrir uma passagem manualmente dentro desse bloco

    DefinirParede(labirinto , alturaOriginal , larguraOriginal , false);
    std::cout << "Labirinto Parede/Passagem:\n" << std::endl;
    ImprimirLabirinto(labirinto);
    std::cout << std::endl;

    // PASSO 3.1: Testar a construcao de um muro longo
    // Cria uma parede horizontal na nova area expandida
    
    ConstruirParede(labirinto, alturaOriginal + 1, 1, alturaOriginal + 1, larguraOriginal - 1);
    std::cout << "Labirinto apos ConstruirParede:\n" << std::endl;
    ImprimirLabirinto(labirinto);
    std::cout << std::endl;

    // PASSO 4: Criar um segundo labirinto (vazio , mesmas dimensoes ) e compara-los

    Labirinto outroLabirinto;
    CriarLabirinto(outroLabirinto , labirinto.largura , labirinto.altura);
    std::cout << "Resultado :" << (CompararLabirintos (labirinto , outroLabirinto) ? " Iguais " : " Diferentes ") << std::endl;

    // PASSO 5: Consultar entrada , saida e uma posicao qualquer

    Posicao entrada = ObterEntrada(labirinto);
    Posicao saida   = ObterSaida(labirinto);
    std::cout << "Entrada   : ("   << entrada.linha << ", " << entrada.coluna   << ")" << std::endl;
    std::cout << "Saida     : ("   << saida.linha   << ", "   << saida.coluna   << ")" << std::endl;
    std::cout << "Posicao (0 ,0) e parede ? " << (EhParede ( labirinto , 0 , 0) ? "Sim" : "Nao") << std::endl;
    std::cout << std::endl;

    // PASSO 6: Chamar o explorador ( fornecido ) sobre o labirinto ja pronto
    ExplorarLabirinto(labirinto);

    // PASSO 7: Liberar toda a memoria alocada
    DestruirLabirinto(labirinto);
    DestruirLabirinto(outroLabirinto);

    return 0;
}