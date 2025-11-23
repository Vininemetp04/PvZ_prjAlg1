#ifndef VIEW_H
#define VIEW_H

#include "color.h"
#include "planta.h"
#include "grid.h"
#include <iostream>
#include <random>
#include <vector>

class View{
    private:
        Grid& gd;
        Planta& pl;
        std::mt19937 gen;
        void randomColor(int r, int g, int b);
        void drawBG(int sz);
        void drawPL(int l);
        void drawZB(int l, int vida);
        void printGrid();
    public:
        View(Grid& gd, Planta& pl);
        void view();
};

#endif
