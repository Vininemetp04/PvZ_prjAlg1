#include <iostream>
#include "planta.h"
#include "poder.h"
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
#include <string>

void menu(char& jogada);

void estatistica(Planta& pl, int rodadas, const std::vector<std::unique_ptr<Poder>>& poderes, bool& venceu);

void drawPoderes(const std::vector<std::unique_ptr<Poder>>& poderes);

void printAlinhado(std::string texto, int larguraTotal);

void menuPrincipal(int& maxRodadas, char& jogada);

void tutorial();
