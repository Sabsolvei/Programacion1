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

}


Employee* employee_new(int id, char name[],char lastName[])
{
    Employee* returnAux = NULL;
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


