#include "grid.h"
#include <vector>
#include <random>

using namespace std;

Grid::Grid(int LIN, int COL){  // Contrutor 
    this->colunas = COL;
    this->linhas = LIN;
    this->grid = vector<vector<int>>(LIN, vector<int>(COL));
    random_device rd;
    this->gen = mt19937(rd());
}

vector<int>& Grid::getLinha(int linha){
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

void Grid::randZB(int chance){ // Randomiza os zumbis
    uniform_int_distribution<> chance_dist(0, 99);
    if (chance_dist(this->gen) >= chance) return;

    uniform_int_distribution<> hp_dist(10, 99);
    int vidaZB = hp_dist(this->gen);
    uniform_int_distribution<> linha_dist(0, this->linhas - 1);
    int linhaRND = linha_dist(this->gen);
    this->grid[linhaRND][this->colunas-1] = vidaZB;
}

void Grid::avancarZumbis(bool& game){ // move os zombis um campo para a esquerda
    for (int i = 0; i < this->linhas; i++){
        for (int j = 0; j < this->colunas; j++){
            if (this->grid[i][j] > 0){
                if (j == 0) {
                    game = false;
                } 
                else if (this->grid[i][j-1] == 0) {
                    this->grid[i][j-1] = this->grid[i][j]; // Copia o HP
                    this->grid[i][j] = 0;                  // Limpa o local antigo
                }
            }
        }
    }
}

