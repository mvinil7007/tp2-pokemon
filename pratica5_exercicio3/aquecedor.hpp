#ifndef AQUECEDOR_HPP
#define AQUECEDOR_HPP

class Aquecedor {
    private:
        double _temperatura;

    public:
        Aquecedor();
        ~Aquecedor();
        void aquecer();
        void esfriar();
        double getTemperatura();
};

#endif