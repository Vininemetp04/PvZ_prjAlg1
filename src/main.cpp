#include <iostream>
#include <vector>
#include "color.h"
#include "grid.h"
#include "planta.h"
#include "view.h"

using namespace std;

int main(){
    bool running = true;
    Grid gd = Grid(8, 20);
    Planta pl = Planta(8);
    View vw = View(gd, pl);
    char jogada;

    while (running){
        clear();
        vw.view();
        cout << "W - sobe linha   P - sair\nS - desce linha\n";
        cin >> jogada;
        if (jogada == 'w'){
            pl.moveCima();
        } 
        if (jogada == 's'){
            pl.moveBaixo();
        }
        if (jogada == 'p'){
            running = false;
        }
    }
    clear();
  	return 0;
}
