#include "Stcf.h"

Stcf::Stcf():Algoritmo(){
    etiqueta_stcf=new string[5];
    colaStcf = new int*[5];   // Inicializa el primer nivel del puntero (5 filas)
        for (int i = 0; i < 5; i++) {
            colaStcf[i] = new int[4];  // Cada fila tiene 4 columnas
        }
    
}

void Stcf::setColaStcf(int** arreglo_stcf, int contador_stcf, string* etiquetastcf){
    for (int i = 0; i < contador_stcf; i++) {
        etiqueta_stcf[i]=etiquetastcf[i];
        for (int j = 0; j < 4; j++) {
            colaStcf[i][j] = arreglo_stcf[i][j]; // Copia profunda
        }
    }
}
Stcf:: ~Stcf(){
        // Liberar la memoria asignada a colaStcf
    for (int i = 0; i < 5; i++) {
        delete[] colaStcf[i];  // Libera cada fila
    }
    delete[] colaStcf;  // Libera el puntero principal de la matriz

    // Liberar la memoria asignada a etiqueta_stcf
    delete[] etiqueta_stcf;

}