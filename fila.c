#include <stdlib.h>

// Tipo dos elementos guardados na fila.
typedef short processo;

typedef struct Fila
{
    processo *array;
    int primeiro, ultimo;
    unsigned tamanho, maxTamanho;
} Fila;

// Cria uma fila de tamanho maxTamanho
Fila *criar_fila(unsigned maxTamanho);

// Verifica se a fila esta cheia
int fila_cheia(Fila *fila);

// Verifica se a fila esta vazia
int fila_vazia(Fila *fila);

// Retorna o primeiro elemento da fila.
processo fila_get(Fila *fila);

// Coloca um elemento no final da fila.
void fila_add(Fila *fila, processo item);

// Tira o elemento do início da fila e o retorna.
processo fila_pop(Fila *fila);

// Executa uma função para cada valor na fila.
void fila_foreach(Fila *fila, void (*fun)(processo));

Fila *criar_fila(unsigned maxTamanho)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));

    fila->primeiro = fila->tamanho = 0;
    fila->ultimo = maxTamanho - 1; // inicializando assim, se tornará 0 na primeira chamada de "add".
    fila->maxTamanho = maxTamanho;

    fila->array = (processo *)malloc(maxTamanho * sizeof(processo));
    return fila;
}

int fila_cheia(Fila *fila)
{
    return (fila->tamanho == fila->maxTamanho);
}

int fila_vazia(Fila *fila)
{
    return !(fila->tamanho);
}

processo fila_get(Fila *fila)
{
    return fila->array[fila->primeiro];
}

void fila_add(Fila *fila, processo item)
{
    if (!fila_cheia(fila))
    {
        fila->ultimo = (fila->ultimo + 1) % fila->maxTamanho;
        fila->array[fila->ultimo] = item;
        fila->tamanho++;
    }
}

processo fila_pop(Fila *fila)
{
    processo item = fila_get(fila);
    fila->primeiro = (fila->primeiro + 1) % fila->maxTamanho;
    fila->tamanho--;
    return item;
}

void fila_foreach(Fila *fila, void (*fun)(processo))
{
    if (fila->tamanho > 0)
    {
        if (fila->primeiro > fila->ultimo)
        {
            for (int i = fila->primeiro; i < fila->maxTamanho; i++)
                (*fun)(fila->array[i]);

            for (int i = 0; i <= fila->ultimo; i++)
                (*fun)(fila->array[i]);
        }
        else
        {
            for (int i = fila->primeiro; i <= fila->ultimo; i++)
                (*fun)(fila->array[i]);
        }
    }
}