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
    Materias* auxMateria = NULL;

    if(materias_getData(auxMateria) == 0)
    {
        printf("EN EL ALTA %p\n", &auxMateria->clases);
        printf("Id: %d -- Nombre: %s -- Carrera: %s -- Clases: %d -- Horas: %d\n", auxMateria->id, auxMateria->name, auxMateria->carrera, auxMateria->clases, auxMateria->horas);
        pListMaterias->add(pListMaterias, auxMateria);

        printf("%d",pListMaterias->len(pListMaterias));
        retorno = 0;
    }
    return retorno;
}

Materias* materias_saveData (int id, char name, char carrera, int horas, int clases)
{
    Materias * auxMateria = materias_new();
    if(auxMateria != NULL)
    {
        strcpy(auxMateria->name, name);
        strcpy(auxMateria->carrera, carrera);
        auxMateria->horas = horas;
        auxMateria->clases = clases;
        auxMateria->id = get_nextId();
    }
    return auxMateria;
}

int materias_getData (Materias* auxMateria)
{
    int retorno = -1, flag = 1;
    int id, clases, horas;
    char buffer[4000], name, carrera;
    system("cls");
    if(flag == 1 && getStringLetras("Ingrese el nombre: ", buffer, 51))
    {
        strncpy(name, buffer,51);
        printf("%s\n", name);
    }
    else
    {
        flag = 0;
    }
    if(flag == 1 && getStringLetras("Ingrese la carrera: ", buffer, 51))
    {
        strncpy(carrera, buffer,51
                );
        printf("%s\n", carrera);
    }
    else
    {
        flag = 0;
    }
    //system("cls");
    if(flag == 1 && getInt("Ingrese cantidad de horas: ", buffer))
    {
        horas = atoi(buffer);
        printf("%d\n", horas);
    }
    else
    {
        flag = 0;
    }
    //system("cls");
    if(flag == 1 && getInt("Ingrese cantidad de clases: ", buffer))
    {
        clases = atoi(buffer);
        printf("%d\n", clases);
    }
    else
    {
        flag = 0;
    }
    if(flag == 1)
    {
        materias_saveData (auxMateria, name, carrera, horas, clases);
        retorno = 0;
    }
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

