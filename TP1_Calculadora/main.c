/*
Crear una funci�n que permita ingresar un numero al usuario y lo retorne.
Crear una funci�n que reciba el radio de un c�rculo y retorne su �rea.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el �rea de un c�rculo
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
 * \brief Solicita un n�mero y lo retorna
 * \return N�mero ingresado por el usuario
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
 * \brief Recibe el radio y calcula el �rea del c�rculo
 * \param Radio correspondiente al radio del c�rculo
 * \return El �rea del c�rculo
 *
 */

    float CalcularArea(int radio)
    {
        float area;
        area = 3.14 * radio * radio;
        return area;
    }








