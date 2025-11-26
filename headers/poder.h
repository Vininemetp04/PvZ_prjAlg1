#ifndef PODER_H
#define PODER_H

#include <vector>
#include <chrono>
#include <string>

class Poder{
    protected:
        int max(std::vector<int>& arr);
        void troca(int& valor1, int&valor2);
        bool disponivel;
        std::string nome;
        std::chrono::high_resolution_clock::time_point inicio;
        std::chrono::high_resolution_clock::time_point fim;
        virtual void _sort(std::vector<int>& arr) = 0;
        int count_troca;
        int count_comparacao;
    public:
        Poder(std::string nome);
        virtual ~Poder() {}
        void ordena(std::vector<int>& arr);
        double getTempo();
        bool getDisponivel();
        std::string getNome();
        int getComparacao();
        int getTroca();
        void reset();
};

#endif
