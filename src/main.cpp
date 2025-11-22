#include "grid.h"
#include "planta.h"
#include "view.h"
#include "menu.h"

int main(){
    bool running = true;
    Grid gd = Grid(8, 20);
    Planta pl = Planta(8);
    View vw = View(gd, pl);
    char jogada;

    while (running){
        clear();
        vw.view();
        menu(jogada); 
        
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
                pl.atacar(gd, 10);
                break;
        }

        gd.avancarZumbis(running);
        gd.randZB(35);
    }
    
    clear();
    estatistica(pl);
  	return 0;
}
