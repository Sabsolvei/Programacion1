#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arraylist.h"
#include "materias.h"
#include "validaciones.h"
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer array ingresado por el usuario
 * \param minimo y maximo del rango
 * \return Devuelve 1 si es numerico y esta dentro del rango, sino 0
 *
 */

int getInt(char mensaje[],char buffer[])
{
    int retorno=0;
    char seguir='s';
    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(buffer);
        if(esNumerico(buffer))
        {
            retorno = 1;
            seguir = 'n';
        }
        else
        {
            printf("Dato ingresado no es numerico. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }
    while(seguir=='s');
    return retorno;
}

/**
 * \brief Verifica si el valor numerico recibido esta dentro del rango permitido
 * \param numero entero a ser analizado
 * \param minimo y maximo del rango
 * \return 1 si esta dentro de los parametros y 0 si no
 */
int verificarRangoInt(int auxiliar, int minimo, int maximo)
{
    int retorno=0;

    if(auxiliar>=minimo && auxiliar<=maximo)
    {
        retorno=1;
    }

    return retorno;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer Array donde se cargará el texto ingresado
 * \param longitud para validar la longitud del array
 * \return 1 si la longitud del dato ingresado es correcta
 */
int getString(char mensaje[],char buffer[], int longitud)
{
    char seguir='s';
    int retorno=0;

    do
    {
        //system("cls");
        printf("%s", mensaje);
        fflush(stdin);
        gets(buffer);

        if(VerificarRangoChar(buffer,longitud))
        {
            retorno=1;
            seguir='n';
        }
        else
        {
            printf("Dato ingresado muy extenso. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

    }
    while(seguir=='s');

    return retorno;
}


int VerificarRangoChar(char buffer[], int longitud)
{
    int retorno=0;
    if(strlen(buffer)<=longitud)
    {
        retorno=1;
    }
    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer Array donde se cargará el texto ingresado
 * \param longitud para validar la longitud del array
 * \return 1 si el texto contiene solo letras y longitud acorde.
 */
int getStringLetras(char mensaje[], char buffer[], int longitud)
{
    int retorno=0;
    int seguir='s';
    do
    {
        if(getString(mensaje,buffer,longitud))
        {
            if(esSoloLetras(buffer))
            {
                retorno=1;
                seguir='n';
            }
            else
            {
                printf("Deben ser solo letras. Desea continuar?s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            seguir='n';
        }
    }
    while(seguir=='s');

    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i = 0;
    char letra;
    int retorno=1;

    while(str[i] != '\0')
    {
        letra=str[i];
        if(isalpha(letra)!=0 || letra==' ')
        {
            //retorno =1;
            i++;
            continue;
        }
        else
        {
            retorno=0;
            break;
        }

    }
    return retorno;
}
