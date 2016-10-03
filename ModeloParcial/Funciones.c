#include <stdio.h>
#include "Funciones.h"

int validarMenu (char menu[], char mensaje[],eValidar strLongitud)
{
    int opcion;
    char respuesta='s';
    int retorno;

        if(getInt(mensaje,strLongitud.buffer,strLongitud.minimo,strLongitud.maximo))
        {
            opcion=atoi(strLongitud.buffer);
        }
        else
        {
            opcion=-1;
        }

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

int altaPelicula (ePelicula pelicula[], eDirector director[],int pos,int estado, int idPMayor, int C, int D, eValidar strLongitud)
{
    int i=0;
    idPMayor++;
    strLongitud.longitud=255;
    if(getString("Ingrese el titulo: ",strLongitud.buffer, strLongitud.longitud))
    {
        strcpy(pelicula[pos].titulo,strLongitud.buffer);
    }
    system("cls");
/*
    listarDirectores (director, D);
    pelicula[pos].idDirector=getInt("Ingrese Id Director: ");
    system("cls");
    getStringLetras("Ingrese nacionalidad: ",pelicula[pos].nacionalidad);
    system("cls");
    pelicula[pos].idEstado=estado;
*/
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
    char menu [255];
    int opcion;
    menu="1. Titulo.\n2. Año.\n3. Nacionalidad.\n4. Id director.\n5. Salir.\n");
    //strcpy(opciones.error,"Ingreso una opcion invalida. Desea continuar? s/n: ");
    //opciones.desde = 1;
    //opciones.hasta = 5;
    char tituloAux[255];

    do
    {
        opcion = getInt ();

        switch (opcion)
        {
        case 1:
            getString("Ingrese el nuevo titulo: ",pelicula[pos].titulo);
            break;

        case 2:
            pelicula[pos].anio=getInt("Ingrese el nuevo anio: ");
            break;

        case 3:
            getStringLetras("Ingrese la nueva nacionalidad: ",pelicula[pos].nacionalidad);
            break;

        case 4:
            pelicula[pos].idDirector=getInt("Ingrese el nuevo Id Director: ");
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
    int validar;
    idDMayor++;

    do
    {
        system("pause");
        system("cls");
        validar=(getStringLetras("Ingrese Nombre: ",nombreAux));
        if(validar==1)
        {
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
            }
        }
        else
        {
            printf("El nombre es invalido.\n");
        }

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


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[],char buffer[],int minimo, int maximo)
{
    int retorno=0;
    char seguir='s';
    int auxiliar;
    do
    {
        printf("%s",mensaje);
        auxiliar=atoi(buffer);
        if(auxiliar>=minimo && auxiliar<=maximo)
        {
            retorno=1;
            seguir='n';
        }
        else
        {
            printf("Dato ingresado incorrecto. Desea continuar?s/n: ");
            scanf("%c",seguir);
        }
    }
    while(seguir=='s');

    return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
int getString(char mensaje[],char buffer[], int longitud)
{
    int flag=0;
    do
    {
        system("cls");
        printf("%s", mensaje);
        scanf ("%s", buffer);
        if(strlen(buffer)<=longitud)
        {
            flag=1;
        }
        else
        {
            printf("El valor ingresado es incorrecto.\n")
        }
    }
    while(flag==0);

    return flag;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \param strLongitud para verificar longitud del array
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[], char buffer[], int longitud)
{
    if(getString(mensaje,buffer,longitud)==1)
    {
       if(esSoloLetras(buffer))
        {
            return 1;
        }
    }
    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


int validarRangoEdad(eValidar cadena)
{
    int edad;
    edad=atoi(cadena.buffer);
    if(edad>=cadena.minimo && edad<=cadena.maximo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int verificarDNI(eValidar cadena)
{
    int dni;
    if((strlen(cadena.buffer))==8)
    {
        dni=atoi(cadena.buffer);

        if (dni>=cadena.minimo && dni<=cadena.maximo)
        {
          return 1;
        }
    }
    return 0;
}

/*

int validarStr(eValidar cadena)
{
    int i = 0;
    char letra;

    while(cadena.buffer[i] != '\0')
    {
        letra=(char)cadena.buffer[i];
        if(!isalpha(letra))
        {
            return 0;
        }
       i++;
    }
    return 1;
}
*/







