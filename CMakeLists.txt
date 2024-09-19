cmake_minimum_required(VERSION 3.29)
project(AnalisisDeAlgoritmos)

set(CMAKE_CXX_STANDARD 20)

add_executable(AnalisisDeAlgoritmos main.cpp
        src/ListaEnlazadaOrdenada.cpp
        include/ListaEnlazadaOrdenada.h
        src/BinarySearchTree.cpp
        include/BinarySearchTree.h
        src/Ordenamiento.cpp
        include/Ordenamiento.h)

# Encontrar las librerías GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Incluir las bibliotecas GTK
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

# Enlazar GTK con el ejecutable
target_link_libraries(AnalisisDeAlgoritmos ${GTK3_LIBRARIES})