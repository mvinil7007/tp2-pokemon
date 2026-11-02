#ifndef AQUECEDOR_HPP
#define AQUECEDOR_HPP

class Aquecedor {
    private:
        double _temperatura;
        double _temperaturaMinima;
        double _temperaturaMaxima;
        double _fatorIncremento;

    public:
        // Construtores sobrecarregados
        Aquecedor();
        Aquecedor(double temperaturaInicial);
        Aquecedor(double temperaturaInicial, double fatorIncremento);
        
        void aquecer();
        void esfriar();
        
        double getTemperatura();
        void setFatorDeIncrementoDaTemperatura(double fator);
};

#endif