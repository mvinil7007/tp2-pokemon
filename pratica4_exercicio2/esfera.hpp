
struct Esfera{
    //dados
    float _raio;

    // Construtor
    Esfera(float _r);

    // Destrutor
    ~Esfera();

    // Função que retorna o raio
    float rRaio();

    // Função para calcular a área da esfera
    float calculaAreaEsfera();

    // Função para calcular o volume da esfera
    float calculaVolumeEsfera();
};