#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"



int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    printf("ID:%4d Name: %-15s Last Name: %15s\n",
               this->id,
               this->name,
               this->lastName);
}

void employee_printAll(ArrayList* this)
{
    int i=0;
    Employee* e;
    for (i=0; i<this->len(this); i++)
    {
        e= (Employee*)al_get(this, i);
        employee_print(e);
    }
}


Employee* employee_new(int id, char name[],char lastName[])
{
    Employee* returnAux = NULL;

    returnAux=(Employee*)malloc(sizeof(Employee));
    returnAux->id=id;
    strcpy(returnAux->name,name);
    strcpy(returnAux->lastName,lastName);

    return returnAux;
}

void employee_delete(Employee* this)
{

}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}

Employee* employee_altaEmpleado()
{
    char id[50];
    char name[50];
    char lastName[50];
Employee* e;

    printf("Ingrese el Id: ");
    fflush(stdin);
    gets(id);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(name);
    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(lastName);

   e= employee_new(atoi(id),name,lastName);
    e->isEmpty=1;

    return e;

}




