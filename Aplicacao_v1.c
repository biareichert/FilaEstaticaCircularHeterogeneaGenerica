#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aplicacao.h"

int main (void) {
    /*Inicializando/criando a fila e as demais variáveis*/
    int tamMax = 3;
    fila *f = criar(tamMax);
    int retorno, ret;
    
    printf("\n\n####### Enfileirando #######\n");
    

    /*############ Pilha 1 ############*/
    pPilha p;
    int var = 0;

    retorno = criapilha(&p,10,sizeof(int)); /*Pilha com 10 posições*/
            
    if (!retorno) {
        printf ("ERRO ao criar a pilha!\n");
    }else{
        /*Aqui empilhamos valores de 0 a 8*/
        for(int i = 0; i < 9; i++){
            ret = empilha(p, &var);
            var++;
        }
  
        /*Inserir a pilha na fila*/
        ret = inserir(f, &p, sizeof(p));
        if(ret == 0){
            printf("\nPilha 1 inserida com sucesso!\n");
        }else{
            printf("\nErro ao inserir a pilha 1!\n");
        }

    }

    /*############ Pilha 2 ############*/
    pPilha p2;
    var = 8;

    retorno = criapilha(&p2,10,sizeof(int)); /*Pilha 2 com 10 posições*/
            
    if (!retorno) {
        printf ("ERRO ao criar a pilha!\n");
    }else{
        /*Aqui empilhamos valores de 8 a 0*/
        for(int i = 0; i < 9; i++){
            ret = empilha(p2, &var);
            var--;
        }
  
        /*Depois de empilhar vamos inserir a pilha na fila*/
        ret = inserir(f, &p2, sizeof(p2));
        if(ret == 0){
            printf("\nPilha 2 inserida com sucesso!\n");
        }else{
            printf("\nErro ao inserir a pilha 2!\n");
        }

    }

    printf("\n####### Desempilhando 4 elementos da pilha 2 #######\n");
    for(int i = 0; i < 4; i++){
        desempilha(p2, &var); 
        printf("%d ", var);
    }

    /*############ Pilha 1 ############*/
    
    pPilha pilhaRemovida;
    int varRemovido, varTopo;

    printf("\n\n####### Desenfileirando pilha 1 #######\n");
    retorno = retirar(f, &pilhaRemovida); /*remover elemento do início da fila*/
    if(retorno == 0){
        topo(pilhaRemovida, &varTopo);
        printf("\nO elemento do topo da pilha é: %d\n", varTopo);

        printf("\nOs itens removidos foram: ");
        for(int i = 0; i < 9; i++){
            desempilha(pilhaRemovida, &varRemovido); /*desempilhando para poder acessar os valores da pilha*/
            printf("%d ", varRemovido);
        }
        printf("\n");
    }else{
        printf("\nErro ao remover os itens.\n");
    }

    
    /*############ Pilha 2 ############*/
    
    pPilha pilhaRemovida2;
    int varRemovido2;

    printf("\n\n####### Desenfileirando pilha 2 #######\n");
    retorno = retirar(f, &pilhaRemovida2); /*remover elemento do início da fila*/
    if(retorno == 0){
        printf("\nOs itens removidos foram: ");
        for(int i = 0; i < 5; i++){
            desempilha(pilhaRemovida2, &varRemovido2); /*desempilhando para poder acessar os valores da pilha*/
            printf("%d ", varRemovido2);
        }
        printf("\n\n");
    }else{
        printf("\nErro ao remover os itens.\n");
    }

    
    /*Destruir as pilhas*/
    destroipilha(&p);
    destroipilha(&p2);

    /*Destruir a fila*/
    destruir(f); 

    return 0;
}
