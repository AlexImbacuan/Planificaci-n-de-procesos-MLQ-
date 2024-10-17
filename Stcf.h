#ifndef STCF_H
#define STCF_H
#include<iostream>
using namespace std;
#include "Algoritmo.h"

class Stcf: public Algoritmo{
    private:
        int** colaStcf;
        string* etiqueta_stcf;
    public:
        Stcf();
        void setColaStcf(int**, int, string*);
        ~Stcf();
};
#else
class Stcf;
#endif