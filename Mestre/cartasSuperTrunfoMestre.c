// Desafio Super Trunfo - Países
// Nível Mestre: Comparação e Super Poder
// - Duas cartas
// - Calcula Densidade Populacional e PIB per Capita
// - Compara atributo a atributo
// - Super Poder = soma de todos os atributos (com 1/densidade no lugar da densidade)
// Observações de tipo:
//   * População: unsigned long int (inteiro sem sinal)
//   * Para somas/cálculos, fazemos cast para double para evitar truncamentos

#include <stdio.h>

/* ------- Funções de apoio simples (para manter o código claro) ------- */

// retorna 1 se a > b, 0 se a < b, e -1 se empate
int compara_maior(double a, double b) {
    if (a > b) return 1;
    if (a < b) return 0;
    return -1; // empate
}

// para densidade (MENOR vence): 1 se a < b, 0 se a > b, -1 se empate
int compara_menor(double a, double b) {
    if (a < b) return 1;
    if (a > b) return 0;
    return -1; // empate
}

int main(void) {
    /* ----------------- CARTA 1 (tipos pedidos) ----------------- */
    char codigo1[4];
    char nome1[30];
    unsigned long int populacao1;
    float area1;
    float pib1;     // em bilhões
    int turismo1;

    /* ----------------- CARTA 2 ----------------- */
    char codigo2[4];
    char nome2[30];
    unsigned long int populacao2;
    float area2;
    float pib2;     // em bilhões
    int turismo2;

    /* ----------------- Entrada (mesmo padrão dos níveis anteriores) ----------------- */
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Codigo (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da cidade: ");
    scanf("%29s", nome1);

    printf("Populacao (inteiro sem sinal): ");
    scanf("%lu", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Pontos turisticos (inteiro): ");
    scanf("%d", &turismo1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Codigo (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da cidade: ");
    scanf("%29s", nome2);

    printf("Populacao (inteiro sem sinal): ");
    scanf("%lu", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Pontos turisticos (inteiro): ");
    scanf("%d", &turismo2);

    /* ----------------- Cálculos (Aventureiro) ----------------- */
    // Densidade = população / área
    // PIB per Capita = PIB / população  (aqui fica em "bilhoes por habitante")
    // OBS: conversões para double evitam divisão inteira.
    double dens1  = (area1 > 0.0f) ? ((double)populacao1 / (double)area1) : 0.0;
    double dens2  = (area2 > 0.0f) ? ((double)populacao2 / (double)area2) : 0.0;
    double pibpc1 = (populacao1 > 0UL) ? ((double)pib1 / (double)populacao1) : 0.0;
    double pibpc2 = (populacao2 > 0UL) ? ((double)pib2 / (double)populacao2) : 0.0;

    /* ----------------- Super Poder -----------------
       Soma de TODOS os atributos: pop + area + pib + turismo + (1/densidade) + pib_per_capita
       - Usamos 1/densidade (se densidade > 0; se densidade == 0, tratamos como 0 para evitar divisão por zero).
       - Fazemos tudo em double para garantir precisão e evitar truncamentos.
    ---------------------------------------------------------------- */
    double inv_dens1 = (dens1 > 0.0) ? (1.0 / dens1) : 0.0;
    double inv_dens2 = (dens2 > 0.0) ? (1.0 / dens2) : 0.0;

    double super1 =
        (double)populacao1 +
        (double)area1 +
        (double)pib1 +
        (double)turismo1 +
        inv_dens1 +
        pibpc1;

    double super2 =
        (double)populacao2 +
        (double)area2 +
        (double)pib2 +
        (double)turismo2 +
        inv_dens2 +
        pibpc2;

    /* ----------------- Exibição dos dados ----------------- */
    printf("\n=== Dados da Carta 1 ===\n");
    printf("Codigo: %s\n", codigo1);
    printf("Nome: %s\n", nome1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", turismo1);
    printf("Densidade Populacional: %.4f hab/km2\n", dens1);
    printf("PIB per Capita: %.10f (bilhoes por habitante)\n", pibpc1);
    printf("Super Poder (soma com 1/densidade): %.6f\n", super1);

    printf("\n=== Dados da Carta 2 ===\n");
    printf("Codigo: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", turismo2);
    printf("Densidade Populacional: %.4f hab/km2\n", dens2);
    printf("PIB per Capita: %.10f (bilhoes por habitante)\n", pibpc2);
    printf("Super Poder (soma com 1/densidade): %.6f\n", super2);

    /* ----------------- Comparações (1 = Carta 1 vence, 0 = Carta 2 vence) -----------------
       Em caso de empate, mostramos "Empate" para clareza.
    --------------------------------------------------------------------- */
    int r;

    printf("\n=== Resultados da Comparacao (Carta1 = 1 - vence, Carta2 = 0 - vence) ===\n");

    r = compara_maior((double)populacao1, (double)populacao2);
    if (r == -1) printf("Populacao: Empate\n");
    else         printf("Populacao: %d\n", r);

    r = compara_maior((double)area1, (double)area2);
    if (r == -1) printf("Area: Empate\n");
    else         printf("Area: %d\n", r);

    r = compara_maior((double)pib1, (double)pib2);
    if (r == -1) printf("PIB: Empate\n");
    else         printf("PIB: %d\n", r);

    r = compara_maior((double)turismo1, (double)turismo2);
    if (r == -1) printf("Pontos Turisticos: Empate\n");
    else         printf("Pontos Turisticos: %d\n", r);

    r = compara_menor(dens1, dens2); // menor vence para densidade
    if (r == -1) printf("Densidade Populacional (menor vence): Empate\n");
    else         printf("Densidade Populacional (menor vence): %d\n", r);

    r = compara_maior(pibpc1, pibpc2);
    if (r == -1) printf("PIB per Capita: Empate\n");
    else         printf("PIB per Capita: %d\n", r);

    r = compara_maior(super1, super2);
    if (r == -1) printf("SUPER PODER: Empate\n");
    else         printf("SUPER PODER: %d\n", r);

    return 0;
}