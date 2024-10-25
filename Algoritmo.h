#ifndef ALGORITMO_H
#define ALGORITMO_H
#include <iostream>
#include <string>
#include "Planificador.h"
using namespace std;

class Algoritmo{
    protected:
        
        std::string* etiqueta;
        int* burst_time;
        int* arrival_time;
        int* queue;
        int* priority;
        int** datos;
        int tamano;
        int** arreglo;
        std::string* starreglo;
        int contador;
    
    private:
        int qq1;
        int qq2;
        Planificador colas = Planificador();
        

        
    public:
        Algoritmo();
        void ejecutar(int, int);
        void leerarchivo();
        void asignarcola();
        void imprimir();
        
        ~Algoritmo();
};
#else
class Algoritmo;
#endif