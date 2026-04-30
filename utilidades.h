#ifndef UTILIDADES_H
#define UTILIDADES_H

namespace CharStyle {
// Convierte texto ASCII a una cadena de caracteres '0' y '1'
char* textoABinario(const char* texto, int longitud);

// Convierte una cadena de '0's y '1's de vuelta a texto ASCII
char* binarioATexto(const char* binario, int longitudBinario);

// Contadores para evaluar las reglas de codificacion
int contarUnos(const char* bloque, int n);
int contarCeros(const char* bloque, int n);
}

namespace StringStyle {
// Las funciones de string las haremos en el Commit 3
}

#endif // UTILIDADES_H
