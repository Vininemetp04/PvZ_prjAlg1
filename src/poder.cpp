#include <vector>
#include <chrono>
#include <string>
#include "poder.h"

Poder::Poder(std::string nome){
    this->nome = nome;
    this->disponivel = true;
    this->count_comparacao = 0;
    this->count_troca = 0;
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
    this->count_troca++;
    valor1 += valor2;
    valor2 = valor1 - valor2;
    valor1 -= valor2;
}

double Poder::getTempo(){
    std::chrono::duration<double, std::nano> duracao = this->fim - this->inicio;  // Pega a diferença de nanosegundos dos tempos de inicio e fim
    return duracao.count();                                                        // Returna os ms
}

bool Poder::getDisponivel(){
    return this->disponivel;
}

std::string Poder::getNome(){
    return this->nome;
}

void Poder::ordena(std::vector<int>& arr){
    if (!this->disponivel) return;
    this->inicio = std::chrono::high_resolution_clock::now(); // Pega hora antes da ordenação
    this->_sort(arr);                                         // Ordena o array
    this->fim = std::chrono::high_resolution_clock::now();    // Pega hora depois da ordenação
    this->disponivel = false;                                 // Deixa poder indisponivel
}

int Poder::getComparacao(){
    return this->count_comparacao;
}

int Poder::getTroca(){
    return this->count_troca;
}
