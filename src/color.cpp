#include <iostream>

void cgColorBG(int r, int g, int b) {
    std::cout << "\e[48;2;" << r << ";" << g << ";" << b << "m";
}

void cgColorTX(int r, int g, int b) {
    std::cout << "\e[38;2;" << r << ";" << g << ";" << b << "m";
}

void resetColor() {
    std::cout << "\e[0m";
}
void clear(){
    std::cout << "\e[H\e[2J";    
}

