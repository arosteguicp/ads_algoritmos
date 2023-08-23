#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename arr>
void countsort(arr& arreglo){
    arr ordenado(arreglo.size(), 0);
    int max = *max_element(arreglo.begin(), arreglo.end());
    arr conteo(max+1,0);

    for(int i = 0;i < arreglo.size();i++){
        conteo[arreglo[i]+1]++;
    }

    for(int i = 2;i <= max+1;i++){
        conteo[i] += conteo[i-1];
    }

    for(int i = 0;i <arreglo.size();i++){
        ordenado[conteo[arreglo[i]]++] = arreglo[i];
    }
    arreglo = ordenado;
}

ostream& operator<<(ostream& os, const vector<int>& array){
    for(int i : array){
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

template <typename arr>
void radix_sort(arr& array){
    // O(d(n+b))
    // b is the base
    // d is the exponent of b
    int base = 10;
    int d = log10(*max_element(array.begin(), array.end()))+1; 
    int N = array.size();
    arr temp(N,0);
    arr* in = &array;
    arr* out = &temp;
    for(int i{};i<d;++i){
        arr count(base+1,0);
        int order = pow(10,i);
        for(int j{};j<N;++j){
            ++count[((*in)[j]/order)%10+1];
        }
        for(int k=2;k<base+1;++k){
            count[k] += count[k-1];
        }
        for(int l{};l<N;++l){
            (*out)[count[((*in)[l]/order)%10]++] = (*in)[l];
        }
        swap(in, out);
    }
}
