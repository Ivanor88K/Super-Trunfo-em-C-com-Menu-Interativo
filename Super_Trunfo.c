#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carta {
    char carta;
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
    int escolha;

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

    // Exibir dados
    float media1 = carta1.populacao / (carta1.area + (carta1.area == 0));
    float media2 = carta2.populacao / (carta2.area + (carta2.area == 0));

    printf("\nDados da Carta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nome_cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", media1);

    printf("\nDados da Carta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome_cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", media2);

    int 
    atributo1, atributo2;

    // primeiro menu 
    printf(" Escolha o primeiro atributo para comparar: \n");
    printf("1- população\n2- Área\n3 -Pib\n4- Pontos turisticos\n5 - Densidade Demográfica\n");
    scanf("%d", &atributo1);

    // Segundo Menu
    printf("Escolha o segundo atributo (diferente do primeiro: \n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) 
    { switch (i) 
    {
    case 1: printf("%d - população\n", i); 
        break;
    case 2: printf("%d - Área\n", i);
        break;
    case 3: printf("%d - PIB\n", i);
        break;
    case 4: printf("%d - Pontos turisticos\n", i);
        break;
    case 5: printf("%d - Densidade Demográfica\n", i); 
        break;    
    default: printf(" Opção incorreta");
        break;
    }
    }
    }
    scanf("%d", &atributo2);
    if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) 
    {
        printf("Atributo invalido, tente novamente. \n");
    }
     while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

     // comparação de atributo
    float valor1_a1 = getValor(carta1, atributo1, media1);
    float valor2_a1 = getValor(carta2, atributo1, media2);
    float valor1_a2 = getValor(carta1, atributo2, media1);
    float valor2_a2 = getValor(carta2, atributo2, media2);

    int pontos1 = 0, pontos2 = 0;
    pontos1 += (atributo1 == 5) ? (valor1_a1 , valor2_a1) : (valor1_a1 > valor2_a1);
    pontos2 += (atributo1 == 5) ? (valor2_a1 , valor1_a1) : (valor2_a1 > valor1_a1);

    pontos1 += (atributo2 == 5) ? (valor1_a2 < valor2_a2) : (valor1_a2 > valor2_a2);
    pontos2 += (atributo2 == 5) ? (valor2_a2 < valor1_a2) : (valor2_a2 > valor1_a2);

    float soma1 = valor1_a1 + valor1_a2;
    float soma2 = valor2_a1 + valor2_a2;

    //Resultado

    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Atributos escolhidos: %d e %d\n", atributo1, atributo2);
    printf("%s: %.2f + %.2f = %.2f\n", carta1.nome_cidade, valor1_a1, valor1_a2, soma1);
    printf("%s: %.2f + %.2f = %.2f\n", carta2.nome_cidade, valor2_a1, valor2_a2, soma2);

    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("Vencedor: %s\n", (soma1 > soma2) ? carta1.nome_cidade : carta2.nome_cidade);
    }

     
    // Menu de comparação
    do {
        printf("\n===== MENU DE COMPARAÇÃO =====\n");
        printf("1 - Comparar população\n");
        printf("2 - Comparar área\n");
        printf("3 - Comparar PIB\n");
        printf("4 - Comparar pontos turísticos\n");
        printf("5 - Comparar densidade demográfica\n");
        printf("0 - Sair\n");
        printf("Escolha um atributo para comparar: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (carta1.populacao > carta2.populacao)
                    printf("Carta 1 tem maior população.\n");
                else if (carta1.populacao < carta2.populacao)
                    printf("Carta 2 tem maior população.\n");
                else
                    printf("Empate em população.\n");
                break;
            case 2:
                if (carta1.area > carta2.area)
                    printf("Carta 1 tem maior área.\n");
                else if (carta1.area < carta2.area)
                    printf("Carta 2 tem maior área.\n");
                else
                    printf("Empate em área.\n");
                break;
            case 3:
                if (carta1.pib > carta2.pib)
                    printf("Carta 1 tem maior PIB.\n");
                else if (carta1.pib < carta2.pib)
                    printf("Carta 2 tem maior PIB.\n");
                else
                    printf("Empate em PIB.\n");
                break;
            case 4:
                if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                    printf("Carta 1 tem mais pontos turísticos.\n");
                else if (carta1.pontos_turisticos < carta2.pontos_turisticos)
                    printf("Carta 2 tem mais pontos turísticos.\n");
                else
                    printf("Empate em pontos turísticos.\n");
                break;
            case 5:
                if (media1 > media2)
                    printf("Carta 1 tem maior densidade demográfica.\n");
                else if (media1 < media2)
                    printf("Carta 2 tem maior densidade demográfica.\n");
                else
                    printf("Empate em densidade demográfica.\n");
                break;
            case 0:
                printf("Encerrando comparação...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
