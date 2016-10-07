#include <stdio.h>
#include "Funciones.h"

/**
 * \brief Inicializa el array ePersona en estado Libre
 * \param Array del tipo ePersona
 * \param Tamaño del array
 * \param estado "libre"
 * \return void
 *
 */
void InicializarEstadoAbonado (ePersona abonado[],int P,int estado)
{
    int i;
    for(i=0; i<P; i++)
    {
        abonado[i].isEmpty=estado;
    }
}

/**
 * \brief Inicializa el array eLlamada en estado Libre
 * \param Array del tipo eLlamada
 * \param Tamaño del array
 * \param estado "libre"
 * \return void
 *
 */
void InicializarEstadoReclamo (eLlamada reclamo[],int R,int estado)
{
    int i;
    for(i=0; i<R; i++)
    {
        reclamo[i].isEmpty=estado;
    }
}

/**
 * \brief Ingresa datos al array Director para el testing
 * \param Array del tipo eDirector
 * \return void
 *
 */
void HardcodearAbonado (ePersona abonado[])
{
    int i=0;
    int Id[]= {1,2,3,4,5};
    char nombre[][50]= {"Juan","Pablo","Juana","Maria","Luis"};
    char apellido[][50]= {"Garcia","Fernandez","Rodriguez","Perez","Ferraro"};
    int telefono[]= {43005656,42523536,43013539,46055689,45227896};
    int idEstado[]= {1,1,1,1,1};


    for(i=0; i<5; i++)
    {
        abonado[i].id=Id[i];
        strcpy(abonado[i].nombre,nombre[i]);
        strcpy(abonado[i].apellido,apellido[i]);
        abonado[i].telefono=telefono[i];
        abonado[i].isEmpty=idEstado[i];
    }
}

/**
 * \brief Ingrea datos al array persona para el testing
 * \param Array del tipo ePelicula
 * \return void
 *
 */
void HardcodearReclamo (eLlamada reclamo[])
{
    int i=0;
    int idReclamo[]= {1,2,3,3,5};
    int idAbonado[]= {1,1,3,4,5};
    char motivo[][20]= {"Falla 3G","Falla 3G","Falla LTE","Falla Equipo","Falla Equipo"};
    char estado[][20]= {"Solucionado","En curso","No solucionado","Solucionado","En curso"};
    int tiempo[]= {200,30,60,20,40};
    int isEmpty[]= {1,1,1,1,1};

    for(i=0; i<5; i++)
    {
        reclamo[i].idReclamo=idReclamo[i];
        reclamo[i].idAbonado=idAbonado[i];
        strcpy(reclamo[i].motivo,motivo[i]);
        strcpy(reclamo[i].estado,estado[i]);
        reclamo[i].tiempoMinutos=tiempo[i];
        reclamo[i].isEmpty=isEmpty[i];
    }
}



/**
 * \brief realizar el alta de abonado
 * \param Array del tipo ePersona
 * \param Posicion donde sera guardado
 * \param Tamaño del array abonado
 * \param char de gran tamaño para validar los datos ingresados
 * \return Devuelve 1 si el alta fue completa, 0 si falto algun dato
 *
 */
int altaPersona (ePersona abonado[], int pos, int P, char buffer[])
{
    int i=0;
    int id;
    int idMayor=0;
    int seguir=1;
    char continuar='s';
    int auxTel;

    if(getStringLetras("Ingrese el nombre: ",buffer, 50))
    {
        strcpy(abonado[pos].nombre,buffer);
    }
    else
    {
        seguir=0;
    }

    system("cls");

    if(seguir==1)
    {
        if(getStringLetras("Ingrese el apellido: ",buffer, 50))
        {
            strcpy(abonado[pos].apellido,buffer);
        }
        else
        {
            seguir=0;
        }
    }

    system("cls");

    if(seguir==1)
    {
        while(continuar=='s')
        {
            if(getString("Ingrese el telefono: ",buffer,10))
            {
                if(esNumerico(buffer))
                {
                    abonado[pos].telefono=atoi(buffer);
                    continuar='n';
                }
                else
                {
                    printf("El telefono no es valido. Desea continuar? s/n: ");
                    fflush(stdin);
                    scanf("%c",&continuar);
                    if(continuar=='n')
                    {
                        seguir=0;
                    }
                }
            }
            else
            {
                continuar='n';
                seguir=0;
            }
        }
    }

    system("cls");

    if(seguir==1)
    {
        buscarIdMayor(abonado,P,&idMayor);
        abonado[pos].id=idMayor+1;
        abonado[pos].isEmpty=1;
    }
    return seguir;
}


