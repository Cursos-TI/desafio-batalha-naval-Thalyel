#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com zeros
void iniciar_Tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para criar matriz de habilidade Cone (5x5)
void criar_Habilidade_Cone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
            // Cone: expande da linha 0 até a base na última linha
            if (i >= 2 && j >= (2 - (i - 2)) && j <= (2 + (i - 2))) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para criar matriz de habilidade Cruz (5x5)
void criar_Habilidade_Cruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
            // Cruz: centro (2,2) com braços horizontais e verticais
            if (i == 2 || j == 2) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para criar matriz de habilidade Octaedro (5x5)
void criar_Habilidade_Octaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
            // Octaedro: losango centrado em (2,2)
            if (abs(i - 2) + abs(j - 2) <= 2) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para validar o posicionamento de um navio
int validar_Navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tamanho, int horizontal) {
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        return 0;
    }

    if (horizontal == 1) { // Horizontal
        if (coluna + tamanho > TAM_TABULEIRO) return 0;
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] != 0) return 0;
        }
    } else if (horizontal == 0) { // Vertical
        if (linha + tamanho > TAM_TABULEIRO) return 0;
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] != 0) return 0;
        }
    } else if (horizontal == 3) { // Diagonal ascendente
        if (linha + tamanho > TAM_TABULEIRO || coluna + tamanho > TAM_TABULEIRO) return 0;
        for (int k = 0; k < tamanho; k++) {
            if (tabuleiro[linha + k][coluna + k] != 0) return 0;
        }
    } else if (horizontal == 2) { // Diagonal descendente
        if (linha + tamanho > TAM_TABULEIRO || coluna - tamanho + 1 < 0) return 0;
        for (int n = 0; n < tamanho; n++) {
            if (tabuleiro[linha + n][coluna - n] != 0) return 0;
        }
    } else {
        return 0;
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionar_Navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tamanho, int horizontal) {
    if (horizontal == 1) {
        for (int j = coluna; j < coluna + tamanho; j++) {
            tabuleiro[linha][j] = 3;
        }
    } else if (horizontal == 0) {
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = 3;
        }
    } else if (horizontal == 3) {
        for (int k = 0; k < tamanho; k++) {
            tabuleiro[linha + k][coluna + k] = 3;
        }
    } else if (horizontal == 2) {
        for (int n = 0; n < tamanho; n++) {
            tabuleiro[linha + n][coluna - n] = 3;
        }
    }
}

// Função para sobrepor habilidade no tabuleiro
int sobrepor_Habilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    // Calcular o offset para centralizar a habilidade
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Calcular coordenadas no tabuleiro
            int tab_linha = origem_linha - offset + i;
            int tab_coluna = origem_coluna - offset + j;
            
            // Verificar se está dentro dos limites do tabuleiro
            if (tab_linha >= 0 && tab_linha < TAM_TABULEIRO && tab_coluna >= 0 && tab_coluna < TAM_TABULEIRO) {
                // Se a habilidade tem valor 1, marcar com 5 (área afetada)
                if (habilidade[i][j] == 1) {
                    tabuleiro[tab_linha][tab_coluna] = 5;
                }
            }
        }
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibir_Tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n  ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf("0 "); // Água
            else if (tabuleiro[i][j] == 3) printf("3 "); // Navio
            else if (tabuleiro[i][j] == 5) printf("5 "); // Área afetada
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade_cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidade_cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidade_octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    printf("\n*** Jogo de Batalha Naval com Habilidades ***\n");

    // Inicializar o tabuleiro
    iniciar_Tabuleiro(tabuleiro);

    // Posicionar navios
    int navios[][4] = {
        {1, 7, 3, 1}, // Horizontal
        {6, 0, 3, 0}, // Vertical
        {1, 1, 3, 3}, // Diagonal ascendente
        {7, 7, 3, 2}  // Diagonal descendente
    };

    for (int i = 0; i < 4; i++) {
        if (validar_Navio(tabuleiro, navios[i][0], navios[i][1], navios[i][2], navios[i][3])) {
            posicionar_Navio(tabuleiro, navios[i][0], navios[i][1], navios[i][2], navios[i][3]);
        } else {
            printf("Erro: Posicionamento inválido para o navio %d!\n", i + 1);
            return 1;
        }
    }

    // Criar matrizes de habilidades
    criar_Habilidade_Cone(habilidade_cone);
    criar_Habilidade_Cruz(habilidade_cruz);
    criar_Habilidade_Octaedro(habilidade_octaedro);

    // Definir pontos de origem para as habilidades
    int origem_cone[] = {4, 4};
    int origem_cruz[] = {2, 2};
    int origem_octaedro[] = {7, 7};

    // Sobrepor habilidades
    sobrepor_Habilidade(tabuleiro, habilidade_cone, origem_cone[0], origem_cone[1]);
    sobrepor_Habilidade(tabuleiro, habilidade_cruz, origem_cruz[0], origem_cruz[1]);
    sobrepor_Habilidade(tabuleiro, habilidade_octaedro, origem_octaedro[0], origem_octaedro[1]);

    // Exibir o tabuleiro com navios e habilidades
    printf("\nTabuleiro com navios e áreas de efeito:\n");
    exibir_Tabuleiro(tabuleiro);

    // Exibir matrizes de habilidades para verificação
    printf("\nMatriz de Habilidade Cone:\n");
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", habilidade_cone[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de Habilidade Cruz:\n");
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", habilidade_cruz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de Habilidade Octaedro:\n");
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", habilidade_octaedro[i][j]);
        }
        printf("\n");
    }

    return 0;
}