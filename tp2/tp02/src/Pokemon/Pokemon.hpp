#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

// Declaração antecipada da classe Golpe
class Golpe;

class Pokemon {
protected:
    std::string nome;
    std::string tipo;
    int idPokemon;
    int vida;
    int vidaMaxima;
    int ataque;
    int defesa;
    int reducaoProximoAtaque; 
    bool fortalecido;         
    Golpe* golpes[2];         // Ponteiros para os dois golpes do Pokémon
                              // [0] golpe principal , [1] secundario
public:
    Pokemon(std::string nome, int idPokemon, int vida, int ataque, int defesa, std::string tipo);
    virtual ~Pokemon();

    
    std::string getNome();
    int getIdPokemon();
    int getVida();
    int getVidaMaxima();
    int getAtaque();
    int getDefesa();
    std::string getTipo();

    
    bool derrotado();

    // Gerenciamento de golpes
    Golpe* getGolpe(int indice);
    void definirGolpe(int indice, Golpe* golpe);

    // Modificadores de vida e efeitos temporários
    int perderVida(int quantidade);
    int curar(int quantidade);
    void reduzirAtaque(int quantidade);
    int consumirReducaoAtaque();
    bool fortalecer();
    double consumirFortalecimento();

    virtual int calcularDanoRecebido(int dano, std::string tipoAtacante) = 0;
};

#endif