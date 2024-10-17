#include "Fcfs.h"
#include "Algoritmo.h"
#include "RoundRobin.h"
#include <iostream>

void bienvenida(){
  string aux;
  int opcion;
  Algoritmo myalgoritmo = Algoritmo();

  do
  {
    cout<<" Selecciona alguno de los siguientes metodos de planificación"
    <<"\n1. RR(1), RR(3), SJF"
    <<"\n2. RR(3), RR(5), FCFS"
    <<"\n3. RR(2), RR(3), STCF."
    <<"\n4. Salir.";
    getline(cin, aux);
    opcion=(stoi(aux));

    switch (opcion)
    {
    case 1://ejcuto la primera planificacion
      myalgoritmo.ejecutar(1,3,"SJF");
      break;
    case 2://ejcuto la segunda planificacion
      myalgoritmo.ejecutar(1,3,"FCFS");
      break;
    case 3://ejcuto la tercera planificacion
      myalgoritmo.ejecutar(2,3,"STCF");
      break;
    case 4:
      cout<<"hasta la proxima";
      break;
    default:
      cout <<
      "Opcion invC!lida del menC:, ingrese nuevamente una opcion correcta!"
      << endl;
    }

  }while (opcion != 4);

}
int main(){
    string nombre;
       
    cout<<"di tu nomnre como sea gonorreaaaaaaa ";
    
    bienvenida();
    return 0;
}


