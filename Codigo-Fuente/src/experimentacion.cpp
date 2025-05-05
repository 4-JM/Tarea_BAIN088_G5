#include "experimentacion.h"
#include "vector.h"
#include <chrono>

//std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

//std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

// Calculamos duracion en segudos
//auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(end - start);

// Imprimimos el tiempo de duracion
//printf("La creacion y ordenamiento del vector llevo %.4f segundos\n", static_cast<double>(duration_creation.count()));

// Calculamos duracion en nanosegundos
//auto duration_search = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

// Imprimimos el tiempo de duracion
//printf("La operacion de busqueda llevo en promedio %.4f nanosegundos\n", static_cast<double>(duration_search.count()) / REP);
using namespace std;

auto creacionDirectorio(vector <string> &vec, const string directorio){
    vector <string> vectorAux;

    //Iniciamos la marca de tiempo
    chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    //Creamos el vector
    vectorAux = crear_vector(directorio);
    //Terminamos la marca de tiempo
    chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    //Asignamos el vector creado al vector recibido como argumento para realizar los posteriores calculos
    vec = vectorAux;
    auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    return duration_creation;
}

auto testSecSearch(vector <string> &vec){
    int n, i, j, k;
    n = vec.size();
    //Iniciamos la marca de tiempo
    chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    for (i = 0; i < REP; i++){
        j = rand()%n;
        k = busquedaSecuencial(vec, vec[j]);
    }
    //Terminamos la marca de tiempo
    chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    return duration_creation; 
}

auto testBinSearch(vector <string> &vec){
    int n, i, j, k;
    n = vec.size();
    //Iniciamos la marca de tiempo
    chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    for (i = 0; i < REP; i++){
        j = rand()%n;
        k = busquedaBinaria(vec, vec[j]);
    }
    //Terminamos la marca de tiempo
    chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    return duration_creation; 
}


