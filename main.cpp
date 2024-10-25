#include "Algoritmo.h"
#include "Planificador.h"
#include <iostream>

void bienvenida() {
    Algoritmo myAlgoritmo = Algoritmo();
    myAlgoritmo.ejecutar(3, 5);
}

int mostrarMenu() {
    int opcion;
    std::cout << "Menu:\n";
    std::cout << "1. Ejecutar\n";
    std::cout << "2. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;
    return opcion;
}

int main() {
    int opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                bienvenida();
                break;
            case 2:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 2);
    return 0;
}
