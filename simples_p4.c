#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontra_letra(char letra, const char* string){
    
    int i;
    int contador = 0;

    for(i=0;i<strlen(string);i++){
        if(string[i]==letra){
            contador++;
        }
    }

    printf("%i", contador);
}

int main (void){

    encontra_letra('a',"uma frase generica de questões de programação");

    return 0;
}