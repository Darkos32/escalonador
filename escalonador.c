#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct p
{
    int pid;
    int tempoExecucao;
    char* operacoesIO;
    int* instantesIO;
    int tempoChegada;
    int numeroIO;
} processo;

int* parseInstantesIO(char* instantesString,int numeroIO){
    int i = 0,j=0,*instantesInt;
    if (numeroIO ==0)
    {
        return NULL;
    }
    instantesInt = (int*) malloc(numeroIO*sizeof(int));
    while (instantesString[i]!='\0')
    {
        if (instantesString == '['||instantesString == ']'||instantesString == ',')
        {
            i++;
            continue;
        }
        instantesInt[j] = atoi(instantesString[i]);
        j++;
        i++;

        
    }
    
}

//Inicializa os atributos de um processo
processo* setProcesso(char* linhaTabela){
    processo * p;
    char*token;
    int i = 0;
    p = (processo *) malloc(sizeof(processo));   
    token = strtok(linhaTabela," ");
    while (token!=NULL)
    {
        switch (i)
        {
        case 0:
            p->pid = atoi(token);
            break;
        case 1:
            p->tempoExecucao = atoi(token);
            break;
        case 2:
            p->numeroIO = atoi(token);
            break;
        case 3:
            p->operacoesIO = token;
            break;
        case 4:
            
        default:
            break;
        }
    }
        
}

//Pega os processos descritos na tabela e os coloca num tipo de área de espera 
int parseTabela(){
    FILE *tabela = fopen("tabela.txt","r");
    char * linha = NULL;
    int i = 0;
    size_t tam_linha = 0;
    int numero_processos;
    processo * espera; 
    if (tabela  == NULL)
    {
        printf("Tabela não encontrada \n");
        return -1;
    }
    
    while (getline(&linha,&tam_linha,tabela)!=-1)
    {
        if(i==1){
            numero_processos = atoi(linha);
            espera = (processo *)malloc(numero_processos*sizeof(processo));//cria a área de espera
            i++;
        }


    }
    fclose(tabela);
    return  0;
    
}
int main(int argc, char const *argv[])
{   
    
    parseTabela();    
    return 0;
}
