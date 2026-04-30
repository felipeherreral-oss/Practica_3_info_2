#include <iostream>
#include <string>
#include "codificacion.h"
#include "cajero.h"

using namespace std;

void menuCodificacion(bool usarString) {
    int opcion, metodo, semilla;
    string archivoIn, archivoOut;

    cout << "\n--- MENU DE CODIFICACION / DECODIFICACION ---" << endl;
    cout << "1. Codificar archivo" << endl;
    cout << "2. Decodificar archivo" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    cout << "Ingrese el metodo (1 o 2): ";
    cin >> metodo;
    cout << "Ingrese la semilla (n bits): ";
    cin >> semilla;
    cout << "Nombre del archivo de entrada (ej. entrada.txt): ";
    cin >> archivoIn;
    cout << "Nombre del archivo de salida (ej. salida.dat): ";
    cin >> archivoOut;

    if (usarString) {
        if (opcion == 1 && metodo == 1) StringStyle::codificarMetodo1(archivoIn, archivoOut, semilla);
        else if (opcion == 2 && metodo == 1) StringStyle::decodificarMetodo1(archivoIn, archivoOut, semilla);
        else if (opcion == 1 && metodo == 2) StringStyle::codificarMetodo2(archivoIn, archivoOut, semilla);
        else if (opcion == 2 && metodo == 2) StringStyle::decodificarMetodo2(archivoIn, archivoOut, semilla);
    } else {
        if (opcion == 1 && metodo == 1) CharStyle::codificarMetodo1(archivoIn.c_str(), archivoOut.c_str(), semilla);
        else if (opcion == 2 && metodo == 1) CharStyle::decodificarMetodo1(archivoIn.c_str(), archivoOut.c_str(), semilla);
        else if (opcion == 1 && metodo == 2) CharStyle::codificarMetodo2(archivoIn.c_str(), archivoOut.c_str(), semilla);
        else if (opcion == 2 && metodo == 2) CharStyle::decodificarMetodo2(archivoIn.c_str(), archivoOut.c_str(), semilla);
    }

    cout << "Operacion finalizada. Revise el archivo de salida." << endl;
}

int main() {
    int opcionPrincipal;
    bool usarString = false;

    do {
        cout << "\n========================================" << endl;
        cout << "   PRACTICA 3 - INFORMATICA II   " << endl;
        cout << "========================================" << endl;
        cout << "Modo actual: " << (usarString ? "Clase std::string" : "Arreglos de Char") << endl;
        cout << "1. Cambiar modo (Char / String)" << endl;
        cout << "2. Probar Codificacion/Decodificacion" << endl;
        cout << "3. Entrar a la Aplicacion Cajero" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1:
            usarString = !usarString;
            cout << "Modo cambiado exitosamente." << endl;
            break;
        case 2:
            menuCodificacion(usarString);
            break;
        case 3:
            // Llamamos a la lógica del cajero que desarrollaremos en los próximos pasos
            Cajero::iniciarSistema();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (opcionPrincipal != 0);

    return 0;
}
