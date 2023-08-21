#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto& i : v) {
        os << i << " ";
    }
    return os;
}

void radix_sort(vector<int>& v, int d, int base = 10){
    // O(d(n+b))
    // b is the base
    // d is the exponent of b
    int N = v.size();
    vector<int>* in = &v;
    vector<int> temp(N);
    vector<int>* out = &temp;
    for(int i{};i<d;++i){
        vector<int> count(base+1);
        for(int j{};j<N;++j){
            ++count[((*in)[j]/(int)pow(10,i))%10+1];
        }
        for(int k=2;k<base+1;++k){
            count[k] += count[k-1];
        }
        for(int l{};l<N;++l){
            (*out)[count[((*in)[l]/(int)pow(10,i))%10]++] = (*in)[l];
        }
        swap(in, out);
    }

}



int main(){
    vector<int> v = {1999, 2003, 1955, 1997, 2005, 2010, 2015, 2019, 2020};
    cout << v << endl;
    radix_sort(v, 4);
    cout << v << endl;
    return 0;


}
