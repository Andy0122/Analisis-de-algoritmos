# Tarea Extraclase 2 - Análisis de Algoritmos

**Instituto Tecnológico de Costa Rica**  
**Escuela de Ingeniería en Computadores**  
**Curso: Algoritmos y Estructuras de Datos II (CE 1103)**  
**II Semestre 2024**

## Descripción

Esta tarea consiste en medir los tiempos de ejecución empíricos de varios algoritmos de ordenamiento y estructuras de datos, y compararlos con los tiempos de ejecución teóricos esperados. La aplicación implementada en C++ realiza la medición de tiempos y genera gráficos que permiten comparar estos tiempos.

### Algoritmos implementados:
- **BubbleSort**
- **SelectionSort**
- **MergeSort**
- **LinkedList Search**
- **Binary Search Tree Insert**

Los algoritmos se miden en tres casos:
- **Peor Caso**
- **Mejor Caso**
- **Caso Promedio**

Se generarán gráficos que muestran los tiempos experimentales versus los tiempos teóricos para cada caso y cada algoritmo.

## Requisitos

### Dependencias

El proyecto tiene las siguientes dependencias:

- C++17 o superior.
- GTK+ para la interfaz gráfica.
- Gnuplot para la generación de gráficos.
- Compilador compatible con C++ (por ejemplo, `g++`).
- `make` (opcional, pero recomendable para compilar y ejecutar más fácilmente).

### Instalación de dependencias

Para instalar las dependencias en Ubuntu, puedes utilizar el siguiente comando:

```bash
sudo apt-get install g++ libgtk-3-dev gnuplot
```
Compilación y Ejecución
Paso 1: Clonar el repositorio

Primero, clona el repositorio del proyecto desde GitHub. Asegúrate de tener git instalado:

```bash

git clone https://github.com/Andy0122/Analisis-de-algoritmos.git
cd Analisis-de-algoritmos
```
Paso 2: Compilar el proyecto

Para compilar el proyecto, puedes usar el siguiente comando si tienes un Makefile configurado (o puedes crear uno si lo necesitas):

```bash

make
```
Si no tienes un Makefile, puedes compilar el proyecto manualmente usando g++:

```bash

g++ -std=c++17 -o tarea2 main.cpp include/BinarySearchTree.cpp include/ListaEnlazadaOrdenada.cpp include/Ordenamiento.cpp `pkg-config --cflags --libs gtk+-3.0`
```
Paso 3: Ejecutar el proyecto

Una vez compilado, puedes ejecutar el programa con el siguiente comando:

```bash

./tarea2
```
El programa abrirá una ventana gráfica donde se mostrarán los resultados experimentales en forma de tablas y gráficos. Los gráficos se generarán utilizando gnuplot y se guardarán como archivos PNG en el directorio del proyecto.
Paso 4: Ver gráficos generados


Los nombres de los archivos están formados por el nombre del algoritmo y el caso de prueba (peor, mejor o promedio).

Referencias

    Documentación de GTK+
    Documentación de Gnuplot
