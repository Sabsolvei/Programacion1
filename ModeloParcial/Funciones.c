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

void inicializarEstadoPelicula (ePelicula pelicula[],int C,int estado)
{
    int i;
    for(i=0;i<C;i++)
    {
        pelicula[i].idEstado=estado;
    }
}

void inicializarEstadoDirector (eDirector director[],int D,int estado)
{
    int i;
    for(i=0;i<D;i++)
    {
        director[i].idEstado=estado;
    }
}

void inicializarDirector (eDirector director[])
{
    int i=0;
    int IdDir[]={1,2,3,4,5};
    char nac[][20]={"argentino" ,"brasileño" ,"uruguayo" ,"boliviano" ,"paraguayo"};
    int idEstado[]={1,1,1,1,1};
    char nombre[][50]={"juan","pepe","pedro","juana","luis"};
    eFecha fecha[]={{10,5,1990},{8,3,1970},{03,9,1985},{15,4,1986},{15,4,1986}};

    for(i=0;i<5;i++)
    {
        director[i].idDirector=IdDir[i];
        strcpy(director[i].nombre,nombre[i]);
        strcpy(director[i].nacionalidad,nac[i]);
        director[i].idEstado=idEstado[i];
        director[i].nacimiento=fecha[i];
    }
}

void inicializarPelicula (ePelicula pelicula[])
{
    int i=0;
    int IdDir[]={1,1,2,2,4};
    int IdPeli[]={1,2,3,4,5};
    char nac[][20]={"argentino" ,"brasileño" ,"uruguayo" ,"boliviano" ,"paraguayo"};
    int idEstado[]={1,1,1,1,1};
    char titulo[][20]={"KungFu","Terminator","LaNaranja","She","Luis"};
    int anio[]={2010,2015,2008,1999,2016};

    for(i=0;i<5;i++)
    {
        pelicula[i].idPelicula=IdPeli[i];
        pelicula[i].idDirector=IdDir[i];
        strcpy(pelicula[i].titulo,titulo[i]);
        strcpy(pelicula[i].nacionalidad,nac[i]);
        pelicula[i].anio=anio[i];
        pelicula[i].idEstado=idEstado[i];
    }
}

int contarPeliculas (ePelicula pelicula[],int C,int id)
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

void BuscarDirConMasPelis (ePelicula pelicula[],eDirector director[],ePeliculaCantidad peliculaCantidad[], int D,int C)
{
    int i=0;
    int j=0;
    int cantidadAux;

    for(i=0;i<D;i++)
    {
        cantidadAux = contarPeliculas(pelicula,C,director[i].idDirector);
        peliculaCantidad[i].idDirector = director[i].idDirector;
        peliculaCantidad[i].cantidad = cantidadAux;
    }
    //return peliculaCantidad;
}

void MostrarDirConMasPelis (ePeliculaCantidad peliculaCantidad[], int D)
{
    int i=0;
    int j=0;
    int k=0;
    ePeliculaCantidad peliculaCantidadAux;

    for(i=0;i<D-1;i++)
    {
        for(j=i+1;j<D;j++)
        {
            if(peliculaCantidad[i].cantidad<peliculaCantidad[j].cantidad)
            {
                peliculaCantidadAux = peliculaCantidad[i];
                peliculaCantidad[i] = peliculaCantidad[j];
                peliculaCantidad[j] = peliculaCantidadAux;
            }
        }
    }
    printf("Id Cantidad\n");
    do
    {
        printf("%d      %d\n",peliculaCantidad[k].idDirector, peliculaCantidad[k].cantidad);
        k++;

    } while(peliculaCantidad[k-1].cantidad==peliculaCantidad[k].cantidad);

}

int encontrarEspacioLibrePelicula (ePelicula pelicula[],int C)
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

int encontrarEspacioLibreDirector (eDirector director[],int D)
{
    int i=0;
    int espLibre=-1;
    for(i=0;i<D;i++)
    {
        if(director[i].idEstado==-1)
        {
            espLibre=i;
            break;
        }
    }
    return espLibre;
}

int altaPelicula (ePelicula pelicula[], eDirector director[],int pos,int estado, int idPMayor, int C)
{
    int i=0;
    idPMayor++;
    printf("Ingrese Titulo: ");
    fflush(stdin);
    gets(pelicula[pos].titulo);
    system("cls");
    for(i=0;i<C;i++)
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

    return idPMayor;
}

