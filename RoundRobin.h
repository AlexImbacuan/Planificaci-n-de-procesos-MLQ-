#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H
#include <iostream>
#include <string>
#include "Algoritmo.h"
using namespace std;


class RoundRobin: public Algoritmo{
    private:
        int queue1;
        int queue2;
        int** colaRR;
        int** colaRR2;
        string* etiqueta_rr1;
        string* etiqueta_rr2;
        int contador;
        int contador2;
        
    public:
        RoundRobin();
        ~RoundRobin();
        void setCola1(int**, int, string*);
        void setCola2(int**, int, string*);
        void moverproceso(string);
        void setqq1(int);
        void setqq2(int);
        void procesarrr1();
        void procesarrr2();


};
#else
class RoundRobin;
#endif