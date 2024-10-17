    
    #include "Sjf.h"

    Sjf::Sjf():Algoritmo(){
        etiqueta_sjf= new string[5];

        colasjf = new int*[5];   // Inicializa el primer nivel del puntero (5 filas)
        for (int i = 0; i < 5; i++) {
            colasjf[i] = new int[4];  // Cada fila tiene 4 columnas
        }
    }
    void Sjf::setColaSjf(int** arreglo_sjf, int contador_sjf, string* etiquetasjf){
        for (int i = 0; i < contador_sjf; i++) {
            etiqueta_sjf[i]=etiquetasjf[i];
            for (int j = 0; j < 4; j++) {
                colasjf[i][j] = arreglo_sjf[i][j]; // Copia profunda
                
            }
        }
    }
    Sjf::~Sjf(){
            // Liberar la memoria asignada a colasjf
        for (int i = 0; i < 5; i++) {
            delete[] colasjf[i];  // Libera cada fila
        }
        delete[] colasjf;  // Libera el puntero principal de la matriz

        // Liberar la memoria asignada a etiqueta_sjf
        delete[] etiqueta_sjf;
        
    }