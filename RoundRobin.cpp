#include "RoundRobin.h"

RoundRobin::RoundRobin(){
        queue1=0; //    quantum1
        queue2=0; // quantum 2
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
    cout<<"\ncolarr2\n";
    for(int i=0; i<contador_rr2;i++){
        cout<<etiqueta_rr2[i]<<"  ";
        for(int j=0;j<4;j++){
            cout<<colaRR2[i][j]<<"  ";
        }
        cout<<"\n";
    } 
  
}
void RoundRobin::setqq1(int q1){//cola roundRobin (quantum 1)
    queue1=q1;
}   
void RoundRobin::setqq2(int q2){//Cola round Robin (quantum 2)
    queue2=q2;
}
void RoundRobin::procesarrr1(){
    int temp=0;
    string etiq_temp;
    colaRR[0][0]=colaRR[0][0]-queue1; //inicia el primero proceso mientras se organiza
    setReloj(queue1);//incrementa el reloj en 1
    etiq_temp=etiqueta_rr1[0][0]; //asigna la etiqueta
    temp=0;//asigna el tiempo de respuesta
    setRT(etiq_temp, temp); //asigno valores al arreglo tiempo de respuesta segun la etiqueta

    if (colaRR[0][0]==0){
        cout<<colaRR[0][0];
        cout<<"proceso "<<etiqueta_rr1[0]<<" terminó";
        setCT(etiq_temp, getReloj());
        setWT(etiq_temp, 0); //si se acaba iniciando entonces no espero nada
    }
    else{
        moverproceso(etiq_temp);
        cout<<etiq_temp;
        for(int i=0;i<contador;i++){ //dejando vacio el proceso que se movio
            for (int j=0;j<4;j++)
                colaRR[0][j]=0;
        }   
    }
    int contadorciclo=0;
    do{
        int maximo=0;
        for (int i = 0; i < contador; i++) {
            if (colaRR[i][3] > maximo) { // Comparar con la tercera columna
                maximo = arreglo[i][2];
                etiq_temp=etiqueta_rr1[i];
                break;
            }    
        }
        for (int k = 0; k < contador; k++) { // Buscamos añadir el proceso por la etiqueta
            int reloj_anterior;
            reloj_anterior=getReloj();
            if (etiqueta_rr1[k] == etiq_temp) {
                if (colaRR[k][0]>=queue1){
                    colaRR[k][0]=colaRR[k][0]-queue1;
                    moverproceso(etiq_temp);
                    setReloj(queue1);

                }else if(colaRR[k][0]<queue1){
                    int dif=queue1-colaRR[k][0];
                    colaRR[k][0]=colaRR[k][0]-dif;
                    setReloj(dif);
                    }
                    
                if (colaRR[k][0]==0){
                        cout<<"proceso "<<etiqueta_rr1[k]<<" terminó";
                        setCT(etiq_temp, getReloj());
                        setWT(etiq_temp, (reloj_anterior-colaRR[k][1]));
                }
            }
        }contadorciclo++;
    }while(contadorciclo< contador);
}       

void RoundRobin::moverproceso(string eti_buscado){
    bool encontrado = false; 
    string etiqueta_buscada = eti_buscado;

    for (int i = 0; i < contador; i++) {    
        for (int j = 0; j < 4; j++) {
            if (colaRR2[i][2] == 0) { // Encontramos un espacio vacío en la columna cola2

                for (int k = 0; k < contador; k++) { // Buscamos añadir el proceso por la etiqueta
                    if (etiqueta_rr1[k] == eti_buscado) {
                        colaRR2[i] = colaRR[k]; // Copiar el proceso junto con su etiqueta
                        etiqueta_rr2[k] = eti_buscado;
                        encontrado = true; // Marcamos que hemos encontrado el proceso
                        break; // Salir del ciclo interno (k)
                    }
                }

                // Verificamos si se encontró el proceso
                if (encontrado) {
                    break; // Salir del ciclo de columnas (j)
                }
            }
        }
    
        // Verificamos si se encontró el proceso en el ciclo de filas (i)
        if (encontrado) {
            break; // Salir del ciclo externo (i)
        }
    }


}
void RoundRobin::procesarrr2(){
    
        
  
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


