#include <vector>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

//Funciones de busqueda
int busquedaSecuencial(const std::vector <std::string> &v, const std::string& nombreBuscado);
int busquedaBinaria (const std::vector <std::string> &v, const std::string& nombreBuscado);

std::vector<std::string> crear_vector(const std::string& directorio);

//Funcion(es) para ordenar el vector ascendentemente (usamos quicksort ya que ordena in-place y la entrada es muy grande)
//Edit: finalmente decidimos usar std::sort(). Las razones estan en el informe.
int partition(std::vector<std::string>& v, int L, int R);
void quickSort(std::vector <std::string> &v, int L, int R);

//Funciones para insertar y eliminar elementos en el vector
int busquedaBinariaAdaptada (const std::vector <std::string> &v, const std::string& x);
void eliminaElemento(std:: vector <std::string> &v, std::string x);
void insertaElemento(std:: vector <std::string> &v, std::string x);

//Funcion para imprimir el vector
void imprimirVector(const std::vector<std::string>& v);