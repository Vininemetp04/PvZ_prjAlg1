#include "poderes/bubble.h"
#include <vector>

BubbleSort::BubbleSort() : Poder("Explosão de seiva") {}

void BubbleSort::_sort(std::vector<int>& arr){
    int sz = arr.size();
    for (int i = 0; i < sz-1; i++){
    for (int j = 1; j < sz; j++){
        if (arr[j-1] > arr[j]) this->troca(arr[j-1], arr[j]);    
    }}
}
