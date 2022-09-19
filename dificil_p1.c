#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    char caracter;
    struct elemento *proximo;
} Elemento;

typedef struct pilha{
    Elemento *topo;
} Pilha;

Pilha *comecaPilha(){
    Pilha *p;
    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void colocaDado(char caracter, Pilha *p) {

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->caracter = caracter;

    novo->proximo = p->topo;

    p->topo = novo;

    
}

int retiraDado(Pilha *p) {
    
    if(p->topo != NULL){

        Elemento *aux = p->topo;

        p->topo = p->topo->proximo;

        free(aux);
        aux = NULL;
    }
    return 0;
}

int main(void){

    int i, j;
    int n;
    Pilha *p = comecaPilha();
    int diamante = 0;
    
    char **matriz;

    scanf("%i", &n);

    matriz = (char**) malloc(n * sizeof (char*));
    
    for (int i = 0; i <n; ++i){
        matriz[i] = (char*) malloc ( 1000 * sizeof (char));
    }


    for (i=0; i<n;i++){
        setbuf(stdin, NULL);
        fgets(matriz[i], 1000, stdin);
        for (j=0;j<1000;j++){

            if(matriz[i][j]=='<'){

                colocaDado(matriz[i][j], p);
            }
            else if(p->topo!=NULL && matriz[i][j]=='>'){

                retiraDado(p);
                diamante++;
            }
        }
        printf("%i\n", diamante);
        diamante = 0;
    }

    return 0;
}