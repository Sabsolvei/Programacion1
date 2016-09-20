#include "Funciones.h"

int hardcodeo (ePelicula pelicula[],eDirector director[])
{
    int IdPeli[5]={1,2,3,4,5};
    char titulo[5][20]={"xmen","naranjamec","juegoshabme","terminator","yorobot"};
    int IdDir[5]={1,2,3,4,5};
    int idNac[5]={7,8,5,4,6};
    int idEstado[5]={0,1,2,2,1};
    char nombre[5][50]={"juan","pepe","pedro","juana","luis"};

    for(i=0;i<C;i++)
    {
       pelicula[i].idPelicula=IdPeli[i];
       strcpy(pelicula[i].titulo,titulo[i]);
       pelicula[i].idDirector=IdDir[i];
       pelicula[i].idNacionalidad=idNac[i];
       pelicula[i].idEstado=idEstado[i];
       director[i].idDirector=IdDir[i];
       director[i].nombre=nombre[i];
       director[i].idNacionalidad=idNac[i];
       director[i].idEstado=idEstado[i];
    }
}

int listar (ePelicula pelicula[],int C;int id)
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

for(i=0;i<C;i++)
{
    int cantx;
    cantx=listar (pelicula,C,director[i].idDirector)
    aux[i].idDir=director[i].idDirector;
    aux[i].cantidad=cantx;

}

ePeliculaDirector aux[1000];



