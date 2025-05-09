#include <iostream>
#include <vector>
#include <chrono>
#include "experimentacion.h"

using namespace std;

// Función principal que ejecuta los experimentos
int main() {

    srand(time(nullptr));
    // Definir el directorio de entrada
    string directorio = "/home/jm_4/Taller_3/TareaGrupal_INFO088_Grupo5_2025-1/mediumDir";  // Actualiza esto con la ruta correcta

    // Crear el vector de archivos y medir su tiempo de creación
    vector<string> archivos;
    auto duracion_creacion = creacionVector(archivos, directorio);

    // Imprimir el tiempo de creación del vector
    cout << "Tiempo de creacion del vector: " << duracion_creacion.count() << " microsegundos" << endl;

    // Realizar la búsqueda secuencial antes de ordenar el vector
    auto duracion_sec = testSecSearch(archivos);
    cout << "Tiempo de busqueda secuencial: " << duracion_sec.count() << " microsegundos" << endl;

    /* Ordenar el vector utilizando QuickSort (finalmente lo cambiamos por std::sort)
    )
    
    cout << "Ordenando vector con quicksort..." << endl; 
    auto duracion_orden = ordenarVector(archivos);
    cout << "Vector ordenado con quicksort. Demoro " << duracion_orden.count() << " microsegundos" << endl;

    */

    //Ordenamos el vector con el sort de la STL

    cout << "Ordenandoo vector.." << endl;
    auto duracion_orden = ordenarVector(archivos);
    cout << "Vector ordenado. Demoro " << duracion_orden.count() << " microsegundos" <<endl;

    // Realizar la búsqueda binaria después de ordenar

    cout << "Realizando busqueda binaria..." << endl;
    auto duracion_bin = testBinSearch(archivos);
    cout << "Tiempo de busqueda binaria: " << duracion_bin.count() << " microsegundos" << endl;

    // Realizar la eliminación de elementos
    cout << "Eliminando elementos del vector..." << endl;
    auto duracion_elim = testEliminacion(archivos);
    cout << "Tiempo de eliminacion: " << duracion_elim.count() << " microsegundos" << endl;

    // Realizar la inserción de elementos
    int tamaño_inicial = archivos.size();
    cout << "Tamaño inicial: " << archivos.size() << endl;
    cout << "Ingresando elementos al vector..." << endl;
    auto duracion_insercion = testInsercion(archivos);
    cout << "Tiempo de insercion: " << duracion_insercion.count() << " microsegundos" << endl;
    cout << "Tamaño final: " << archivos.size() << endl;
    cout << "Inserciones efectivas: " << archivos.size() - tamaño_inicial << endl;

}
