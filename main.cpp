#include <algorithm>
#include <chrono>
#include <gtk/gtk.h>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <cstdio>  // Para popen() y pclose()
#include <cmath>   // Para funciones matemáticas
#include <map>

#include "include/BinarySearchTree.h"
#include "include/ListaEnlazadaOrdenada.h"
#include "include/Ordenamiento.h"

// Estructura para almacenar los resultados de cada algoritmo
struct Resultados {
    std::string algoritmo;
    double peorCaso;
    double mejorCaso;
    double casoPromedio;
};
std::map<int, std::vector<Resultados>> resultadosAlmacenados;  // Almacena resultados por tamaño de n

// Prototipo de la función que devuelve los tiempos de ejecución
// Función para medir los tiempos y devolver los resultados
std::vector<Resultados> resultados(int n) {
    std::cout << "Generando resultados para n = " << n << std::endl;
    std::vector<Resultados> resultadosAlgoritmos;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generar lista aleatoria
    std::vector<int> arr(n);
    std::generate(arr.begin(), arr.end(), [&gen]() { return gen() % 10000; });

    // Copias de la lista para distintos casos
    std::vector<int> arrPromedio = arr;
    std::vector<int> arrMejor = arr;
    std::vector<int> arrPeor = arr;

    // Ordenar para mejor caso y peor caso
    std::sort(arrMejor.begin(), arrMejor.end());       // Mejor caso
    std::sort(arrPeor.begin(), arrPeor.end(), std::greater<int>());  // Peor caso

    // Tiempos de ejecución para BubbleSort
    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(arrPromedio);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionPromedio = fin - inicio;

    inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(arrMejor);
    fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionMejor = fin - inicio;

    inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(arrPeor);
    fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionPeor = fin - inicio;

    // Guardar los resultados para BubbleSort
    resultadosAlgoritmos.push_back({"BubbleSort", duracionPeor.count(), duracionMejor.count(), duracionPromedio.count()});

    // Repetir para SelectionSort
    arrPromedio = arr;
    arrMejor = arrMejor;
    arrPeor = arrPeor;

    inicio = std::chrono::high_resolution_clock::now();
    selectionSort(arrPromedio);
    fin = std::chrono::high_resolution_clock::now();
    duracionPromedio = fin - inicio;

    inicio = std::chrono::high_resolution_clock::now();
    selectionSort(arrMejor);
    fin = std::chrono::high_resolution_clock::now();
    duracionMejor = fin - inicio;

    inicio = std::chrono::high_resolution_clock::now();
    selectionSort(arrPeor);
    fin = std::chrono::high_resolution_clock::now();
    duracionPeor = fin - inicio;

    resultadosAlgoritmos.push_back({"SelectionSort", duracionPeor.count(), duracionMejor.count(), duracionPromedio.count()});

    // Repetir para MergeSort
    arrPromedio = arr;
    arrMejor = arrMejor;
    arrPeor = arrPeor;

    inicio = std::chrono::high_resolution_clock::now();
    mergeSort(arrPromedio, 0, arrPromedio.size() - 1);
    fin = std::chrono::high_resolution_clock::now();
    duracionPromedio = fin - inicio;

    inicio = std::chrono::high_resolution_clock::now();
    mergeSort(arrMejor, 0, arrMejor.size() - 1);
    fin = std::chrono::high_resolution_clock::now();
    duracionMejor = fin - inicio;

    inicio = std::chrono::high_resolution_clock::now();
    mergeSort(arrPeor, 0, arrPeor.size() - 1);
    fin = std::chrono::high_resolution_clock::now();
    duracionPeor = fin - inicio;

    resultadosAlgoritmos.push_back({"MergeSort", duracionPeor.count(), duracionMejor.count(), duracionPromedio.count()});

// 1. Pruebas para ListaEnlazadaOrdenada (solo búsqueda)

    // Caso Promedio: Insertamos los elementos en orden aleatorio sin medir el tiempo
    ListaEnlazadaOrdenada listaPromedio;
    for (const int& valor : arr) {
        listaPromedio.insertar(valor);
    }

    // Elegimos un número aleatorio de la lista para buscar
    int numeroAleatorio = arr[gen() % n];

    // Medir el tiempo de búsqueda
    inicio = std::chrono::high_resolution_clock::now();
    listaPromedio.buscar(numeroAleatorio);
    fin = std::chrono::high_resolution_clock::now();
    duracionPromedio = fin - inicio;

    // Caso Mejor: Insertamos los elementos en orden ascendente sin medir el tiempo
    ListaEnlazadaOrdenada listaMejor;
    for (const int& valor : arrMejor) {
        listaMejor.insertar(valor);
    }

    // Buscar el primer elemento (mejor caso)
    inicio = std::chrono::high_resolution_clock::now();
    listaMejor.buscar(arrMejor[0]);  // Mejor caso: primer elemento
    fin = std::chrono::high_resolution_clock::now();
    duracionMejor = fin - inicio;

    // Caso Peor: Insertamos los elementos en orden descendente sin medir el tiempo
    ListaEnlazadaOrdenada listaPeor;
    for (const int& valor : arrPeor) {
        listaPeor.insertar(valor);
    }

    // Buscar el último elemento (peor caso)
    inicio = std::chrono::high_resolution_clock::now();
    listaPeor.buscar(arrPeor[n - 1]);  // Peor caso: último elemento
    fin = std::chrono::high_resolution_clock::now();
    duracionPeor = fin - inicio;

    // Guardar los resultados para ListaEnlazadaOrdenada
    resultadosAlgoritmos.push_back({"Lista Enlazada Buscar", duracionPeor.count(), duracionMejor.count(), duracionPromedio.count()});

    // 2. Pruebas para BinarySearchTree (solo inserción)

    // Caso Promedio: Insertamos los elementos en orden aleatorio sin medir el tiempo
    BinarySearchTree arbolPromedio;
    for (const int& valor : arr) {
        arbolPromedio.insertar(valor);
    }

    // Insertamos un nuevo valor aleatorio y medimos el tiempo
    int nuevoValor = 10001;  // Un valor nuevo que no esté en el árbol
    inicio = std::chrono::high_resolution_clock::now();
    arbolPromedio.insertar(nuevoValor);
    fin = std::chrono::high_resolution_clock::now();
    duracionPromedio = fin - inicio;

    // Caso Mejor: Insertamos los elementos en orden ascendente sin medir el tiempo
    BinarySearchTree arbolMejor;
    for (const int& valor : arrMejor) {
        arbolMejor.insertar(valor);
    }

    // Insertamos un nuevo valor mayor que todos los existentes (mejor caso)
    nuevoValor = arrMejor.back() + 1;
    inicio = std::chrono::high_resolution_clock::now();
    arbolMejor.insertar(nuevoValor);
    fin = std::chrono::high_resolution_clock::now();
    duracionMejor = fin - inicio;

    // Caso Peor: Insertamos los elementos en orden descendente sin medir el tiempo
    BinarySearchTree arbolPeor;
    for (const int& valor : arrPeor) {
        arbolPeor.insertar(valor);
    }

    // Insertamos un nuevo valor menor que todos los existentes (peor caso)
    nuevoValor = arrPeor.back() - 1;
    inicio = std::chrono::high_resolution_clock::now();
    arbolPeor.insertar(nuevoValor);
    fin = std::chrono::high_resolution_clock::now();
    duracionPeor = fin - inicio;

    // Guardar los resultados para BinarySearchTree
    resultadosAlgoritmos.push_back({"Árbol Binario Insertar", duracionPeor.count(), duracionMejor.count(), duracionPromedio.count()});
    std::cout << "Resulados Generados" << std::endl;
    return resultadosAlgoritmos;
}

