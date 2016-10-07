#include <stdio.h>
#include "Funciones.h"


/**
 * \brief Inicializa el array Pelicula en estado Libre
 * \param Array del tipo ePelicula
 * \param Tamaño del array
 * \param estado "libre"
 * \return void
 *
 */
void inicializarEstadoPelicula (ePelicula pelicula[],int C,int estado)
{
    int i;
    for(i=0;i<C;i++)
    {
        pelicula[i].idEstado=estado;
    }
}

/**
 * \brief Inicializa el array Director en estado Libre
 * \param Array del tipo eDirector
 * \param Tamaño del array
 * \param estado "libre"
 * \return void
 *
 */
void inicializarEstadoDirector (eDirector director[],int D,int estado)
{
    int i;
    for(i=0;i<D;i++)
    {
        director[i].idEstado=estado;
    }
}

/**
 * \brief Ingresa datos al array Director para el testing
 * \param Array del tipo eDirector
 * \return void
 *
 */
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

/**
 * \brief Ingrea datos al array Pelicula para el testing
 * \param Array del tipo ePelicula
 * \return void
 *
 */
void inicializarPelicula (ePelicula pelicula[])
{
    int i=0;
    int IdDir[]={1,1,2,2,4};
    int IdPeli[]={1,2,3,4,5};
    char nac[][20]={"argentino" ,"brasileño" ,"uruguayo" ,"boliviano" ,"paraguayo"};
    int idEstado[]={1,1,1,1,1};
    char titulo[][20]={"KungFu","Terminator","Terminator","She","Luis"};
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




/**
 * \brief realizar el alta de pelicula
 * \param Array del tipo eDirector
 * \param Array del tipo ePelicula
 * \param Posicion donde sera guardado
 * \param Tamaño del array pelicula
 * \param Tamaño del array director
 * \param char de gran tamaño para validar los datos ingresados
 * \return Devuelve 1 si el alta fue completa, 0 si falto algun dato
 *
 */
int altaPelicula (ePelicula pelicula[], eDirector director[],int pos,int C, int D, char buffer[])
{
    int i=0;
    int id;
    int idMayor=0;
    int seguir=1;
    char continuar='s';

    if(getString("Ingrese el titulo: ",buffer, 255))
    {
        strcpy(pelicula[pos].titulo,buffer);
    }
    else { seguir=0; }

    system("cls");

    if(seguir==1)
    {
        if(getInt("Ingrese Año: ",buffer,1900,2017))
        {
            pelicula[pos].anio= atoi(buffer);
        }
        else { seguir=0; }
    }

    system("cls");

    if(seguir==1)
    {
        while(continuar=='s')
        {
            listarDirectores (director, D);
            if(getInt("Ingrese Id Director: ",buffer,1,D))
            {
                if(buscarIdDirExistente(director,D,buffer,0)>-1)
                {
                    pelicula[pos].idDirector= atoi(buffer);
                    continuar='n';
                }
                else
                {
                    printf("El Id Director ingresado no existe. Desea continuar? s/n: ");
                    fflush(stdin);
                    scanf("%c",&continuar);
                    if(continuar=='n')
                    {
                        seguir=0;
                    }
                    system("cls");
                }
            }
        }
    }

    system("cls");
    if(seguir==1)
    {
        if(getStringLetras("Ingrese nacionalidad: ",buffer, 20))
        {
            strcpy(pelicula[pos].nacionalidad,buffer);
        }
        else { seguir=0; }
    }
    if(seguir==1)
    {
        buscarIdMayorPelicula(pelicula,C,&idMayor);
        pelicula[pos].idPelicula=idMayor+1;
        pelicula[pos].idEstado=1;

    }
    return seguir;
}

/**
 * \brief Encontrar espacio libre para ingresar pelicula
 * \param Array del tipo ePelicula
 * \param Tamaño del array pelicula
 * \return posicion del array libre, o -1 si no encuentra espacio libre.
 *
 */
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

/**
 * \brief Buscar el ultimo id generado
 * \param Array del tipo ePelicula
 * \param Tamaño del array pelicula
 * \param Puntero para guardar el ultimo id
 * \return puntero
 *
 */
int buscarIdMayorPelicula (ePelicula pelicula[], int C, int *idMayor)
{
    int i=0;
    for(i=0;i<C;i++)
    {
        if(pelicula[i].idEstado==0 || pelicula[i].idEstado==1)
        {
            if(pelicula[i].idPelicula>*idMayor)
            {
                *idMayor = pelicula[i].idPelicula;
            }
        }
    }
}

/**
 * \brief Modificar uno o mas campos de un registro de pelicula
 * \param Array del tipo ePelicula
 * \param Posicion del array donde se hace la modificacion
 * \param char de gran tamaño para validar los datos ingresados
 * \return puntero
 *
 */
int modificarPelicula (ePelicula pelicula[],int pos,char buffer[])
{
    int seguir = 's';
    int opcion;
    int retorno=0;
    char menu[]="1. Titulo.\n2. Año.\n3. Nacionalidad.\n4. Id director.\n5. Salir.\nIngrese una opcion: ";

    do
    {
        system("pause");
        system("cls");
        if(getInt(menu,buffer,1,5))
        {
            opcion=atoi(buffer);

            switch (opcion)
            {
            case 1:
                system("cls");
                if(getString("Ingrese el nuevo titulo: ",buffer,255))
                {
                    strcpy(pelicula[pos].titulo,buffer);
                    printf("Titulo modificado con exito.\n");
                    retorno=1;
                }
                else { printf("El titulo no fue modificado.\n"); }
                break;

            case 2:
                system("cls");
                if(getInt("Ingrese el nuevo anio: ",buffer,1900,2017))
                {
                    pelicula[pos].anio=atoi(buffer);
                    printf("Anio modificado con exito.\n");
                    retorno=1;
                }
                else { printf("El anio no fue modificado.\n"); }
                break;

            case 3:
                system("cls");
                if(getStringLetras("Ingrese la nueva nacionalidad: ",buffer,20))
                {
                    strcpy(pelicula[pos].nacionalidad,buffer);
                    printf("Nacionalidad modificada con exito.\n");
                    retorno=1;
                }
                else { printf("La nacionalidad no fue modificada.\n"); }
                break;

            case 4:
                system("cls");
                if(getInt("Ingrese el nuevo Id Director: ",buffer,1,5))
                {
                    pelicula[pos].idDirector=atoi(buffer);
                    printf("Id Director modificado con exito.\n");

                }
                else { printf("Id Director no fue modificado.\n"); }
                break;

            case 5:
                seguir = 'n';
                break;
            }
        }
    } while (seguir == 's');

    return retorno;
}


/**
 * \brief Eliminar pelicula
 * \param Array del tipo ePelicula
 * \param Posicion del array donde se hace la baja
 * \param Estado "baja"
 * \return void
 *
 */
void eliminarPelicula (ePelicula pelicula[],int baja, int pos)
{
    pelicula[pos].idEstado=baja;
}

/**
 * \brief Buscar si la id pelicula ingresado esta activo
 * \param Array del tipo ePelicula
 * \param Tamaño del array
 * \param Id Pelicula ingresado por el usuario
 * \return 1 si encuentra coincidencias, 0 si no
 *
 */
int buscarIdPeliExistente (ePelicula pelicula[],int C,int idPelicula)
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
    if(pos==-1)
    {
        printf("El id ingresado no corresponde a una pelicula vigente.\n");
    }

    return pos;
}

