#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila_privado.h"

/*Função Construtora: criar e inicializar a fila*/
fila *criar(int tamMax){
    /*Alocação de memória para o descritor da fila*/
    fila *f = (fila*) malloc(sizeof(fila));

    if(f == NULL){
        printf("\nErro ao criar a fila!\n");
    }else{ 
        /*Alocação de memória para a variável **vetor*/
        f->vetor = (elemento**) malloc(sizeof(elemento*) * tamMax);
    
        /*Inicializando a fila como vazia*/
        f->inicio = -1;
        f->fim = -1; 
        f->tamAtual = 0;
        f->tamMax = tamMax;
    }

    
    /*Retorna o descritor da fila*/
    return f;
    
}

/*Função Destrutora: destruir a fila*/
void destruir(fila *f){
    int i;

    /*Se a fila não estiver vazia vamos percorre-la para
    liberar o espaço de memória do vetor*/
    if(verificarVazia(f) != 0){
        /*Se fim < inicio vamos percorrer do fim até o inicio,
        caso contrário vamos percorrer do inicio até o fim*/
        if(f->fim < f->inicio){ 
            for(i = f->fim; i <= f->inicio; i++){
                free(f->vetor[i]);
            }
        }else{
            for(i = f->inicio; i <= f->fim; i++){
                free(f->vetor[i]);
            }
        }
    }

    /*Libera o vetor*/
    free(f->vetor);
    /*Libera o descritor da fila*/
    free(f);
}

/*Função Manipuladora: enfileirar*/
int inserir(fila *f, void *elem, int tamInfo){
    
    /*Verificar se a pilha está cheia*/
    if(verificarCheia(f) == 0){
        printf("\nA fila está cheia, não foi possível enfileirar!\n");
        return 1;

    }else{
        if(verificarVazia(f) == 0){ 
            /*Se a pilha está vazia significa que estamos inserindo o primeiro elemento,
            este irá na posição 0 do vetor*/
            f->inicio = 0;
            f->fim = 0;
        }else{
            if(f->fim == f->tamMax - 1){ 
                /*Se o fim estiver no limite do vetor, o novo elemento será inserido
                na posição 0*/
                f->fim = 0;
            }else{
                /*Caso contrário é só ir incrementando as posições (fim)*/
                f->fim++;
            }
        }

        /*Alocando espaço de memória para o novo elemento*/
        /*Aloca espaço de memória para o descritor*/
        if((f->vetor[f->fim] = (elemento*)malloc(sizeof(elemento))) != NULL){
            /*Aloca espaço de memória para o elemento do tipo void* */
            if((f->vetor[f->fim]->elemento = (void*) malloc(tamInfo)) != NULL){
                /*Setando o valor correto para o tamanho da informação do novo elemento*/
                f->vetor[f->fim]->tamInfo = tamInfo; 
        
                /*Cópia do novo elemento para a sua devida posição na fila*/
                memcpy(f->vetor[f->fim]->elemento, elem, tamInfo);

                /*Incrementando o tamanho atual da fila já que foi adicionado um novo
                elemento*/
                f->tamAtual++;

                return 0;
            }else{
                printf("\nErro na alocação!\n");
                return 1;
            }
        }else{
            printf("\nErro na alocação!\n");
            return 1;
        }

    }

    return 1;
}

/*Função Manipuladora: desenfileirar*/
int retirar(fila *f, void *elem){
    /*Verificar se a fila está vazia*/
    if(verificarVazia(f) == 0){
        printf("\nA fila está vazia, não foi possível desenfileirar!\n");
        return 1;
    }else{
        
        /*Cópia do item removido da fila para a nova variável passada por
        parâmetro*/
        memcpy(elem, f->vetor[f->inicio]->elemento, f->vetor[f->inicio]->tamInfo);

        /*Liberando espaço de memória do elemento void* */
        free(f->vetor[f->inicio]->elemento);

        /*Liberando espaço de memória da posição do vetor em que estava o elememto
        que foi removido*/
        free(f->vetor[f->inicio]);

        /*Decrementando o tamanho atual da fila já que foi retirado um elemento*/
        f->tamAtual--;

        /*Se foi retirado o último elemento, então a fila é novamente
        setada como vazia*/
        if(f->inicio == f->fim){
            f->fim = -1;
            f->inicio = -1;
        }else{
            /*Se o início estiver no limite do vetor, o novo elemento do inicio será o 0*/
            if(f->inicio == f->tamMax - 1){ 
                f->inicio = 0;
            }else{
                /*Caso contrário é só ir incrementando o inicio*/
                f->inicio++;
            }
        }

        return 0;
    }

    return 1; 
}

/*Função de Acesso: realiza a busca no início da fila*/
int verInicio(fila *f, void *elem){
   /*Verifica se a fila está vazia*/
    if(verificarVazia(f) == 0){
        printf("\nA fila está vazia!\n");
        return 1;
    }else{
       
        /*Cópia do elemento do início da fila para a nova variável passada por
        parâmetro*/
        memcpy(elem, f->vetor[f->inicio]->elemento, f->vetor[f->inicio]->tamInfo);

        return 0;

    }  

    return 1;
}


/*Função para verificar se a fila está cheia*/
int verificarCheia(fila *f){
    /*A primeira condição é a padrão, onde o início é 0 e o fim é o limite do vetor.
    A segunda condição é se o fim estiver atrás do inicio, quer dizer que o vetor
    está cheio.*/
    if((f->inicio == 0 && f->fim == f->tamMax - 1) || (f->fim == f->inicio - 1)){
        /*A fila está cheia!*/
        return 0;
    }

    /*A fila não está cheia!*/
    return 1;
}

/*Função para verificar se a fila está vazia*/
int verificarVazia(fila *f){
    if(f->inicio == -1 && f->fim == -1){
        /*A fila está vazia!*/
        return 0;
    }

    /*A fila não está vazia!*/
    return 1;
}


