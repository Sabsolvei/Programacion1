#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define C 10
#define D 10

#define VACIO -1
#define OCUPADO 1
#define BAJA 0


int main()
{
    eDirector director[D];
    ePelicula pelicula[C];
    ePeliculaCantidad peliculaCantidad[D];
    inicializarEstadoPelicula (pelicula,C,VACIO);
    inicializarEstadoDirector (director,D,VACIO);
    inicializarDirector (director);
    inicializarPelicula (pelicula);

    char seguir='s';
    int opcion=0;
    eMenu opciones;
    strcpy(opciones.menu,"1. Agregar una pelicula.\n2. Modificar una pelicula.\n3. Eliminar una pelicula.\n4. Agregar un director.\n5. Eliminar director.\n6. Informar los directores con mas peliculas.\n7. Informar las peliculas con mas directores.\n8. Listar peliculas\n9. Salir.\nINGRESE UNA OPCION: ");
    strcpy(opciones.error,"Ingreso una opcion invalida. Desea continuar? s/n: ");
    opciones.desde=1;
    opciones.hasta=9;
    int pos=0;
    int idPMayor=0;
    int idDMayor=0;
    int idPelicula=0;
    int idDirector=0;

    do
    {
        system("pause");
        system("cls");
        opcion=validarMenu(opciones);

        switch (opcion)
        {
            case 1://ALTA PELICULA
                pos=encontrarEspacioLibrePelicula (pelicula,C);

                if(pos>=0)
                {
                    idPMayor=altaPelicula(pelicula,director,pos,OCUPADO,idPMayor,D);
                }
                else
                {
                    printf("No hay espacio libre.");
                }
                break;

            case 2://MODIFICAR PELICULA
                system("cls");
                listarPeliculas (pelicula,C);
                printf("Ingrese el Id Pelicula que desea modificar: ");
                scanf("%d",&idPelicula);

                pos=buscarIdPelicula (pelicula,C,idPelicula);
                if(pos>=0)
                {
                    modificarPelicula (pelicula,pos);
                }
                else
                {
                    printf("El id ingresado no existe.\n");
                }

                break;

            case 3://BAJA PELICULA
                system("cls");
                listarPeliculas (pelicula,C);
                printf("Ingrese el Id Pelicula que desea borrar: ");
                scanf("%d",&idPelicula);

                pos=buscarIdPelicula (pelicula,C,idPelicula);

                if(pos>=0)
                {
                    system("cls");
                    eliminarPelicula (pelicula,BAJA,pos);
                    printf("Pelicula eliminada con exito\n");
                }
                else
                {
                    printf("El id ingresado no corresponde a una pelicula vigente.\n");
                }

                break;

            case 4: //ALTA DIRECTOR
                pos=encontrarEspacioLibreDirector (director,D);

                if(pos>=0)
                {
                    idDMayor=altaDirector(director,pos,OCUPADO,idDMayor,D);
                }
                else
                {
                    printf("No hay espacio libre.");
                }
                break;

            case 5: //BORRAR DIRECTOR
                system("cls");
                listarDirectores (director, D);
                printf("Ingrese el Id de director que desea eliminar: ");
                scanf("%d",&idDirector);

                pos=buscarIdDirector (director, D, idDirector);

                if(pos>=0)
                {
                    system("cls");
                    eliminarDirector (director, BAJA, pos);
                    printf("Director eliminado con exito\n");
                }
                else
                {
                    printf("El id ingresado no corresponde a un director vigente.\n");
                }

                break;

            case 6://DIRECTOR CON MAS PELICULAS
                system("cls");
                BuscarDirConMasPelis(pelicula,director,peliculaCantidad,C,D);
                MostrarDirConMasPelis (peliculaCantidad, D);

                break;

            case 7:
                break;

            case 8:
                system("cls");
                listarPeliculas (pelicula,D);
                break;

            case 9:
                seguir='n';
                break;

        }

    } while(seguir=='s');

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