/**
 * \brief Hacer un listado de peliculas
 * \param Array del tipo ePelicula
 * \param tamaño del array
 * \return void
 *
 */
void listarPeliculas (ePelicula pelicula[], int C)
{
    int i=0;
    ordenarPelicula (pelicula, C);
    printf("Id  Titulo  Año Nacionalidad    IdDirector\n");
    for(i=0;i<C;i++)
    {
        if(pelicula[i].idEstado==1)
            printf("%d  %s  %d  %s  %d\n",pelicula[i].idPelicula,pelicula[i].titulo, pelicula[i].anio, pelicula[i].nacionalidad, pelicula[i].idDirector);
    }
}

/**
 * \brief Ordenar las peliculas por titulo descendente, o año ascendente
 * \param Array del tipo ePelicula
 * \param tamaño del array
 * \return void
 *
 */
void ordenarPelicula (ePelicula pelicula[], int C)
{
    int i=0;
    int j=0;
    ePelicula auxiliar;
    for(i=0;i<C-1;i++)
    {
        if(pelicula[i].idEstado==1)
        {
            for(j=i+1;j<C;j++)
            {
                if(pelicula[j].idEstado==1)
                {
                    if(stricmp(pelicula[i].titulo,pelicula[j].titulo)<0)
                    {
                            auxiliar=pelicula[i];
                            pelicula[i]=pelicula[j];
                            pelicula[j]=auxiliar;
                    }
                    if((stricmp(pelicula[i].titulo,pelicula[j].titulo)==0) && pelicula[i].anio>pelicula[j].anio)
                    {
                            auxiliar=pelicula[i];
                            pelicula[i]=pelicula[j];
                            pelicula[j]=auxiliar;
                    }
                }
            }
        }
    }
}







