#include "Planificador.h"

Planificador::Planificador() {
    tamanoA = 0;
    etiquetaA = new string[5];
    queue1 = 0; // quantum1
    queue2 = 0; // quantum 2
    contador = 0;
    contador2 = 0;
    contador3 = 0;
    reloj = 0;
    ct = new int[5]();
    rt = new int[5]();

    etiqueta_rr1 = new string[5];  // Inicializa el arreglo para las etiquetas de cola 1
    etiqueta_rr2 = new string[5];
    etiqueta_fcfs = new string[5];

    for (int i = 0; i < 5; i++) {
        etiqueta_rr1[i] = "";
        etiqueta_rr2[i] = "";
        etiqueta_fcfs[i] = "";
    }

    colaRR = new int*[5]();
    colaRR2 = new int*[5]();
    colaFcfs = new int*[5]();
    for (int i = 0; i < 5; i++) {
        colaRR[i] = new int[4]();
        colaRR2[i] = new int[4]();
        colaFcfs[i] = new int[4]();
    }    

    arregloA = new int*[5]();
    for (int i = 0; i < 5; i++) {
        arregloA[i] = new int[4]();
    }
    posicion = 0;
}

void Planificador::setArregloArchivo(int** arregloarchivo, int tamanoarchivo, string* etiquetaarchivo) {
    tamanoA = tamanoarchivo;
    for (int i = 0; i < 5; i++) {
        etiquetaA[i] = etiquetaarchivo[i];
        for (int j = 0; j < 4; j++) {
            arregloA[i][j] = arregloarchivo[i][j];  // Copia los elementos
        }
    }
}

void Planificador::setCola1(int** arreglo_rr1, int contador_rr1, string* etiquetarr1) {
    for (int i = 0; i < 5; i++) {   
        for (int j = 0; j < 4; j++) {
            colaRR[i][j] = 0;
        }
    }
    contador = contador_rr1;
    posicion = contador;
    for (int i = 0; i < contador; i++) {
        etiqueta_rr1[i] = etiquetarr1[i];
        for (int j = 0; j < 4; j++) {
            colaRR[i][j] = arreglo_rr1[i][j]; // Copia profunda
        }
    }
    cout << "\ncolarr1\n";
    for (int i = 0; i < contador; i++) {
        cout << etiqueta_rr1[i] << "  ";
        for (int j = 0; j < 4; j++) {
            cout << colaRR[i][j] << "  ";
        }
        cout << "\n";
    }
}

void Planificador::setCola2(int** arreglo_rr2, int contador_rr2, string* etiquetarr2) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            colaRR2[i][j] = 0;
        }
    }
    contador2 = contador_rr2;
    for (int i = 0; i < contador_rr2; i++) {
        etiqueta_rr2[i] = etiquetarr2[i];
        for (int j = 0; j < 4; j++) {
            colaRR2[i][j] = arreglo_rr2[i][j]; // Copia profunda
        }
    }
    cout << "\ncolarr2\n";
    for (int i = 0; i < contador2; i++) {
        cout << etiqueta_rr2[i] << "  ";
        for (int j = 0; j < 4; j++) {
            cout << colaRR2[i][j] << "  ";
        }
        cout << "\n";
    }
}

void Planificador::setColaFcfs(int** arreglo_Fcfs, int contador_fcfs, string* etiquetafcfs) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            colaFcfs[i][j] = 0;
        }
    }
    contador3 = contador_fcfs;
    for (int i = 0; i < contador3; i++) {
        etiqueta_fcfs[i] = etiquetafcfs[i];
        for (int j = 0; j < 4; j++) {
            colaFcfs[i][j] = arreglo_Fcfs[i][j]; // Copia profunda
        }
    }
    cout << "\ncolaFcfs\n";
    for (int i = 0; i < contador3; i++) {
        cout << etiqueta_fcfs[i] << "  ";
        for (int j = 0; j < 4; j++) {
            cout << colaFcfs[i][j] << "  ";
        }
        cout << "\n";
    }
}

void Planificador::setqq1(int q1) { //cola roundRobin (quantum 1)
    queue1 = q1;
}

void Planificador::setqq2(int q2) { //Cola round Robin (quantum 2)
    queue2 = q2;
}

