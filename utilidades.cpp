#include "utilidades.h"

#include "utilidades.h"

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


namespace StringStyle {

}
