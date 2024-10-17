#ifndef ALGORITMO_H
#define ALGORITMO_H
#include <iostream>
using namespace std;


class Algoritmo{
    protected:
        int reloj;
        int* wt;
        int* ct;
        int* rt;
        int* tat;
        string* etiqueta;
        int* burst_time;
        int* arrival_time;
        int* queue;
        int* priority;
        int** datos;
        int tamano;
        int** arreglo;
        string* starreglo;
        int contador;
    
    private:
        int qq1;
        int qq2;
        string tercero;
        
    public:
        Algoritmo();
        void ejecutar(int, int, string);
        void leerarchivo();
        void asignarcola();
        void setWT(string, int);
        void setCT(string, int);
        void setRT(string, int);
        int getReloj();
        void setReloj(int);
        string gettercero(); //obtiene la tercera cola
        ~Algoritmo();

};
#else
class Algoritmo;
#endif