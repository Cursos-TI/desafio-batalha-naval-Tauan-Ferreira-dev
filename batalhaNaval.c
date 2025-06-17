#include <stdio.h>

int main() {
    // Criação do tabuleiro 10x10 preenchido com 0 (água)
    int tabuleiro[10][10];

    // Inicializa todo o tabuleiro com 0
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    int tamanhoNavio = 3;  // Tamanho fixo dos navios
    int podeColocar = 1;   // Variável de controle

    // --- NAVIO HORIZONTAL ---
    int linhaH = 2;
    int colunaH = 4;

    if (colunaH + tamanhoNavio <= 10) {
        podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        } else {
            printf("Não foi possível posicionar o navio horizontal.\n");
        }
    } else {
        printf("Navio horizontal fora dos limites!\n");
    }

    // --- NAVIO VERTICAL ---
    int linhaV = 5;
    int colunaV = 6;

    if (linhaV + tamanhoNavio <= 10) {
        podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Não foi possível posicionar o navio vertical.\n");
        }
    } else {
        printf("Navio vertical fora dos limites!\n");
    }

    // --- NAVIO DIAGONAL PRINCIPAL ↘ (linha e coluna aumentam) ---
    int linhaD1 = 0;
    int colunaD1 = 0;

    if (linhaD1 + tamanhoNavio <= 10 && colunaD1 + tamanhoNavio <= 10) {
        podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        } else {
            printf("Não foi possível posicionar o navio diagonal ↘.\n");
        }
    } else {
        printf("Navio diagonal ↘ fora dos limites!\n");
    }

    // --- NAVIO DIAGONAL SECUNDÁRIA ↙ (linha aumenta e coluna diminui) ---
    int linhaD2 = 0;
    int colunaD2 = 9;

    if (linhaD2 + tamanhoNavio <= 10 && colunaD2 - (tamanhoNavio - 1) >= 0) {
        podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        } else {
            printf("Não foi possível posicionar o navio diagonal ↙.\n");
        }
    } else {
        printf("Navio diagonal ↙ fora dos limites!\n");
    }

    // --- EXIBINDO O TABULEIRO ---
    printf("\nTABULEIRO FINAL:\n\n");
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
