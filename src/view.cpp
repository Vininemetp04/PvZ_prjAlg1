#include "view.h"
#include "color.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

View::View(Grid& gd, Planta& pl): gd(gd), pl(pl){
    random_device rd;
    this->gen = mt19937(rd());
}

void View::randomColor(int r, int g, int b){ // Randomiza o cores dentro de um padrão
    uniform_int_distribution<> dis(-1, 1);
    int varR = 20 * dis(this->gen);
    int varG = 35 * dis(this->gen);
    int varB = 20 * dis(this->gen);
    cgColorBG(r+varR, g+varG, b+varB);
    cgColorTX(r-varR, g-varG, b-varB);
}

void View::drawBG(int sz){ // Desenha o fundo do jogo
    for (int r = 0; r<sz;r++){
        this->randomColor(35, 220, 35);
        cout << "▄";
    }
    resetColor();
}

void View::drawPL(int l){ // Desenha a Planta
   switch(l){ 
    case 0:
        this->drawBG(1);
        cgColorBG(20, 200, 20);
        cgColorTX(200,0,150);
        cout << "★";
        this->drawBG(1);
        break;
    case 1:
        cgColorBG(20, 200, 20);
        cout << "⧫█⧫";
        break;
    case 2: 
        this->drawBG(1);
        cgColorBG(20,200,20);
        cgColorTX(105, 48, 1);
        cout << "▀";
        this->drawBG(1);
        break;
   } 
}

void View::drawZB(int l, int vida){  // Desenha o Zombie
    int r = 255 - (vida*2);
    int g = 40;
    int b = 40;
    switch(l){
        case 0:
            this->drawBG(1);
            cgColorTX(r, g, b);
            cgColorBG(20,200,20);
            cout << "●";
            this->drawBG(1);
            break;
        case 1:
            cgColorTX(r, g, b);
            cgColorBG(20,200,20);
            cout << "/§\\";
            break;
        case 2:
            cgColorTX(r, g, b);
            cgColorBG(20,200,20);
            cout << "∫";
            this->drawBG(1);
            cgColorTX(r, g, b);
            cgColorBG(20,200,20);
            cout << "∫";
            break;
    }
}

void View::printGrid(){
    for (int i = 0; i < this->gd.getNLinhas(); i++){      // Imprime a Matriz do jogo na tela
        for (int linha = 0; linha < 3; linha++){                // Para ficar mais bonito cada 
            if (this->pl.getPosicao() == i) this->drawPL(linha);      // parte da matriz tem 3x3 caracteres
            else this->drawBG(3); // Alinha a matriz na tela
            for (int j = 0; j < this->gd.getNColunas(); j++){
                if (this->gd.getPOS(i, j) == 0) {
                    this->drawBG(3);
                    continue;
                }
                this->drawZB(linha, this->gd.getPOS(i, j));                
            }
        cout << endl;
        }
    }
}

void View::view(){
    this->printGrid();
}
