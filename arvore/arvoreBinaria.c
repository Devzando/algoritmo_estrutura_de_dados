#include <stdio.h>
#include <stdlib.h>

typedef int Tipo;

typedef struct{
    Tipo idade;
}Aluno;

typedef struct no{
    Aluno aluno;
    struct no *esquerda;
    struct no *direita;
}No;


typedef struct{
    No *raiz;
}Arvore;


void iniciarArvore(Arvore *arvore){
    arvore->raiz = NULL;
}

void inserirNaDireita(No *node, Arvore *arvore, int valor){
    if(node->direita == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->aluno.idade = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        node->direita = novo;
    }else{
        if(valor < node->direita->aluno.idade){
            inserirNaEsquerda(node->direita, arvore, valor);
        }
        
        if(valor > node->direita->aluno.idade){
            inserirNaDireita(node->direita, arvore, valor);
        }
    }
}

void inserirNaEsquerda(No *node, Arvore *arvore, int valor){
    if(node->esquerda == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->aluno.idade = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        node->esquerda = novo;
    }else{
        if(valor < node->esquerda->aluno.idade){
            inserirNaEsquerda(node->esquerda, arvore, valor);
        }if(valor > node->esquerda->aluno.idade)
            inserirNaDireita(node->esquerda, arvore, valor);
        }
}



void inserirArvore(Arvore *arvore, int valor){

    if(arvore->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->aluno.idade = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        arvore->raiz = novo;
    }else{
        if(valor < arvore->raiz->aluno.idade){
            inserirNaEsquerda(arvore->raiz, arvore, valor);
        }if(valor > arvore->raiz->aluno.idade){
            inserirNaDireita(arvore->raiz, arvore, valor);
        }
    }
}

No* removerArvore(No *raiz, int valor){

    if(raiz == NULL){
        printf("Não tem nenhum elemento na arvore\n");
        return NULL;
    }else{
        if(valor == raiz->aluno.idade){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }else{
                if(raiz->esquerda != NULL && raiz->direita == NULL){
                    No *aux;
                    aux = raiz->esquerda;
                    free(raiz);
                    return aux;
                }else{
                    if(raiz->direita != NULL && raiz->esquerda == NULL){
                        No *aux;
                        aux = raiz->direita;
                        free(raiz);
                        return aux;
                    }else{
                        No *aux;
                        aux = raiz->esquerda;
                        while(aux->direita != NULL){
                            aux = aux->direita;
                        }
                        raiz->aluno.idade = aux->aluno.idade;
                        aux->aluno.idade = valor;
                        raiz->esquerda = removerArvore(aux->esquerda, valor);
                        return raiz;
                    }
                }
            }
        }else{
            if(valor < raiz->aluno.idade){
                raiz->esquerda = removerArvore(raiz->esquerda, valor);
            }else{
                raiz->direita = removerArvore(raiz->direita, valor);
            }
            return raiz;
        }
    }
}

void buscaNaArvore(No *raiz, int valor){
    if(raiz == NULL){
        printf("Valor não encontrado\n");
    }else{
        if(valor == raiz->aluno.idade){
            printf("%i\n", raiz->aluno.idade);
        }else{
            if(valor < raiz->aluno.idade){
                buscaNaArvore(raiz->esquerda, valor);
            }else{
                buscaNaArvore(raiz->direita, valor);
            }
        }
    }
}


void imprimirArvore(No *raiz){
    if(raiz != NULL){
        imprimirArvore(raiz->esquerda);
        printf("%i, ", raiz->aluno.idade);
        imprimirArvore(raiz->direita);
    }
}

// void imprimirDireita(No *raiz){
//     if(raiz != NULL){
//         imprimirDireita(raiz->direita);
//         printf("%i, ", raiz->aluno.idade);
//     }
// }

int main(){

    Arvore arvore;
    iniciarArvore(&arvore);
    inserirArvore(&arvore, 3);
    inserirArvore(&arvore, 4);
    inserirArvore(&arvore, 2);
    inserirArvore(&arvore, 1);
    inserirArvore(&arvore, 45);
    inserirArvore(&arvore, 23);
    inserirArvore(&arvore, 46);
    imprimirArvore(arvore.raiz);
    printf("\n");
    removerArvore(arvore.raiz, 45);
    imprimirArvore(arvore.raiz);
    // buscaNaArvore(arvore.raiz, 1);

    return 0;
}