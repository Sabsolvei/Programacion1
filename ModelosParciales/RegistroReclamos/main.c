#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define P 10
#define R 10

#define LIBRE -1
#define ALTA 1
#define BAJA 0




int main()
{
    ePersona abonado[P];
    eLlamada reclamo[R];
    eReclamoCantidad reclamoCantidad[R];

    int pos=0;
    int idDMayor=0;
    int idAbonado;
    int idReclamo;
    char seguir='s';
    int opcion=0;
    char buffer[4000];
    char menu[]= "1. Alta del abonado.\n2. Modificar datos del abonado.\n3. Baja del abonado.\n4. Nuevo reclamo.\n5. Fin reclamo.\n6. Informar abonado con mas reclamos.\n7. Informar el reclamo mas realizado.\n8. Reclamo con mas demora\n9. Salir.\n";
    char mensaje[]="Ingrese una opcion: ";

    InicializarEstadoAbonado (abonado,P,LIBRE);
    InicializarEstadoReclamo (reclamo,R,LIBRE);
    HardcodearAbonado (abonado);
    HardcodearReclamo (reclamo);

    do
    {
        system("pause");
        system("cls");
        printf("%s",menu);
        if(getInt(mensaje,buffer,1,9))
        {
            opcion = atoi(buffer);

            switch (opcion)
            {
            case 1://ALTA PERSONA
                pos=encontrarEspacioLibre (abonado,P);

                if(pos>=0)
                {
                    if(altaPersona(abonado, pos, P, buffer))
                    {
                        printf("Abonado agregado con exito.\n");
                    }
                }
                else
                {
                    printf("No hay espacio libre para agregar abonado.\n");
                }
                break;

            case 2://MODIFICAR PERSONA
                system("cls");
                ListarPersonas (abonado,P);
                if(getInt("Ingrese el Id Persona que desea modificar: ",buffer, 1, 20))
                {
                    idAbonado = atoi(buffer);
                    pos = buscarIdPersonaExistente (abonado,P,idAbonado,ALTA);
                    if(pos >= 0)
                    {
                        if(ModificarPersona (abonado,pos,buffer))
                        {
                            printf("Persona modificada con exito\n");
                        }
                    }
                }

                break;

            case 3://BAJA PERSONA
                system("cls");
                ListarPersonas(abonado,P);
                if(getInt("Ingrese el Id Persona que desea borrar: ", buffer, 1, 20))
                {
                    idAbonado = atoi(buffer);

                    pos = buscarIdPersonaExistente (abonado, P, idAbonado, ALTA);

                    if(pos >= 0)
                    {
                        system("cls");
                        EliminarPersona (abonado, BAJA, pos);
                        printf("Persona eliminada con exito\n");
                    }
                }
                break;

            case 4://ALTA RECLAMO
                pos=encontrarEspacioLibreReclamo (reclamo,R);

                if(pos>=0)
                {
                    if(altaReclamo(reclamo,abonado, pos,R, P, buffer))
                    {
                        printf("Reclamo agregado con exito.\n");
                    }
                }
                else
                {
                    printf("No hay espacio libre para agregar reclamo.\n");
                }
                break;

            case 5: //MODIFICAR RECLAMO
                system("cls");
                ListarReclamos (reclamo,R);
                if(getInt("Ingrese el Id Reclamo que desea modificar: ",buffer, 1, 20))
                {
                    idReclamo = atoi(buffer);
                    pos = buscarIdReclamoExistente (reclamo,R,idReclamo,ALTA);
                    if(pos >= 0)
                    {
                        if(ModificarReclamo (reclamo,pos,buffer))
                        {
                            printf("Reclamo modificada con exito\n");
                        }
                    }
                    else
                    {
                        printf("Id reclamo no existe\n");
                    }
                }
                break;


            case 6://ABONADO CON MAS RECLAMOS
                system("cls");
                BuscarAbonadoConMasReclamos(abonado,reclamo,reclamoCantidad,P,R);
                MostrarAbonadoConMasReclamos (reclamoCantidad, R);

                break;

            case 7:
//                reclamoMasRealizado (reclamo,R);
                break;
            /*
                                                                          case 8:
                                                                              system("cls");
                                                                              listarPeliculas (abonado,D);
                                                                              break;
            */
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

