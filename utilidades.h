#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>

namespace CharStyle {
char* textoABinario(const char* texto, int longitud);
char* binarioATexto(const char* binario, int longitudBinario);
int contarUnos(const char* bloque, int n);
int contarCeros(const char* bloque, int n);
}

namespace StringStyle {
// Retornamos por valor ya que string gestiona su propia memoria
std::string textoABinario(const std::string& texto);
std::string binarioATexto(const std::string& binario);

int contarUnos(const std::string& bloque);
int contarCeros(const std::string& bloque);
}

#endif // UTILIDADES_H
