#include <stdlib.h>
#include <stdio.h>

#define MAX_NUMERO_PROCESSOS 6

int processos[MAX_NUMERO_PROCESSOS];
int NumProcessos;
int quantum; // fatia de tempo de uso da cpu

void tempo()
{
    int numero;
    int i;
    for (i = 1; i <= NumProcessos; i++)
    {
        printf("\nDigite o numero de tempo total do processo %d:", i);
        scanf("%d", &numero);
        processos[i] = numero; // cada processo recebe o valor informado
    }
}

void fila()
{
    int contadorFila = NumProcessos;
    int frenteFila = 1;
    while (contadorFila != 0)
    {
        while (processos[frenteFila] <= 0)
        { // Tira processos que nao tem tempo da primeira posicao
            frenteFila++;
            if (frenteFila >= NumProcessos) // Faz a rotacao
                frenteFila = 0;
        }
        printf("\n\nO processo %d ainda tem %d de tempo", frenteFila, processos[frenteFila]);
        printf("\nGastou %d do tempo", quantum);
        processos[frenteFila] = processos[frenteFila] - quantum; // Pagamento de quantum tempo
        if (processos[frenteFila] <= 0)
        {
            printf("\nE sai da fila.\n");
            contadorFila--;
        }
        else
        {
            printf("\nE vai pro final da fila com %d tempo restantes.\n", processos[frenteFila]);
        }
        frenteFila++;                  // Atualiza primeira posicao
        if (frenteFila > NumProcessos) // Faz a rotacao
            frenteFila = 0;
    }
}

int main(void)
{

    printf("\nNumero maximo de quantum por processo: ");
    scanf("%d", &quantum);
    printf("\nNumero de total de processos: ");
    scanf("%d", &NumProcessos);
    tempo();
    fila();
}