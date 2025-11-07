#include "grid.h"
#include "color.h"
#include <iostream>
#include <vector>

using namespace std;

Grid::Grid(int LIN, int COL){
    this->colunas = COL;
    this->linhas = LIN;
    this->plantaPOS = 0;
    this->grid = vector<vector<int>>(LIN, vector<int>(COL));
}

void Grid::print(){
    int green[] = {20, 200, 20};
    for (int i = 0; i < this->linhas; i++){     // Imprime a Matriz do jogo na tela
        if (this->plantaPOS == i) cout << "Planta  "; 
        else cout << "\t"; // Alinha a matriz na tela
        for (int j = 0; j < this->colunas; j++){
            if (this->grid[i][j] == 0){
                cgColorBG(green);                
                cout << "   ";
                resetColor();
            }
        }
        cout << endl;
    }
}

void Grid::movePlanta(int dir){
    if (this->plantaPOS+dir < 0 ||             
        this->plantaPOS+dir == this->linhas) { //   Garante que a Planta
        return;                                //   não saia da matriz
    }

    this->plantaPOS += dir;
}

// Daqui pra frente é só pra trás 
