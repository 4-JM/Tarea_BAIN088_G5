#include "experimentacion.h"
#include "vector.h"
using namespace std;

// A continuacion hay 3 vectores que se usan para crear nombres aleatorios para el test de insercion

std::vector <std::string> carpetas = {
    "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
    "a_data/", "b_src/", "c_lib/", "d_docs/", "e_config/", "f_images/", "g_assets/",
    "h_temp/", "i_backup/", "j_bin/", "k_build/", "l_dist/", "m_logs/", "n_test/",
    "o_web/", "p_server/", "q_client/", "r_utils/", "s_models/", "t_controllers/",
    "u_views/", "v_scripts/", "w_styles/", "x_media/", "y_audio/", "z_video/"
};

std::vector<std::string> nombres = {
    "archivo", "base", "config", "datos", "entrada", "fondo", "guardar", "helper",
    "index", "juego", "kernel", "lista", "main", "notas", "objeto", "parametro",
    "query", "registro", "sistema", "temporal", "usuario", "valor", "worker", "extra",
    "yacimiento", "zorro", "alpha", "beta", "gamma", "delta", "epsilon", "zeta",
    "archivo1", "archivo2", "archivo3", "base1", "base2", "config1", "config2",
    "datos1", "datos2", "entrada1", "entrada2", "fondo1", "fondo2", "guardar1",
    "helper1", "index1", "index2", "juego1", "kernel1", "lista1", "main1", "main2",
    "notas1", "objeto1", "parametro1", "query1", "registro1", "sistema1", "temporal1",
    "usuario1", "valor1", "worker1", "extra1", "alpha1", "beta1", "gamma1", "delta1",
    "admin", "backup", "cache", "debug", "error", "file", "global", "host", "input",
    "join", "key", "log", "memory", "network", "output", "process", "random", "save",
    "text", "update", "virtual", "window", "xpath", "yaml", "zero", "account",
    "buffer", "command", "device", "event", "filter", "graphic", "handler", "instance",
    "java", "kafka", "loader", "manager", "node", "operator", "package", "quality",
    "resource", "service", "token", "utility", "variable", "widget", "xml", "yarn",
    "zip", "array", "boolean", "class", "domain", "export", "format", "generic",
    "hash", "import", "jpeg", "kilobyte", "library", "method", "numeric", "object",
    "pointer", "queue", "request", "string", "template", "unique", "vector", "width",
    "xunit", "yield", "zone", "audio", "binary", "client", "driver", "element",
    "function", "gateway", "http", "interface", "javascript", "kotlin", "language",
    "module", "namespace", "open", "protocol", "query", "react", "storage", "type",
    "user", "view", "web", "xcode", "yui", "zlib", "action", "browser", "context",
    "database", "environment", "framework", "generator", "header", "iterator", "json",
    "keyboard", "listener", "middleware", "normalize", "observer", "promise", "query",
    "router", "stream", "transaction", "unicode", "validator", "wrapper", "xhr",
    "yacc", "zsh", "adapter", "binding", "callback", "descriptor", "expression",
    "factory", "guard", "hook", "immutable", "jquery", "knockout", "lazy", "mixin",
    "nullable", "overload", "predicate", "quantifier", "reducer", "singleton", "thunk",
    "unary", "void", "wildcard", "xlsx", "yaml", "zstd"
};

