/*
Crear una función que permita ingresar un numero al usuario y lo retorne.
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el área de un círculo
cuyo radio es ingresado por el usuario. Documentar las funciones al estilo Doxygen.
*/

#include <stdio.h>
#include <stdlib.h>

int IngresarRadio();
float CalcularArea(int radio);


int main()
{
    int radioAux;
    float area;

    radioAux = IngresarRadio();
    area = CalcularArea(radioAux);
    printf("El area del circulo es: %.2f \n",area);

  return 0;
}

/**
 * \brief Solicita un número y lo retorna
 * \return Número ingresado por el usuario
 *
 */

    int IngresarRadio()
    {
        int numeroRadio;
        printf("Ingrese el radio del circulo: ");
        scanf("%i",&numeroRadio);
        return numeroRadio;
    }

    /**
 * \brief Recibe el radio y calcula el área del círculo
 * \param Radio correspondiente al radio del círculo
 * \return El área del círculo
 *
 */

    float CalcularArea(int radio)
    {
        float area;
        area = 3.14 * radio * radio;
        return area;
    }








