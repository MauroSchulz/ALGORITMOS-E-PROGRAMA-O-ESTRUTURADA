#include <stdio.h>


int validaQuantidade() {
    int quantidade;
    do {
        printf("Digite a quantidade de peças fabricadas (um número válido): ");
        scanf("%d", &quantidade);
    } while (quantidade < 0);
}


float calculaSalario(int quantidade) {
    const float salarioBase = 600.0;
    const int limite1 = 50;
    const int limite2 = 80;
    const float adicional1 = 0.5;
    const float adicional2 = 0.75;

    if (quantidade <= limite1) {
        return salarioBase;
    } else if (quantidade <= limite2) {
        return salarioBase + (quantidade - limite1) * adicional1;
    } else {
        return salarioBase + (limite2 - limite1) * adicional1 + (quantidade - limite2) * adicional2;
    }
}


void mostraFinal() {
    printf("Bem-vindo à fábrica de peças!\n");

    char resposta;
    do {
        int quantidade = validaQuantidade();
        float salario = calculaSalario(quantidade);
        printf("O salário do operário é: R$ %.2f\n", salario);

        printf("Deseja calcular o salário de outro operário? (S/N): ");
        scanf(" %c", &resposta); 

    } while (resposta == 'S' || resposta == 's');
}

int main() {
    mostraFinal();
    return 0;
}