//código feito usando pilhas, mas da pra fazer com filas também (ver documentação)
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct pilha {
    Elemento *topo;
} Pilha;
//função que inicializa pilha
Pilha *inicializaPilha() {
    Pilha *p;
    p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
    return p;
}
//função para colocar dado na pilha
void colocaDado(int d, Pilha *p) {

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->dado = d;

    novo->proximo = p->topo;

    p->topo = novo;
    
}

//função que retira dado da pilha
int retiraDado(Pilha *p) {
    
    if(p->topo != NULL){

        Elemento *aux = p->topo;

        p->topo = p->topo->proximo;

        free(aux);
        aux = NULL;
    }
    return 0;
}
//função que imprime pilha
void imprimePilha(Pilha *p) {

    Elemento *aux = p->topo;

    while(aux != NULL){
        printf("%i ", aux->dado);
        aux = aux->proximo;
    }
    printf("\n");
}

int encontra_primo(Pilha *p1){ //função recebe uma pilha


    Pilha *p2 = inicializaPilha(); //pilha para armazenar os números primos

    int a, b, i;
    int contador = 0;
    

    while(p1->topo != NULL){ //enquanto a p1 não for nula

        for(i=1; i<=p1->topo->dado; i++){ //i de 1 até dado do topo da pilha

            if(p1->topo->dado%i==0){ //se o resto for 0(ou seja, divisor) contador soma 1
                contador++;
            }
        }
        if(contador==2){ //se o contador no final for igual a 2 (divisivel apenas por 1 e ele mesmo)
            a = p1->topo->dado;
            retiraDado(p1); //coloca dado na p2 e tira da p1
            colocaDado(a, p2);
        }
        else{ //senão só retira o dado da p1
            retiraDado(p1);
        }
        i=2;
        contador=0;
    }

    

    while(p2->topo != NULL){ //enquanto a p2 não é nula

        b = p2->topo->dado;
        retiraDado(p2);
        colocaDado(b, p1); //passa os dados da p2 de volta para a p1
    }
    
    return 0;
}


int main (void){

    Pilha *p = inicializaPilha();
    
    colocaDado(1,p); //coloca os dados
    colocaDado(2,p);
    colocaDado(3,p);
    colocaDado(4,p);
    colocaDado(5,p);
    imprimePilha(p);

    encontra_primo(p); //exemplo de chamada

    imprimePilha(p);

    return 0;
}
