#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void cargarMascotas (eMascota m[])
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("Ingrese identificador: ");
        scanf("%d",&m[i].identificador);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(m[i].nombre);

        printf("Ingrese edad: ");
        scanf("%d",&m[i].edad);

        printf("Ingrese tipo: ");
        scanf("%d",&m[i].tipo);
        m[i].comio=0;
        m[i].estaVivo=1;
    }
}

void mostrarMascota (eMascota c)
{
    printf("%d\t %s\t %d\t",c.identificador,c.nombre,c.edad);
}
void mostrarMascotas (eMascota cS[])
{
    int i;
    for(i=0;i<3;i++)
    {
        mostrarMascota(cS[i]);
        switch (cS[i].tipo)
        {
            case 1:
                printf("Perro\t");
            break;
            case 2:
                printf("Gato\t");
            break;
            case 3:
                printf("Reptil\t");
            break;
            case 4:
                printf("Pez\t");
            break;
        }
        if(cS[i].comio==0)
        {
            printf("No Comio\t");
        }else
        {
            printf("Comio\t");
        }
        if(cS[i].estaVivo==0)
        {
            printf("Esta muerto\t");
        }
        else
        {
            printf("Esta vivo\t");
        }

    }
}


void alimentar(mascotas,cantidad,nombre,tipo)
{
   //si come el gato, mato un pez
    void RIP(mascotas,cantidad,nombre,tipo)
    {

    //muere solo el pez
    }
}