std::vector <std::string> extensiones = {
    ".txt", ".pdf", ".jpg", ".png", ".gif", ".svg", ".mp3", ".mp4", ".avi", ".mov",
    ".doc", ".docx", ".xls", ".xlsx", ".ppt", ".pptx", ".csv", ".json", ".xml", ".yaml",
    ".html", ".css", ".js", ".ts", ".jsx", ".tsx", ".py", ".java", ".class", ".jar",
    ".c", ".cpp", ".h", ".hpp", ".cs", ".go", ".php", ".rb", ".pl", ".sh", ".bash",
    ".zsh", ".swift", ".kt", ".kts", ".m", ".mm", ".dart", ".r", ".sql", ".db", ".dat",
    ".bin", ".hex", ".iso", ".tar", ".gz", ".zip", ".7z", ".rar", ".pkg", ".dmg",
    ".exe", ".msi", ".deb", ".rpm", ".apk", ".aac", ".wav", ".flac", ".ogg", ".mid",
    ".psd", ".ai", ".eps", ".sketch", ".xd", ".fig", ".ttf", ".otf", ".woff", ".woff2",
    ".eot", ".wasm", ".dll", ".so", ".a", ".lib", ".obj", ".o", ".out", ".app", ".ipa",
    ".kext", ".dylib", ".bundle", ".framework", ".pch", ".pdb", ".ilk", ".exp", ".res",
    ".rc", ".def", ".map", ".sln", ".vcxproj", ".cmake", ".make", ".ninja", ".gradle",
    ".properties", ".ini", ".cfg", ".conf", ".env", ".gitignore", ".dockerignore",
    ".npmignore", ".htaccess", ".htpasswd", ".editorconfig", ".eslintrc", ".prettierrc",
    ".babelrc", ".jshintrc", ".stylelintrc", ".browserslistrc", ".eslintignore",
    ".prettierignore", ".stylelintignore", ".npmrc", ".yarnrc", ".bowerrc", ".jscsrc",
    ".jshintignore", ".flowconfig", ".tern-project", ".istanbul.yml", ".nycrc",
    ".coveralls.yml", ".codeclimate.yml", ".sonarcloud.yml", ".travis.yml",
    ".appveyor.yml", ".circleci.yml", ".gitlab-ci.yml", ".azure-pipelines.yml",
    ".docker-compose.yml", ".dockerfile", ".vagrantfile", ".procfile", ".gemfile",
    ".rakefile", ".makefile", ".cmakelists.txt", ".gradle.properties", ".mvnw",
    ".mvn", ".sbt", ".scala", ".clj", ".cljs", ".cljc", ".edn", ".boot", ".lein",
    ".shadow-cljs", ".deps.edn", ".bb.edn", ".lfe", ".erl", ".hrl", ".yrl", ".xrl",
    ".app.src", ".config", ".sys.config", ".vm.args", ".rel", ".script", ".escript",
    ".beam", ".dump", ".core", ".ez", ".plt", ".coverdata", ".trace", ".crashdump",
    ".sock", ".port", ".pid", ".lock", ".tmp", ".cache", ".log", ".error", ".out",
    ".pid", ".swo", ".swp", ".swn", ".spl", ".hs", ".lhs", ".hi", ".hie", ".cabal",
    ".stack.yaml", ".hsc", ".chs", ".x", ".y", ".l", ".ll", ".yy", ".g", ".peg",
    ".reb", ".rl", ".sl", ".v", ".sv", ".svh", ".vhd", ".vhdl", ".tcl", ".tk",
    ".wish", ".itcl", ".itk", ".tbc", ".f", ".for", ".f90", ".f95", ".f03", ".f08",
    ".ads", ".adb", ".ali", ".o", ".a", ".so", ".dll", ".dylib", ".class", ".jar"
};

//Funcion que crea el vector y mide el tiempo de su creacion

chrono::microseconds creacionVector(vector<string>& vec, const string directorio) {
    // Iniciamos la marca de tiempo
    auto start = chrono::high_resolution_clock::now();

    // Creamos el vector 
    vec = crearVector(directorio);

    // Terminamos la marca de tiempo
    auto end = chrono::high_resolution_clock::now();

    auto duration_creation = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration_creation;
}

//Funcion que optimiza codigo que se repite en las funciones test
string obtenerNombreAleatorio(const vector<string>& vec) {
    int n = vec.size();
    int j = rand() % n;
    fs::path ruta(vec[j]);
    return ruta.filename().string();
}

//Ordena con quicksort
chrono::microseconds ordenarVector(vector<string> &v){
    auto inicio = chrono::high_resolution_clock::now();
    
    quickSort(v, 0, v.size() - 1);

    auto fin = chrono::high_resolution_clock::now();
    auto duration_creation = chrono::duration_cast<chrono::microseconds>(fin - inicio);
    return duration_creation;
}

//Test busqueda secuencial
std::chrono::microseconds testSecSearch(vector <string> &vec){
    //Iniciamos la marca de tiempo
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    for (int i = 0; i < REP; i++){
        string testNombre = obtenerNombreAleatorio(vec);
        busquedaSecuencial(vec, testNombre);
    }

    //Terminamos la marca de tiempo
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    
    auto duration_creation = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration_creation; 
}

//Test busqueda binaria
std::chrono::microseconds testBinSearch(vector <string> &vec){
    //Iniciamos la marca de tiempo
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    for (int i = 0; i < REP; i++){
        string testNombre = obtenerNombreAleatorio(vec);
        busquedaBinaria(vec, testNombre);
    }

    //Terminamos la marca de tiempo
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    auto duration_creation = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration_creation; 
}

//Test Eliminacion
std::chrono::microseconds testEliminacion(vector <string> &vec){
    //Iniciamos la marca de tiempo  
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    for (int i = 0; i < REP; i++){
        string testNombre = obtenerNombreAleatorio(vec);
        eliminaElemento(vec, testNombre);
    }

    //Terminamos la marca de tiempo
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    auto duration_creation = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration_creation;
}

std::chrono::microseconds testInsercion (vector <string> &vec){
    //Iniciamos la marca de tiempo  
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for (int i = 0; i < REP; ++i) {

        // Seleccionar componentes al azar
        string carpeta = carpetas[rand() % carpetas.size()];
        string nombre = nombres[rand() % nombres.size()];
        string extension = extensiones[rand() % extensiones.size()];
        
        // Combinar para formar la ruta
        string ruta = carpeta + nombre + extension + "_" + to_string(i) + "_" + to_string(rand());
        insertaElemento(vec, ruta); 
    }
    //Terminamos la marca de tiempo
    
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    auto duration_creation = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration_creation;
}
