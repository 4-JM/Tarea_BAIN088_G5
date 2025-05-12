#include "vector.h"
#include <iostream>
using namespace std;

int busquedaSecuencial(const vector<string>& v, const string& nombreBuscado) {
    for (size_t i = 0; i < v.size(); ++i) {
        // Extraer solo el nombre del archivo de la ruta almacenada
        fs::path ruta(v[i]);
        string nombreArchivo = ruta.filename().string();
        
        if (nombreArchivo == nombreBuscado) {
            return static_cast<int>(i);
        }
    }
    return -1;
}
int busquedaBinaria(const vector<string>& v, const string& nombreBuscado) {
    int l, m, r, n;
    n = v.size();
    l = 0;
    r = n - 1;

    while (l <= r) {
        m = (l + r) / 2;
        // Extraer solo el nombre del archivo de la ruta almacenada
        fs::path ruta(v[m]);
        string nombreArchivo = ruta.filename().string();
        if (nombreBuscado == nombreArchivo) {
            return m;
        } else {
            if (nombreBuscado < nombreArchivo) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    return -1;
}

// Función para obtener todos los archivos de un directorio (recursivo)
vector<string> crearVector(const string& directorio) {
    vector<string> archivos;
    
    try {
        // Recorrido recursivo del directorio
        for (const auto& entry : fs::recursive_directory_iterator(directorio)) {
            if (fs::is_regular_file(entry)) {
                // Obtener ruta relativa
                string ruta = fs::relative(entry.path(), directorio).string();
                archivos.push_back(ruta);
            }
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Error al acceder al directorio: " << e.what() << endl;
    }
    
    return archivos;
}

void eliminaElemento(vector <string> &v, string x){
    int indice = busquedaBinaria(v, x);
    if (indice != -1) {v.erase(v.begin() + indice);}
    else{
        cout << "Error. El elemento no está en el directorio" << endl;
    }
}

void insertaElemento(vector<std::string> &v, string x) {
    // Encontrar posición usando lower_bound 
    auto it = lower_bound(v.begin(), v.end(), x);

    // Solo insertar si no es duplicado
    if (it == v.end() || *it != x) {
        v.insert(it, x); // Inserta manteniendo el orden
    }
}
void imprimirVector(const vector<string>& v) {
    cout << "=== Contenido del vector ===" << endl;
    for (const auto& ruta : v) {
        cout << ruta << endl;
    }
    cout << "=== Total: " << v.size() << " elementos ===" << endl;
}

int partition(vector<string>& v, int L, int R) {
    // Elegir un pivote aleatorio entre L y R 
    int pivotIndex = L + rand() % (R - L + 1);
    string pivot = v[pivotIndex];
    
    // Mover el pivote al inicio del subarray
    swap(v[pivotIndex], v[L]);
    
    int i = L; // Índice del pivote
    
    // Recorrer desde L+1 hasta R
    for (int j = L + 1; j <= R; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    
    // Colocar el pivote en su posición final
    swap(v[L], v[i]);
    
    return i; // Retornar la posición final del pivote
}

void quickSort(vector<string>& v, int L, int R) {
    if (L < R) {
        int p = partition(v, L, R);
        quickSort(v, L, p - 1);  // Ordenar subarray izquierdo
        quickSort(v, p + 1, R);  // Ordenar subarray derecho
    }
}


// FUNCIONES QUE NO SE IMPLEMENTARON EN EL CODIGO FINAL

/*
A continuacion, la funcion busquedaBinariaAdaptada retorna el indice donde se deberia insertar 
un nuevo elemento en un vector ordenado, manteniendo el orden. Si bien, comprobamos empiricamente que funciona
en todos los casos que probamos, no sabemos si existe algun caso de borde que se nos haya pasado. Por esta razon,
usamos "std::lower_bound" para insertar el nuevo elemento en el vector ordenado. Cabe destacar que se nos ocurrio a 
nosotros esta funcion (busquedaBinariaAdaptada).

// Busca la posición donde se debería insertar el string 'x' en un vector ordenado 'v'
// Retorna -1 si ya existe (no se debe insertar), o el índice sugerido de inserción

int busquedaBinariaAdaptada (const vector<string>& v, const string& x){
    int l, m, r, n, pL, pR;
    bool es_par; // Indica si el tamaño del vector es par (esto afecta la inserción)

    n = v.size();
    l = pL = 0;
    r = pR = n - 1;

    // Determinamos si el tamaño del vector es par para ajustar el índice de inserción
    es_par = (r % 2 == 0);

    m = r / 2;

    while (l <= r){
        if (x == v[m]){
            // Ya existe el elemento, no se debe insertar
            return -1;
        }
        else if (x < v[m]){
            // Guardamos el valor anterior de r como pR
            pR = r;
            r = m - 1;
        }
        else {
            // Guardamos el valor anterior de l como pL
            pL = l;
            l = m + 1;
        }
        m = (l + r) / 2;
    }

    // Política de inserción: si el tamaño original es par, insertamos después de pL
    // Si es impar, insertamos antes de pR
    return es_par ? (pL + 1) : (pR - 1);
}
*/