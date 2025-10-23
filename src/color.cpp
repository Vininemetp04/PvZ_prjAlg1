#include <iostream>

void cgColorBG(int rgb[]) {
    std::cout << "\e[48;2;" << rgb[0] << ";" << rgb[1] << ";" << rgb[2] << "m";
}

void cgColorTX(int rgb[]) {
    std::cout << "\e[38;2;" << rgb[0] << ";" << rgb[1] << ";" << rgb[2] << "m";
}

void resetColor() {
    std::cout << "\e[0m";
}

void blink(){
    
}

void italic(){

}

