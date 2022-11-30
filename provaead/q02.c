#include <stdio.h>
#include <stdlib.h>

typedef int TIPO_IDENTIFICADOR;
 
typedef struct{
    TIPO_IDENTIFICADOR identificador;
    char *nome;
    char *matricula;
    int idade;
    int periodo;
    int curso;
}REGISTRO_ALUNO;


typedef struct{
    int dia;
    int mes;
    int ano;
}DATA;
 

typedef struct{
    DATA *data;
    int qdtAlunos;
    REGISTRO_ALUNO *alunos;
}FILA_DO_DIA;

typedef struct noFila{
    FILA_DO_DIA *valor;
    struct noFila *proximo;
}NOFILA; 

typedef struct{
    NOFILA *inicio;
}FILA;

 
typedef struct{
    int qtdFilas;
    FILA_DO_DIA *filas;
}COLECAO_FILAS;


 
const char *cursos[] = {"informatica", "agroindutria", "agropecuaria", "engenharia de software", "musica"};


void iniciarFilaDoDia(FILA_DO_DIA *fd, FILA *fila, int n){



    fd->data->dia = 0;
    fd->data->mes = 0;
    fd->data->ano = 0;
    fd->qdtAlunos = 1;
    fila->inicio = NULL;

    printf("%i", fd->qdtAlunos);
}

void iniciarColecaoFilas(COLECAO_FILAS *cf){
    cf->qtdFilas = 1;
    //printf("iniciou");
}

void inserirNaFila(FILA_DO_DIA *filaDia, FILA *fila, REGISTRO_ALUNO *aluno, DATA *data){
    NOFILA *novo = (NOFILA*) malloc(sizeof(NOFILA));
    printf("teste");

    printf("%i", aluno->idade);
    if(fila->inicio == NULL){
        filaDia->alunos->curso = 2;
        filaDia->data = data;
        novo->valor = filaDia;
        novo->proximo = NULL;
        fila->inicio = novo;
    }else{

    }


}

void imprimirFila(FILA_DO_DIA *filaDia, FILA *fila){
    NOFILA *aux;
    int i;

    aux = fila->inicio;
    for(i=0; i<filaDia->qdtAlunos; i++){
        printf("%i", aux->valor->alunos->curso);
    }
}



int main(){

    FILA_DO_DIA filaDia;
    COLECAO_FILAS filas;
    REGISTRO_ALUNO aluno;
    DATA *data;
    FILA fila;

    aluno.curso = 0;
    aluno.idade = 19;
    aluno.nome = "gabriel";
    aluno.matricula = "20221ewbj0041";
    aluno.identificador = 1;
    aluno.periodo = 2;
    

    data->dia = 1;
    data->mes = 2;
    data->ano = 2022;

    iniciarFilaDoDia(&filaDia, &fila, 1);
    iniciarColecaoFilas(&filas);
    inserirNaFila(&filaDia, &fila, &aluno, data);
    imprimirFila(&filaDia, &fila);

    return 0;
}