#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int nIngresado;
    int nOculto;
    char jugar ='s';
    int flag;

    while(jugar=='s')
    {
        flag=1;
        nOculto= getNumeroAleatorio(1 , 100, 1);
        do
        {
            nIngresado= getInt("Ingrese un numero entre 1 y 100: ", "Numero invalido. Ingrese numero entre 1 y 100: ");

            if(nIngresado==-1)
            {
                flag=0;
                jugar='n';
            }
            else if(nIngresado<nOculto)
            {
                printf("Esta por debajo del numero. \n");
            }
            else if(nIngresado>nOculto)
            {
                printf("Esta por encima del numero. \n");
            }
            else if(nIngresado==nOculto)
            {
                printf("Felicitaciones, ganaste!\n");
                flag=0;
            }

        }
        while(flag==1);
        if(jugar=='s')
        {
            jugar= getChar("¿Desea seguir jugando? Ingrese 's' o 'n': ");
        }
    }

    //printf("%d \n",nIngresado);
    //printf("%d \n",nOculto);
    return 0;
}
/*
Objetivo:
*   A-  Desarrollar una biblioteca "utn.h" que posea funciones para
*       pedirle al usuario el ingreso de datos
*           - getInt()
*           - getFloat()
*           - getChar()
*
*   B-  Diseñar un programa para jugar a adivinar un número entre 0 y 100.
*       El juego tiene que dar pistas de si el número introducido por el
*       jugador está por encima o por debajo. El juego termina cuando se
*       adivina el número o se decide terminar de jugar ingresando un número
*       negativo. Permitir jugar tantas veces como lo desee el jugador y al
*       salir mostrar su mejor puntuación. Utilizar la biblioteca del punto 1.
*
*/
