#include <stdio.h>
#include <stdlib.h>

#define VACIO '0'
#define OCUPADO '1'
#define LIBRE '2'


struct pelicula
{
    int idPelicula;
    char titulo[255];
    int idDirector;
    int idNacionalidad;
    char idEstado;
};

struct Estado
{
    char idEstado;
    char Descripcion[50];
};

struct Director
{
    int idDirector;
    char nombre[50];
    int idNacionalidad;
    char idEstado;
};

struct Nacionalidad
{
    int idNacionalidad;
    char descripcion[50];
    char idEstado;
};



int main()
{

    int i;

    for(i=0;i<2;i++)

    {
    //director
    struct Director dir1[i];
    printf("Ingrese la id del director: ");
    scanf("%d",&dir1[i].idDirector);

    fflush(stdin);
    printf("Ingrese el nombre del director: ");
    gets(dir1[i].nombre);

    printf("Ingrese la id de nacionalidad: ");
    scanf("%d",&dir1[i].idNacionalidad);

    dir1[i].idEstado=OCUPADO;

    printf("%d - %s - %d - %c\n",dir1[i].idDirector,dir1[i].nombre,dir1[i].idNacionalidad,dir1[i].idEstado);

    }
    //pelicula

    struct pelicula peli1[i];

    printf("Ingrese id de pelicula: ");
    scanf("%d",&peli1[i].idPelicula);

    fflush(stdin);
    printf("Ingrese nombre de pelicula: ");
    gets(peli1[i].titulo);

    printf("Ingrese id del director: ");
    scanf("%d",&peli1[0].idDirector);



    printf("Ingrese id de la nacionalidad: ");
    scanf("%d",&peli1[i].idNacionalidad);

    peli1[i].idEstado = OCUPADO;

    //printf("%c",peli1[0].idEstado);*/






  return 0;

}

