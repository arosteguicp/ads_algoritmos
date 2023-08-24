#include "functions.h" 
#include <fstream>

//Experimentacion de counting_sort n < k
int main() {
    srand(time(NULL)); // Inicializar semilla para generar valores aleatorios

    std::vector<long int> data_sizes = {10, 100, 1000, 10000, 100000, 1000000};
    std::vector<chrono::milliseconds> algorithm_times;

    for (long int n : data_sizes) {
        long int min_value = 10000000;
        long int max_value = 100000000; 
        std::vector<long int> arreglo = generar_arreglo<std::vector<long int>>(n, min_value , max_value);

        auto start_time = std::chrono::high_resolution_clock::now();
        countsort(arreglo);
        auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
        algorithm_times.push_back(duration);
    }

    for (int i = 0; i < data_sizes.size(); ++i) {
        std::cout << "n = " << data_sizes[i] << ", Time: " << algorithm_times[i].count() << " ms" << std::endl;
    }

    std::ofstream outputFile("CountSortTest2.csv");

    for (int i = 0; i < data_sizes.size(); ++i) {
        outputFile << data_sizes[i] << "," << algorithm_times[i].count() << "\n";
    }

    outputFile.close();

    return 0;
}