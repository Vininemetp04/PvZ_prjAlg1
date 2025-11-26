#include <vector>
#include <memory>
#include "grid.h"
#include "planta.h"
#include "view.h"
#include "menu.h"
#include "poder.h"
#include "poderes/todos.h"

#ifdef _WIN32
    #include <windows.h>
#endif

const int WIDTH = 8;
const int HEIGHT = 20;

Grid gd = Grid(WIDTH, HEIGHT); // Grid do jogo.
Planta pl = Planta(WIDTH); // A planta.
View vw = View(gd, pl); // O objeto de view para printar tudo na tela.
char jogada; // Controle do jogador.
int rodadas = 0; // contador de turnos.
int maxRodadas = 0; // contador da Maior pontuação.
bool venceu = true;
std::vector<std::unique_ptr<Poder>> poderes;

void jogo(){
    for (auto& p : poderes) p->reset();
    bool running = true; // Controle do jogo.
    while (running){
        rodadas++;
        clear();
        vw.view();
        drawPoderes(poderes);
        menu(jogada); 
        if (jogada == 'p'){
            running = false; 
        } else { 
            switch (jogada){
                case 'w': pl.moveCima(); break;
                case 's': pl.moveBaixo(); break;
                case 'a': pl.atacar(gd, 10); break;
                case '1': poderes[0]->ordena(gd.getLinha(pl.getPosicao())); break;
                case '2': poderes[1]->ordena(gd.getLinha(pl.getPosicao())); break;
                case '3': poderes[2]->ordena(gd.getLinha(pl.getPosicao())); break;
                case '4': poderes[3]->ordena(gd.getLinha(pl.getPosicao())); break;
                case '5': poderes[4]->ordena(gd.getLinha(pl.getPosicao())); break;
                case '6': poderes[5]->ordena(gd.getLinha(pl.getPosicao())); break;
            }
            gd.avancarZumbis(running, venceu);
            gd.randZB(35);
        }
    }
    if (maxRodadas < rodadas && venceu) maxRodadas = rodadas;
    clear();
    estatistica(pl, rodadas, poderes, venceu);
}

void loop(){
    while (true){
        clear();
        menuPrincipal(maxRodadas, jogada);
        switch (jogada){
            case '1':
                // Jogo
                jogo();
                break;
            case '2':
                // Tutorial
                clear();
                tutorial();
                break;
            case '0':
                return;
        }
    }
}

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    // Vetor com um ponteiro para os obj dos Poderes.
    poderes.push_back(std::make_unique<SelectionSort>());
    poderes.push_back(std::make_unique<InsertionSort>());
    poderes.push_back(std::make_unique<BubbleSort>());
    poderes.push_back(std::make_unique<MergeSort>());
    poderes.push_back(std::make_unique<QuickSort>());
    poderes.push_back(std::make_unique<HeapSort>());

    // Loop do jogo.
    loop();

    // Quando o jogo acaba limpa a tela e mostra as estatisticas. 
    clear();
  	return 0;
}
