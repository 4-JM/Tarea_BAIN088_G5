#ifndef EXPERIMENTACION_H
#define EXPERIMENTACION_H

#include <string>
#include <chrono>
#include <cstdlib>
#include "vector.h"

// Constante para número de repeticiones en los experimentos
#define REP 100000 

// Función para crear el vector y medir el tiempo
std::chrono::microseconds creacionVector(std::vector<std::string>& vec, const std::string directorio);

// Función para ordenar el vector y medir el tiempo
std::chrono::microseconds ordenarVector(std::vector<std::string> &v);

// Función auxiliar para obtener un nombre aleatorio del vector
std::string obtenerNombreAleatorio(const std::vector<std::string>& vec);

// Funciones de test para las diferentes operaciones
std::chrono::microseconds testSecSearch(std::vector<std::string> &vec);
std::chrono::microseconds testBinSearch(std::vector<std::string> &vec);
std::chrono::microseconds testEliminacion(std::vector<std::string> &vec);
std::chrono::microseconds testInsercion(std::vector<std::string> &vec);

#endif // EXPERIMENTACION_H