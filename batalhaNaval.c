#include <stdio.h>

// Constantes dos itens da batalha naval
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para mostrar o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicialização do tabuleiro com água (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Vetores representando os navios (valores 3)
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais fixas dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;

    // verifica se  o navio horizontal está dentro dos limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // verifica se o navio vertical está dentro dos limites
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // verifica sobreposição entre navios
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha_h = linha_horizontal;
        int col_h = coluna_horizontal + i;

        int linha_v = linha_vertical + i;
        int col_v = coluna_vertical;

        if (linha_h == linha_v && col_h == col_v) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios estão sobrepostos!\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}