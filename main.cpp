#include "functions.h"
#include "fstream"
using namespace std;

int main(){
    srand(time(0)); //semilla

    // |===| tester with custom arrs.
    // vectores con tamaño de datos de entrada para comparar eficiencia
    std::vector<long int> tester_sizes = {1, 20000};
    std::ofstream file("tester_times.txt");

    for(long int current_size : tester_sizes){
        std::cout << "CURRENT SIZE: " << current_size <<std::endl;
    
        long int min = 70000000;
        long int max = 90000000;


        // |===| count_sort
        vector<long int> array_count_sort = generar_arreglo<vector<long int>>(current_size,min,max);
        // medir tiempo
        auto start_time = chrono::high_resolution_clock::now();
        countsort(array_count_sort);
        auto end_time = chrono::high_resolution_clock::now();
        //tiempo en ms
        auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
        cout << boolalpha << is_sorted(array_count_sort.begin(),array_count_sort.end()) << endl;
        cout << "Tiempo de ejecucion para el array_count_sort: " << duration.count() << " ms" <<endl << string(50,'-') << endl;
        file << current_size << "/count_sort/" << duration.count() << endl;


        // |===| radix_sort
        vector<long int> array_radix_sort = generar_arreglo<vector<long int>>(current_size,min,max);
        //medir tiempo
        auto start_time2 = chrono::high_resolution_clock::now();
        radix_sort(array_radix_sort);
        auto end_time2 = chrono::high_resolution_clock::now();
        //tiempo en ms
        auto duration2 = chrono::duration_cast<chrono::milliseconds>(end_time2 - start_time2);
        cout << boolalpha << is_sorted(array_radix_sort.begin(),array_radix_sort.end()) << endl;
        file << current_size << "/radix_sort/" << duration.count() << endl;
    };

    file.close();
    return 0;
};