#include <stdio.h>

// Função para imprimir espaços
void print_spaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Função para imprimir hashes
void print_hashes(int count) {
    for (int i = 0; i < count; i++) {
        printf("#");
    }
}

int main() {
    int height;

    // Solicita ao usuário a altura da pirâmide
    do {
        printf("Digite a altura da pirâmide (1 a 8): ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    // Imprime a metade esquerda da pirâmide
    for (int i = 1; i <= height; i++) {
        print_spaces(height - i);
        print_hashes(i);
        printf("\n");
    }

    return 0;
}

