#ifndef PLANTA_H
#define PLANTA_H

class Planta{
    private:
        int posicao; // Posição atual da planta
        int max;     // Valor maximo da posição 
    public:
        Planta(int max);
        void moveCima();
        void moveBaixo();
        int getPosicao();
};

#endif
