#ifndef FILA_PUBLICO_H
#define FILA_PUBLICO_H

/*Chamada da struct da fila e do elemento*/
typedef struct fila fila;
typedef struct elemento elemento;

/*Funções da fila, aqui tem-se acesso a manipulação da fila*/
fila *criar(int tamMax); //Função construtora
int inserir(fila *f, void *elem, int tamInfo); //Função manipuladora
int retirar(fila *f, void *elem); //Função manipuladora
int verificarCheia(fila *f); //Função de acesso
int verificarVazia(fila *f); //Função de acesso
int verInicio(fila *f, void *elem); //Função de acesso
void destruir(fila *f); //Função destrutora


#endif
