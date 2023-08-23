#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;

//en la mayoria para ordenar numeros
template <typename arr>
arr countsort(arr arreglo){
    //arreglo ordenado
    arr ordenado(arreglo.size(), 0);
    //max_element(arreglo.begin(), arreglo.end());
    //tiene el tamaño del rango de valores
    int max = *max_element(arreglo.begin(), arreglo.end());
    //int min = *min_element(arreglo.begin(), arreglo.end());
    arr conteo(max+1,0);

    for(int i = 0;i < arreglo.size();i++){
        conteo[arreglo[i]]++;
    }

    for(int i = 1;i <= max;i++){
        conteo[i] += conteo[i-1];
    }

    for(int i = 0;i <arreglo.size();i++){
        ordenado[conteo[arreglo[i]]-1] = arreglo[i];
        conteo[arreglo[i]] -= 1;
    }
    return ordenado;
}
ostream& operator<<(ostream& os, const vector<int>& vector){
    for(int i :vector){
        os << i << " ";
    }
    os << endl;
    return os;
}

template <typename arr>
arr generar_arreglo(int n, int k){
    arr arreglo;
    for(int i=0; i < n; i++){
        arreglo.push_back(rand()%(k+1));
    }
    return arreglo;
}


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

    return 0;
}
