#include "poderes/heap.h"
#include <vector>

HeapSort::HeapSort() : Poder("Domínio das raízes profundas") {}

void HeapSort::_sort(std::vector<int>& arr){
    int sz = arr.size();
    this->_criaHeap(arr, sz);
    int fim = sz -1;
    while (fim > 0){
        this->troca(arr[0], arr[fim]);
        fim--;
        this->_arrumaHeap(arr, 0, fim);
    }
}

void HeapSort::_criaHeap(std::vector<int>& arr, int sz){
    int init = (sz-1)/2;
    while (init >= 0){
        this->_arrumaHeap(arr, init, sz-1);
        init--;
    }
}

void HeapSort::_arrumaHeap(std::vector<int>& arr, int init, int fim){
    int root = init;
    while (root*2+1 <= fim){
        int filho = root*2+1;
        int troca = root;
        this->count_comparacao++;
        if (arr[troca] < arr[filho]) troca = filho;
        if (filho+1 <= fim){
            this->count_comparacao++;
            if (arr[troca] < arr[filho+1]) troca = filho+1;
        }
        if (troca == root) break;
        else {
            this->troca(arr[root], arr[troca]);
            root = troca;
        }
    }
}
