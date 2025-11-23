#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "poder.h"

class SelectionSort : public Poder {
    public:
        SelectionSort();
    
    protected:
        void _sort(std::vector<int>& arr) override;
};

#endif
