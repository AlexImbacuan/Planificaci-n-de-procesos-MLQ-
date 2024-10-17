#include "Algoritmo.h"
#include "RoundRobin.h"
#include "Sjf.h"
#include "Fcfs.h"
#include "Stcf.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cstring>
using namespace std;
    

Algoritmo::Algoritmo(){
    reloj= 0;
    wt= new int[5];
    ct= new int[5];
    rt= new int[5];
    tat= new int[5];
    etiqueta= nullptr;
    burst_time=nullptr;
    arrival_time=nullptr;
    queue=nullptr;
    priority=nullptr;
    datos = new int*[5];
    arreglo = new int*[5];
    starreglo = new string[5];
    qq1=0;
    qq2=0;
    tamano=0;
    tercero= "";
    contador=0;
    // Inicializa el datos
    for (int i = 0; i < 5; i++) {
        datos[i] = new int[4];  // Cada fila tiene 4 columnas
    }

       // Inicializa arreglo
    for (int i = 0; i < 5; i++) {
        arreglo[i] = new int[4];  // Cada fila tiene 4 columnas
    }
}
void Algoritmo::ejecutar(int qq1x, int qq2x, string tercerox)//queue1 queue2, 3er palnificador,
{   
    tamano=0;
    leerarchivo();
    qq1=qq1x;
    qq2=qq2x;
    tercero=tercerox;

    cout<<tamano<<"\n\n";
    for (int i = 0; i < tamano; ++i) {
        datos[i] = new int[4];  // Cada proceso tiene 4 atributos: burst_time, arrival_time, queue, priority
        datos[i][0] = burst_time[i];
        datos[i][1] = arrival_time[i];
        datos[i][2] = queue[i];
        datos[i][3] = priority[i];
    }

    asignarcola();  
    
}
void Algoritmo::setWT(string etiq_entradawt, int wt_entrada){
    for (int i = 0; i < tamano; i++) { 
        if (etiqueta[i] == etiq_entradawt) {
            wt[i] = wt_entrada;
            break;
        }
    }
}
void Algoritmo::setCT(strint etiq_entradact, int ct_entrada){
    for (int i = 0; i < tamano; i++) { 
        if (etiqueta[i] == etiq_entradact) {
            ct[i] = ct_entrada;
            break;
        }
    }
}
void Algoritmo::setRT(strint etiq_entradart, int rt_entrada){
        for (int i = 0; i < tamano; i++) { 
        if (etiqueta[i] == etiq_entradart) {
            rt[i] = rt_entrada;
            break;
        }
    }
}
int Algoritmo::getReloj(){
    return reloj;
}

Algoritmo::~Algoritmo(){
    delete[] etiqueta;
    delete[] burst_time;
    delete[] arrival_time;
    delete[] queue;
    delete[] priority;
    for (int i = 0; i < 5; i++) {
        delete[] datos[i];   // Libera cada fila de datos
        delete[] arreglo[i];  // Libera cada fila de arreglo
    }
    delete[] datos;  // Libera el puntero de datos
    delete[] arreglo; // Libera el puntero de arreglo
    delete[] starreglo;
    delete[] wt;
    delete[] ct;
    delete[] rt;
    delete[] tat;
}

void Algoritmo::leerarchivo(){
    

    string linea;
    
    ifstream archivo ("mlq001.txt");
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            tamano++; 
            }            
        archivo.close();      
    }    
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
  
    tamano=tamano-2;
    etiqueta = new string[tamano];
    burst_time = new int[tamano]();
    arrival_time = new int[tamano]();
    queue = new int[tamano]();
    priority = new int[tamano]();


    archivo.open("mlq001.txt");
    getline(archivo, linea);
    getline(archivo, linea);
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {

            stringstream ss(linea);
            string dato;
                        
            getline(ss, dato, ';');
            etiqueta[contador]=dato;
            
            getline(ss, dato, ';');
            if(!dato.empty()){
                burst_time[contador]=stoi(dato);
            }
            
            getline(ss, dato, ';');
            if(!dato.empty()){
                arrival_time[contador]=stoi(dato);
            }
            getline(ss, dato, ';');
            if(!dato.empty()){
                queue[contador]=stoi(dato);
            }
            getline(ss, dato, ';');
            if(!dato.empty()){
                priority[contador]=stoi(dato);
            }
       
            contador+=1;
            //cout<<contador;
        }
        archivo.close();
    }else {
        cout << "No se pudo abrir el archivoo" << endl;
    }
    contador=0;

}
void Algoritmo::asignarcola(){
    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] == 1) {  // condicion para asignar a la cola 1
                arreglo[contador] = datos[i];  // Copia proceso
                starreglo[i]=etiqueta[i];
            contador++;  // Incrementa el contador
        }
    }
    RoundRobin colarr1;  // Crear el objeto
    colarr1.setCola1(arreglo, contador, starreglo);
    colarr1.setqq1(qq1);
    contador=0; //reiniciar el contador
    cout<<"aqui se detiene primero";   
    for (int i = 0; i < 5; ++i) {
        delete[] arreglo[i]; // Limpia cada fila
        arreglo[i] = new int[4]; 
    }
    cout<<"aqui se detiene despues";
    for (int i = 0; i < tamano; ++i) {
        starreglo[i].clear();  // Limpia el contenido del string
    }


    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] ==2 ) {  // condicion para asignar a la cola 2
                arreglo[contador] = datos[i];  // Copiar proceso 
                starreglo[i]=etiqueta[i];
            contador++;  // Incrementa el contador
        }
    }
    for(int i=0; i<5;i++){
        cout<<starreglo[i];
    }
    RoundRobin colarr2;  // Crear el objeto
    colarr2.setqq2(qq2);
    colarr2.setCola2(arreglo, contador, starreglo);
    contador=0; //reiniciar el contador

    for (int i = 0; i < 5; ++i) {
        delete[] arreglo[i]; // Limpia cada fila
        arreglo[i] = new int[4]; 
    }
    for (int i = 0; i < tamano; ++i) {
        starreglo[i].clear();  // Limpia el contenido del string
    }
    

    for (int i = 0; i < tamano; i++) {
        if (datos[i][2] ==3) {  // condicion para asignar a la cola 3
                arreglo[contador] = datos[i];  // Copiar proceso
                starreglo[i]=etiqueta[i];
            contador++;  // Incrementa el contador
        }
    }

    //Asigna la tercera cola segun el metodo de planificacion.
    if(tercero=="SJF"){
        Sjf colasjf = Sjf();
        colasjf.setColaSjf(arreglo, contador, starreglo);
    } 
    if(tercero=="FCFS"){
        Fcfs colaFcfs= Fcfs();
        colaFcfs.setColaFcfs(arreglo, contador, starreglo);
    }
    if(tercero=="STCF"){
        Stcf colaStcf= Stcf();
        colaStcf.setColaStcf(arreglo, contador, starreglo);
    }

    for (int i = 0; i < 5; ++i) {
        delete[] arreglo[i]; // Limpia cada fila
        arreglo[i] = new int[4]; 
    }
    for (int i = 0; i < tamano; ++i) {
        starreglo[i].clear();  // Limpia el contenido del string
    }
    contador=0;
}






