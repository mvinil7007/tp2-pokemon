// contador.h -> guarda a struct e as funções (cabeçalho ou contrato do codígo)

struct Contador {

    //dados
    int valor;
    
    // Construtor
    Contador(int v);

    // Métodos
    void incrementar();
    void decrementar();
    void imprimirValor();
    void resetarValor();
};
