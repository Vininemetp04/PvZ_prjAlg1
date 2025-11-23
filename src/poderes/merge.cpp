#include "poderes/merge.h"
#include <vector>

MergeSort::MergeSort() : Poder("Divisão de galhos") {}

void MergeSort::_sort(std::vector<int>& arr){
    int sz = arr.size();
    this->_merge(arr, 0, sz-1);
}

void MergeSort::_merge(std::vector<int>& arr, int init, int fim){
    if (init < fim){
        int mid = (init+fim)/2;
        this->_merge(arr, init, mid);
        this->_merge(arr, mid+1, fim);
        this->_intercala(arr, init, mid, fim);
    }
}

void MergeSort::_intercala(std::vector<int>& arr, int init, int mid, int fim){
    std::vector<int> l, r;

    for (int i = init; i <= mid; i++){
        l.push_back(arr[i]);
    }
    for (int i = mid+1; i <= fim; i++){
        r.push_back(arr[i]);
    }
    
    size_t i = 0;
    size_t j = 0;
    int k = init;
    
    while (i < l.size() && j < r.size()) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < l.size()) {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < r.size()) {
        arr[k] = r[j];
        j++;
        k++;
    }
}