/**
 * \brief Encontrar espacio libre para ingresar abonado
 * \param Array del tipo ePersona
 * \param Tamaño del array abonado
 * \return posicion del array libre, o -1 si no encuentra espacio libre.
 *
 */
int encontrarEspacioLibre (ePersona abonado[],int P)
{
    int i=0;
    int espLibre=-1;
    for(i=0; i<P; i++)
    {
        if(abonado[i].isEmpty==-1)
        {
            espLibre=i;
            break;
        }
    }
    return espLibre;
}

/**
 * \brief Buscar el ultimo id generado
 * \param Array del tipo ePersona
 * \param Tamaño del array abonado
 * \param Puntero para guardar el ultimo id
 * \return puntero
 *
 */
int buscarIdMayor (ePersona abonado[], int P, int *idMayor)
{
    int i=0;
    for(i=0; i<P; i++)
    {
        if(abonado[i].isEmpty==0 || abonado[i].isEmpty==1)
        {
            if(abonado[i].id>*idMayor)
            {
                *idMayor = abonado[i].id;
            }
        }
    }
}

/**
 * \brief Hacer un listado de personas
 * \param Array del tipo ePersona
 * \param tamaño del array
 * \return void
 *
 */
void ListarPersonas (ePersona abonado[], int P)
{
    int i=0;

    printf("Id  Nombre  Apellido    Telefono\n");
    for(i=0; i<P; i++)
    {
        if(abonado[i].isEmpty==1)
            printf("%d  %s  %s  %d\n",abonado[i].id,abonado[i].nombre, abonado[i].apellido, abonado[i].telefono);
    }
}


/**
 * \brief Modificar uno o mas campos de un registro de abonado
 * \param Array del tipo ePersona
 * \param Posicion del array donde se hace la modificacion
 * \param char de gran tamaño para validar los datos ingresados
 * \return puntero
 *
 */
int ModificarPersona (ePersona abonado[],int pos,char buffer[])
{
    int seguir = 's';
    int opcion;
    int retorno=0;
    char menu[]="1. Nombre.\n2. Apellido.\n3. Telefono.\n4. Salir.\nIngrese la opcion que desea modificar: ";

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
                if(getStringLetras("Ingrese el nuevo nombre: ",buffer,50))
                {
                    strcpy(abonado[pos].nombre,buffer);
                    printf("Nombre modificado con exito.\n");
                    retorno=1;
                }
                else
                {
                    printf("El nombre no fue modificado.\n");
                }
                break;

            case 2:
                system("cls");
                if(getStringLetras("Ingrese el nuevo apellido: ",buffer,50))
                {
                    strcpy(abonado[pos].apellido,buffer);
                    printf("Apellido modificado con exito.\n");
                    retorno=1;
                }
                else
                {
                    printf("El apellido no fue modificado.\n");
                }
                break;

            case 3:
                system("cls");

                if(getString("Ingrese el nuevo telefono: ",buffer,10))
                {
                    if(esNumerico(buffer))
                    {
                        abonado[pos].telefono=atoi(buffer);
                        printf("Telefono modificado con exito.\n");
                        retorno=1;
                    }
                    else
                    {
                        printf("Telefono invalido. El telefono no fue modificado.\n");
                    }
                }
                else
                {
                    printf("El telefono no fue modificado.\n");
                }
                break;

            case 4:
                seguir = 'n';
                break;
            }
        }
    }
    while (seguir == 's');

    return retorno;
}




