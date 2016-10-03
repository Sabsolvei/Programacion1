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
    eValidar strLongitud;
    //eMenu opciones;
    ePeliculaCantidad peliculaCantidad[D];
    int pos=0;
    int idPMayor=0;
    int idDMayor=0;
    int idPelicula=0;
    int idDirector=0;
    char seguir='s';
    int opcion=0;
    char mensaje[100];
    char menu[255];

    menu= "1. Agregar una pelicula.\n2. Modificar una pelicula.\n3. Eliminar una pelicula.\n4. Agregar un director.\n5. Eliminar director.\n6. Informar los directores con mas peliculas.\n7. Informar las peliculas con mas directores.\n8. Listar peliculas\n9. Salir.\n");
    mensaje="Ingrese una opcion: "
    strLongitud.minimo=1;
    strLongitud.maximo=9;
    //strcpy(opciones.error,"Ingreso una opcion invalida. Desea continuar? s/n: ");
    //opciones.desde=1;
    //opciones.hasta=9;

    inicializarEstadoPelicula (pelicula,C,VACIO);
    inicializarEstadoDirector (director,D,VACIO);
    inicializarDirector (director);
    inicializarPelicula (pelicula);

    do
    {
        system("pause");
        system("cls");
        if(validarMenu(menu,mensaje,strLongitud))
        {

            switch (opcion)
            {
                case 1://ALTA PELICULA
                    pos=encontrarEspacioLibrePelicula (pelicula,C);

                    if(pos>=0)
                    {
                        idPMayor=altaPelicula(pelicula,director,pos,OCUPADO,idPMayor,C,D);
                    }
                    else
                    {
                        printf("No hay espacio libre.");
                    }
                    break;

                case 2://MODIFICAR PELICULA
                    system("cls");
                    listarPeliculas (pelicula,C);
                    idPelicula=getInt("Ingrese el Id Pelicula que desea modificar: ");

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
        }
        else
        {
            seguir='n';
        }

    }
    while(seguir=='s');

  return 0;
}
