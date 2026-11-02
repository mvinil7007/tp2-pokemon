#include <string>

struct Aluno{

    // dados
    std::string nome;
    int matricula;
    double *notas;
    double media_notas = 0;

    // dados auxiliares
    int total_materias;
    int notas_inseridas;

    // construtor
    Aluno(std::string _nome,int _matricula,int _num_materias);

    // destrutor
    ~Aluno();  

    // método
    void adicionarNota(double nota);
    void calcularMediaAluno();
    void imprimeInformacoesAluno();

}; 

