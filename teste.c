#include <stdio.h>
#include <stdlib.h>

typedef struct teste1
{
    int t;
    struct teste1  *next;
} teste;

void t2(teste* elemento){
    teste *temp = (teste *)malloc(sizeof(teste));
    elemento->next =(teste *) temp;
    temp->t = 15;
}
int main(int argc, char const *argv[])
{
    teste* c = (teste *)malloc(sizeof(teste));
    t2(c);
    t2(c->next);
    printf("%d", c->next->t);
    printf("%d", c->next->next->t);
    return 0;
}
