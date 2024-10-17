#ifndef SJF_H
#define SJF_H
#include<iostream>
using namespace std;
#include "Algoritmo.h"

class Sjf: public Algoritmo{
    private:
        int** colasjf;
        string* etiqueta_sjf;
    public:
        Sjf();
        void setColaSjf(int**, int, string*);
        ~Sjf();
};
#else
class Sjf;
#endif