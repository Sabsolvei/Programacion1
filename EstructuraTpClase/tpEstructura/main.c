#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define C 5

#define VACIO '0'
#define OCUPADO '1'
#define LIBRE '2'


int main()
{

    int opcion=0;
    eMenu opciones;
    strcpy(opciones.menu,"1. Agregar un director.\n2. Bajar director.\n3. Agregar una pelicula. \n4. Modificar una pelicula. \n5.Borrar una pelicula.\n6. Informar los directores con mas peliculas.\n7. Informar las peliculas con mas directores.\n8. Listar peliculas\n.9. Salir.\nINGRESE UNA OPCION: ");
    strcpy(opciones.error,"Ingreso una opcion invalida. Desea continuar? s/n: ");
    opciones.desde=1;
    opciones.hasta=9;
    eDirector director[C];
    ePelicula pelicula[C];
    hardcodeo(pelicula,director,C);
    opcion=validarMenu(opciones);

    switch (opcion)
    {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:

            BuscarDirector(pelicula,director,C);

            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            break;

    }





  return 0;

}


/*

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

    //printf("%c",peli1[0].idEstado);

    */



