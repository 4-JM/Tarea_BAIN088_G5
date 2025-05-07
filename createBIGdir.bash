#!/bin/bash

# Verificar parámetros
if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Uso: $0 <cantidad_de_archivos> <directorio_destino>"
  exit 1
fi

num_files=$1
output_dir=$2

# Lista de extensiones como string separado por espacios
EXTENSIONS_STR=".txt .csv .cpp .c .json .xml .md .py .mp4 .avi .png"

# Convertir a array para verificación
IFS=' ' read -ra EXTENSIONS <<< "$EXTENSIONS_STR"
if [ ${#EXTENSIONS[@]} -eq 0 ]; then
  echo "Error: No hay extensiones definidas"
  exit 1
fi

# Función para generar nombre aleatorio
random_name() {
  tr -dc 'a-z0-9' </dev/urandom | head -c $((RANDOM % 11 + 10))
}

mkdir -p "$output_dir"

# Calcular número de hilos (75% de los núcleos)
THREADS=$(( ($(nproc) * 3 + 3) / 4 ))
[ $THREADS -lt 1 ] && THREADS=1

echo "Creando $num_files archivos usando $THREADS hilos..."

# Exportar variables necesarias
export output_dir
export EXTENSIONS_STR
export -f random_name

# Crear archivos en paralelo (versión robusta)
seq 1 $num_files | xargs -P $THREADS -n 1 -I {} bash -c \
  'IFS=" " read -ra extensions <<< "$EXTENSIONS_STR"; \
   idx=$(( RANDOM % ${#extensions[@]} )); \
   touch "${output_dir}/$(random_name)${extensions[$idx]}"'

echo "Creados $num_files archivos en $output_dir"