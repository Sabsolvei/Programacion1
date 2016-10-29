#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)


        1ER EJERCICIO
        1. Crear arrayList (newArrayList())
        2. Implementar Parser Employee:
            Leer archivo -> Por cada lectura:. Crear un empleado (new employee())
                                             . Agregarlo al arrayList
        3. Mostrar el arrayList

*****************************************************/


int main()
{

    ArrayList* pArrayListEmployee;
    pArrayListEmployee= al_newArrayList();
    FILE* pFile;

    parserEmployee(pFile , pArrayListEmployee);



    return(0);
}


