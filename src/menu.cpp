#include <iostream>
#include "planta.h"
#include "poder.h"
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
#include <string>

using namespace std;

void menu(char& jogada){
    cout << "W - Sobe Linha  | P - Sair\nS - Desce Linha | A - Ataca\n";
    cin >> jogada;
}

void drawPoderes(const vector<unique_ptr<Poder>>& poderes) {
    cout << " PODERES \n";
    
    for (size_t i = 0; i < poderes.size(); i++) {
        
        if (poderes[i]->getDisponivel()) {
            cout << "\033[97m"; // BRANCO (Disponível)
        } else {
            cout << "\033[90m"; // CINZA (Indisponível)
        }

        cout << (i + 1) << " - " << poderes[i]->getNome();

        cout << "\033[0m"; // RESETAR COR IMEDIATAMENTE
        if (i%2==1) cout << "\n";
        else cout << " | ";
    }
}

void menuPrincipal(int& maxRodadas, char& jogada) {
    cout << "=========================================\n";
    cout << "      PLANTS VS ZOMBIES: ALG EDITION     \n";
    if (maxRodadas > 0){
        cout << "=========================================\n";
        cout << "       RECORDE ATUAL: " << maxRodadas << " RODADAS       \n";
    }
    cout << "=========================================\n\n";
    
    cout << "1 - Iniciar Jogo\n";
    cout << "2 - Tutorial / Dicas\n";
    cout << "0 - Sair\n\n";
    
    cout << "Escolha uma opcao: ";
    cin >> jogada;
}

void tutorial() {
    cout << "================= TUTORIAL =================\n\n"
     << "[ MECANICA DE VIDA ]\n"
     << "  Os zumbis nao mostram numeros de vida.\n"
     << "  Porem, preste atencao na cor deles:\n"
     << "  Quanto mais \033[31mVERMELHO\033[0m o zumbi estiver,\n"
     << "  mais perto da morte ele esta!\n\n";
    
    cout << "[ OBJETIVO ]\n"
     << "  Sobreviva o maximo de rodadas possivel.\n"
     << "  Use seus poderes de ordenacao com sabedoria,\n"
     << "  pois cada um so pode ser usado UMA VEZ.\n\n";
    
    cout << "Pressione qualquer tecla e ENTER para voltar...";
    char temp;
    cin >> temp;
}

// Função auxiliar para alinhar texto com acentos corretamente
void printAlinhado(string texto, int larguraTotal) {
    int tamanhoVisual = 0;
    for (size_t i = 0; i < texto.length(); i++) {
        // Em UTF-8, bytes de continuação começam com 10xxxxxx (0x80).
        // Contamos apenas os bytes que NÃO são continuação.
        if ((texto[i] & 0xC0) != 0x80) {
            tamanhoVisual++;
        }
    }
    
    int espacos = larguraTotal - tamanhoVisual;
    if (espacos < 0) espacos = 0;
    
    cout << texto << string(espacos, ' ');
}

void estatistica(Planta& pl, int rodadas, const vector<unique_ptr<Poder>>& poderes, bool& venceu){
    cout << "=-=-=-=-=-=-=| ESTATISTICAS |=-=-=-=-=-=-=\n";
    if (venceu) cout << "A Planta VENCEU!!!\n";
    else cout << "A Planta PERDEU :(\n";
    cout << "Zombis Mortos: " << pl.getZombiesMortos() << " | Rodadas: " << rodadas << "\n\n";

    // --- CABEÇALHO ---
    cout << "*" << string(72, '-') << "*\n";
    cout << "| "; 
    printAlinhado("Nome do Poder", 30); // Usamos nossa função aqui
    cout << "| " << setw(10) << "Tempo" 
         << " | " << setw(10) << "Trocas" 
         << " | " << setw(12) << "Comparações " << " |\n";
    
    // --- LINHA DIVISÓRIA ---
    cout << "|" << string(31, '-') << "|" << string(12, '-') << "|" << string(12, '-') << "|" << string(14, '-') << "|\n";

    // --- CONTEÚDO ---
    cout << fixed << setprecision(1);
    for (const auto& poder : poderes) { // Escreve o frame dos dados dos PODERES
        cout << "| ";
        
        // 1. Imprime o Nome alinhado (corrige o problema dos acentos)
        printAlinhado(poder->getNome(), 30);
        
        cout << "|";

        if (!poder->getDisponivel()) { 
            // 2. Se foi usado, imprime os dados numéricos alinhados à direita
            cout << setw(8) << poder->getTempo() << "ns " << " |"
                 << setw(11) << poder->getTroca() << " |" 
                 << setw(13) << poder->getComparacao() << " |";
        } else { 
            // 3. Se não foi usado, imprime traços centralizados
            cout << setw(11) << " - " << " |" 
                 << setw(11) << " - " << " |" 
                 << setw(13) << " - " << " |";
        }
        cout << "\n";
    }

    // --- LINHA FINAL ---
    cout << "*" << string(72, '-') << "*\n";
    cout << "Pressione qualquer tecla e ENTER para voltar...";
    char temp;
    cin >> temp;
}

