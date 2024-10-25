#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H
#include <iostream>
#include <string>

using namespace std;

class Planificador {
private:
    int tamanoA; //tamaño archivo
    int** arregloA; //arreglo archivo
    string* etiquetaA; //etiqueta archivo
    int queue1;
    int queue2;
    int** colaRR;
    int** colaRR2;
    int** colaFcfs;
    string* etiqueta_rr1;
    string* etiqueta_rr2;
    string* etiqueta_fcfs;
    int contador;
    int contador2;
    int contador3;
    int reloj;
    int* ct;
    int* rt;
    int posicion; //para ubicar donde se agrega en la cola

public:
    Planificador();
    ~Planificador();
    void setCola1(int**, int, string*);
    void setCola2(int**, int, string*);
    void setColaFcfs(int**, int, string*);
    void moverproceso(string);
    void moverprocesoaFcfs(string);
    void setqq1(int);
    void setqq2(int);
    void correr1();
    void correr2();
    void correr3();
    void setCT(string, int);
    void setRT(string, int);
    int getCT(int);
    int getRT(int);
    void setArregloArchivo(int**, int, string*);
    int getReloj();
    void setReloj(int);
    void imprimirColas();
};

#endif