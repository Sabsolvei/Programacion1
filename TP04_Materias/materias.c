#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#include "materias.h"
#include "clases.h"

static int id = 0;

Materias* materias_add(Materias* returnAux, int id, char name[],char carrera[], int clases, int horas)
{
    returnAux->id=id;
    strcpy(returnAux->name,name);
    strcpy(returnAux->carrera,carrera);
    returnAux->id=id;
    returnAux->horas=horas;

    return returnAux;
}

Materias* materias_new()
{
    Materias* returnAux = NULL;
    returnAux=(Materias*)malloc(sizeof(returnAux));
    return returnAux;
}

int get_nextId ()
{

    id++;
    return id-1;
}

void materias_alta(ArrayList* pListMaterias, Materias* auxMateria)
{
    int id;
    char name[51];
    char carrera[51];
    int clases;
    int horas;
    int isEmpty;

    printf("Ingrese el Id: ");
    scanf("%d",&id);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(name);
    printf("Ingrese la carrera: ");
    fflush(stdin);
    gets(carrera);
    printf("Ingrese cantidad de horas: ");
    scanf("%d",&horas);
    printf("Ingrese la cantidad de clases: ");
    scanf("%d",&clases);


    if (auxMateria != NULL)
    {
        auxMateria = materias_add(auxMateria, id, name, carrera, clases, horas);
        pListMaterias->add(pListMaterias, auxMateria);
    }
    //printf("Id: %d --Nombre:  %s\n",auxMateria->id, auxMateria->name);
    //printf("%d",pListMaterias->size);
}

int materias_getId(ArrayList* pListMaterias)
{
    int i;
    int indiceMaximo = 0;
    Materias* auxMateria;

    for (i=0; i<pListMaterias->size; i++)
    {
        auxMateria = pListMaterias->get(pListMaterias, i);
        if (auxMateria->id > indiceMaximo);
            indiceMaximo = auxMateria->id;
    }
    return indiceMaximo;
}
