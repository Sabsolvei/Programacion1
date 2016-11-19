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
    /*
        char buf [5];
    scanf("%5s", buf);
    printf("%s", buf);
    */
    ArrayList* pListMaterias;
    Materias* pMaterias;

    char seguir='s';
    int opcion=0;
    char buffer[4000];
    char menu[]= "1. Alta de materia.\n2. Modificar materia.\n3. Baja de materia.\n4. Alta Clase.\n5. Modificar clase.\n6. Baja de clase.\n7. Guardar y Salir.\n";
//char subMenu[]= "1. \n";
    char mensaje[]="Ingrese una opcion: ";
    pListMaterias = al_newArrayList();
/*
    FILE *f;
    int i;
    int cantidad;

    pMaterias* m0 = materias_saveData (1, "Programacion","TP", 116, 28)
    pMaterias* m1 = materias_saveData (2, "Laboratorio","TP", 116, 28);
    pMaterias* m2 = materias_saveData (3, "Matematica","TP", 87, 28);
    pMaterias* m3 = materias_saveData (4, "Ingles","TP", 28, 14);
    pMaterias* m4 = materias_saveData (5, "SPD","TP", 46, 14);

    pListMaterias->add(pListMaterias, m0);
    pListMaterias->add(pListMaterias, m1);
    pListMaterias->add(pListMaterias, m2);
    pListMaterias->add(pListMaterias, m3);
    pListMaterias->add(pListMaterias, m4);

    f = fopen("Materias.dat", "wb");
    if(f != NULL)
    {
        cantidad = pListMaterias->len(pListMaterias);
        for(i=0; i< cantidad; i++)
        {
            fwrite((Materias*)pListMaterias->get(pListMaterias, i), sizeof(Materias), 1, f);
        }
        fclose(f);
        printf("Archivo guardado con exito\n\n");
    }

    ArrayList *lista2 = al_newArrayList();

    f = fopen("Materias.dat", "rb");
    if(f!=NULL)
    {
        while(!feof(f))
        {
            aux = (Materias*)malloc(sizeof(Materias));
            if(aux !=NULL)
            {
                if(fread(aux, sizeof(Materias), 1, f)==1)
                    lista2->add(lista2, aux);
            }
        }
        fclose(f);

        printf("Archivo levantado con exito\n\n");
    }

    printf("Muestro empleados\n\n");

    for(i=0; i<lista2->len(lista2); i++)
    {
        printEmployee(lista2->get(lista2,i));
    }

    return 0;
    }*/

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

