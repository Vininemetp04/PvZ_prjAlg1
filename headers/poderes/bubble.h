#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "poder.h"

class BubbleSort : public Poder {
    public:
        BubbleSort();
    
    protected:
        void _sort(std::vector<int>& arr) override;
};

#endif
