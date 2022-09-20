//programa feito em pilha, mas também funciona com fila, apenas mudando as estruturas (mais explicações na documentação)
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

void push(Pilha *p, int d) { //insere dado pilha

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->dado = d;

    novo->proximo = p->topo;

    p->topo = novo;
}

int pop(Pilha *p) { //retira dado pilha
    
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
//função para tirar repetido
void tiraRepetido(Pilha *p1){ //recebe a pilha com dados repetidos

    int contador = 0; //para contar quantas vezes repetiu
    int a, b, c; //auxiliares para passar dados de uma pilha para outra
    Pilha *p2 = inicializaPilha(); //pilha para comparar se há repetidos
    Pilha *p3 = inicializaPilha(); //pilha para armazenar dados sem repetidos antes de voltar para a p1

    

    while(p1->topo!=NULL){ //enquanto a pilha repetida não está vazia
        
        Elemento *aux = p1->topo;

        while(aux!=NULL){
            push(p2, aux->dado); //auxiliar copia os dados da p1 para a p2
            aux=aux->proximo;
        }
        while(p2->topo!=NULL){ //enquanto a p2 não está vazia
            if(p1->topo->dado==p2->topo->dado){ //se o dado do topo da p1 for igual o do topo da p2
                contador++; //contador soma 1
                pop(p2); //tira dado da p2
            }
            else{ //senão só tira o dado
                pop(p2); 
            }
        } //agora o topo é o proximo, compara até esvaziar a p2
        
        if(contador==1){ //se no final o contador for 1, ou seja, só aparece o número 1 vez
            a = p1->topo->dado;
            pop(p1); //tira esse dado da p1
            push(p3, a); //coloca esse dado na p3
            
        }
        
        else{ //senão só tira da p1
            pop(p1);
            
        }
        contador=0; //zera contador para comparar o proximo da p1
    } //faz isso até a p1 ser nula

    while(p3->topo!=NULL){ //passa os dados da p3 para a p1 novamente

        b = p3->topo->dado;
        pop(p3);
        push(p1,b);

    }
    imprimePilha(p1); //imprime a p1
    
}

int main (void){

    Pilha *p = inicializaPilha(); //exemplo de como usar a função

    push(p, 1); //coloca dados
    push(p, 3);
    push(p, 0);
    push(p, 3);
    push(p, 4);

    imprimePilha(p); //imprime para comparação
    tiraRepetido(p); //chama função
    return 0;
}
