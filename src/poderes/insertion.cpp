#include "poderes/insertion.h"
#include <vector>

InsertionSort::InsertionSort() : Poder("Crescimento gradual") {}

void InsertionSort::_sort(std::vector<int>& arr){
    int sz = arr.size();
    for (int i = 1; i < sz; i++){
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            this->troca(arr[j-1], arr[j]);
            j--;
        }
    }
}
