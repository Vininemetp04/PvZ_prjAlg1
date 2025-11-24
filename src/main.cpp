#include <vector>
#include <memory>
#include "grid.h"
#include "planta.h"
#include "view.h"
#include "menu.h"
#include "poder.h"
#include "poderes/todos.h"

const int WIDTH = 8;
const int HEIGHT = 20;

int main(){
    // Inicia os objs principais.
    bool running = true; // Controle do jogo.
    Grid gd = Grid(WIDTH, HEIGHT); // Grid do jogo.
    Planta pl = Planta(WIDTH); // A planta.
    View vw = View(gd, pl); // O objeto de view para printar tudo na tela.
    char jogada; // Controle do jogador.
    int rodadas = 0; // contador de turnos.

    // Vetor com um ponteiro para os obj dos Poderes.
    std::vector<std::unique_ptr<Poder>> poderes;
    poderes.push_back(std::make_unique<SelectionSort>());
    poderes.push_back(std::make_unique<InsertionSort>());
    poderes.push_back(std::make_unique<BubbleSort>());
    poderes.push_back(std::make_unique<MergeSort>());
    poderes.push_back(std::make_unique<QuickSort>());
    poderes.push_back(std::make_unique<HeapSort>());

    // Loop do jogo.
    while (running){
        rodadas++;
        clear();
        vw.view();
        drawPoderes(poderes);
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
            case '1':
                poderes[0]->ordena(gd.getLinha(pl.getPosicao()));
                break;
            case '2':
                poderes[1]->ordena(gd.getLinha(pl.getPosicao()));
                break;
            case '3':
                poderes[2]->ordena(gd.getLinha(pl.getPosicao()));
                break;
            case '4':
                poderes[3]->ordena(gd.getLinha(pl.getPosicao()));
                break;
            case '5':
                poderes[4]->ordena(gd.getLinha(pl.getPosicao()));
                break;
            case '6':
                poderes[5]->ordena(gd.getLinha(pl.getPosicao()));
                break;
        }

        gd.avancarZumbis(running);
        gd.randZB(35);
    }

    // Quando o jogo acaba limpa a tela e mostra as estatisticas. 
    clear();
    estatistica(pl, rodadas, poderes);
  	return 0;
}
