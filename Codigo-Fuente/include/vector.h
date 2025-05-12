#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

// Función para crear un vector con las rutas relativas de los archivos en un directorio
std::vector<std::string> crearVector(const std::string& directorio);

// Función de búsqueda secuencial
int busquedaSecuencial(const std::vector<std::string>& v, const std::string& nombreBuscado);

// Función de búsqueda binaria 
int busquedaBinaria(const std::vector<std::string>& v, const std::string& nombreBuscado);

// Función para eliminar un elemento del vector
void eliminaElemento(std::vector<std::string> &v, std::string x);

// Función para insertar un elemento manteniendo el orden
void insertaElemento(std::vector<std::string> &v, std::string x);

void imprimirVector(const std::vector<std::string>& v);

// Quicksort
int partition(std::vector<std::string>& v, int L, int R);
void quickSort(std::vector<std::string>& v, int L, int R);

#endif // VECTOR_H