#include <stdio.h>
#include <stdlib.h>

int main (void){

    int vetor[10];
    int i;
    int x, y;
    int soma = 0;

    for (i=0; i<10 ;i++){ //le vetor de 10 posições
        
        scanf("%i", &vetor[i]);
    }

    printf("Digite x: ");
    scanf("%i", &x); //le a primeira posição
    printf("Digite y: ");
    scanf("%i", &y); //le a segunda posição

    soma = vetor[x-1]+vetor[y-1]; //soma é a soma da posição x + y (respeitando indices)

    printf("Soma = %i", soma);

    return 0;
}
