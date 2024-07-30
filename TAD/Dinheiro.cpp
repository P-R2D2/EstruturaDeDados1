#include <stdio.h>
#include <math.h>

int main(void)
{
    // Solicita ao usu�rio o valor do troco
    float change;
    do
    {
        change = get_float("Troco devido: ");
    }
    while (change <= 0);

    // Converte o valor para centavos
    int cents = round(change * 100);

    // Lista de moedas dispon�veis em centavos
    int coins[] = {25, 10, 5, 1};

    // Inicializa o contador de moedas
    int coin_count = 0;

    // Calcula o n�mero m�nimo de moedas
    for (int i = 0; i < 4; i++)
    {
        coin_count += cents / coins[i];
        cents %= coins[i];
    }

    // Imprime o resultado
    printf("Menor n�mero de moedas: %d\n", coin_count);

    return 0;
}

