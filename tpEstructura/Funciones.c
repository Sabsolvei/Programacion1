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

void inicializarEstado (ePelicula pelicula[],eDirector director[],int C,int estado)
{
    int i;
    for(i=0;i<C;i++)
    {
        director[i].idEstado=estado;
        pelicula[i].idEstado=estado;
    }
}

void hardcodeo (ePelicula pelicula[],eDirector director[])
{
    int i=0;
    int idPeli=0;
    char titulo[][20]={"xmen","naranja","terminator","yorobot","juegos"};
    int IdDir[]={1,2,3,4,5};
    char nac[][20]={"argentino" ,"brasileño" ,"uruguayo" ,"boliviano" ,"paraguayo"};
    int idEstado[]={1,1,1,1,1};
    char nombre[][50]={"juan","pepe","pedro","juana","luis"};
    eFecha fecha[]={{10,5,1990},{8,3,1970},{03,9,1985},{15,4,1986},{15,4,1986}};

    for(i=0;i<5;i++)
    {
        idPeli++;
        pelicula[i].idPelicula=idPeli;
        strcpy(pelicula[i].titulo,titulo[i]);
        pelicula[i].idDirector=IdDir[i];
        strcpy(pelicula[i].nacionalidad,nac[i]);
        pelicula[i].idEstado=idEstado[i];
        director[i].idDirector=IdDir[i];
        strcpy(director[i].nombre,nombre[i]);
        strcpy(director[i].nacionalidad,nac[i]);
        director[i].idEstado=idEstado[i];
        director[i].nacimiento=fecha[i];
    }
}

int listar (ePelicula pelicula[],int C,int id)
{
    int i;
    int contador=0;
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
        printf("Id Director Cantidad\n");
        printf("%d      %d",auxiliar[i].idDirector, auxiliar[i].cantidad);
}

int encontrarEspacioLibre (ePelicula pelicula[],int C)
{
    int i=0;
    int espLibre=-1;
    for(i=0;i<C;i++)
    {
        if(pelicula[i].idEstado==-1)
        {
            espLibre=i;
            break;
        }
    }
    return espLibre;
}

int altaPelicula (ePelicula pelicula[], eDirector director[],int pos,int estado, int idMayor, int D)
{
    int i=0;
    idMayor++;
    printf("Ingrese Titulo: ");
    fflush(stdin);
    gets(pelicula[pos].titulo);
    system("cls");
    for(i=0;i<D;i++)
    {
        if(director[i].idEstado==1)
            printf("%d --> %s\n",director[i].idDirector,director[i].nombre);
    }
    printf("Ingrese Id Director: ");
    fflush(stdin);
    scanf("%d",&pelicula[pos].idDirector);
    system("cls");
    printf("Ingrese nacionalidad: ");
    fflush(stdin);
    gets(pelicula[pos].nacionalidad);
    system("cls");
    pelicula[pos].idEstado=estado;

    return idMayor;
}

/*
void listarPeliculas ()
{
    printf("%d %d %d",fecha[i].dia,fecha[i].mes,fecha[i].anio);
}
*/





