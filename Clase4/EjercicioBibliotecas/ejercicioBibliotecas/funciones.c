#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInt (char pedido[],char error[])
{
    int r=-1;
    int numero;
    do
    {
        printf("%s",pedido);
        scanf("%d",&numero);
        if(numero>=1 && numero<=100)
        {
            r=0;
        }
        else if(numero==-1)
        {
            r=0;
        }
        else
        {
            printf("%s",error);
        }
    }while(r==-1);

    return numero;

}

char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

char getChar(char pregunta[])
{
    char respuesta;
    printf("%s",pregunta);
    scanf("%s",&respuesta);
    return respuesta;
}

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
