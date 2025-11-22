#ifndef PLANTA_H
#define PLANTA_H

#include "grid.h"
#include <vector>

class Planta{
    private:
        int posicao; // Posição atual da planta
        int max;     // Valor maximo da posição 
        int zombieMortos;
    public:
        Planta(int max);
        void moveCima();
        void moveBaixo();
        int getPosicao();
        void atacar(Grid& gd, int dano);
        int getZombiesMortos();
};

#endif
