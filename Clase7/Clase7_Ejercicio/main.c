#include <stdio.h>
#include <stdlib.h>
#define P 2

int main()
{
    char nombre[P][50];
    char apellido[P][50];
    int legajo[P];
    int opcion=0;
    int cont=0;
    int i=0;

    for(i=0;i<P;i++)
    {
        legajo[i]=-1;
    }
    do
    {
        printf("1. ALTAS.\n2. BAJAS\n3. MODIFICACIONES\n4. LISTAR\n5. SALIR\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                fflush(stdin);
                printf("Ingrese nombre: ");
                gets(nombre[cont]);

                system("cls");
                fflush(stdin);
                printf("Ingrese apellido: ");
                gets(apellido[cont]);

                system("cls");
                fflush(stdin);
                printf("Ingrese Legajo: ");
                scanf("%d",legajo[cont]);

                cont++;
                break;
            case 2:
            break;
            case 3:
            break;
            case 4:
                for(i=0;i<P;i++)
                {
                    if(legajo[i]!=-1)
                    {
                        printf("%s\t,%s\t,%d\n",nombre,apellido,legajo);
                    }
                }
            break;
        }
    }
    while(opcion!=5);




    return 0;
}
