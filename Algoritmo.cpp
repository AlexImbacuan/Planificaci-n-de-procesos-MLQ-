#include "Algoritmo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cstring>


using namespace std;

Algoritmo::Algoritmo() {
    reloj = 0;
    wt = new int[5]();
    ct = new int[5]();
    rt = new int[5]();
    tat = new int[5]();
    etiqueta = nullptr;
    burst_time = nullptr;
    arrival_time = nullptr;
    queue = nullptr;
    priority = nullptr;
    datos = new int*[5]();
    arreglo = new int*[5]();
    starreglo = new string[5];
    qq1 = 0;
    qq2 = 0;
    tamano = 0;
    tercero = "";
    contador = 0;
    colarr1 = new RoundRobin();  
    colarr2 = new RoundRobin();  
    colasjf = new Sjf();         
    colaFcfs = new Fcfs();       
    colaStcf = new Stcf();    

    for (int i = 0; i < 5; i++) {
        datos[i] = new int[4](); 
        arreglo[i] = new int[4](); 
    }
}

void Algoritmo::ejecutar(int qq1x, int qq2x, string tercerox) {
    tamano = 0;
    leerarchivo();
    qq1 = qq1x;
    qq2 = qq2x;
    tercero = tercerox;

    if (tamano > 0) {
        for (int i = 0; i < tamano; ++i) {
            datos[i] = new int[4]; 
            datos[i][0] = burst_time[i];
            datos[i][1] = arrival_time[i];
            datos[i][2] = queue[i];
            datos[i][3] = priority[i];
        }

        asignarcola();
        colarr1->correr1();
    } else {
        cout << "No hay datos válidos para procesar." << endl;
    }
}

void Algoritmo::leerarchivo() {
    string linea;
    ifstream archivo("mlq001.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (getline(archivo, linea)) {
        tamano++; 
    }
    archivo.clear();
    archivo.seekg(0, ios::beg);

    tamano -= 2; // Ajusta el tamaño según la lógica de tu archivo
    if (tamano <= 0) {
        cout << "No hay datos válidos en el archivo." << endl;
        return;
    }

    etiqueta = new string[tamano];
    burst_time = new int[tamano]();
    arrival_time = new int[tamano]();
    queue = new int[tamano]();
    priority = new int[tamano]();

    getline(archivo, linea); // Salta la primera línea
    getline(archivo, linea); // Salta la segunda línea
    contador = 0;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string dato;

        getline(ss, dato, ';');
        etiqueta[contador] = dato;

        getline(ss, dato, ';');
        if (!dato.empty()) {
            burst_time[contador] = stoi(dato);
        }

        getline(ss, dato, ';');
        if (!dato.empty()) {
            arrival_time[contador] = stoi(dato);
        }

        getline(ss, dato, ';');
        if (!dato.empty()) {
            queue[contador] = stoi(dato);
        }

        getline(ss, dato, ';');
        if (!dato.empty()) {
            priority[contador] = stoi(dato);
        }

        contador++;
    }
    archivo.close();
}

void Algoritmo::asignarcola() {
    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] == 1) {
            arreglo[contador] = datos[i];
            starreglo[contador] = etiqueta[i];
            contador++;
        }
    }

    colarr1->setCola1(arreglo, contador, starreglo);
    colarr1->setqq1(qq1);
    contador = 0;

    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] == 2) {
            arreglo[contador] = datos[i];
            starreglo[contador] = etiqueta[i];
            contador++;
        }
    }

    colarr2->setCola2(arreglo, contador, starreglo);
    colarr2->setqq2(qq2);
    contador = 0;

    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] == 3) {
            arreglo[contador] = datos[i];
            starreglo[contador] = etiqueta[i];
            contador++;
        }
    }

    if (tercero == "SJF") {
        colasjf->setColaSjf(arreglo, contador, starreglo);
    } else if (tercero == "FCFS") {
        colaFcfs->setColaFcfs(arreglo, contador, starreglo);
    } else if (tercero == "STCF") {
        colaStcf->setColaStcf(arreglo, contador, starreglo);
    }

    contador = 0; // Reiniciar contador
}

void Algoritmo::setWT(string etiq_entradawt, int wt_entrada) {
    for (int i = 0; i < tamano; i++) { 
        if (etiqueta[i] == etiq_entradawt) {
            wt[i] = wt_entrada;
            break;
        }
    }
}

void Algoritmo::setCT(string etiq_entradact, int ct_entrada) {
    for (int i = 0; i < tamano; i++) { 
        if (etiqueta[i] == etiq_entradact) {
            ct[i] = ct_entrada;
            break;
        }
    }
}

void Algoritmo::setRT(string etiq_entradart, int rt_entrada) {
    for (int i = 0; i < tamano; i++) { 
        if (etiqueta[i] == etiq_entradart) {
            rt[i] = rt_entrada;
            break;
        }
    }
}

int Algoritmo::getReloj() {
    return reloj;
}

void Algoritmo::setReloj(int incremento_reloj) {
    reloj += incremento_reloj;
}

string Algoritmo::gettercero() {
    return tercero;
}

Algoritmo::~Algoritmo() {
    delete[] etiqueta;
    delete[] burst_time;
    delete[] arrival_time;
    delete[] queue;
    delete[] priority;
    for (int i = 0; i < 5; i++) {
        delete[] datos[i];
        delete[] arreglo[i];  
    }
    delete[] datos;
    delete[] arreglo;
    delete[] starreglo;
    delete[] wt;
    delete[] ct;
    delete[] rt;
    delete[] tat;
    delete colarr1;  
    delete colarr2;
    delete colasjf;
    delete colaFcfs;
    delete colaStcf;
}
