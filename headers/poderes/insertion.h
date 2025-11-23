#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "poder.h"

class InsertionSort : public Poder {
    public:
        InsertionSort();
    
    protected:
        void _sort(std::vector<int>& arr) override;
};

#endif