// Función para crear una tabla de resultados (complejidades o tiempos)
GtkWidget* create_table(std::vector<std::vector<std::string>> data, const char* title) {
    std::cout << "Creando Tabla" << std::endl;
    GtkWidget *grid = gtk_grid_new();

    GtkWidget *titleLabel = gtk_label_new(title);
    gtk_grid_attach(GTK_GRID(grid), titleLabel, 0, 0, 4, 1);  // Título de la tabla

    // Crear las filas y columnas de la tabla con bordes
    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            // Crear un frame para cada celda, con un borde
            GtkWidget *frame = gtk_frame_new(NULL);
            gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);  // Tipo de borde

            // Crear la etiqueta con el contenido de la celda
            GtkWidget *label = gtk_label_new(data[i][j].c_str());
            gtk_container_add(GTK_CONTAINER(frame), label);

            // Añadir el frame (que contiene la celda) al grid
            gtk_grid_attach(GTK_GRID(grid), frame, j, i+1, 1, 1);  // i+1 para dejar espacio al título
        }
    }

    return grid;
}
// Función para graficar con Gnuplot
void plot_with_gnuplot(const std::vector<double>& ns, const std::vector<double>& tiempos, const std::vector<double>& teorico, const std::string& nombreAlgoritmo, const std::string& caso, const std::string& outputFilename) {
    std::cout << "Generando gráfico para " << nombreAlgoritmo << " - " << caso << std::endl;

    // Imprimir los valores de n y los tiempos experimentales para depuración
    std::cout << "Valores de n y tiempos experimentales:\n";
    for (size_t i = 0; i < ns.size(); ++i) {
        std::cout << "n = " << ns[i] << ", Tiempo experimental = " << tiempos[i] << std::endl;
    }

    FILE* gnuplotPipe = popen("gnuplot", "w");
    if (!gnuplotPipe) {
        std::cerr << "Error al abrir Gnuplot.\n";
        return;
    }

    // Configurar Gnuplot para generar una imagen PNG
    fprintf(gnuplotPipe, "set terminal pngcairo size 800,600\n");
    fprintf(gnuplotPipe, "set output '%s'\n", outputFilename.c_str());
    fprintf(gnuplotPipe, "set title '%s - %s'\n", nombreAlgoritmo.c_str(), caso.c_str());
    fprintf(gnuplotPipe, "set xlabel 'n'\n");
    fprintf(gnuplotPipe, "set ylabel 'Tiempo (s)'\n");

    // Configurar estilos de línea
    fprintf(gnuplotPipe, "set style line 1 lc rgb 'blue' lt 1 lw 2 pt 7 ps 1.5\n"); // Azul para puntos experimentales
    fprintf(gnuplotPipe, "set style line 2 lc rgb 'red' lt 1 lw 2\n");             // Rojo para la función teórica

    // Dibujar la curva de los tiempos experimentales y la función teórica
    fprintf(gnuplotPipe, "plot '-' with linespoints linestyle 1 title 'Tiempos Experimentales', '-' with lines linestyle 2 title 'Teórico O(n^2)'\n");

    // Tiempos experimentales (azul)
    for (size_t i = 0; i < ns.size(); ++i) {
        fprintf(gnuplotPipe, "%f %f\n", ns[i], tiempos[i]);
    }
    fprintf(gnuplotPipe, "e\n");

    // Curva teórica (rojo)
    for (size_t i = 0; i < ns.size(); ++i) {
        fprintf(gnuplotPipe, "%f %f\n", ns[i], teorico[i]);
    }
    fprintf(gnuplotPipe, "e\n");

    // Cerrar la tubería
    pclose(gnuplotPipe);
}

