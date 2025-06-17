#include <stdio.h>

// Tamanho do tabuleiro e das matrizes de habilidade
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para imprimir o tabuleiro com legenda
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n===== TABULEIRO FINAL =====\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". "); // água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // área de habilidade
            }
        }
        printf("\n");
    }
}

int main() {
    // --- 1. INICIALIZA O TABULEIRO COM ÁGUA ---
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- 2. POSICIONA ALGUNS NAVIOS COMO EXEMPLO ---
    tabuleiro[2][4] = tabuleiro[2][5] = tabuleiro[2][6] = 3; // navio horizontal
    tabuleiro[5][1] = tabuleiro[6][1] = tabuleiro[7][1] = 3; // navio vertical
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = 3; // navio diagonal ↘
    tabuleiro[0][9] = tabuleiro[1][8] = tabuleiro[2][7] = 3; // navio diagonal ↙

    // --- 3. MATRIZ DE HABILIDADE: CONE 🔺 ---
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i >= j && i + j >= TAM_HABILIDADE - 1) {
                cone[i][j] = 1; // dentro da área do cone
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // --- 4. MATRIZ DE HABILIDADE: CRUZ ✝️ ---
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                cruz[i][j] = 1; // parte da cruz
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // --- 5. MATRIZ DE HABILIDADE: OCTAEDRO 💎 ---
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1; // dentro da forma de losango
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // --- 6. FUNÇÃO PARA SOBREPOR A HABILIDADE NO TABULEIRO ---
    void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
        int offset = TAM_HABILIDADE / 2;

        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                int linhaTab = origemX - offset + i;
                int colunaTab = origemY - offset + j;

                // Garante que a posição está dentro dos limites
                if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {
                    if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] != 3) {
                        tabuleiro[linhaTab][colunaTab] = 5; // marca área de efeito (não sobrescreve navios)
                    }
                }
            }
        }
    }

    // --- 7. APLICA HABILIDADES NO TABULEIRO ---
    aplicarHabilidade(tabuleiro, cone, 7, 2);      // Aplica cone na posição (7,2)
    aplicarHabilidade(tabuleiro, cruz, 3, 5);      // Aplica cruz na posição (3,5)
    aplicarHabilidade(tabuleiro, octaedro, 6, 6);  // Aplica octaedro na posição (6,6)

    // --- 8. EXIBE O TABULEIRO ---
    imprimirTabuleiro(tabuleiro);

    return 0;
}
