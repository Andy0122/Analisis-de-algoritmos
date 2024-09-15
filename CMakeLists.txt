cmake_minimum_required(VERSION 3.29)
project(AnalisisDeAlgoritmos)

set(CMAKE_CXX_STANDARD 20)

add_executable(AnalisisDeAlgoritmos main.cpp
        src/ListaEnlazadaOrdenada.cpp
        include/ListaEnlazadaOrdenada.h
        src/BinarySearchTree.cpp
        include/BinarySearchTree.h)
