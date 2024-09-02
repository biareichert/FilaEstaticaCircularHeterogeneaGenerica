#ifndef APLICACAO_H
#define APLICACAO_H

#include "Fila_publico.h"
#include "pilha_publico.h"

/*Struct para o aluno, esta será enfileirada*/
typedef struct{
    char nome[20];
    char curso[50];
    int idade;
} aluno;

#endif