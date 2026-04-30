#include "utilidades.h"

#include "utilidades.h"
using namespace std;

namespace CharStyle {

char* textoABinario(const char* texto, int longitudTexto) {
    int lenBinario = longitudTexto * 8;
    // Se reserva memoria dinamica, quien llame a la funcion debe usar delete[]
    char* binario = new char[lenBinario + 1];

    for (int i = 0; i < longitudTexto; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Desplazamiento de bits para evaluar desde el MSB al LSB
            binario[i * 8 + j] = ((texto[i] >> (7 - j)) & 1) ? '1' : '0';
        }
    }
    binario[lenBinario] = '\0';
    return binario;
}

char* binarioATexto(const char* binario, int longitudBinario) {
    int lenTexto = longitudBinario / 8;
    char* texto = new char[lenTexto + 1];

    for (int i = 0; i < lenTexto; ++i) {
        char caracter = 0;
        for (int j = 0; j < 8; ++j) {
            if (binario[i * 8 + j] == '1') {
                // Se enciende el bit correspondiente mediante una mascara
                caracter |= (1 << (7 - j));
            }
        }
        texto[i] = caracter;
    }
    texto[lenTexto] = '\0';
    return texto;
}

int contarUnos(const char* bloque, int n) {
    int conteo = 0;
    for (int i = 0; i < n; ++i) {
        if (bloque[i] == '1') conteo++;
    }
    return conteo;
}

int contarCeros(const char* bloque, int n) {
    int conteo = 0;
    for (int i = 0; i < n; ++i) {
        if (bloque[i] == '0') conteo++;
    }
    return conteo;
}

}
namespace StringStyle {

// Ya no necesitas poner std::string, solo string
string textoABinario(const string& texto) {
    string binario = "";
    for (char c : texto) {
        for (int i = 7; i >= 0; --i) {
            binario += ((c >> i) & 1) ? '1' : '0';
        }
    }
    return binario;
}

string binarioATexto(const string& binario) {
    string texto = "";
    for (size_t i = 0; i < binario.length(); i += 8) {
        char caracter = 0;
        for (int j = 0; j < 8; ++j) {
            if (binario[i + j] == '1') {
                caracter |= (1 << (7 - j));
            }
        }
        texto += caracter;
    }
    return texto;
}

int contarUnos(const string& bloque) {
    int conteo = 0;
    for (char bit : bloque) {
        if (bit == '1') conteo++;
    }
    return conteo;
}

int contarCeros(const string& bloque) {
    int conteo = 0;
    for (char bit : bloque) {
        if (bit == '0') conteo++;
    }
    return conteo;
}
}
