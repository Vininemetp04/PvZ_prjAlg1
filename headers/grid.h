#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid{
    private:
        int colunas;
        int linhas;
        std::vector<std::vector<int>> grid;
    public:
        Grid(int LIN, int COL);
        std::vector<int> getLinha(int linha);
        int getPOS(int linha, int coluna);
        int getNLinhas();
        int getNColunas();
};

#endif
