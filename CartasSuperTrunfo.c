#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARTAS 32
#define RODADAS 5

typedef struct {
    char nome[30];
    char codigo[5];
    float populacao;
    float pib;
    float area;
    int pontos_turisticos;
} Carta;

int main() {
    Carta baralho[TOTAL_CARTAS] = {
        {"Argentina", "A1", 84.48, 4.456, 357.592, 5},
        {"Argentina", "A2", 70.2, 5.398, 789.678, 8},
        {"Argentina", "A3", 65.8, 8.987, 987.698, 10},
        {"Argentina", "A4", 36.7, 10.859, 598.321, 7},
        {"Brasil", "B1", 216.4, 2.174, 8.510, 3},
        {"Brasil", "B2", 215.9, 1.175, 9.516, 6},
        {"Brasil", "B3", 213.5, 5.176, 6.897, 12},
        {"Brasil", "B4", 212.0, 6.879, 3.879, 14},
        {"Canada", "C1", 20.8, 25.9, 30.8, 35},
        {"Canada", "C2", 40.8, 45.6, 50.8, 40},
        {"Canada", "C3", 55.7, 60.4, 65.3, 45},
        {"Canada", "C4", 70.3, 75.1, 80.0, 1},
        {"Dinamarca", "D1", 30.0, 40.1, 50.2, 10},
        {"Dinamarca", "D2", 60.3, 70.4, 80.5, 20},
        {"Dinamarca", "D3", 90.6, 100.7, 110.8, 30},
        {"Dinamarca", "D4", 120.9, 130.0, 140.1, 40},
        {"Espanha", "E1", 144.2, 148.4, 152.6, 4},
        {"Espanha", "E2", 160.8, 164.6, 168.4, 8},
        {"Espanha", "E3", 176.6, 180.4, 184.2, 12},
        {"Espanha", "E4", 192.4, 196.8, 240.6, 16},
        {"Franca", "F1", 102.1, 104.2, 106.4, 5},
        {"Franca", "F2", 104.5, 110.7, 112.8, 7},
        {"Franca", "F3", 109.3, 115.3, 120.8, 9},
        {"Franca", "F4", 108.3, 116.3, 114.1, 11},
        {"Grecia", "G1", 90.1, 92.4, 94.7, 6},
        {"Grecia", "G2", 192.3, 170.4, 145.9, 1},
        {"Grecia", "G3", 41.2, 87.6, 47.8, 5},
        {"Grecia", "G4", 55.9, 163.8, 157.7, 4},
        {"Holanda", "H1", 103.7, 105.8, 107.9, 7},
        {"Holanda", "H2", 111.9, 113.7, 115.5, 8},
        {"Holanda", "H3", 117.3, 119.1, 121.7, 1},
        {"Holanda", "H4", 123.4, 125.0, 127.0, 4}
    };

    char *nomesAtributos[] = {
        "População (em milhões)",
        "PIB (em trilhões)",
        "Área (em km²)",
        "Pontos turísticos"
    };

    int score = 0;
    srand(time(NULL));

    printf("=== SUPER TRUNFO DE CIDADES - MODO SOLO ===\n");
    printf("Adivinhe qual é o melhor atributo da sua carta em %d rodadas.\n", RODADAS);

    for (int rodada = 1; rodada <= RODADAS; rodada++) {
        // Sorteia uma carta
        int idx = rand() % TOTAL_CARTAS;
        Carta carta = baralho[idx];

        printf("\n----- Rodada %d -----\n", rodada);
        printf("Sua carta: %s - %s\n", carta.codigo, carta.nome);
        printf("1. %s: %.2f\n", nomesAtributos[0], carta.populacao);
        printf("2. %s: %.3f\n", nomesAtributos[1], carta.pib);
        printf("3. %s: %.3f\n", nomesAtributos[2], carta.area);
        printf("4. %s: %d\n", nomesAtributos[3], carta.pontos_turisticos);
        printf("Qual atributo você acha que é o melhor (1-4)? ");
        int escolha;
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 4) {
            printf("Opção inválida! Você perde esta rodada.\n");
            continue;
        }

        // Armazena os valores dos atributos em um vetor
        float valores[4];
        valores[0] = carta.populacao;
        valores[1] = carta.pib;
        valores[2] = carta.area;
        valores[3] = (float)carta.pontos_turisticos;

        // Encontra qual atributo é o melhor (maior valor)
        int melhor = 0;
        for (int i = 1; i < 4; i++) {
            if (valores[i] > valores[melhor]) {
                melhor = i;
            }
        }

        if (escolha - 1 == melhor) {
            printf("Você acertou! Esse é o melhor atributo da carta.\n");
            score++;
        } else {
            printf("Você errou. O melhor atributo era o %d - %s.\n", melhor + 1, nomesAtributos[melhor]);
        }
    }

    printf("\n=== Placar Final ===\n");
    printf("Você acertou %d de %d rodadas.\n", score, RODADAS);

    return 0;
}
