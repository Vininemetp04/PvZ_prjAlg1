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
        cout << "W - sobe linha   P - sair\nS - desce linha   A - ataca\n";
        cin >> jogada;
        
        switch (jogada){
            case 'w':
                pl.moveCima();
                break;
            case 's':
                pl.moveBaixo();
                break;
            case 'p':
                running = false;
                break;
            case 'a':
                pl.atacar(gd);
                break;
        }

        gd.avancarZumbis(running);
        gd.randZB(35);
    }
    
    clear();

  	return 0;
}
