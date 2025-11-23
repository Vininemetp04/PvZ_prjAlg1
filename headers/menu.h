#include <iostream>
#include "planta.h"
#include "poder.h"
#include <vector>
#include <memory>
#include <string>

void menu(char& jogada);

void estatistica(Planta& pl, const std::vector<std::unique_ptr<Poder>>& poderes);

void drawPoderes(const std::vector<std::unique_ptr<Poder>>& poderes);
