#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "poder.h"

class QuickSort : public Poder {
    public:
        QuickSort();
    
    protected:
        void _sort(std::vector<int>& arr) override;
        void _quick(std::vector<int>& arr, int init, int fim);
        int _part(std::vector<int>& arr, int init, int fim);
};

#endif