void listarPeliculas (ePelicula pelicula[], int C)
{
    int i=0;
    printf("Id  Titulo  Año Nacionalidad    IdDirector\n");
    for(i=0;i<C;i++)
    {
        if(pelicula[i].idEstado==1)
        {
            printf("%d  %s  %d  %s  %d\n",pelicula[i].idPelicula,pelicula[i].titulo, pelicula[i].anio, pelicula[i].nacionalidad, pelicula[i].idDirector);
        }
    }
}

void listarDirectores (eDirector director[], int D)
{
    int i=0;
    printf("Id  Nombre  F Nac   Nacionalidad\n");
    for(i=0;i<D;i++)
    {
        if(director[i].idEstado==1)
        {
            printf("%d  %s  %d-%d-%d  %s\n",director[i].idDirector,director[i].nombre,director[i].nacimiento.dia,director[i].nacimiento.mes,director[i].nacimiento.anio,director[i].nacionalidad);
        }
    }
}

int buscarIdPelicula (ePelicula pelicula[],int C,int idPelicula)
{
    int i=0;
    int pos=-1;
    for(i=0;i<C;i++)
    {
        if(pelicula[i].idEstado==1 && idPelicula==pelicula[i].idPelicula)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

int buscarIdDirector (eDirector director[],int D,int idDirector)
{
    int i=0;
    int pos=-1;
    for(i=0;i<D;i++)
    {
        if(director[i].idEstado==1 && idDirector==director[i].idDirector)
        {
            pos=i;
            break;
        }
    }
    return pos;
}


void modificarPelicula (ePelicula pelicula[],int pos)
{
    int seguir = 's';
    eMenu opciones;
    int opcion;
    strcpy(opciones.menu,"1. Titulo.\n2. Año.\n3. Nacionalidad.\n4. Id director.\n5. Salir.\nIngrese el campo que desea modificar: ");
    strcpy(opciones.error,"Ingreso una opcion invalida. Desea continuar? s/n: ");
    opciones.desde = 1;
    opciones.hasta = 5;

    do
    {
        opcion = validarMenu (opciones);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el nuevo Titulo: ");
            fflush(stdin);
            gets(pelicula[pos].titulo);
            break;
        case 2:
            printf("Ingrese el nuevo Año: ");
            scanf("%d",&pelicula[pos].anio);
            break;
        case 3:
            printf("Ingrese la nueva nacionalidad: ");
            fflush(stdin);
            gets(pelicula[pos].nacionalidad);
            break;
        case 4:
            printf("Ingrese el nuevo Id Director: ");
            scanf("%d",&pelicula[pos].idDirector);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    } while (seguir == 's');
}

void eliminarPelicula (ePelicula pelicula[],int baja, int pos)
{
    pelicula[pos].idEstado=baja;
}

void eliminarDirector (eDirector director[],int baja, int pos)
{
    director[pos].idEstado=baja;
}

int altaDirector (eDirector director[],int pos,int estado, int idDMayor, int D)
{
    int flag=1;
    int resultado;
    char nombreAux[50];
    idDMayor++;
    system("cls");
    do
    {
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(nombreAux);
        resultado=verificarNombre (director, D, nombreAux);
        if(resultado==-1)
        {
            continue;
        }
        else
        {
            strcpy(director[pos].nombre,nombreAux);
            flag=0;
            break;
        };
    }while(flag==1);

    system("cls");
    printf("Ingrese nacionalidad: ");
    fflush(stdin);
    gets(director[pos].nacionalidad);
    system("cls");
    printf("Ingrese fecha de nacimiento\n");
    printf("Ingrese dia: ");
    scanf("%d",&director[pos].nacimiento.dia);
    printf("\n");
    printf("Ingrese mes: ");
    scanf("%d",&director[pos].nacimiento.mes);
    printf("\n");
    printf("Ingrese año: ");
    scanf("%d",&director[pos].nacimiento.anio);
    system("cls");
    director[pos].idEstado=estado;

    return idDMayor;
}

int verificarNombre (eDirector director[], int D, char nombreAux[])
{
    int i=0;
    int retorno=0;
    for(i=0;i<D;i++)
    {
        if(strcmp(director[i].nombre,nombreAux)==0)
        {
            printf("El nombre ya existe.\n");
            retorno=-1;
            break;
        }
    }
    return retorno;
}


//printf("%d-%d-%d",fecha[i].dia,fecha[i].mes,fecha[i].anio);





