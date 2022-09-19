#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct pilha {
    Elemento *topo;
} Pilha;

Pilha *inicializaPilha() {
    Pilha *p;
    p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
    return p;
}

void colocaDado(int d, Pilha *p) {

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->dado = d;

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

void imprimePilha(Pilha *p) {

    Elemento *aux = p->topo;

    
    
    while(aux != NULL){
        printf("%i ", aux->dado);
        aux = aux->proximo;

    }

    printf("\n");


}

int encontra_primo(Pilha *p1){


    Pilha *p2 = inicializaPilha();

    int a, b, i;
    int contador = 0;
    

    while(p1->topo != NULL){

        for(i=1; i<=p1->topo->dado; i++){

            if(p1->topo->dado%i==0){
                contador++;
            }
        }
        if(contador==2){
            a = p1->topo->dado;
            retiraDado(p1);
            colocaDado(a, p2);
        }
        else{
            retiraDado(p1);
        }
        i=2;
        contador=0;
    }

    

    while(p2->topo != NULL){

        b = p2->topo->dado;
        retiraDado(p2);
        colocaDado(b, p1);
    }
    
    return 0;
}


int main (void){

    Pilha *p = inicializaPilha();
    
    colocaDado(1,p);
    colocaDado(2,p);
    colocaDado(3,p);
    colocaDado(4,p);
    colocaDado(5,p);
    imprimePilha(p);

    encontra_primo(p);

    imprimePilha(p);

    return 0;
}