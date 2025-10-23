# Projeto Algoritmos I: A Defesa das Plantas

> Um jogo de estratégia em C++ baseado em Plants vs. Zombies, onde os poderes de defesa são algoritmos de ordenação.

Este projeto foi desenvolvido para a disciplina de **Algoritmos I** como uma forma prática de aplicar e analisar o comportamento de diferentes métodos de ordenação em um ambiente de simulação interativo.

## 🎯 Objetivos de Aprendizagem

* Aplicar estruturas bidimensionais (matrizes) em problemas de simulação.
* Implementar e comparar métodos clássicos de ordenação.
* Explorar o conceito de recursão em algoritmos (Merge Sort, Quick Sort).
* Analisar complexidade de tempo e espaço de diferentes abordagens.
* Desenvolver raciocínio lógico e estratégico em programação.

## 🧟 O Jogo

Os zumbis estão invadindo o jardim! Você é uma planta guerreira defendendo um campo de batalha (uma matriz N x M). Cada linha é uma trilha de ataque, e novos zumbis surgem a cada rodada.

Sua missão é sobreviver o máximo possível usando seus "poderes" — algoritmos de ordenação — para organizar os zumbis e eliminá-los eficientemente. Cuidado: **cada poder só pode ser usado uma vez!**

## ✨ Funcionalidades

* **Campo de Batalha (Matriz):** Um campo N x M onde `0` é uma célula vazia e um valor `> 0` representa o HP de um zumbi.
* **Movimentação da Planta:** A planta pode se mover verticalmente (para cima e para baixo) para escolher a linha onde vai agir.
* **Geração de Zumbis:** A cada rodada, novos zumbis com HP aleatório (entre 10 e 99) podem surgir no final das linhas.
* **Ataque Básico:** A planta pode atacar a linha atual, causando 5 de dano ao zumbi mais avançado (o que está mais à esquerda).
* **Poderes de Defesa (Ordenação):** 6 algoritmos de ordenação que podem ser usados uma única vez por jogo.
* **Menu Interativo:** Um menu completo no terminal para controlar todas as ações do jogo.
* **Estatísticas Detalhadas:** O jogo registra e exibe o número de **comparações**, **trocas** e o **tempo de execução** (em nanossegundos) de cada poder de ordenação utilizado.
* **Ranking de Algoritmos:** Ao final do jogo, um relatório compara o desempenho de todos os algoritmos que foram usados.

## ⚡ Poderes de Defesa (Algoritmos)

Cada poder ordena os zumbis na linha atual da planta por HP (ordem crescente):

1.  **Selection Sort** – “Raízes calculistas”
2.  **Insertion Sort** – “Crescimento gradual”
3.  **Bubble Sort** – “Explosão de seiva”
4.  **Merge Sort** – “Divisão de galhos”
5.  **Quick Sort** – “Ataque relâmpago”
6.  **Heap Sort** – “Domínio das raízes profundas”

## 🎮 Como Jogar

O jogo é controlado por um menu numérico:

* `1) Subir linha`: Move a planta para a linha de cima (`linha - 1`).
* `2) Descer linha`: Move a planta para a linha de baixo (`linha + 1`).
* `3) Usar poder de defesa (ordenar)`: Abre o menu de algoritmos. Escolha um para ordenar a linha atual.
* `4) Atacar linha atual`: Causa 5 de dano ao zumbi mais avançado (mais à esquerda) na linha da planta.
* `5) Próxima rodada`: Avança o contador de rodada e gera novos zumbis.
* `6) Mostrar estatísticas`: Exibe o relatório de desempenho (comparações, trocas, tempo) dos poderes já usados.
* `0) Sair`: Encerra o jogo.

**Objetivo:** Sobreviva! Você vence se limpar o campo de todos os zumbis e perde se o campo ficar totalmente cheio.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++

## 👨‍💻 Autores

* **Rafaela de Castro Lima** **Vinicius Nemet**
