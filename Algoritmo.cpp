#include "Algoritmo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cstring>


using namespace std;

Algoritmo::Algoritmo() {
   
    etiqueta = new std::string[5];
    starreglo = new std::string[5];
    burst_time = new int[5];
    arrival_time = new int[5];
    queue = new int[5];
    priority = new int[5];
    datos = new int*[5];
    arreglo = new int*[5];

    for (int i = 0; i < 5; i++) {
            datos[i] = new int[4]();
            arreglo[i] = new int[4]();
        }    
    
    for (int i = 0; i < 5; i++) {   
        for (int j = 0; j < 4; j++) {
            datos[i][j] = 0;
            arreglo[i][j]=0;
        }
    }
}
void Algoritmo::ejecutar(int qq1x, int qq2x) {
    tamano = 0;
    leerarchivo();
    qq1 = qq1x;
    qq2 = qq2x;

    if (tamano > 0) {
        for (int i = 0; i < tamano; ++i) {
            datos[i][0] = burst_time[i];
            datos[i][1] = arrival_time[i];
            datos[i][2] = queue[i];
            datos[i][3] = priority[i];
        }

        asignarcola();
        colas.setArregloArchivo(arreglo,tamano,etiqueta);
        colas.correr1();
        colas.correr2();
        colas.correr3();
        imprimir();


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
    contador=0;
    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] == 1) {
            arreglo[contador] = datos[i];
            starreglo[contador] = etiqueta[i];
            contador++;
        }
    }

    colas.setCola1(arreglo, contador, starreglo);
    colas.setqq1(qq1);
    contador = 0;

    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] == 2) {
            arreglo[contador] = datos[i];
            starreglo[contador] = etiqueta[i];
            contador++;
        }
    }

    colas.setCola2(arreglo, contador, starreglo);
    colas.setqq2(qq2);
    contador = 0;

    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] == 3) {
            arreglo[contador] = datos[i];
            starreglo[contador] = etiqueta[i];
            contador++;
        }
    }
    colas.setColaFcfs(arreglo, contador, starreglo);

    contador = 0; // Reiniciar contador
}
void Algoritmo::imprimir(){
    cout<<"\nPLANIFICACIÓN MLQ\n";
    cout<<"\nEtiqueta\tBT\tAT\tQ\tPr\tWT\tCT\tRT\tTAT\n";
    int tat[5];
    int wt[5];
    double promediowt=0;
    double promedioct=0;
    double promediort=0;
    double promediotat=0;

    for(int i=0; i<5;i++){
        tat[i]=colas.getCT(i)-arrival_time[i];
        wt[i]=colas.getCT(i)-burst_time[i];
    }
    for (int i=0; i<5;i++){
        cout<<"   "<<etiqueta[i]<<"\t\t";
        for(int j=0; j<4;j++){
            cout<<datos[i][j]<<"\t";
        }
        cout<<wt[i]<<"\t"<<colas.getCT(i)<<"\t"<<colas.getRT(i)<<"\t"<<tat[i]<<"\n";
        promediowt+=wt[i];
        promedioct+=colas.getCT(i);
        promediort+=colas.getRT(i);
        promediotat+=tat[i];
    }
    cout<<" PROMEDIO WT: "<<promediowt/5<<"\n";
    cout<<" PROMEDIO CT: "<<promedioct/5<<"\n";
    cout<<" PROMEDIO RT: "<<promediort/5<<"\n";
    cout<<" PROMEDIO TAT: "<<promediotat/5<<"\n";
}


Algoritmo::~Algoritmo() {

    delete[] etiqueta;
    delete[] starreglo;
    delete[] burst_time;
    delete[] arrival_time;
    delete[] queue;
    delete[] priority;
    for (int i = 0; i < 5; i++) {
        if (datos[i] != nullptr) {
            delete[] datos[i];
        }
        if (arreglo[i] != nullptr) {
            delete[] arreglo[i];
        }
    }
    delete[] datos;
    delete[] arreglo;
    std::cout << "Algoritmo destruido." << std::endl;
}