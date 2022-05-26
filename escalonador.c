#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int tempoExecucao;
    int tempoChegada;
    char *operacoesIO;
    int *instantesIO;

} Processo;

typedef struct
{

    Processo **vetor;
    Processo **inicio;
    Processo **fim;
} Fila;

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
