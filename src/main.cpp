#include <iostream>
#include <vector>
#include "color.h"
#include "grid.h"

using namespace std;

int main(){
    bool running = true;
    Grid gd = Grid(5, 9);
    char jogada;

    while (running){
        clear();
        gd.print();
        cout << "W - sobe linha   P - sair\nS - desce linha\n";
        cin >> jogada;
        if (jogada == 'w'){
            gd.movePlanta(-1);
        } 
        if (jogada == 's'){
            gd.movePlanta(1);
        }
        if (jogada == 'p'){
            running = false;
        }
    }
    clear();
  	return 0;
}
