#include "grid.h"
#include <vector>

using namespace std;

Grid::Grid(int LIN, int COL){  // Contrutor 
    this->colunas = COL;
    this->linhas = LIN;
    this->grid = vector<vector<int>>(LIN, vector<int>(COL));
}

vector<int> Grid::getLinha(int linha){
    return this->grid[linha];
}

int Grid::getPOS(int linha, int coluna){
    return this->grid[linha][coluna];
}

int Grid::getNLinhas(){
    return this->linhas;
}

int Grid::getNColunas(){
    return this->colunas;
}
// Daqui pra frente é só pra trás 
