#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aplicacao.h"

int main (void) {
    /*Inicializando/criando a fila e as demais variáveis*/
    int tamMax = 100;
    fila *f = criar(tamMax);
    int retorno, ret;
    
    /*########################## Inserção na fila ##########################*/

    /*############ Inteiro ############*/
    int nota = 10;
    retorno = inserir(f, &nota, sizeof(nota));
    if(retorno == 0){
        printf("\nNota inserida com sucesso!\n");
    }else{
        printf("\nErro ao inserir a nota!\n");
    }

    /*############ String ############*/
    char materia[20];
    strcpy(materia, "Estrutura de dados");
    retorno = inserir(f, &materia, sizeof(materia));
    if(retorno == 0){
        printf("\nMatéria inserida com sucesso!\n");
    }else{
        printf("\nErro ao inserir a matéria!\n");
    }

    /*############ Struct ############*/
    aluno a;
    strcpy(a.nome, "Maria Eduarda");
    strcpy(a.curso, "Quimica");
    a.idade = 23;

    retorno = inserir(f, &a, sizeof(a));
    if(retorno == 0){
        printf("\nAluno inserido com sucesso!\n");
    }else{
        printf("\nErro ao inserir o aluno!\n");
    }

    /*############ Pilha ############*/
    pPilha p;
    nota = 10;

    retorno = criapilha(&p,5,sizeof(int));
            
    if (!retorno) {
        printf ("ERRO ao criar a pilha!\n");
    }else{
        /*Aqui inserimos 5 notas, são elas: 10, 9, 8, 7, 6*/
        for(int i = 0; i < 5; i++){
            ret = empilha(p, &nota);
            nota = nota - 1;
        }
  
        /*Depois de empilhar as notas na pilha vamos inserir
        a pilha na fila*/
        ret = inserir(f, &p, sizeof(p));
        if(ret == 0){
            printf("\nNotas inseridas com sucesso!\n");
        }else{
            printf("\nErro ao inserir as notas!\n");
        }

    }

    /*########################## Remoção e ver elemento do início da fila ##########################*/

    int notaRemovida, notaInicio, notaTop;
    char matRemovida[20], matInicio[20];
    aluno alunoRemovido, alunoInicio;
    pPilha pilhaRemovida, pilhaInicio;

    verInicio(f, &notaInicio); /*ver elemento do início da fila*/
    printf("\nO elemento do início é: %d\n", notaInicio);

    retorno = retirar(f, &notaRemovida); /*remover elemento do início da fila*/
    if(retorno == 0){
        printf("\nA nota removida foi: %d\n", notaRemovida);
    }else{
        printf("\nErro ao remover a nota.\n");
    }
    
    verInicio(f, &matInicio); /*ver elemento do início da fila*/
    printf("\nO elemento do início é: %s\n", matInicio);

    retorno = retirar(f, &matRemovida); /*remover elemento do início da fila*/
    if(retorno == 0){
        printf("\nA matéria removida foi: %s\n", matRemovida);
    }else{
        printf("\nErro ao remover a matéria.\n");
    }
    
    verInicio(f, &alunoInicio); /*ver elemento do início da fila*/
    printf("\nO elemento do início é: %s, %d, %s\n", alunoInicio.nome, alunoInicio.idade, alunoInicio.curso);

    retorno = retirar(f, &alunoRemovido); /*remover elemento do início da fila*/
    if(retorno == 0){
        printf("\nO aluno removido foi: %s, %d, %s\n", alunoRemovido.nome, alunoRemovido.idade, alunoRemovido.curso);
    }else{
        printf("\nErro ao remover o aluno.\n");
    }
    

    verInicio(f, &pilhaInicio); /*ver elemento do início da fila*/
    topo(pilhaInicio, &notaTop);
    printf("\nO elemento do início é uma pilha e o item do topo desta pilha é: %d\n", notaTop);
    
    retorno = retirar(f, &pilhaRemovida); /*remover elemento do início da fila*/
    if(retorno == 0){
        printf("\nAs notas removidas foram: ");
        for(int i = 0; i < 5; i++){
            desempilha(pilhaRemovida, &notaRemovida); /*desempilhando para poder acessar os valores da pilha*/
            printf("%d ", notaRemovida);
        }
        printf("\n");
    }else{
        printf("\nErro ao remover as notas.\n");
    }
    
    /*Destruir pilha*/
    destroipilha(&p);
    /*Destruir fila*/
    destruir(f); 

    return 0;
}
