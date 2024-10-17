#include "Fcfs.h"

Fcfs::Fcfs(){
    eti_fcfs = new string[5];
    ColaFcfs = new int*[5];
    for (int i = 0; i < 5; i++) {
        ColaFcfs[i] = new int[4];  // Cada fila tiene 4 columnas
    }

}
void Fcfs::setColaFcfs(int** arreglo_fcfs, int contador_fcfs, string* etiqueta_fcfs){
    for (int i = 0; i < contador_fcfs; i++) {
        eti_fcfs[i]=etiqueta_fcfs[i];
        for (int j = 0; j < 4; j++) {
            ColaFcfs[i][j] = arreglo_fcfs[i][j]; // Copia profunda
            
        }
    }
    cout<<"crear  objeto FCFS";
}
Fcfs:: ~Fcfs(){
        // Libera la memoria dinámica asignada a ColaFcfs
    for (int i = 0; i < 5; i++) {
        delete[] ColaFcfs[i];  // Libera cada fila
    }
    delete[] ColaFcfs;  // Libera el puntero principal de la matriz

    // Libera la memoria dinámica asignada a las etiquetas
    delete[] eti_fcfs;

}