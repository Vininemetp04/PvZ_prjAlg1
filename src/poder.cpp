#include <vector>
#include <chrono>
#include <string>
#include "poder.h"

Poder::Poder(std::string nome){
    this->nome = nome;
    this->disponivel = true;
}

int Poder::max(std::vector<int>& arr){
    int max = arr[0];
    for (int& a : arr){
        if (a > max) max = a;
    }
    return max;
}

void Poder::troca(int& valor1, int& valor2){
    if (valor1 == valor2) return;
    valor1 += valor2;
    valor2 = valor1 - valor2;
    valor1 -= valor2;
}

double Poder::getTempo(){
    std::chrono::duration<double, std::milli> duracao = this->fim - this->inicio;
    return duracao.count();
}

std::string Poder::getNome(){
    return this->nome;
}

void Poder::ordena(std::vector<int>& arr){
    if (!this->disponivel) return;
    this->inicio = std::chrono::high_resolution_clock::now();
    this->_sort(arr);
    this->fim = std::chrono::high_resolution_clock::now();
    this->disponivel = false;
}
