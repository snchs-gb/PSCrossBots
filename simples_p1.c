#include <stdio.h>
#include <stdlib.h>

int main (void){

    int vetor[10];
    int i;
    int x, y;
    int soma = 0;

    for (i=0; i<10 ;i++){
        
        scanf("%i", &vetor[i]);
    }

    printf("Digite x: ");
    scanf("%i", &x);
    printf("Digite y: ");
    scanf("%i", &y);

    soma = vetor[x-1]+vetor[y-1];

    printf("Soma = %i", soma);

    return 0;
}