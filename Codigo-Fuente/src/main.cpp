#include <iostream>
#include <ctime>
#include "experimentacion.h"

using namespace std;

int main() {

    // Inicializar la semilla para la generación de números aleatorios
    srand(time(nullptr));
    
    // Definir el directorio de entrada
    string directorio = "/home/jm_4/Taller_3/TareaGrupal_INFO088_Grupo5_2025-1/smallDir"; 

    // Crear el vector de archivos y medir su tiempo de creación
    cout << "Creando vector..." << endl;
    vector<string> archivos;
    auto duracion_creacion = creacionVector(archivos, directorio);
    
    cout << "Número de archivos cargados: " << archivos.size() << endl;
    cout << "Tiempo de creación del vector: " << duracion_creacion.count() << " microsegundos" << endl;
    cout << endl;
    
    // Realizar la búsqueda secuencial antes de ordenar el vector
    cout << "Experimentando con: Busqueda Secuencial..." << endl;
    auto duracion_sec = testSecSearch(archivos);
    cout << "Tiempo total para " << REP << " búsquedas secuenciales: " << duracion_sec.count() << " microsegundos" << endl;
    cout << endl;
    
    // Ordenamos el vector con QuickSort
    cout << "Ordenando vector con QuickSort..." << endl;
    auto duracion_orden = ordenarVector(archivos);
    cout << "Vector ordenado. Tiempo de ordenamiento: " << duracion_orden.count() << " microsegundos" << endl;
    cout << endl;
    
    // Realizar la búsqueda binaria después de ordenar
    cout << "Experimentando: Busqueda Binaria..." << endl;
    auto duracion_bin = testBinSearch(archivos);
    cout << "Tiempo total para " << REP << " búsquedas binarias: " << duracion_bin.count() << " microsegundos" << endl;
    cout << endl;
    
    // Realizar experimentos de eliminación
    cout << "Actualmente hay " << archivos.size() << " elementos en el vector. Se quieren eliminar " << REP << endl;
    cout << "Eliminando elementos (aleatorios)..." << endl;

    int before = archivos.size();
    auto duracion_elim = testEliminacion(archivos);
    int after = archivos.size();

    cout << "Se han realizado " << (before - after) << " eliminaciones. Esto ha tardado " << duracion_elim.count() << " microsegundos" << endl;
    cout << endl;
    
    // Realizar experimentos de inserción
    before = archivos.size();
    cout << "Actualmente hay " << before << " elementos en el vector. Ahora se quieren insertar " << REP << " elementos." << endl;

    auto duracion_insercion = testInsercion(archivos);
    after = archivos.size();
    cout << "Se hicieron "<< (after - before) << " inserciones, en un tiempo total de " << duracion_insercion.count() << " microsegundos" << endl;
    cout << "El tamanio final del vector es de " << after << " elementos." << endl;
    
    return 0;
}