#include "poderes/quick.h"
#include <vector>

QuickSort::QuickSort() : Poder("Ataque relâmpago") {}

void QuickSort::_sort(std::vector<int>& arr){
    int sz = arr.size();
    this->_quick(arr, 0, sz-1);
}

void QuickSort::_quick(std::vector<int>& arr, int init, int fim){
    if (init < fim){
        int mid = this->_part(arr, init, fim);
        this->_quick(arr, init, mid-1);
        this->_quick(arr, mid+1, fim);
    }
}

int QuickSort::_part(std::vector<int>& arr, int init, int fim){
    int i = init + 1;
    int j = fim;
    int pivo = arr[init];
    while (i <= j){
        if (i < fim && arr[i] <= pivo) i++;
        else {
            if (arr[j] > pivo) j--;
            else {
                this->troca(arr[i], arr[j]);
                i++;
                j--;
            }
        }
    }
    this->troca(arr[init], arr[j]);
    return j;
}
