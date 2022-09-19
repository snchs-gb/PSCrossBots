//Escreva uma função que receba uma lista de números e que
//retorne a lista sem números repetidos.

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

void push(Pilha *p, int d) { //insere pilha

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->dado = d;

    novo->proximo = p->topo;

    p->topo = novo;
}

int pop(Pilha *p) { //retira pilha
    
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

void tiraRepetido(Pilha *p1){

    int contador = 0;
    int a, b, c;
    Pilha *p2 = inicializaPilha();
    Pilha *p3 = inicializaPilha();

    

    while(p1->topo!=NULL){
        
        Elemento *aux = p1->topo;

        while(aux!=NULL){
            push(p2, aux->dado);
            aux=aux->proximo;
        }
        while(p2->topo!=NULL){
            if(p1->topo->dado==p2->topo->dado){
                contador++;
                pop(p2);
            }
            else{
                pop(p2);
            }
        }
        
        if(contador==1){
            a = p1->topo->dado;
            pop(p1);
            push(p3, a);
            
        }
        
        else{
            pop(p1);
            
        }
        contador=0;
    }

    while(p3->topo!=NULL){

        b = p3->topo->dado;
        pop(p3);
        push(p1,b);

    }
    imprimePilha(p1);
    
}

int main (void){

    Pilha *p = inicializaPilha();

    push(p, 1);
    push(p, 3);
    push(p, 0);
    push(p, 3);
    push(p, 4);

    imprimePilha(p);
    tiraRepetido(p);
    return 0;
}