#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void angulo(float x1, float y1, float x2, float y2, float x3, float y3){ // função recebe 3 pontos

    float xvetor1, yvetor1, xvetor2, yvetor2; //componentes dos vetores
    double modBA, modBC; //módulo dos vetores BA e BC
    double multVet; //multiplicação (produto interno) dos vetores
    double x;
    double angulo;
    float pi = 3.1415; //constante para mudar de rad para graus

    //BA = A-B = (x1-x2,y1-y2)
    xvetor1 = x1 - x2;
    yvetor1 = y1 - y2;
    
    modBA = sqrt(pow(xvetor1,2)+pow(yvetor1,2)); //módulo = √(x1^2 + y1^2)


    xvetor2 = x3 - x2;
    yvetor2 = y3 - y2;

    modBC = sqrt(pow(xvetor2,2)+pow(yvetor2,2));
    
    
    multVet = (xvetor1*xvetor2)+(yvetor1*yvetor2); //u*v= (x1*x2)+(y1*y2)


    x = (multVet/(modBA*modBC)); //cos θ = (u*v)/(|u|*|v|)

    angulo = acos(x)*180/pi; //função acos() retorna um valor em π multiplicando por (180/π) tem em graus

    printf("%.1f graus", angulo);

}

int main(void){

    angulo(1,2,3,4,5,6); //exemplo de como chamar função

    return 0;
}
