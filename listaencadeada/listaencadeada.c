#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *nome;
    int id;
}ALUNO;

typedef struct no{
    ALUNO aluno;
    struct no *proximo;
}NO;

typedef struct{
    NO *inicio;
    int tam;
}LISTA;

void inicializarLista(LISTA *lista){
    lista->inicio = NULL;
    lista->tam=0;
}

void inserirNoInicio(LISTA *lista, char *valor, int id){
    NO *novo = (NO*) malloc(sizeof(NO)); 

    if(lista->inicio == NULL){
        novo->aluno.nome = valor;
        novo->aluno.id = id;
        novo->proximo == NULL;
        lista->inicio = novo;
    }else{
        novo->aluno.nome = valor;
        novo->aluno.id = id;
        novo->proximo = lista->inicio;
        lista->inicio = novo;

    }
    lista->tam++;

}

void removerItemLista(LISTA *lista, int id){
    NO *aux = lista->inicio;
    NO *auxAnt;
    int tamanhoLista = 1;

    while(tamanhoLista != 0){
        if(lista->inicio->aluno.id == id){
            lista->inicio = aux->proximo;
            tamanhoLista = 0;
            lista->tam--;
        }else{
            auxAnt = aux;
            aux = aux->proximo;
            if(aux->aluno.id == id){
                auxAnt->proximo = aux->proximo;
                tamanhoLista = 0;
                lista->tam--;
            }
        }
    }

}

void imprimirLista(LISTA *lista){
    NO *aux;
    int i;
    aux = lista->inicio;
    
    for(i=0; i<lista->tam; i++){
        printf("%s ", aux->aluno.nome);
        printf("%i, ", aux->aluno.id);
        aux = aux->proximo;
    }
}

int main(){
    LISTA lista;

    inicializarLista(&lista);
    inserirNoInicio(&lista, "gabriel", 1);
    inserirNoInicio(&lista, "lira", 2);
    inserirNoInicio(&lista, "jose", 3);
    removerItemLista(&lista, 3);
    imprimirLista(&lista);

    return 0;
}