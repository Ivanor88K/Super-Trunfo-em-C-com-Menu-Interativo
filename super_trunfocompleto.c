#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carta {
    char estado;
    char codigo[4];
    char nome_cidade[20];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

int main() {
    struct carta carta1, carta2;
    int atributo1, atributo2;
    float valor1_a1, valor2_a1, valor1_a2, valor2_a2;

    printf("Desafio Cartas Super Trunfo!\n");

    // Cadastro da carta 1
    printf("\nCarta 1\n");
    printf("Digite o estado: ");
    scanf(" %c", &carta1.estado);

    printf("Digite o código: ");
    scanf("%s", carta1.codigo);

    printf("Digite o nome da cidade: ");
    scanf("%s", carta1.nome_cidade);

    printf("Digite a população: ");
    scanf("%d", &carta1.populacao);

    printf("Digite a área: ");
    scanf("%f", &carta1.area);

    printf("Digite o PIB: ");
    scanf("%f", &carta1.pib);

    printf("Digite os pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cadastro da carta 2
    printf("\nCarta 2\n");
    printf("Digite o estado: ");
    scanf(" %c", &carta2.estado);

    printf("Digite o código: ");
    scanf("%s", carta2.codigo);

    printf("Digite o nome da cidade: ");
    scanf("%s", carta2.nome_cidade);

    printf("Digite a população: ");
    scanf("%d", &carta2.populacao);

    printf("Digite a área: ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB: ");
    scanf("%f", &carta2.pib);

    printf("Digite os pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculo da densidade demográfica
    float media1 = carta1.area == 0 ? 0 : carta1.populacao / carta1.area;
    float media2 = carta2.area == 0 ? 0 : carta2.populacao / carta2.area;

    // Exibição dos dados
    printf("\nDados da Carta 1:\n");
    printf("Cidade: %s | Estado: %c | Código: %s\n", carta1.nome_cidade, carta1.estado, carta1.codigo);
    printf("População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d | Densidade: %.2f\n",
           carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos, media1);

    printf("\nDados da Carta 2:\n");
    printf("Cidade: %s | Estado: %c | Código: %s\n", carta2.nome_cidade, carta2.estado, carta2.codigo);
    printf("População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d | Densidade: %.2f\n",
           carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos, media2);

    // Escolha dos atributos
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    scanf("%d", &atributo1);

    // Menu dinâmico para o segundo atributo
    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != atributo1) {
                switch (i) {
                    case 1: printf("%d - População\n", i); break;
                    case 2: printf("%d - Área\n", i); break;
                    case 3: printf("%d - PIB\n", i); break;
                    case 4: printf("%d - Pontos Turísticos\n", i); break;
                    case 5: printf("%d - Densidade Demográfica\n", i); break;
                }
            }
        }
        scanf("%d", &atributo2);
        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
            printf("Atributo inválido ou repetido. Tente novamente.\n");
        }
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

    // Atribuição dos valores do primeiro atributo
    switch (atributo1) {
        case 1:
            valor1_a1 = carta1.populacao;
            valor2_a1 = carta2.populacao;
            break;
        case 2:
            valor1_a1 = carta1.area;
            valor2_a1 = carta2.area;
            break;
        case 3:
            valor1_a1 = carta1.pib;
            valor2_a1 = carta2.pib;
            break;
        case 4:
            valor1_a1 = carta1.pontos_turisticos;
            valor2_a1 = carta2.pontos_turisticos;
            break;
        case 5:
            valor1_a1 = media1;
            valor2_a1 = media2;
            break;
    }

    // Atribuição dos valores do segundo atributo
    switch (atributo2) {
        case 1:
            valor1_a2 = carta1.populacao;
            valor2_a2 = carta2.populacao;
            break;
        case 2:
            valor1_a2 = carta1.area;
            valor2_a2 = carta2.area;
            break;
        case 3:
            valor1_a2 = carta1.pib;
            valor2_a2 = carta2.pib;
            break;
        case 4:
            valor1_a2 = carta1.pontos_turisticos;
            valor2_a2 = carta2.pontos_turisticos;
            break;
        case 5:
            valor1_a2 = media1;
            valor2_a2 = media2;
            break;
    }

    // Comparação dos atributos
    int pontos1 = 0, pontos2 = 0;

    pontos1 += (atributo1 == 5) ? (valor1_a1 < valor2_a1) : (valor1_a1 > valor2_a1);
    pontos2 += (atributo1 == 5) ? (valor2_a1 < valor1_a1) : (valor2_a1 > valor1_a1);

    pontos1 += (atributo2 == 5) ? (valor1_a2 < valor2_a2) : (valor1_a2 > valor2_a2);
    pontos2 += (atributo2 == 5) ? (valor2_a2 < valor1_a2) : (valor2_a2 > valor1_a2);

    float soma1 = valor1_a1 + valor1_a2;
    float soma2 = valor2_a1 + valor2_a2;

    // Exibição do resultado
    printf("===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Atributos escolhidos: %d e %d\n", atributo1, atributo2);
    printf("%s: %.2f + %.2f = %.2f\n", carta1.nome_cidade, valor1_a1, valor1_a2, soma1);
    printf("%s: %.2f + %.2f = %.2f\n", carta2.nome_cidade, valor2_a1, valor2_a2, soma2);

    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("Vencedor: %s\n", (soma1 > soma2) ? carta1.nome_cidade : carta2.nome_cidade);
    }

    return 0;
}
