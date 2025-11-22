#include "planta.h"
#include "grid.h"
#include <vector>

Planta::Planta(int max){
    this->posicao = 0;
    this->max = max-1;
    this->zombieMortos = 0;
}

void Planta::moveCima(){
    if(this->posicao == 0) return;
    this->posicao--;
}

void Planta::moveBaixo(){
    if(this->posicao == this->max) return;
    this->posicao++;
}

int Planta::getPosicao(){
    return this->posicao;
}

void Planta::atacar(Grid& gd, int dano){
   for (int& z : gd.getLinha(this->posicao)){
        if (z > 0){ 
            z -= dano;
            if(z<0) z = 0;
            if(z==0) this->zombieMortos++;
            break;
        }
   } 
}

int Planta::getZombiesMortos(){
    return this->zombieMortos;
}
