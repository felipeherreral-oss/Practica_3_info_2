#include "codificacion.h"
#include "utilidades.h"
#include <fstream>

using namespace std;

namespace CharStyle {

// =========================================================
// METODO 1 - CHAR
// =========================================================
void codificarMetodo1(const char* archivoEntrada, const char* archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary | ios::ate);
    if (!entrada.is_open()) return;

    streamsize tamano = entrada.tellg();
    entrada.seekg(0, ios::beg);

    char* buffer = new char[tamano];
    entrada.read(buffer, tamano);
    entrada.close();

    char* binario = textoABinario(buffer, tamano);
    int lenBinario = tamano * 8;

    char* codificado = new char[lenBinario + 1];
    codificado[lenBinario] = '\0';

    for (int i = 0; i < lenBinario; i += semilla) {
        int fin = (i + semilla > lenBinario) ? lenBinario : i + semilla;
        int tamBloque = fin - i;

        if (i == 0) {
            for (int j = 0; j < tamBloque; ++j) {
                codificado[i + j] = (binario[i + j] == '1') ? '0' : '1';
            }
        } else {
            int ceros = contarCeros(binario + i - semilla, semilla);
            int unos = contarUnos(binario + i - semilla, semilla);

            for (int j = 0; j < tamBloque; ++j) {
                int pos = j + 1;
                bool invertir = false;

                if (unos == ceros) invertir = true;
                else if (ceros > unos && pos % 2 == 0) invertir = true;
                else if (unos > ceros && pos % 3 == 0) invertir = true;

                codificado[i + j] = invertir ? ((binario[i + j] == '1') ? '0' : '1') : binario[i + j];
            }
        }
    }

    char* salidaBytes = binarioATexto(codificado, lenBinario);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaBytes, lenBinario / 8);
        salida.close();
    }

    delete[] buffer;
    delete[] binario;
    delete[] codificado;
    delete[] salidaBytes;
}

void decodificarMetodo1(const char* archivoEntrada, const char* archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary | ios::ate);
    if (!entrada.is_open()) return;

    streamsize tamano = entrada.tellg();
    entrada.seekg(0, ios::beg);

    char* buffer = new char[tamano];
    entrada.read(buffer, tamano);
    entrada.close();

    char* binario = textoABinario(buffer, tamano);
    int lenBinario = tamano * 8;

    char* decodificado = new char[lenBinario + 1];
    decodificado[lenBinario] = '\0';

    for (int i = 0; i < lenBinario; i += semilla) {
        int fin = (i + semilla > lenBinario) ? lenBinario : i + semilla;
        int tamBloque = fin - i;

        if (i == 0) {
            for (int j = 0; j < tamBloque; ++j) {
                decodificado[i + j] = (binario[i + j] == '1') ? '0' : '1';
            }
        } else {
            int ceros = contarCeros(decodificado + i - semilla, semilla);
            int unos = contarUnos(decodificado + i - semilla, semilla);

            for (int j = 0; j < tamBloque; ++j) {
                int pos = j + 1;
                bool invertir = false;

                if (unos == ceros) invertir = true;
                else if (ceros > unos && pos % 2 == 0) invertir = true;
                else if (unos > ceros && pos % 3 == 0) invertir = true;

                decodificado[i + j] = invertir ? ((binario[i + j] == '1') ? '0' : '1') : binario[i + j];
            }
        }
    }

    char* salidaTexto = binarioATexto(decodificado, lenBinario);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaTexto, lenBinario / 8);
        salida.close();
    }

    delete[] buffer;
    delete[] binario;
    delete[] decodificado;
    delete[] salidaTexto;
}

// =========================================================
// METODO 2 - CHAR (Desplazamiento Circular)
// =========================================================
void codificarMetodo2(const char* archivoEntrada, const char* archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary | ios::ate);
    if (!entrada.is_open()) return;

    streamsize tamano = entrada.tellg();
    entrada.seekg(0, ios::beg);

    char* buffer = new char[tamano];
    entrada.read(buffer, tamano);
    entrada.close();

    char* binario = textoABinario(buffer, tamano);
    int lenBinario = tamano * 8;

    char* codificado = new char[lenBinario + 1];
    codificado[lenBinario] = '\0';

    for (int i = 0; i < lenBinario; i += semilla) {
        int fin = (i + semilla > lenBinario) ? lenBinario : i + semilla;
        int tamBloque = fin - i;
        char ultimoBit = binario[fin - 1];

        codificado[i] = ultimoBit; // Desplazamiento derecha
        for (int j = 1; j < tamBloque; ++j) {
            codificado[i + j] = binario[i + j - 1];
        }
    }

    char* salidaBytes = binarioATexto(codificado, lenBinario);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaBytes, lenBinario / 8);
        salida.close();
    }

    delete[] buffer;
    delete[] binario;
    delete[] codificado;
    delete[] salidaBytes;
}