/**
 * \brief Buscar si la id abonado ingresado esta activo
 * \param Array del tipo ePersona
 * \param Tamaño del array
 * \param Id Director ingresado por el usuario
 * \return 1 si encuentra coincidencias, 0 si no
 *
 */
int buscarIdPersonaExistente (ePersona abonado[],int P,int idAbonado,int estado)
{
    int i=0;
    int pos=-1;
    for(i=0; i<P; i++)
    {
        if(abonado[i].isEmpty>=estado && idAbonado==abonado[i].id)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

/**
 * \brief Eliminar persona
 * \param Array del tipo ePelicula
 * \param Posicion del array donde se hace la baja
 * \param Estado "baja"
 * \return void
 *
 */
void EliminarPersona (ePersona abonado[],int estado, int pos)
{
    abonado[pos].isEmpty=estado;
}

void ListarMotivo ()
{
    printf("Id  Motivo\n");
    printf("1   FALLA 3G\n");
    printf("2   FALLA LTE\n");
    printf("3   FALLA EQUIPO\n");
}

void ListarEstados ()
{
    printf("Id  Estado\n");
    printf("1   EN CURSO\n");
    printf("2   SOLUCIONADO\n");
    printf("3   NO SOLUCIONADO\n");
}

/**
 * \brief Buscar el ultimo id generado
 * \param Array del tipo ePersona
 * \param Tamaño del array reclamo
 * \param Puntero para guardar el ultimo id
 * \return puntero
 *
 */
int buscarIdMayorReclamo (eLlamada reclamo[], int R, int *idMayor)
{
    int i=0;
    for(i=0; i<R; i++)
    {
        if(reclamo[i].isEmpty==0 || reclamo[i].isEmpty==1)
        {
            if(reclamo[i].idReclamo>*idMayor)
            {
                *idMayor = reclamo[i].idReclamo;
            }
        }
    }
}


/**
 * \brief realizar el alta de reclamo
 * \param Array del tipo eLlamada
 * \param Posicion donde sera guardado
 * \param Tamaño del array reclamo
 * \param char de gran tamaño para validar los datos ingresados
 * \return Devuelve 1 si el alta fue completa, 0 si falto algun dato
 *
 */
int altaReclamo (eLlamada reclamo[],ePersona abonado[], int pos, int R,int P, char buffer[])
{
    int i=0;
    int id;
    int idMayor=0;
    int seguir=1;
    char continuar='s';
    int idAbonado;
    int motivo;
    int estado;

    system("cls");

    ListarMotivo();
    if(getInt("Ingrese el Id Motivo: ",buffer, 1, 3))
    {
        motivo=atoi(buffer);
        switch (motivo)
        {
        case 1:
            strcpy(reclamo[pos].motivo,"Falla 3G");
            break;
        case 2:
            strcpy(reclamo[pos].motivo,"Falla LTE");
            break;
        case 3:
            strcpy(reclamo[pos].motivo,"Falla equipo");
            break;
        }
    }
    else
    {
        seguir=0;
    }

    system("cls");

    if(seguir==1)
    {
        ListarPersonas (abonado,P);
        if(getInt("Ingrese el Id Persona: ",buffer,1,10))
        {
            idAbonado=atoi(buffer);
            if(buscarIdPersonaExistente (abonado, P,idAbonado,estado)>=0)
            {
                reclamo[pos].idAbonado=idAbonado;
            }
        }
        else
        {
            printf("El id ingresado no corresponde a una persona vigente\n");
            seguir=0;
        }

        system("cls");

    }
    if(seguir==1)
    {
        system("cls");
        buscarIdMayorReclamo(reclamo,R,&idMayor);
        reclamo[pos].idReclamo=idMayor+1;
        strcpy(reclamo[pos].estado,"En Curso");
        reclamo[pos].isEmpty=1;
    }

    return seguir;
}



/**
 * \brief Hacer un listado de reclamos
 * \param Array del tipo ePersona
 * \param tamaño del array
 * \return void
 *
 */
void ListarReclamos (eLlamada reclamo[], int R)
{
    int i=0;

    printf("Id  Motivo      Estado      Tiempo   Id Abonado\n");
    for(i=0; i<R; i++)
    {
        if(reclamo[i].isEmpty==1)
            printf("%d  %s     %s     %d    %d\n",reclamo[i].idReclamo,reclamo[i].motivo, reclamo[i].estado,reclamo[i].tiempoMinutos, reclamo[i].idAbonado);
    }
}

/**
 * \brief Modificar uno o mas campos de un registro de abonado
 * \param Array del tipo ePersona
 * \param Posicion del array donde se hace la modificacion
 * \param char de gran tamaño para validar los datos ingresados
 * \return puntero
 *
 */
int ModificarReclamo (eLlamada reclamo[],int pos,char buffer[])
{
    int seguir = 's';
    int estado;
    int opcion;
    int retorno=0;
    char menu[]="1. Estado.\n2. Tiempo.\n3. Salir.\nIngrese la opcion que desea modificar: ";

    do
    {
        system("pause");
        system("cls");
        if(getInt(menu,buffer,1,3))
        {
            opcion=atoi(buffer);

            switch (opcion)
            {
            case 1:
                system("cls");
                ListarEstados();
                if(getInt("Ingrese el Id Estado: ",buffer, 1, 3))
                {
                    estado=atoi(buffer);
                    switch (estado)
                    {
                    case 1:
                        strcpy(reclamo[pos].motivo,"En Curso");
                        break;
                    case 2:
                        strcpy(reclamo[pos].motivo,"Solucionado");
                        break;
                    case 3:
                        strcpy(reclamo[pos].motivo,"No solucionado");
                        break;
                    }
                    retorno=1;
                }

            case 2:
                system("cls");
                {
                    if(getInt("Ingrese el tiempo en minutos: ",buffer, 1, 100000))
                    {
                        reclamo[pos].tiempoMinutos= atoi(buffer);
                        retorno=1;
                    }
                }

            case 3:
                seguir = 'n';
                break;
            }
        }
    }
    while (seguir == 's');

    return retorno;
}


/**
 * \brief Encontrar espacio libre para ingresar reclamo
 * \param Array del tipo eLlamada
 * \param Tamaño del array reclamo
 * \return posicion del array libre, o -1 si no encuentra espacio libre.
 *
 */
int encontrarEspacioLibreReclamo (eLlamada reclamo[],int R)
{
    int i=0;
    int espLibre=-1;
    for(i=0; i<R; i++)
    {
        if(reclamo[i].isEmpty==-1)
        {
            espLibre=i;
            break;
        }
    }
    return espLibre;
}


/**
 * \brief Buscar si la id reclamo ingresado esta activo
 * \param Array del tipo eLlamada
 * \param Tamaño del array
 * \param Id Reclamo ingresado por el usuario
 * \return 1 si encuentra coincidencias, 0 si no
 *
 */
int buscarIdReclamoExistente (eLlamada reclamo[],int P,int idReclamo,int estado)
{
    int i=0;
    int pos=-1;
    for(i=0; i<P; i++)
    {
        if(reclamo[i].isEmpty>=estado && idReclamo==reclamo[i].idReclamo)
        {
            pos=i;
            break;
        }
    }
    return pos;
}





/**
 * \brief Contar reclamos por cada 1 director
 * \param Array del tipo ePelicula
 * \param tamaño del array
 * \param id director enviado por otra funcion
 * \return cantidad de reclamos
 *
 */
int contarReclamos (eLlamada reclamo[],int R,int id)
{
    int i;
    int contador=0;
    for(i=0; i<R; i++)
    {
        if(reclamo[i].idAbonado==id)
        {
            contador++;
        }
    }
    return contador;
}

/**
 * \brief Registrar cantidad de reclamos por abonado
 * \param Array del tipo ePersona
 * \param tamaño del array
 * \param Array del tipo eLlamada
 * \param Array del tipo ePeliculaCantidad
 * \param tamaño del array abonado
 * \param tamaño del array reclamo
 * \return void
 *
 */
void BuscarAbonadoConMasReclamos (ePersona abonado[],eLlamada reclamo[],eReclamoCantidad reclamoCantidad[], int P,int R)
{
    int i=0;
    int cantidadAux;

    for(i=0; i<P; i++)
    {
        cantidadAux = contarReclamos(reclamo,P,abonado[i].id);
        reclamoCantidad[i].idAbonado = abonado[i].id;
        reclamoCantidad[i].cantidad = cantidadAux;
    }
}


/**
 * \brief Mostrar director/es con mas reclamos
 * \param Array del tipo eReclamoCantidad
 * \param tamaño del array
 * \return void
 *
 */
void MostrarAbonadoConMasReclamos (eReclamoCantidad reclamoCantidad[], int R)
{
    int i=0;
    int j=0;
    int k=0;
    eReclamoCantidad reclamoCantidadAux;

    for(i=0; i<R-1; i++)
    {
        for(j=i+1; j<R; j++)
        {
            if(reclamoCantidad[i].cantidad<reclamoCantidad[j].cantidad)
            {
                reclamoCantidadAux = reclamoCantidad[i];
                reclamoCantidad[i] = reclamoCantidad[j];
                reclamoCantidad[j] = reclamoCantidadAux;
            }
        }
    }
    printf("Id Cantidad\n");
    do
    {
        printf("%d      %d\n",reclamoCantidad[k].idAbonado, reclamoCantidad[k].cantidad);
        k++;

    }
    while(reclamoCantidad[k-1].cantidad==reclamoCantidad[k].cantidad);

}
/*
void reclamoMasRealizado (eLlamada reclamo[],int R)
{
    int i = 0;
    int j = 0;
    int k = 0;
    eMotivoCantidad motivoCantidad[3];
    eMotivoCantidad motCantAux;
    int contMotivo1;
    int contMotivo2;
    int contMotivo3;


    for(i=0; i<R; i++)
    {
        if(reclamo[i].isEmpty==1)
        {
            if(stricmp(reclamo[i].motivo,"Falla 3g")==0)
            {
                contMotivo1 ++;
            }
            if(stricmp(reclamo[i].motivo,"Falla LTE")==0)
            {
                contMotivo2 ++;
            }
            if(stricmp(reclamo[i].motivo,"Falla Equipo")==0)
            {
                contMotivo3 ++;
            }
        }
    }

    char motivo[][20]= {"Falla 3g", "Falla LTE", "Falla Equipo"};
    int cantidad[]= {"%d, %d, %d",contMotivo1,contMotivo2,contMotivo3};
     for(i=0; i<3; i++)
     {
         strcpy(motivoCantidad[i].motivo,motivo[i]);
         motivoCantidad[i].cantidad=cantidad[i];
     }

    for(i=0; i<3-1; i++)
    {
        for (j=i+1; j<3; j++)
        {
            if(motivoCantidad[i].cantidad<motivoCantidad[j].cantidad)
            {
                motCantAux= motivoCantidad[i];
                motivoCantidad[i]=motivoCantidad[j];
                motivoCantidad[j]=motCantAux;
            }
        }
    }

    printf("Id Cantidad\n");
    do
    {
        for(k=0; k<3; k++)
        {

            printf("%d      %d\n",motivoCantidad[k].motivo, motivoCantidad[k].cantidad);
            k++;

        }

    }
    while(motivoCantidad[k-1].cantidad==motivoCantidad[k].cantidad);

}




*/

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
                printf("Dato ingresado fuera del rango permitido. Desea continuar?s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            printf("Dato ingresado no es numerico. Desea continuar?s/n: ");
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
    int retorno=0;

    if(auxiliar>=minimo && auxiliar<=maximo)
    {
        retorno=1;
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

        if(VerificarRangoChar(buffer,longitud))
        {
            retorno=1;
            seguir='n';
        }
        else
        {
            printf("Dato ingresado muy extenso. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

    }
    while(seguir=='s');

    return retorno;
}


int VerificarRangoChar(char buffer[], int longitud)
{
    int retorno=0;
    if(strlen(buffer)<=longitud)
    {
        retorno=1;
    }
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
                printf("Deben ser solo letras. Desea continuar?s/n: ");
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


