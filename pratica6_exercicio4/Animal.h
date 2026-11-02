#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <vector>
#include <string>

class Animal {
    protected:
        unsigned int _id;
        static unsigned int _next_id; // Tornar estático para partilhar entre todos
        std::string _cor;
    public:
        virtual ~Animal(); // Destrutor virtual para evitar memory leaks
        static unsigned int get_new_id();
        virtual Animal* reproduz()=0;
        virtual void faz_barulho()=0;
        virtual unsigned int get_id()=0;
};

void popula(std::vector<Animal*>& fazenda, Animal* A, unsigned int max_populacao);
#endif