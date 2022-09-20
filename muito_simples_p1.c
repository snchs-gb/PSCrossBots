#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void distancia(float x1, float y1, float x2, float y2){ //recebe as coordenadas de dois pontos

    float distancia;

    distancia = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)); //distancia entre dois pontos = √((x2-x1)^2+(y2-y1)^2)

    printf("%.5f", distancia);

}

int main (void){

    distancia(1, 2, 5, 6); //exemplo de chamada da função 

    return 0;
}
