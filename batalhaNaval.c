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

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // --- NAVIO HORIZONTAL ---
    // Começa na linha 2, coluna 4
    int linhaH = 2;
    int colunaH = 4;

    // Verifica se cabe no tabuleiro
    if (colunaH + tamanhoNavio <= 10) {
        // Verifica se não tem outro navio no caminho
        int podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podeColocar = 0;
            }
        }

        // Se puder, coloca o navio
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
    // Começa na linha 5, coluna 6
    int linhaV = 5;
    int colunaV = 6;

    // Verifica se cabe no tabuleiro
    if (linhaV + tamanhoNavio <= 10) {
        // Verifica se não tem outro navio no caminho
        int podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeColocar = 0;
            }
        }

        // Se puder, coloca o navio
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
