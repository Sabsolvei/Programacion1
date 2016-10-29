#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre (compara 2 empleados, devuelve resultado,
                               y con ese result se lo paso como puntero a la funcion SORT

        4. Agregar un elemento
        5. Eliminar un elemento: busco dentro del arrya por Id, devuelve el puntero a empleado hacia donde apunta el
                            empleado de ese id.
                            puntero= buscarxId -> ese puntero se lo paso al indexOf
                            IndexOf(aList, void*)-> devuelve el indice del empleado que pasè. Ese indice se lo paso al pop.
                            pop(alist,indice)=levanta del array lo q quiero eliminar, lo elimina y devuelve ese elemento
                               entonces se puede mostrar lo que eliminò
        6. Listar Empleados (Desde/Hasta)
                               subList->desde: indice desde donde muestra, incluido. hasta donde, excluido. (se puede preg
                              al usuario que quiere ver, ej top 5)


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
    Employee* empleado;
    pArrayListEmployee= al_newArrayList();
    FILE* pFile;

    parserEmployee(pFile, pArrayListEmployee);
    employee_printAll(pArrayListEmployee);

    system("pause");
    system("cls");
    empleado= employee_altaEmpleado();
    employee_print(empleado);
    system("pause");
    pArrayListEmployee->add(pArrayListEmployee,empleado);
    employee_printAll(pArrayListEmployee);


    return(0);
}


