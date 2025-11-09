#include "grid.h"
#include "color.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

Grid::Grid(int LIN, int COL){  // Contrutor 
    this->colunas = COL;
    this->linhas = LIN;
    this->plantaPOS = 0;
    this->grid = vector<vector<int>>(LIN, vector<int>(COL));
    random_device rd;           // Isso aqui é para
    this->gen = mt19937(rd());  // randomizar número
}

void Grid::randomColor(int r, int g, int b){ // Randomiza o cores dentro de um padrão
    uniform_int_distribution<> dis(-1, 1);
    int varR = 20 * dis(this->gen);
    int varG = 35 * dis(this->gen);
    int varB = 20 * dis(this->gen);
    cgColorBG(r+varR, g+varG, b+varB);
    cgColorTX(r-varR, g-varG, b-varB);
}

void Grid::drawBG(int sz){ // Desenha o fundo do jogo
    for (int r = 0; r<sz;r++){
        this->randomColor(20, 200, 20);
        cout << "▄";
    }
    resetColor();
}

void Grid::drawPL(int l){ // Desenha a Planta
   switch(l){ 
    case 0:
        this->drawBG(1);
        cgColorBG(20, 200, 20);
        cgColorTX(255,0,100);
        cout << "V";
        resetColor();
        this->drawBG(1);
        break;
    case 1:
        cgColorBG(20, 200, 20);
        cout << "-+-";
        resetColor();
        break;
    case 2: 
        this->drawBG(1);
        cgColorBG(20, 200, 20);
        cout << "|";
        resetColor();
        this->drawBG(1);
        break;
   } 
}

void Grid::drawZB(int l){  // Desenha o Zombie
   switch(l){
    case 0:
        this->drawBG(1);
        cout << "O";
        this->drawBG(1);
        break;
    case 1:
        cout << "/|\\";
        break;
    case 2:
        cout << "/";
        this->drawBG(1);
        cout << "\\";
        break;
   }
}

void Grid::print(){
    for (int i = 0; i < this->linhas; i++){      // Imprime a Matriz do jogo na tela
        for (int linha = 0; linha < 3; linha++){                // Para ficar mais bonito cada 
            if (this->plantaPOS == i) this->drawPL(linha);      // parte da matriz tem 3x3 caracteres
            else this->drawBG(3); // Alinha a matriz na tela
            for (int j = 0; j < this->colunas; j++){
                if (this->grid[i][j] == 0) this->drawBG(3);
            }
        cout << endl;
        }
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
