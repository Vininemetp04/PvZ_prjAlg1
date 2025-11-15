#ifndef GRID_H
#define GRID_H

#include <vector>
#include <random>

class Grid{
    private:
        int colunas;
        int linhas;
        std::vector<std::vector<int>> grid;
        std::mt19937 gen;
    public:
        Grid(int LIN, int COL);
        std::vector<int>& getLinha(int linha);
        int getPOS(int linha, int coluna);
        int getNLinhas();
        int getNColunas();
        void randZB(int chance);
        void avancarZumbis(bool& game);
};

#endif
