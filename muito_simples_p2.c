#include <stdio.h>
#include <stdlib.h>

void converte_temperatura(float f){ //recebe a temperatura em fahrenheit

    float c;

    c = (f - 32)/1.8; //tranforma em celsius

    printf("%.2f", c);
}



int main (void){

    converte_temperatura(77.2); //exemplo da chamada da função

    return 0;
}
