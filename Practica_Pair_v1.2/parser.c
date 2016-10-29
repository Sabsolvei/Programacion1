#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int id;
    char name[51];
    char lastName[51];
    char isEmpty[10];
    int i=0;
    pFile = fopen ("data.csv", "r");

    if(pFile==NULL)
        exit(0);


    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

        if(i==0)
        {
            i++;
            continue;
        }
        Employee* empleado;
        empleado= employee_new(id,name,lastName);
        if(strcmp(isEmpty,"false"))
        {
            empleado->isEmpty=0;
        }
        else
        {
            empleado->isEmpty=1;
        }

        pArrayListEmployee->al_add(* pArrayListEmployee,* empleado);
        for (i=0; i<pArrayListEmployee->len(pArrayListEmployee); i++)
        {
            if(pArrayListEmployee->isEmpty == 0)
            {

                printf("ID:%4d Name: %-15s Last Name: %15s\n" ,
                       empleado->id;
                       empleado->name;
                       empleado->lastName;
                       empleado->isEmpty;
            }

        }


    }

    fclose(pFile);

    return 0;
}