void generar_graficas() {
    std::cout << "Generando todas las gráficas..." << std::endl;
    std::vector<double> ns = {5000, 10000, 15000};  // Valores de n

    // Generar resultados para cada valor de n
    std::vector<double> tiemposPeorCaso, tiemposMejorCaso, tiemposPromedio;

    for (int n : ns) {
        std::vector<Resultados> resultadosN = resultados(n);

        // Extraer los tiempos para BubbleSort (u otro algoritmo que desees graficar)
        for (const auto& resultado : resultadosN) {
            if (resultado.algoritmo == "BubbleSort") {
                tiemposPeorCaso.push_back(resultado.peorCaso);
                tiemposMejorCaso.push_back(resultado.mejorCaso);
                tiemposPromedio.push_back(resultado.casoPromedio);
            }
        }
    }

    // Curvas teóricas (n^2 para BubbleSort en el peor caso, por ejemplo)
    std::vector<double> teoricoPeorCaso(ns.size());
    std::vector<double> teoricoMejorCaso(ns.size());
    std::vector<double> teoricoPromedio(ns.size());

    for (size_t i = 0; i < ns.size(); ++i) {
        teoricoPeorCaso[i] = ns[i] * ns[i];  // O(n^2) para BubbleSort peor caso
        teoricoMejorCaso[i] = ns[i];  // O(n) para BubbleSort mejor caso
        teoricoPromedio[i] = ns[i] * ns[i];  // O(n^2) para el promedio
    }

    // Graficar BubbleSort con los resultados calculados
    plot_with_gnuplot(ns, tiemposPeorCaso, teoricoPeorCaso, "BubbleSort", "Peor Caso", "bubble_sort_peor.png");
    plot_with_gnuplot(ns, tiemposMejorCaso, teoricoMejorCaso, "BubbleSort", "Mejor Caso", "bubble_sort_mejor.png");
    plot_with_gnuplot(ns, tiemposPromedio, teoricoPromedio, "BubbleSort", "Caso Promedio", "bubble_sort_promedio.png");

    std::cout << "Gráficas generadas correctamente" << std::endl;
}

