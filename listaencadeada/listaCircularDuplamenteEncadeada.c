#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char *nome;
    int id;
}Aluno;

typedef struct no{
    Aluno aluno;
    struct no *proximo;
    struct no *anterior;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void iniciarLista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserirNaLista(Lista *lista, char *nomeAluno, int idAluno){
    No *novo = (No*) malloc(sizeof(No));

    if(lista->inicio == NULL){
        novo->aluno.nome = nomeAluno;
        novo->aluno.id = idAluno;
        novo->proximo = novo;
        novo->anterior = lista;
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        novo->aluno.nome = nomeAluno;
        novo->aluno.id = idAluno;
        novo->proximo = lista->inicio;
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam = lista->tam+1;
}

void imprimirLista(Lista *lista){
    No *aux;
    int i;
    aux = lista->inicio;

    for(i=0; i<lista->tam; i++){
        printf("%s ", aux->aluno.nome);
        printf("%i ", aux->aluno.id);
        aux = aux->proximo;
    }
}
void removerNaLista(Lista *lista){
    No *aux;
    int i;
    aux = lista->inicio;

    for(i=0; i<lista->tam; i++){
        if(aux->proximo == lista->inicio){
            printf("\nAluno %s removido\n", aux->aluno.nome);
            lista->fim = aux->anterior;
            lista->fim->proximo = lista->inicio;
            lista->tam = lista->tam-1;
            free(aux);
            imprimirLista(lista);
        }
        aux = aux->proximo;
    }
}

void reinicializarLista(Lista *lista){
    iniciarLista(lista);
}

int main (){

    Lista lista;
    
    iniciarLista(&lista);

    inserirNaLista(&lista, "gabriel", 1);
    inserirNaLista(&lista, "lira", 2);
    inserirNaLista(&lista, "santos", 3);
    inserirNaLista(&lista, "jose", 4);
    imprimirLista(&lista);

    removerNaLista(&lista);
    removerNaLista(&lista);

    reinicializarLista(&lista);
    inserirNaLista(&lista, "gabriel", 1);
    imprimirLista(&lista);
    return 0;
}