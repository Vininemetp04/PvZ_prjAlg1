#include <iostream>
#include <vector>
#include "color.hpp"

using namespace std;

void showGrid(vector<vector<int>> grid, int COLS, int LINE){
    int green[3] = {80, 180, 80};  	
    for (int i = 0; i < LINE; i++){
        for (int j = 0; j < COLS; j++){
            cgColorBG(green); // Deixa o fundo do terminal na cor verde
            cout << grid[i][j];
            resetColor(); // Volta o terminal a aparencia padrão
  	    }
        cout << endl;
  	} 
}

int main(){
    const int COLS = 9, LINE = 5;

    // Cria o "Mapa" do jogo
    vector<vector<int>> grid(LINE, vector<int>(COLS));
    for (int i = 0; i < LINE; i++){ 
        for (int j = 0; j < COLS; j++){
            grid[i][j] = 0;
  	    }
  	}

    clear();

    showGrid(grid, COLS, LINE); 
    char saida;
    cin >> saida;
    clear();

  	return 0;
}
