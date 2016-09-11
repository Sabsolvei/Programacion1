#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define E 4


int main()
{
    int opcion;
    long int dni[E];
    char nombreApellido[E][30];
    char domicilio[E][25];
    char localidad[E][20];
    int edad[E];
    char categoria[E];
    int hsTrabajadas [E];
    float sueldoNeto[E];
    int i=0;
    int j;
    int cont=0;

    for(i=0;i<E;i++)
    {
        dni[i]=-1;
    }

    do
    {
        printf("\n1. Altas.\n2. Modificacion.\n3. Listar.\n4. Buscar por localidad.\n5. Buscar empleados con maximo sueldo.\n6. Buscar empleados con minimo sueldo.\n7. Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                system("cls");

                printf("Ingrese numero de documento: ");
                scanf("%ld",&dni[cont]);
                system("cls");

                fflush(stdin);
                printf("Ingrese Nombre/s y Apellido/s: ");
                gets(nombreApellido[cont]);
                system("cls");

                fflush(stdin);
                printf("Ingrese domicilio: ");
                gets(domicilio[cont]);
                system("cls");

                fflush(stdin);
                printf("Ingrese localidad: ");
                gets(localidad[cont]);
                system("cls");

                fflush(stdin);
                printf("Ingrese edad: ");
                scanf("%d",&edad[cont]);
                system("cls");

                printf("Ingrese la categoria (A, B o C): ");
                categoria[cont]=toupper(getche());
                system("cls");

                fflush(stdin);
                printf("Ingrese cantidad de horas trabajadas: ");
                scanf("%d",&hsTrabajadas[cont]);
                system("cls");

               switch(categoria[cont])
                    {
                        case 'A':
                            sueldoNeto[cont]= hsTrabajadas[cont]*50;
                        break;

                        case 'B':
                            sueldoNeto[cont]= hsTrabajadas[cont]*30.5;
                        break;

                        case 'C':
                            sueldoNeto[cont]= hsTrabajadas[cont]*20.67;
                        break;
                    }
                system("cls");
                cont++;
                break;

            case 3:

                for(i=0;i<E;i++)
                {
                    if(dni[i]!=-1)
                    {
                        printf("%ld\t%s\t%d\t%s\t%s\t%c\t%d\t%.2f\n",dni[i],nombreApellido[i],edad[i],localidad[i],domicilio[i],categoria[i],hsTrabajadas[i],sueldoNeto[i]);

                    }
                    system("pause");


                }

            break;

        }
    }
    while(opcion!=7);


















    return 0;
}
