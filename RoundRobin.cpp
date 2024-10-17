#include "RoundRobin.h"

RoundRobin::RoundRobin(){
        queue1=0;
        queue2=0;
        contador=0;
        contador2=0;
        etiqueta_rr1 = new string[5];  // Inicializa el arreglo para las etiquetas de cola 1
        etiqueta_rr2 = new string[5];

        colaRR = new int*[5];   // Inicializa el primer nivel del puntero (5 filas)
        for (int i = 0; i < 5; i++) {
            colaRR[i] = new int[4];  // Cada fila tiene 4 columnas
        }
        colaRR2 = new int*[5];   // Inicializa el primer nivel del puntero (5 filas)
        for (int i = 0; i < 5; i++) {
            colaRR2[i] = new int[4];  // Cada fila tiene 4 columnas
        }
}
void RoundRobin::setCola1(int** arreglo_rr1, int contador_rr1, string* etiquetarr1 )
{   
    contador=contador_rr1;
    for (int i = 0; i < contador_rr1; i++) {
        etiqueta_rr1[i]= etiquetarr1[i];
        for (int j = 0; j < 4; j++) {
            colaRR[i][j] = arreglo_rr1[i][j]; // Copia profunda
            
        }
    }
    cout<<"\ncolarr1\n";
    for(int i=0; i<contador_rr1;i++){
        cout<<etiqueta_rr1[i]<<"  ";
        for(int j=0;j<4;j++){
            cout<<colaRR[i][j]<<"  ";
        }
        cout<<"\n";    
    }
    

}
void RoundRobin::setCola2(int** arreglo_rr2, int contador_rr2, string* etiquetarr2)
{   
    contador2=contador_rr2;
    for (int i = 0; i < contador_rr2; i++) {
        etiqueta_rr2[i]= etiquetarr2[i];
        for (int j = 0; j < 4; j++) {
            colaRR2[i][j] = arreglo_rr2[i][j]; // Copia profunda
            
        }
    }
}
void RoundRobin::setqq1(int q1){
    queue1=q1;
}
void RoundRobin::setqq2(int q2){
    queue2=q2;
}
int RoundRobin::procesarrr1(){

}

RoundRobin::~RoundRobin(){
 // Libera la memoria asignada a colaRR
    for (int i = 0; i < 5; i++) {
        delete[] colaRR[i]; // Libera cada fila
    }
    delete[] colaRR; // Libera el puntero principal

    // Libera la memoria asignada a colaRR2
    for (int i = 0; i < 5; i++) {
        delete[] colaRR2[i]; // Libera cada fila
    }
    delete[] colaRR2; // Libera el puntero principal
    delete[] etiqueta_rr1;
    delete[] etiqueta_rr2;
}