void decodificarMetodo2(const char* archivoEntrada, const char* archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary | ios::ate);
    if (!entrada.is_open()) return;

    streamsize tamano = entrada.tellg();
    entrada.seekg(0, ios::beg);

    char* buffer = new char[tamano];
    entrada.read(buffer, tamano);
    entrada.close();

    char* binario = textoABinario(buffer, tamano);
    int lenBinario = tamano * 8;

    char* decodificado = new char[lenBinario + 1];
    decodificado[lenBinario] = '\0';

    for (int i = 0; i < lenBinario; i += semilla) {
        int fin = (i + semilla > lenBinario) ? lenBinario : i + semilla;
        int tamBloque = fin - i;
        char primerBit = binario[i];

        for (int j = 0; j < tamBloque - 1; ++j) {
            decodificado[i + j] = binario[i + j + 1]; // Desplazamiento izquierda
        }
        decodificado[fin - 1] = primerBit;
    }

    char* salidaTexto = binarioATexto(decodificado, lenBinario);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaTexto, lenBinario / 8);
        salida.close();
    }

    delete[] buffer;
    delete[] binario;
    delete[] decodificado;
    delete[] salidaTexto;
}
}

namespace StringStyle {

// =========================================================
// METODO 1 - STRING
// =========================================================
void codificarMetodo1(const string& archivoEntrada, const string& archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary);
    if (!entrada.is_open()) return;

    string contenido((istreambuf_iterator<char>(entrada)), istreambuf_iterator<char>());
    entrada.close();

    string binario = textoABinario(contenido);
    string codificado = "";

    for (size_t i = 0; i < binario.length(); i += semilla) {
        string bloqueActual = binario.substr(i, semilla);

        if (i == 0) {
            for (char bit : bloqueActual) codificado += (bit == '1') ? '0' : '1';
        } else {
            string bloqueAnterior = binario.substr(i - semilla, semilla);
            int ceros = contarCeros(bloqueAnterior);
            int unos = contarUnos(bloqueAnterior);

            for (size_t j = 0; j < bloqueActual.length(); ++j) {
                int pos = j + 1;
                bool invertir = false;

                if (unos == ceros) invertir = true;
                else if (ceros > unos && pos % 2 == 0) invertir = true;
                else if (unos > ceros && pos % 3 == 0) invertir = true;

                codificado += invertir ? ((bloqueActual[j] == '1') ? '0' : '1') : bloqueActual[j];
            }
        }
    }

    string salidaBytes = binarioATexto(codificado);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaBytes.c_str(), salidaBytes.length());
        salida.close();
    }
}

void decodificarMetodo1(const string& archivoEntrada, const string& archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary);
    if (!entrada.is_open()) return;

    string contenido((istreambuf_iterator<char>(entrada)), istreambuf_iterator<char>());
    entrada.close();

    string binario = textoABinario(contenido);
    string decodificado = "";

    for (size_t i = 0; i < binario.length(); i += semilla) {
        string bloqueActual = binario.substr(i, semilla);

        if (i == 0) {
            for (char bit : bloqueActual) decodificado += (bit == '1') ? '0' : '1';
        } else {
            string bloqueAnterior = decodificado.substr(i - semilla, semilla);
            int ceros = contarCeros(bloqueAnterior);
            int unos = contarUnos(bloqueAnterior);

            for (size_t j = 0; j < bloqueActual.length(); ++j) {
                int pos = j + 1;
                bool invertir = false;

                if (unos == ceros) invertir = true;
                else if (ceros > unos && pos % 2 == 0) invertir = true;
                else if (unos > ceros && pos % 3 == 0) invertir = true;

                decodificado += invertir ? ((bloqueActual[j] == '1') ? '0' : '1') : bloqueActual[j];
            }
        }
    }

    string salidaTexto = binarioATexto(decodificado);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaTexto.c_str(), salidaTexto.length());
        salida.close();
    }
}

// =========================================================
// METODO 2 - STRING (Desplazamiento Circular)
// =========================================================
void codificarMetodo2(const string& archivoEntrada, const string& archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary);
    if (!entrada.is_open()) return;

    string contenido((istreambuf_iterator<char>(entrada)), istreambuf_iterator<char>());
    entrada.close();

    string binario = textoABinario(contenido);
    string codificado = "";

    for (size_t i = 0; i < binario.length(); i += semilla) {
        string bloque = binario.substr(i, semilla);
        // Desplazamiento a la derecha: extraemos el último y le pegamos el resto
        char ultimo = bloque.back();
        codificado += ultimo;
        codificado += bloque.substr(0, bloque.length() - 1);
    }

    string salidaBytes = binarioATexto(codificado);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaBytes.c_str(), salidaBytes.length());
        salida.close();
    }
}

void decodificarMetodo2(const string& archivoEntrada, const string& archivoSalida, int semilla) {
    ifstream entrada(archivoEntrada, ios::binary);
    if (!entrada.is_open()) return;

    string contenido((istreambuf_iterator<char>(entrada)), istreambuf_iterator<char>());
    entrada.close();

    string binario = textoABinario(contenido);
    string decodificado = "";

    for (size_t i = 0; i < binario.length(); i += semilla) {
        string bloque = binario.substr(i, semilla);
        // Desplazamiento a la izquierda: extraemos el primero y lo pasamos al final
        char primero = bloque.front();
        decodificado += bloque.substr(1);
        decodificado += primero;
    }

    string salidaTexto = binarioATexto(decodificado);
    ofstream salida(archivoSalida, ios::binary);
    if (salida.is_open()) {
        salida.write(salidaTexto.c_str(), salidaTexto.length());
        salida.close();
    }
}
}