/**
 * \brief realizar el alta de director
 * \param Array del tipo eDirector
 * \param Array del tipo ePelicula
 * \param Posicion donde sera guardado
 * \param Tamaño del array pelicula
 * \param Tamaño del array director
 * \param char de gran tamaño para validar los datos ingresados
 * \return Devuelve 1 si el alta fue completa, 0 si falto algun dato
 *
 */

int altaDirector (eDirector director[], ePelicula pelicula[],int pos,int C, int D, char buffer[])
{
    int i=0;
    int id;
    int idMayor=0;
    int seguir=1;
    char continuar='s';

    while(continuar=='s')
    {
        if(getStringLetras("Ingrese el nombre: ",buffer, 255))
        {
            if (verificarNombre (director, D, buffer))
            {
                strcpy(director[pos].nombre,buffer);
                continuar='n';
            }
            else
            {
                printf("El nombre ya existe. Desea continuar? s/n: ");
                fflush(stdin);
                scanf("%c",&continuar);
                if(continuar=='n')
                {
                    seguir=0;
                }

            }
        }
        else { seguir=0; }
    }
    system("cls");

    if(seguir==1)
    {
        printf("Ingrese fecha de nacimiento: 00/00/0000\n:");

        if(getInt("Ingrese dia: ",buffer,1,31))
        {
            director[pos].nacimiento.dia=atoi(buffer);
        }
        else { seguir=0; }

        if(seguir==1)
        {
            if(getInt("Ingrese mes: ",buffer,1,12))
            {
                director[pos].nacimiento.mes=atoi(buffer);
            }
            else { seguir=0; }
        }

        if(seguir==1)
        {
            if(getInt("Ingrese anio: ",buffer,1900,2016))
            {
                director[pos].nacimiento.anio=atoi(buffer);
            }
            else { seguir=0; }
        }

    }
    system("cls");

    if(seguir==1)
    {
        if(getStringLetras("Ingrese nacionalidad: ",buffer, 20))
        {
            strcpy(director[pos].nacionalidad,buffer);
        }
        else { seguir=0; }
    }

    if(seguir==1)
    {
        buscarIdMayorDirector(director,D,&idMayor);
        director[pos].idDirector=idMayor+1;
        director[pos].idEstado=1;
    }
    return seguir;
}

/**
 * \brief Buscar el ultimo id generado
 * \param Array del tipo eDirector
 * \param Tamaño del array director
 * \param Puntero para guardar el ultimo id
 * \return puntero
 *
 */
int buscarIdMayorDirector (eDirector director[], int D, int *idMayor)
{
    int i=0;
    for(i=0;i<D;i++)
    {
        if(director[i].idEstado==0 || director[i].idEstado==1)
        {
            if(director[i].idDirector>*idMayor)
            {
                *idMayor = director[i].idDirector;
            }
        }
    }
}

/**
 * \brief Verifica que el nombre de director no exista
 * \param Array del tipo eDirector
 * \param Tamaño del array director
 * \param nombre ingresado por usuario
 * \return 1 si no encuentra coincidencias, 0 si el nombre ya existe
 *
 */
