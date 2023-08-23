#include "functions.h"

int main(){
    srand(time(0)); //semilla

    //inicializar n
    int n = 100;
    //inicializar K
    int k = 900;
    //manual
    vector<int> sin_ordenar = {6,1,1,1,1,1,15};
    cout <<"Arreglo 1 ordenado: " << endl;
    cout << countsort(sin_ordenar)<< endl;

    //con funciones
    //experimentacion



    vector<int> sin_ordenar2 = generar_arreglo<vector<int>>(n,k);
    cout << sin_ordenar2 << endl;
    cout <<"Arreglo 2 ordenado: " << endl;
    //medir tiempo
    auto start_time = chrono::high_resolution_clock::now();
    cout << countsort(sin_ordenar2);
    auto end_time = chrono::high_resolution_clock::now();
    //tiempo en ms
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" <<endl;

    //radix sort
    vector<int> v = {1999, 2003, 1955, 1997, 2005, 2010, 2015, 2019, 2020};
    cout << v << endl;
    radix_sort(v);
    cout << v << endl;
    return 0;
}
