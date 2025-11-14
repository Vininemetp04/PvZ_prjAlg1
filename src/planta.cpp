#include "planta.h"

Planta::Planta(int max){
    this->posicao = 0;
    this->max = max-1;
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
