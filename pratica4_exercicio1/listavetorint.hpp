#define TAMANHO_INICIAL 100

struct ListaVetorInteiros { 

    // Dados
    int *_elementos;
    int _num_elementos_inseridos;
    // implementação
    int _capacidade;
    int _inicio;

    // Construtor
    ListaVetorInteiros();

    // Destrutor
    ~ListaVetorInteiros();

    // Insere um inteiro na lista
    void inserir_elemento(int elemento);

    // Imprime a lista
    void imprimir();

    // remover primeiro
    void remover_primeiro();

    // remover ultimo
    void remover_ultimo();

    // inverter o veotr
    void inverte();
};