#include <iostream>
#include "planta.h"

using namespace std;

void menu(char& jogada){
    cout << "W - sobe linha   P - sair\nS - desce linha   A - ataca\n";
    cin >> jogada;
}

void estatistica(Planta& pl){
    cout << "=-=-=-=-=-=-=| ESTATISTICAS |=-=-=-=-=-=-=";
    cout << endl;
    cout << "Zombis Mortos: " << pl.getZombiesMortos() << endl;
}