void Planificador::correr1() {
    cout<<"\nEjecución Round Robin (3)\n";
    int contadorciclo = 0;
    int reloj_anterior = 0;
    bool parada = false;
    int temp = 0;
    string etiq_temp;
    if (colaRR[0][0] < queue1) {
        int dif = 0;
        dif = queue1 - colaRR[0][0];
        setReloj(dif);
        colaRR[0][0] = colaRR[0][0] - dif;
    } else {
        colaRR[0][0] = colaRR[0][0] - queue1; //inicia el primero proceso mientras se organiza
        setReloj(queue1); //incrementa el reloj
    }
    etiq_temp = etiqueta_rr1[0]; //asigna la etiqueta
    setRT(etiq_temp, temp); //asigno valores al arreglo tiempo de respuesta segun la etiqueta
    setCT(etiq_temp, getReloj());

    if (colaRR[0][0] != 0) {
        moverproceso(etiq_temp);
        for(int i=0; i<4;i++){
            colaRR[0][i]=0;
        }
    }

    do {
        int maximo = 0;
        for (int i = 1; i < contador; i++) {
            if (colaRR[i][3] > maximo) { // Comparar con la tercera columna
                maximo = colaRR[i][3];
                etiq_temp = etiqueta_rr1[i]; //llevar la etiqueta con mayor prioridad
                break;
            }
        }
        if (maximo == 0) {
            parada = true;
            continue;
        }

        reloj_anterior = getReloj(); //tomar el valor antes de
        for (int k = 1; k < contador; k++) { // Buscamos añadir el proceso por la etiqueta
            if (etiqueta_rr1[k] == etiq_temp) { //buscamos la etiqueta para obtener la posicion
                if (colaRR[k][0] >= queue1) {
                    colaRR[k][0] = colaRR[k][0] - queue1;
                    moverproceso(etiq_temp);
                    setReloj(queue1);
                } else if (colaRR[k][0] < queue1) {
                    int dif = queue1 - colaRR[k][0];
                    colaRR[k][0] = colaRR[k][0] - dif;
                    setReloj(dif);
                }
                setRT(etiq_temp, reloj_anterior);
                setCT(etiq_temp, getReloj());
                for (int j = 0; j < 4; j++) { //dejando la cola vacia
                    colaRR[k][j] = 0;
                }
            }
        }
        contadorciclo++;
    } while (contadorciclo < contador && !parada);
    imprimirColas();
    cout<<"\nAqui termina la ejecucion de la primera cola\n";
}

void Planificador::correr2() {
    cout<<"\nEjecución Round Robin (5)\n";
    int contadorciclo = 0;
    int reloj_anterior = 0;
    bool parada = false;
    string etiq_temp=" ";
    do {
        int maximo = 0;
        for (int i = 0; i < tamanoA; i++) {
            if (colaRR2[i][3] > maximo) { // Comparar con la tercera columna      
                maximo = colaRR2[i][3];
                etiq_temp = etiqueta_rr2[i]; //llevar la etiqueta con mayor prioridad  
            }
        }
        if (maximo == 0) {
            parada = true;
            continue;
        }

        reloj_anterior = getReloj(); //tomar el valor antes de
        for (int k = 0; k < tamanoA; k++) { // Buscamos añadir el proceso por la etiqueta
            if (etiqueta_rr2[k] == etiq_temp) { //buscamos la etiqueta para obtener la posicion
                if (colaRR2[k][0] >= queue2) {
                    colaRR2[k][0] = colaRR2[k][0] - queue2;
                    if(colaRR2[k][0]!=0){
                        moverprocesoaFcfs(etiq_temp);
                    }
                    setReloj(queue2);
                } else if (colaRR2[k][0] < queue2) {
                    int dif = queue2 - colaRR2[k][0];
                    colaRR2[k][0] = colaRR2[k][0] - dif;
                    setReloj(dif+1);
                }
                setRT(etiq_temp, reloj_anterior);
                setCT(etiq_temp, getReloj());
                for (int j = 0; j < 4; j++) { //dejando la cola vacia
                    colaRR2[k][j] = 0;
                }
            }
        }
        contadorciclo++;
    } while (contadorciclo < tamanoA && !parada);
    imprimirColas();
    cout<<"\nAqui termina la ejecucion de la segunda cola\n";

}

void Planificador::correr3() {
    cout<<"\nEjecución FCFS \n";
    int contadorciclo = 0;
    int reloj_anterior = 0;
    bool parada = false;
    string etiq_temp=" ";
    do {
        int maximo = 0;
        for (int i = 0; i < tamanoA; i++) {
            if (colaFcfs[i][3] > maximo) { // Comparar con la tercera columna      
                maximo = colaFcfs[i][3];
                etiq_temp = etiqueta_fcfs[i]; //llevar la etiqueta con mayor prioridad  
            }
        }
        if (maximo == 0) {
            parada = true;
            continue;
        }

        reloj_anterior = getReloj(); //tomar el valor antes de
        for (int k = 0; k < tamanoA; k++) { // Buscamos añadir el proceso por la etiqueta
            if (etiqueta_fcfs[k] == etiq_temp) { //buscamos la etiqueta para obtener la posicion
                setReloj(colaFcfs[k][0]);
                //cout<<colaFcfs[k][0]<<" el orden \n";
                setRT(etiq_temp, reloj_anterior);
                setCT(etiq_temp, getReloj());
                for (int j = 0; j < 4; j++) { //dejando la cola vacia
                    colaFcfs[k][j] = 0;
                }
            }

        }
        contadorciclo++;
    } while (contadorciclo < tamanoA && !parada);
    imprimirColas();
    cout<<"\nAqui termina la ejecucion de todo\n";

}

