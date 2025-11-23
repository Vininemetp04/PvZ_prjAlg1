#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "poder.h"

class HeapSort : public Poder {
    public:
        HeapSort();
    
    protected:
        void _sort(std::vector<int>& arr) override;
        void _arrumaHeap(std::vector<int>& arr, int init, int fim);
        void _criaHeap(std::vector<int>& arr, int sz);
};

#endif
