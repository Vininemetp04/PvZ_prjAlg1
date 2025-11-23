#include <iostream>
#include "planta.h"
#include "poder.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

void menu(char& jogada){
    cout << "W - Sobe Linha  | P - Sair\nS - Desce Linha | A - Ataca\n";
    cin >> jogada;
}

void drawPoderes(const vector<unique_ptr<Poder>>& poderes) {
    cout << " PODERES " << endl;
    
    for (size_t i = 0; i < poderes.size(); i++) {
        
        if (poderes[i]->getDisponivel()) {
            cout << "\033[97m"; // BRANCO (Disponível)
        } else {
            cout << "\033[90m"; // CINZA (Indisponível)
        }

        cout << (i + 1) << " - " << poderes[i]->getNome();

        cout << "\033[0m"; // RESETAR COR IMEDIATAMENTE
        if (i%2==1) cout << endl;
        else cout << " | ";
    }
}

void estatistica(Planta& pl, const vector<unique_ptr<Poder>>& poderes){
    cout << "=-=-=-=-=-=-=| ESTATISTICAS |=-=-=-=-=-=-=";
    cout << endl;
    cout << "Zombis Mortos: " << pl.getZombiesMortos() << endl;
     for (size_t i = 0; i < poderes.size(); i++) {
        
        if (!poderes[i]->getDisponivel()) {
             cout << poderes[i]->getNome() << ": " << poderes[i]->getTempo() << "ms";
        } else {
             cout << poderes[i]->getNome() << ": Não utilizado";
        }
        cout << endl;
    }
}
