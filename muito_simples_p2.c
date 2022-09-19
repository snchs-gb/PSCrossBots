#include <stdio.h>
#include <stdlib.h>

void converte_temperatura(float f){

    float c;

    c = (f - 32)/1.8;

    printf("%.2f", c);
}



int main (void){

    converte_temperatura(77.2);

    return 0;
}