#include "poderes/selection.h"
#include <vector>

SelectionSort::SelectionSort() : Poder("Raízes calculistas") {}

void SelectionSort::_sort(std::vector<int>& arr){
    int sz = arr.size();
    for (int i = 0; i < sz-1; i++){
        int min = i;
        for (int j = i+1; j < sz; j++){
            if (arr[j] < arr[min]) min = j;
        }
        this->troca(arr[i], arr[min]);
    }
}
