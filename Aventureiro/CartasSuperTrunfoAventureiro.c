// Desafio Super Trunfo - Países
// Tema 2 - Cadastro das Cartas + Cálculo de Atributos
// Nivel Aventureiro

#include <stdio.h>

int main() {
    // ----------------- CARTA 1 -----------------
    char codigo1[4];
    char nome1[30];
    int populacao1;
    float area1;
    float pib1;
    int turismo1;
    float densidade1;
    float pib_per_capita1;

    // ----------------- CARTA 2 -----------------
    char codigo2[4];
    char nome2[30];
    int populacao2;
    float area2;
    float pib2;
    int turismo2;
    float densidade2;
    float pib_per_capita2;

    // Cadastro da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o codigo da cidade (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf("%s", nome1);

    printf("Digite a populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a area (em km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &turismo1);

    // Cálculos da Carta 1
    densidade1 = populacao1 / area1;
    pib_per_capita1 = pib1 / populacao1;

    // Cadastro da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o codigo da cidade (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf("%s", nome2);

    printf("Digite a populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a area (em km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &turismo2);

    // Cálculos da Carta 2
    densidade2 = populacao2 / area2;
    pib_per_capita2 = pib2 / populacao2;

    // Exibição da Carta 1
    printf("\n=== Dados da Carta 1 ===\n");
    printf("Codigo: %s\n", codigo1);
    printf("Nome: %s\n", nome1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", turismo1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f bilhoes/habitante\n", pib_per_capita1);

    // Exibição da Carta 2
    printf("\n=== Dados da Carta 2 ===\n");
    printf("Codigo: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", turismo2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f bilhoes/habitante\n", pib_per_capita2);

    return 0;
}