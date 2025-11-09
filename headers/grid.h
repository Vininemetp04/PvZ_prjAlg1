#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <random>

class Grid{
    private:
        int colunas;
        int linhas;
        int plantaPOS;
        std::mt19937 gen;
        std::vector<std::vector<int>> grid;
        void randomColor(int r, int g, int b);
        void drawBG(int sz);
        void drawPL(int l);
        void drawZB(int l);
    public:
        Grid(int LIN, int COL);
        void print();
        void movePlanta(int dir);
};

#endif
