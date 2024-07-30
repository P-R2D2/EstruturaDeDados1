#include <stdio.h>

// Fun��o para imprimir espa�os
void print_spaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Fun��o para imprimir hashes
void print_hashes(int count) {
    for (int i = 0; i < count; i++) {
        printf("#");
    }
}

int main() {
    int height;

    // Solicita ao usu�rio a altura da pir�mide
    do {
        printf("Digite a altura da pir�mide (1 a 8): ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    // Imprime a metade esquerda da pir�mide
    for (int i = 1; i <= height; i++) {
        print_spaces(height - i);
        print_hashes(i);
        printf("\n");
    }

    return 0;
}

