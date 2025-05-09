#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <algorithm>

#define REP 100000


std::chrono::microseconds creacionVector(std::vector <std::string> &vec, const std::string directorio);

std::chrono::microseconds testSecSearch(std::vector <std::string> &vec);

std::chrono::microseconds ordenarVector(std::vector<std::string>& v);

std::chrono::microseconds testBinSearch(std::vector <std::string> &vec);

std::chrono::microseconds testEliminacion(std::vector <std::string> &vec);

std::chrono::microseconds testInsercion(std::vector <std::string> &vec);

std::string obtenerNombreAleatorio(const std::vector<std::string>& vec);
