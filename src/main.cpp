#include <iostream>

using namespace std;

void printColor(int r, int g, int b, string str){
    cout << "\e[48;2;"<<r<<";"<<g<<";"<<b<<";2m"<<str<<"\e[0m";
    
}

int main(){
    const int COLS = 9;
    const int LINE = 5;
  	
    int grid[LINE][COLS];
  
    for (int i = 0; i < LINE; i++){
        for (int j = 0; j < COLS; j++){
            grid[i][j] = 3;
            printColor(20, 180, 23, " ");
  	    }
        cout << endl;
  	}
  
  	return 0;
}
