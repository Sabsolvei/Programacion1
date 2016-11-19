#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#include "materias.h"
#include "clases.h"
#include "validaciones.h"

static int id = 0;

Materias* materias_new()
{
    Materias* returnAux = NULL;
    returnAux=(Materias*)malloc(sizeof(Materias*));
    return returnAux;
}

int get_nextId ()
{
    id++;
    return id;
}

int materias_alta(ArrayList* pListMaterias)
{
    int retorno = -1;
    Materias* pMateria = NULL;
    pMateria = materias_new();
    if (pMateria != NULL)
    {
        if(materias_getData(pMateria) == 0)
        {
            pMateria->id = get_nextId();
             printf("EN EL ALTA %p\n", &pMateria->clases);
             printf("Id: %d -- Nombre: %s -- Carrera: %s -- Clases: %d -- Horas: %d\n", pMateria->id, pMateria->name, pMateria->carrera, pMateria->clases, pMateria->horas);
            pListMaterias->add(pListMaterias, pMateria);

            printf("%d",pListMaterias->len(pListMaterias));
            retorno = 0;
        }
    }
    return retorno;
}

int materias_getData (Materias* auxMateria)
{
    char buffer[4000];
    int retorno = -1, flag = 1;

    if(auxMateria != NULL)
    {
        system("cls");
        /*if(getInt("Ingrese el Id: ", buffer))
        {
            auxMateria->id = atoi(buffer);
            flag = 1;
        }
        else
        {
            flag = 0;
        }*/
        if(flag == 1 && getStringLetras("Ingrese el nombre: ", buffer, 51))
        {
            strcpy(auxMateria->name, buffer);
            printf("%s\n", auxMateria->name);
        }
        else
        {
            flag = 0;
        }
        if(flag == 1 && getStringLetras("Ingrese la carrera: ", buffer, 51))
        {
            strcpy(auxMateria->carrera, buffer);
            printf("%s\n", auxMateria->carrera);
        }
        else
        {
            flag = 0;
        }
        //system("cls");
        if(flag == 1 && getInt("Ingrese cantidad de horas: ", buffer))
        {
            auxMateria->horas = atoi(buffer);
            printf("%d\n", auxMateria->horas);
        }
        else
        {
            flag = 0;
        }
        //system("cls");
        if(flag == 1 && getInt("Ingrese cantidad de clases: ", buffer))
        {
            auxMateria->clases = atoi(buffer);
            printf("%d\n", auxMateria->clases);
        }
        else
        {
            flag = 0;
        }
    }
    if(flag == 1)
        retorno = 0;

    return retorno;
}

int materias_getId(ArrayList* pListMaterias)
{
    int i;
    int indiceMaximo = 0;
    Materias* pAuxMateria;

    for (i=0; i<pListMaterias->size; i++)
    {
        pAuxMateria = pListMaterias->get(pListMaterias, i);
        if (pAuxMateria->id > indiceMaximo);
        indiceMaximo = pAuxMateria->id;
    }
    return indiceMaximo;
}

void materias_list (ArrayList* pListMaterias)
{
    int i = 0;
    Materias* pAuxMateria;
   // pAuxMateria = materias_new();

    //pAuxMateria =(Materias*) pListMaterias->get(pListMaterias, i);

 // printf("Id: %d -- Nombre: %s -- Carrera: %s -- Clases: %d -- Horas: %d\n", pAuxMateria->id, pAuxMateria->name, pAuxMateria->carrera, pAuxMateria->clases, pAuxMateria->horas);

    for(i=0; i<pListMaterias->len(pListMaterias); i++)
    {

        if(pAuxMateria != NULL)
        {
            pAuxMateria =(Materias*) pListMaterias->get(pListMaterias, i);
            printf("EN LA LISTA %p--%p--%p\n",pAuxMateria->carrera, &pAuxMateria->clases, &pAuxMateria->horas);
            printf("Id: %d -- Nombre: %s -- Carrera: %s -- Clases: %d -- Horas: %d\n", pAuxMateria->id, pAuxMateria->name, pAuxMateria->carrera, pAuxMateria->clases, pAuxMateria->horas);
        }
    }
}

int materias_modificar(ArrayList* pListMaterias)
{
    char mensaje = "Ingrese el Id de la materia que desea modificar: \n";
    char buffer[4000];
    int index, retorno = -1;
    if(getInt(mensaje, buffer))
    {
        index = atoi(buffer);
        if(pListMaterias->contains(pListMaterias, pListMaterias->get(pListMaterias, index))==1);
        retorno = 0;
    }
    return retorno;
}

