#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void angulo(float x1, float y1, float x2, float y2, float x3, float y3){

    float xvetor1, yvetor1, xvetor2, yvetor2;
    double modBA, modBC;
    double multVet;
    double x;
    double angulo;
    float pi = 3.1415;

  
    xvetor1 = x1 - x2;
    yvetor1 = y1 - y2;

    modBA = sqrt(pow(xvetor1,2)+pow(yvetor1,2));


    xvetor2 = x3 - x2;
    yvetor2 = y3 - y2;

    modBC = sqrt(pow(xvetor2,2)+pow(yvetor2,2));
    

    multVet = (xvetor1*xvetor2)+(yvetor1*yvetor2);


    x = (multVet/(modBA*modBC));

    angulo = acos(x)*180/pi;

    printf("%.1f graus", angulo);

}

int main(void){

    angulo(1,2,3,4,5,6);

    return 0;
}