#!/bin/bash

# Verificar parámetros
if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Uso: $0 <cantidad_de_archivos> <directorio_destino>"
  exit 1
fi

num_files=$1
output_dir=$2

extensions=(".txt" ".csv" ".cpp" ".c" ".json" ".xml" ".md" ".py" ".cpp" ".mp4" ".avi" ".png")

random_name() {
  tr -dc 'a-z0-9' </dev/urandom | head -c $((RANDOM % 11 + 10))
}

mkdir -p "$output_dir"

# Versión corregida - sin usar xargs con {}
for i in $(seq 1 $num_files); do
  touch "${output_dir}/$(random_name)${extensions[$((RANDOM % ${#extensions[@]}))]}"
done

echo "Creados $num_files archivos en $output_dir"