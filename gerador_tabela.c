#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_NUMERO_PROCESSOS = 5;
const int MIN_NUMERO_PROCESSOS = 3;
const int MAX_TEMPO_EXECUCAO = 30;
const int MIN_TEMPO_EXECUCAO = 1;
const int MAX_OPERACOES_IO = 3;
const int MIN_OPERACOES_IO = 0;
const char SIMBOLO_DISCO = 'D';
const char SIMBOLO_FITA = 'F';
const char SIMBOLO_IMPRESSORA = 'I';
const char DISPOSITIVOS_IO[] = {SIMBOLO_DISCO, SIMBOLO_FITA, SIMBOLO_IMPRESSORA};
int setNumeroProcesso()
{
    
    return (rand() % (MAX_NUMERO_PROCESSOS - MIN_NUMERO_PROCESSOS + 1)) + MIN_NUMERO_PROCESSOS;
}
int setTempoExecucao()
{
    
    return (rand() % MAX_TEMPO_EXECUCAO) + MIN_TEMPO_EXECUCAO;
}
int setNumeroIO()
{
    
    return (rand() % MAX_NUMERO_PROCESSOS - MIN_OPERACOES_IO + 1) + MIN_OPERACOES_IO;
}
char *setIntantesIO(int TempoExecucao, int numeroIO)
{
    char *InstantesIO;
    
    InstantesIO = malloc(numeroIO * sizeof(char));
    for (size_t i = 0; i < numeroIO; i++)
    {
        InstantesIO[i] = (char)(((rand() % (TempoExecucao - 1)) + 1) + 48);
    }

    return InstantesIO;
}
char *setIO(int numeroIO)
{
    char *operacoesIO;
    operacoesIO = malloc(numeroIO * sizeof(char));
    ;
    for (size_t i = 0; i < numeroIO; i++)
    {
        operacoesIO[i] = DISPOSITIVOS_IO[rand() % 3];
    }
    return operacoesIO;
}
void printCharArrayOnFile(char *array, FILE *arquivo,int tamanhoVetor)
{
    
    fprintf(arquivo, "[");
    for (size_t i = 0; i < tamanhoVetor; i++)
    {

        if (!(i == tamanhoVetor - 1))
        {
            fprintf(arquivo, "%c,", array[i]);
        }
        else
        {
            fprintf(arquivo, "%c]", array[i]);
        }
    }
}
int main(int argc, char const *argv[])
{
    int numeroProcessos, processoPid, tempoExecucao, numeroIO;
    FILE *tabela;
    srand(time(NULL));
    tabela = fopen("tabela.txt", "w");
    numeroProcessos = setNumeroProcesso();
    for (size_t i = 0; i < numeroProcessos; i++)
    {

        fprintf(tabela, "%d", i + 1);
        fprintf(tabela, " %d ", tempoExecucao = setTempoExecucao());
        printCharArrayOnFile(setIO(numeroIO = setNumeroIO()), tabela,numeroIO);
        fprintf(tabela, " ");
        printCharArrayOnFile(setIntantesIO(tempoExecucao, numeroIO), tabela,numeroIO);
        fprintf(tabela, "\n");
    }
    fclose(tabela);

    return 0;
}
