#ifndef FCFS_H
#define FCFS_H
#include<iostream>
using namespace std;
#include "Algoritmo.h"


class Fcfs :public Algoritmo{
    private:
        int** ColaFcfs;
        string* eti_fcfs;
        string mensaje;
    public:
        Fcfs();
        ~Fcfs();
        void setColaFcfs(int**, int, string*);

};
#else
class Fcfs
#endif