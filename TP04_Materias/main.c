#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arraylist.h"
#include "materias.h"
#include "validaciones.h"

#define P 10
#define R 10
#define LIBRE -1
#define ALTA 1
#define BAJA 0
/*
• ArrayList* al_newArrayList(void);
• int al_add(ArrayList* pList,void* pElement);
• int al_deleteArrayList(ArrayList* pList);
• int al_len(ArrayList* pList);
• void* al_get(ArrayList* pList , int index);
• int al_contains(ArrayList* pList, void* pElement);
• int al_set(ArrayList* pList, int index,void* pElement);
• int al_remove(ArrayList* pList,int index);
• int al_clear(ArrayList* pList);
• int al_push(ArrayList* pList, int index, void* pElement);
• int al_indexOf(ArrayList* pList, void* pElement);
• int al_isEmpty(ArrayList* pList);
• void* al_pop(ArrayList* pList,int index);
*/

int main()
{
    ArrayList* pListMaterias;
    Materias* pMaterias;

    char seguir='s';
    int opcion=0;
    char buffer[4000];
    char menu[]= "1. Alta de materia.\n2. Modificar materia.\n3. Baja de materia.\n4. Alta Clase.\n5. Modificar clase.\n6. Baja de clase.\n7. Salir.\n";
    //char subMenu[]= "1. \n";
    char mensaje[]="Ingrese una opcion: ";
    pListMaterias = al_newArrayList();

    do
    {
        system("pause");
        system("cls");
        printf("%s",menu);
        if(getInt(mensaje,buffer))
        {
            opcion = atoi(buffer);

            switch (opcion)
            {
            case 1://ALTA MATERIA

                materias_alta(pListMaterias);
                break;

            case 2://MODIFICAR MATERIA
                system("cls");
                materias_list (pListMaterias);

                break;

            case 3://BAJA MATERIA
                system("cls");

                break;

            case 4://ALTA ALQUILER

                break;

            case 5: //MODIFICAR ALQUILER
                system("cls");
                break;


            case 6:

                system("pause");
                system("cls");


                break;

            case 7:
                seguir='n';
                break;

            }

        }
        else
        {
            seguir='n';
        }

    }
    while(seguir=='s');

    return 0;
}

