#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontra_letra(char letra, const char* string){ //recebe uma string e um caracter(diferencia maiúscula de minúscula)
    
    int i;
    int contador = 0;

    for(i=0;i<strlen(string);i++){  //i de 0 até menor que o tamanho da string
        if(string[i]==letra){ //se um elemento da string for igual ao caracter informado, contador soma 1
            contador++;
        }
    }

    printf("%i", contador); //ao final imprime o contador
}

int main (void){

    encontra_letra('a',"uma frase generica de questões de programação"); //exemplo de chamada

    return 0;
}