void Planificador::moverproceso(string eti_buscado) {
    string etiqueta_buscada = eti_buscado;
    for (int i = 0; i < contador; i++) {
        if (etiqueta_rr1[i] == etiqueta_buscada) {
            for (int j = 2; j < 5; j++) {
                if (etiqueta_rr2[j] == "") {  // Comparar con una cadena vacía
                    etiqueta_rr2[j] = etiqueta_buscada;
                    for (int k = 0; k < 4; k++) {
                        colaRR2[j][k] = colaRR[i][k];
                    }
                    contador2++;
                    break;
                }
            }
            break;  // Salir del bucle una vez que se encuentra y mueve el proceso
        }
    }

}

void Planificador::moverprocesoaFcfs(string eti_buscado){
    string etiqueta_buscada = eti_buscado;
    for (int i = 0; i < tamanoA; i++) {
        if (etiqueta_rr2[i] == etiqueta_buscada) {
            for (int j = 0; j < 5; j++) {
                if (etiqueta_fcfs[j] == "") {  // Comparar con una cadena vacía
                    etiqueta_fcfs[j] = etiqueta_buscada;
                    for (int k = 0; k < 4; k++) {
                        colaFcfs[j][k] = colaRR2[i][k];
                    }
                    contador3++;
                    break;
                }
            }
            break;  // Salir del bucle una vez que se encuentra y mueve el proceso
        }
    }
}

void Planificador::imprimirColas() {
    cout << "\ncolarr1\n";
    for (int i = 0; i < contador; i++) {
        cout << etiqueta_rr1[i] << "  ";
        for (int j = 0; j < 4; j++) {
            cout << colaRR[i][j] << "  ";
        }
        cout << "\n";
    }

    std::cout << "colaRR2:" << std::endl;
    for (int i = 0; i < tamanoA-1; i++) {
        std::cout << etiqueta_rr2[i] << "  ";
        for (int j = 0; j < 4; j++) {
            std::cout << colaRR2[i][j] << "  ";
        }
        std::cout << std::endl;
    }
        cout << "\ncolaFcfs\n";
    for (int i = 0; i < contador3; i++) {
        cout << etiqueta_fcfs[i] << "  ";
        for (int j = 0; j < 4; j++) {
            cout << colaFcfs[i][j] << "  ";
        }
        cout << "\n";
    }
}

void Planificador::setCT(string etiq_entradact, int ct_entrada) {
    for (int i = 0; i < tamanoA; i++) {
        if (etiquetaA[i] == etiq_entradact) {
            ct[i] = ct_entrada;
            break;
        }
    }
}

void Planificador::setRT(string etiq_entradart, int rt_entrada) {
    for (int i = 0; i < tamanoA; i++) {
        if (etiquetaA[i] == etiq_entradart) {
            if (i==0){
                rt[0]=0;
            }else if (rt[i]==0)
            {
                rt[i] = rt_entrada;
            }

            break;
        }
    }
}

void set_time_ejecutado(string, int) {
    // Implementación de set_time_ejecutado
}

int Planificador::getReloj() {
    return reloj;
}

void Planificador::setReloj(int incremento_reloj) {
    reloj += incremento_reloj;
}

int Planificador::getCT(int pos) {
    return ct[pos];
}

int Planificador::getRT(int pos) {
    return rt[pos];
}

Planificador::~Planificador() {
    // Liberar memoria asignada dinámicamente
    for (int i = 0; i < 5; i++) {
        delete[] arregloA[i];
    }
    delete[] arregloA;
    delete[] etiquetaA;

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

    // Libera la memoria asignada a colaFcfs
    for (int i = 0; i < 5; i++) {
        delete[] colaFcfs[i]; // Libera cada fila
    }
    delete[] colaFcfs; // Libera el puntero principal

    delete[] etiqueta_rr1;
    delete[] etiqueta_rr2;
    delete[] etiqueta_fcfs;
    delete[] ct;
    delete[] rt;
}