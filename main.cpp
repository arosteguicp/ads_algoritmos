#include "functions.h"

int main(){
    srand(time(0)); //semilla

    //inicializar n
    int n = 1000000;
    //inicializar K
    int k = 90000;

    vector<int> arreglo1 = generar_arreglo<vector<int>>(n,k);
//    cout << "Arreglo 1 desordenado:\n " << arreglo1 << endl << endl;
//    cout <<"Arreglo 1 ordenado:\n ";
    //medir tiempo
    auto start_time = chrono::high_resolution_clock::now();
//    cout << countsort(arreglo1) << endl << endl;
    auto end_time = chrono::high_resolution_clock::now();
    //tiempo en ms
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "Tiempo de ejecucion para el arreglo1: " << duration.count() << " ms" <<endl;

    //radix sort
    vector<int> arreglo2 = generar_arreglo<vector<int>>(n,k);
//    cout << "Arreglo 2 desordenado:\n " << arreglo1 << endl << endl;
//    cout <<"Arreglo 2 ordenado:\n ";
    //medir tiempo
    auto start_time2 = chrono::high_resolution_clock::now();
    radix_sort(arreglo2);
//    cout << arreglo2 << endl << endl;
    auto end_time2 = chrono::high_resolution_clock::now();
    //tiempo en ms
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end_time2 - start_time);
    cout << "Tiempo de ejecucion para el arreglo2: " << duration2.count() << " ms" <<endl;
    return 0;
}
