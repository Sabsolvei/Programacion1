#include <stdio.h>
#include "Funciones.h"

int validarMenu (eMenu opciones)
{
    int opcion;
    char respuesta='s';

    do
    {
        printf(opciones.menu);
        fflush(stdin);
        scanf("%d",&opcion);

        if(opcion>=opciones.desde && opcion<=opciones.hasta)
        {
            break;
        }
        else
        {
            system("cls");
            printf("%s",opciones.error);
            fflush(stdin);
            scanf("%c",&respuesta);
            opcion=-1;
        }
    }
    while(respuesta=='s');

    return opcion;
}


int hardcodeo (ePelicula pelicula[],eDirector director[],int C)
{
    int IdPeli[5]={1,2,3,4,5};
    char titulo[5][20]={"xmen","naranjamec","juegoshabme","terminator","yorobot"};
    int IdDir[5]={1,2,3,4,5};
    int idNac[5]={7,8,5,4,6};
    int idEstado[5]={0,1,2,2,1};
    char nombre[5][50]={"juan","pepe","pedro","juana","luis"};
    int i;

    for(i=0;i<C;i++)
    {
       pelicula[i].idPelicula=IdPeli[i];
       strcpy(pelicula[i].titulo,titulo[i]);
       pelicula[i].idDirector=IdDir[i];
       pelicula[i].idNacionalidad=idNac[i];
       pelicula[i].idEstado=idEstado[i];
       director[i].idDirector=IdDir[i];
       strcpy(director[i].nombre,nombre[i]);
       director[i].idNacionalidad=idNac[i];
       director[i].idEstado=idEstado[i];
    }
}

int listar (ePelicula pelicula[],int C,int id)
{
    int i;
    int contador;
    for(i=0;i<C;i++)
    {
        if(pelicula[i].idDirector==id)
        {
            contador++;
        }
    }
    return contador;
}

void BuscarDirector (ePelicula pelicula[],eDirector director[],int C)
{
    int i=0;
    ePeliculaDirector auxiliar[C];
    int cantidadAux;

    for(i=0;i<C;i++)
    {
        cantidadAux=listar (pelicula,C,director[i].idDirector);
        auxiliar[i].idDirector=director[i].idDirector;
        auxiliar[i].cantidad=cantidadAux;

    }

}

ePeliculaDirector aux[1000];


/*

*/



