#include <iostream>

using namespace std;

void printColor(int cor, string str){
	string cores[] = {
        "\033[0m",     // 0:  Limpa formatação (Reset)
        "\033[31m",    // 1:  Vermelho
        "\033[33m",    // 2:  Amarelo
        "\033[32m",    // 3:  Verde
        "\033[34m",    // 4:  Azul
        "\033[35m",    // 5:  Magenta
        "\033[36m",    // 6:  Ciano
        "\033[1;31m",  // 7:  Vermelho claro 
        "\033[1;33m",  // 8:  Amarelo claro 
        "\033[1;32m",  // 9:  Verde claro  
        "\033[1;34m",  // 10: Azul claro
	"\033[1;35m",  // 11: Magenta claro
        "\033[1;36m",  // 12: Ciano claro
    }; 

	cout << cores[cor] << str << cores[0];
}

int main(){
	const int COLS = 9;
	const int LINE = 5;
	
	int grid[LINE][COLS];

	for (int i = 0; i < LINE; i++){
		for (int j = 0; j < COLS; j++){
			grid[i][j] = 3;
			printColor(grid[i][j], "M");
		}
		cout << endl;
	}

	return 0;
}
