
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct p
{
    int pid;
    int tempoExecucao;
    char* operacoesIO;
    int* instantesIO;
    int tempoChegada;
    int numeroIO;
} processo;
void stringOverflow(char* vetor){
    int tam = strlen(vetor);
}
int* parseInstantesIO(char* instantesString,int numeroIO){
    int i = 0,j=0,l=0,*instantesInt;
    char *numero;
    numero = (char *)malloc(3*sizeof(char));//a string esta preparada a priori pra receber no maximo 3 digitos
    if (numeroIO ==0)
    {
        return NULL;
    }
    instantesInt = (int*) malloc(numeroIO*sizeof(int));
    while (instantesString[i]!='\0')
    {
        
        if (instantesString[i] == '['||instantesString[i] == ']'||instantesString[i] == ',')
        {
            i++;
            continue;
        }else{
            numero[j] = instantesString[i];
            j++;

            while (instantesString[i + 1] != '\0' && isdigit(instantesString[i + 1]))
            {
                
                numero[j] = instantesString[i + 1];
                j++;
                i++;
            }
            
        }
        instantesInt[l] = atoi(numero);
        l++;
        i++;
    }
    return instantesInt;
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
            p->instantesIO = parseInstantesIO(linhaTabela,p->numeroIO);
            break;
        case 5:
            p->tempoChegada = atoi(token);
            break;
        default:
            printf("ERRO PARSE INSTANTES");
            break;
        }
        token = strtok(NULL, " ");
        i++;
    }
    return p;
}

//Pega os processos descritos na tabela e os coloca num tipo de área de espera 
processo** parseTabela(){
    FILE *tabela = fopen("tabela.txt","r");
    char * linha = NULL;
    short int flag = 1;// marca se a primeira linha da tabela ainda não foi lida
    int i = 0;
    size_t tam_linha = 0;
    int numero_processos;
    processo **espera; 
    if (tabela  == NULL)
    {
        printf("Tabela não encontrada \n");
        return NULL;
    }
    
    while (getline(&linha,&tam_linha,tabela)!=-1)
    {
        if(flag){
            numero_processos = atoi(linha);
            espera = (processo **)malloc(numero_processos*sizeof(processo*));//cria a área de espera
            flag = 0;
            continue;
        }
        espera[i] = setProcesso(linha);
        i++;
    }
    
    fclose(tabela);
    return  espera;
    
}
int main(int argc, char const *argv[])
{   
    
    processo** p;
    p = parseTabela();
    printf("%d", p[0]->pid);

    return 0;
}