int verificarNombre (eDirector director[], int D, char nombreAux[])
{
    int i=0;
    int retorno=1;

    for(i=0;i<D;i++)
    {
        if(stricmp(director[i].nombre,nombreAux)==0)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Encontrar espacio libre para ingresar director
 * \param Array del tipo eDirector
 * \param Tamaño del array director
 * \return posicion del array libre, o -1 si no encuentra espacio libre.
 *
 */
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

/**
 * \brief Eliminar director
 * \param Array del tipo eDirector
 * \param Posicion del array donde se hace la baja
 * \param Estado "baja"
 * \return void
 *
 */
void eliminarDirector (eDirector director[],int baja, int pos)
{
    director[pos].idEstado=baja;
}


/**
 * \brief Buscar si la id director ingresado esta activo
 * \param Array del tipo eDirector
 * \param Tamaño del array
 * \param Id Director ingresado por el usuario
 * \return 1 si encuentra coincidencias, 0 si no
 *
 */
int buscarIdDirExistente (eDirector director[],int D,char idDirector[],int estado)
{
    int i=0;
    int pos=-1;
    int idAux;
    idAux= atoi(idDirector);
    for(i=0;i<D;i++)
    {
        if(director[i].idEstado>=estado && idAux==director[i].idDirector)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

/**
 * \brief Hacer un listado de directores
 * \param Array del tipo eDirector
 * \param tamaño del array
 * \return void
 *
 */
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



/**
 * \brief Contar peliculas por cada 1 director
 * \param Array del tipo ePelicula
 * \param tamaño del array
 * \param id director enviado por otra funcion
 * \return cantidad de peliculas
 *
 */
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

/**
 * \brief Registrar cantidad de peliculas por director
 * \param Array del tipo ePelicula
 * \param tamaño del array
 * \param Array del tipo eDirector
 * \param Array del tipo ePeliculaCantidad
 * \param tamaño del array director
 * \param tamaño del array pelicula
 * \return void
 *
 */
void BuscarDirConMasPelis (ePelicula pelicula[],eDirector director[],ePeliculaCantidad peliculaCantidad[], int D,int C)
{
    int i=0;
    int cantidadAux;

    for(i=0;i<D;i++)
    {
        cantidadAux = contarPeliculas(pelicula,C,director[i].idDirector);
        peliculaCantidad[i].idDirector = director[i].idDirector;
        peliculaCantidad[i].cantidad = cantidadAux;
    }
}


/**
 * \brief Mostrar director/es con mas peliculas
 * \param Array del tipo ePeliculaCantidad
 * \param tamaño del array
 * \return void
 *
 */
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





/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer array ingresado por el usuario
 * \param minimo y maximo del rango
 * \return Devuelve 1 si es numerico y esta dentro del rango, sino 0
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
        fflush(stdin);
        gets(buffer);
        if(esNumerico(buffer))
        {
            auxiliar=atoi(buffer);
            if(verificarRangoInt(auxiliar, minimo, maximo))
            {
                retorno=1;
                seguir='n';
            }
            else
            {
                printf("Desea continuar?s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            printf("Dato ingresado incorrecto. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }
    while(seguir=='s');

    return retorno;
}

/**
 * \brief Verifica si el valor numerico recibido esta dentro del rango permitido
 * \param numero entero a ser analizado
 * \param minimo y maximo del rango
 * \return 1 si esta dentro de los parametros y 0 si no
 */
int verificarRangoInt(int auxiliar, int minimo, int maximo)
{
    char seguir='s';
    int retorno=0;

        if(auxiliar>=minimo && auxiliar<=maximo)
        {
            retorno=1;
            seguir = 'n';
        }
        else
        {
            printf("Dato ingresado fuera del rango permitido.");
        }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer Array donde se cargará el texto ingresado
 * \param longitud para validar la longitud del array
 * \return 1 si la longitud del dato ingresado es correcta
 */
int getString(char mensaje[],char buffer[], int longitud)
{
    char seguir='s';
    int retorno=0;

    do
    {
        system("cls");
        printf("%s", mensaje);
        scanf ("%s", buffer);
        if(strlen(buffer)<=longitud)
        {
            retorno=1;
            seguir='n';
        }
        else
        {
            printf("Dato ingresado incorrecto. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }
    while(seguir=='s');

    return retorno;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer Array donde se cargará el texto ingresado
 * \param longitud para validar la longitud del array
 * \return 1 si el texto contiene solo letras y longitud acorde.
 */
int getStringLetras(char mensaje[], char buffer[], int longitud)
{
    int retorno=0;
    int seguir='s';
     do
    {
        if(getString(mensaje,buffer,longitud))
        {
            if(esSoloLetras(buffer))
            {
                retorno=1;
                seguir='n';
            }
            else
            {
                printf("Dato ingresado incorrecto. Desea continuar?s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            seguir='n';
        }
    }
    while(seguir=='s');

    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i = 0;
    char letra;

    while(str[i] != '\0')
    {
        letra=str[i];
        if(!isalpha(letra))
        {
            return 0;
        }
       i++;
    }
   return 1;
}









