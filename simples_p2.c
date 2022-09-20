#include <stdio.h>
#include <stdlib.h>

void verificaPerfeito(int numero){ //função recebe um número inteiro

    int soma = 0;
    int i;

    for(i=1;i<=(numero/2);i++){ //i de um até a metade do número(maior divisor fora ele mesmo)

        if(numero%i==0){        //se o resto for 0 soma o i
            soma+=i;
        }
    }

    if (soma == numero){  //se no final a soma for igual o numero retorna 1 senão retorna 0
        printf("1");
    }
    else{
        printf("0");
    }
}

int main (void){

    verificaPerfeito(6); //exemplo de chamada da função

    return 0;
}