// Función para crear una imagen de la gráfica generada
GtkWidget* create_image(const std::string& filename) {
    std::cout << "Crando Imagen" << std::endl;
    GtkWidget *image = gtk_image_new_from_file(filename.c_str());
    return image;
}
// Función principal para construir la ventana de la interfaz
static void activate(GtkApplication* app, gpointer user_data) {
    // Crear la ventana principal
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Gráficas de Algoritmos");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Crear una scrolled window
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    // Crear una caja vertical (VBox) para organizar las tablas
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(scrolled_window), vbox);

    // Complejidades teóricas (Big-O)
    std::vector<std::vector<std::string>> bigO_data = {
        {"Algoritmo", "Peor Caso", "Mejor Caso", "Caso Promedio"},
        {"BubbleSort", "O(n^2)", "O(n)", "O(n^2)"},
        {"SelectionSort", "O(n^2)", "O(n^2)", "O(n^2)"},
        {"MergeSort", "O(n log n)", "O(n log n)", "O(n log n)"},
        {"LinkedList Search", "O(n)", "O(1)", "O(n)"},
        {"Binary Search Tree Insert", "O(n)", "O(log n)", "O(log n)"}
    };

    GtkWidget *bigO_table = create_table(bigO_data, "Complejidades Teóricas (Big-O)");
    gtk_box_pack_start(GTK_BOX(vbox), bigO_table, FALSE, FALSE, 10);

    // Resultados experimentales para n = 10000, 20000, 40000
    std::vector<int> ns = {5000, 10000, 15000};

    for (int n : ns) {
        std::vector<Resultados> resultadosN = resultados(n);

        // Crear la tabla para los tiempos de ejecución
        std::vector<std::vector<std::string>> tiempo_data = {
            {"Algoritmo", "Peor Caso", "Mejor Caso", "Caso Promedio"}
        };

        for (const auto& resultado : resultadosN) {
            tiempo_data.push_back({
                resultado.algoritmo,
                std::to_string(resultado.peorCaso) + " s",
                std::to_string(resultado.mejorCaso) + " s",
                std::to_string(resultado.casoPromedio) + " s"
            });
        }

        std::string title = "Resultados Experimentales para n = " + std::to_string(n);
        GtkWidget *tiempo_table = create_table(tiempo_data, title.c_str());
        gtk_box_pack_start(GTK_BOX(vbox), tiempo_table, FALSE, FALSE, 10);
    }
    // Generar todas las gráficas
    generar_graficas();

    // Agregar las imágenes al VBox
    gtk_box_pack_start(GTK_BOX(vbox), create_image("bubble_sort_peor.png"), FALSE, FALSE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), create_image("bubble_sort_mejor.png"), FALSE, FALSE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), create_image("bubble_sort_promedio.png"), FALSE, FALSE, 10);

    // Agregar más imágenes (SelectionSort, MergeSort, etc.)
    // ...
    gtk_box_pack_start(GTK_BOX(vbox), create_image("bst_insert_peor.png"), FALSE, FALSE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), create_image("bst_insert_mejor.png"), FALSE, FALSE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), create_image("bst_insert_promedio.png"), FALSE, FALSE, 10);


    // Mostrartodo
    gtk_widget_show_all(window);
}



int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.GtkTables", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}