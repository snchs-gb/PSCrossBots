#include <stdio.h>
#include <stdlib.h>

void verificaPerfeito(int numero){

    int soma = 0;
    int divisores[100];
    int i;

    for(i=1;i<=(numero/2);i++){

        if(numero%i==0){           
            soma+=i;
        }
    }

    if (soma == numero){
        printf("1");
    }
    else{
        printf("0");
    }
}

int main (void){

    verificaPerfeito(6);

    return 0;
}