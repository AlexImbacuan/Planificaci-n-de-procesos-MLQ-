#ifndef STCF_H
#define STCF_H
#include<iostream>
#include<string>
using namespace std; 
class Stcf{
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