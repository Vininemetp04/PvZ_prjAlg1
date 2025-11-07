#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>

class Grid{
    private:
        int colunas;
        int linhas;
        int plantaPOS;
        std::vector<std::vector<int>> grid;
         
    public:
        Grid(int LIN, int COL);
        void print();
        void movePlanta(int dir);
};

#endif
