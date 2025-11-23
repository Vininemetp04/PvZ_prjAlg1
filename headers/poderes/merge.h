#ifndef MERGESORT_H
#define MERGESORT_H

#include "poder.h"

class MergeSort : public Poder {
    public:
        MergeSort();
    
    protected:
        void _sort(std::vector<int>& arr) override;
        void _merge(std::vector<int>& arr, int init, int fim);
        void _intercala(std::vector<int>& arr, int init, int mid, int fim);
};

#endif
