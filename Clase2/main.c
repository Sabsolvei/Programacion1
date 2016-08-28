/*
Realizar un programa que pida 5 numeros (por for) entre -100 y 100 (validar con while) y muestre:
Sumatoria, promedio, cantidad de positivos, negativos y ceros, numero maximo, minimo y sus posiciones.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numero=0;
    int acumulador =0;
    int maximo;
    int minimo;
    int posMax;
    int posMin;
    int negativos=0;
    int positivos=0;
    int ceros=0;
    int flag=0;
    float promedio;


    for(i=0;i<5;i++)
    {
        printf("Ingrese un número: ");
        scanf("%i", &numero);

        while(numero<-100 || numero>100)
        {
            printf("Error. Ingrese un número entre -100 y 100 inclusive: \a");
            scanf("%i", &numero);
        }

        acumulador=acumulador+numero;

        if(numero>maximo || flag==0)
        {
                maximo = numero;
                posMax = i+1;
                flag=1;
        }
        if (numero<minimo || flag==0)
        {
            minimo = numero;
            posMin = i+1;
            flag=1;
        }
        if(numero<0)
        {
            negativos++;
        }
        else if(numero>0)
        {
            positivos++;
        }
        else
        {
           ceros++;
        }

    }
    promedio=acumulador/i;
    printf("El numero maximo es: %i, en la posicion %i \n", maximo, posMax);
    printf("El numero minimo es: %i, en la posicion %i \n", minimo, posMin);
    printf("La cantidad de numeros positivos es: %i \n",positivos);
    printf("La candidad de numeros negativos es: %i \n",negativos);
    printf("La candidad de numeros ceros es: %i \n",ceros);
    printf("La suma de los numeros es %i, y su promedio es: %f \n",acumulador, promedio);

    return 0;
}
