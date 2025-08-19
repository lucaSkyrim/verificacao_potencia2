#include <stdio.h>
#include <math.h>  // para log()

int main() {
    double n;
    int c;
    
    while (1) {
        printf("\t\t\tEscreva um número para verificarmos se ele é potência de 2 (digite 1 para sair): \n");

        // leitura com validação
        if (scanf("%lf", &n) != 1) {
            printf("Entrada inválida, tente novamente.\n");
            while ((c = getchar()) != '\n' && c != EOF); // limpa buffer
            continue; // volta pro início do loop
        }

        // condição de saída
        if (n == 1) {
            printf("Programa encerrado.\n");
            break;
        }

        if (n <= 0) {
            printf("Somente números positivos são considerados.\n");
            continue;
        }

        // calcula o expoente em base 2
        double expoente = log(n) / log(2);

        // checa se é um número inteiro (dentro de uma margem de erro)
        if (fabs(expoente - round(expoente)) < 1e-9) {
            printf("%.6f é potência de 2\n", n);
            printf("Expoente: %.0f\n", round(expoente));
        } else {
            printf("%.6f não é potência de 2.\n", n);
        }
    }

    return 0;
}

