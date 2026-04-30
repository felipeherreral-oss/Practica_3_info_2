#ifndef CODIFICACION_H
#define CODIFICACION_H

#include <string>

namespace CharStyle {
void codificarMetodo1(const char* archivoEntrada, const char* archivoSalida, int semilla);
void decodificarMetodo1(const char* archivoEntrada, const char* archivoSalida, int semilla);
void codificarMetodo2(const char* archivoEntrada, const char* archivoSalida, int semilla);
void decodificarMetodo2(const char* archivoEntrada, const char* archivoSalida, int semilla);
}

namespace StringStyle {
void codificarMetodo1(const std::string& archivoEntrada, const std::string& archivoSalida, int semilla);
void decodificarMetodo1(const std::string& archivoEntrada, const std::string& archivoSalida, int semilla);
void codificarMetodo2(const std::string& archivoEntrada, const std::string& archivoSalida, int semilla);
void decodificarMetodo2(const std::string& archivoEntrada, const std::string& archivoSalida, int semilla);
}

#endif // CODIFICACION_H
