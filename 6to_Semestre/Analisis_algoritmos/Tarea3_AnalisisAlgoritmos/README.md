# Análisis de algoritmos - Tarea 3 (Unidad 3)

Este repositorio contiene los scripts de C++ para las pruebas de rendimiento temporal de los algoritmos analizados en clase, así como el cuaderno de Jupyter encargado del análisis estadístico y visualización de curvas asintóticas.

---

## 📂 Descarga Selectiva de la Subcarpeta (Sin clonar todo el repositorio)

Si deseas descargar únicamente el material y los archivos asociados a esta tarea sin tener que clonar el historial ni las carpetas de todo el repositorio masivo, puedes ejecutar la siguiente secuencia de comandos utilizando el método nativo de **Git Sparse Checkout**:

```bash
# 1. Crear una carpeta local para tu espacio de trabajo e ingresar a ella
mkdir espacio_tarea3 && cd espacio_tarea3

# 2. Inicializar un repositorio Git vacío
git init

# 3. Habilitar sparse-checkout ANTES de conectar el remoto
git sparse-checkout init --cone

# 4. Establecer la ruta de la subcarpeta
git sparse-checkout set "6to_Semestre/Analisis_algoritmos/Tarea3_AnalisisAlgoritmos"

# 5. Vincular el remoto y hacer FETCH con profundidad 1 (IGNORA EL HISTORIAL PESADO)
git remote add origin https://github.com/AlbertoAmayaSoria/Trabajos-Universidad.git
git fetch --depth 1 origin main

# 6. Traer los archivos finales instantáneamente
git pull origin main
```

---

## Configuración del entorno (conda)

Para aislar las dependencias del sistema operativo y garantizar la reproducibilidad de las gráficas de Pandas y Matplotlib, se incluye environment.yml

```bash
conda env create -f environment.yml

conda activate Tarea3Analisis_Algoritmos