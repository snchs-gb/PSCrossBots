#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    char caracter;
    struct elemento *proximo;
} Elemento;

//criação da estrutura pilha
typedef struct pilha{
    Elemento *topo;
} Pilha;

//função ´para inicializar pilha
Pilha *comecaPilha(){
    Pilha *p;
    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

//função para colocar dado na pilha
void colocaDado(char caracter, Pilha *p) {

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->caracter = caracter;

    novo->proximo = p->topo;

    p->topo = novo;

    
}
//função para retirar dado da pilha
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
    //declaração da matriz para ter n(definido pelo usuário) linhas
    matriz = (char**) malloc(n * sizeof (char*));
    
    for (int i = 0; i <n; ++i){
        matriz[i] = (char*) malloc ( 1000 * sizeof (char));
    }


    for (i=0; i<n;i++){     //vai repetir esse laço n vezes 
        setbuf(stdin, NULL);
        fgets(matriz[i], 1000, stdin); //lê uma linha da matriz
        for (j=0;j<1000;j++){

            if(matriz[i][j]=='<'){ //se um elemento da linha for '<' coloca ele numa pilha

                colocaDado(matriz[i][j], p);
            }
            else if(p->topo!=NULL && matriz[i][j]=='>'){ //se a pilha já tiver um '<' e outro elemento for '>'
                                                        //tira esse '<' da pilha e conta 1 diamante
                retiraDado(p);
                diamante++;
            }
        }
        printf("%i\n", diamante);               //após ler toda a linha mostra a quantidade de diamantes
        diamante = 0;                           //zera diamante para contar da próxima linha 
    }

    return 0;
}
