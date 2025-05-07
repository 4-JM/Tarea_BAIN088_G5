#include "vector.h"
#include <filesystem>
#include <iostream>

using namespace std;

namespace fs = std::filesystem;

int busquedaSecuencial(const vector <string> &v, const string& x){
    int n = v.size();
    for (int i = 0; i < n; i++){
        if (v[i] > x) {break;}
        if (v[i] == x){return i;}
    }
    return -1;
}

int busquedaBinaria (const vector <string> &v, const string& x){
    int l, m, r, n;
    n = v.size();
    l = 0;
    r = n - 1;
    m = r/2;
    while (l <= r){
        if (x == v[m]){
            return m;
        }
        else{
            if (x < v[m]){
                r = m - 1;
            }
            else{ 
                l = m + 1;
            } 
        }
        m = (l + r)/2;
    }
    return -1;

}


// Función para obtener todos los archivos de un directorio (recursivo)
vector<string> crear_vector(const string& directorio) {
    vector<string> archivos;
    
    try {
        // Recorrido recursivo del directorio
        for (const auto& entry : fs::recursive_directory_iterator(directorio)) {
            if (fs::is_regular_file(entry)) {
                // Obtener ruta relativa
                string ruta = fs::relative(entry.path(), directorio).string();
                
                // Convertir separadores a / (opcional, para consistencia en Windows)
                ruta.replace(ruta.begin(), ruta.end(), '\\', '/');
                
                archivos.push_back(ruta);
            }
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Error al acceder al directorio: " << e.what() << endl;
    }
    
    return archivos;
}

//Implementa la funcion que particiona el vector y deja el elemento pivote en su posicion final (p)
int partition(vector<string>& v, int L, int R) {
    int random_pivot = L + rand() % (R - L + 1);
    swap(v[L], v[random_pivot]);
    string pv = v[L];
    int p = L;
    
    for (int i = L + 1; i <= R; i++) {
        if (v[i] <= pv) {
            p++;
            swap(v[i], v[p]);
        }
    }
    
    swap(v[L], v[p]);
    return p;
}

//Algoritmo de ordenamiento quicksort de toda la vida
void quickSort(vector<string>& v, int L, int R) {
    if (L < R) {
        int p = partition(v, L, R);
        quickSort(v, L, p - 1);
        quickSort(v, p + 1, R);
    }
}

int busquedaBinariaAdaptada (const vector <string> &v, const string& x){
    int l, m, r, n, pL, pR; //pL y pR son los valores previos de l y r respectivamente
    bool es_par; //este booleano indica si la funcion debe retornar pL o pR
    n = v.size();
    l = pL = 0;
    r = pR = n - 1;

    if (r%2 == 0){es_par = 1;}
    else{es_par = 0;}

    m = r/2;
    while (l <= r){
        if (x == v[m]){
            return -1;
        }
        else{
            if (x < v[m]){
                pR = r;
                r = m - 1;
            }
            else{ 
                pL = l;
                l = m + 1;
            } 
        }
        m = (l + r)/2;
    }
    if (es_par){
        return (pL + 1);
    }
    else{
        return (pR - 1);
    }
}

void eliminaElemento(vector <string> &v, string x){
    int indice = busquedaBinaria(v, x);
    if (indice != -1) {v.erase(v.begin() + indice);}
    else{
        cout << "Error. El elemento no está en el directorio" << endl;
    }
}

void insertaElemento(vector <string> &v, string x){
    int indice = busquedaBinariaAdaptada(v, x);
    if (indice != -1){
        v.insert(v.begin() + indice, x);
    }
    
}
    

void imprimirVector(const std::vector<std::string>& v) {
    cout << "=== Contenido del vector ===" << endl;
    for (const auto& ruta : v) {
        cout << ruta << endl;
    }
    cout << "=== Total: " << v.size() << " elementos ===" << endl;
}



/* TEST (IGNORAR)
int main(){
    std::vector<std::string> rutas = {
        "docs/informe.txt",
        "src/main.py",
        "data/config.json",
        "img/logo.png",
        "backup/2023.zip",
        "lib/utils.cpp",
        "README.md",
        "config.ini",
        "tests/unit_test.py",
        "assets/icon.jpg",
        "docs/contrato.pdf",
        "src/helpers.hpp",
        "data/users.csv",
        "img/portada.webp",
        "backup/2022.zip",
        "lib/colors.h",
        "CHANGELOG.md",
        "settings.toml",
        "tests/integration_test.py",
        "assets/background.png",
        "docs/presentacion.pptx",
        "src/algorithm.cpp",
        "data/stats.xlsx",
        "img/foto1.jpg",
        "backup/january.tar.gz",
        "lib/geometry.py",
        "LICENSE",
        "environment.yml",
        "tests/performance_test.py",
        "assets/sprite.svg",
        "docs/manual.docx",
        "src/network.rs",
        "data/transactions.db",
        "img/avatar.jpeg",
        "backup/march.zip",
        "lib/audio.wav",
        "CONTRIBUTING.md",
        "requirements.txt",
        "tests/security_test.py",
        "assets/theme.css",
        "docs/reporte.txt",
        "src/database.sql",
        "data/sample.json",
        "img/banner.gif",
        "backup/old_version.rar",
        "lib/video.mp4",
        "Makefile",
        "docker-compose.yml",
        "tests/ui_test.py",
        "assets/font.ttf"
    };
    int largo = rutas.size() - 1;
    cout << "Vector desordenado: " << endl;
    printVector(rutas);
    
    quick_sort(rutas, 0, largo);
    cout << "Vector Ordenado: " << endl;
    printVector(rutas);
    cout << "\n";
    string inserta = "ARRIBA.txt";
    string inserta2 = "zzzzzzz.py";
    string inserta3 = "holaquehace.png";
    inserta_elemento(rutas, inserta);
    inserta_elemento(rutas, inserta2);
    inserta_elemento(rutas, inserta3);
    printVector(rutas);
}
*/