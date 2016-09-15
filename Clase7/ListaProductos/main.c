#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define F 15

void main()
{
    char codigo[F][20], codigoAux[10], descripcion[F][50];
    float precio[F];
    int opcion, flag=0, i, acum=0;

    for(i=0;i<F;i++)
    {
        strcpy(codigo[i],"-1");
    }
    do
    {
        printf("1. Altas\n2. Bajas\n3.Modificacion\n4.Listar\n5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                printf("Ingrese codigo: \n");
                fflush(stdin);
                gets(codigo[acum]);

                printf("Ingrese descripcion: \n");
                fflush(stdin);
                gets(descripcion[acum]);

                printf("Ingrese precio: \n");
                fflush(stdin);
                scanf("%f",&precio[acum]);

                acum++;

            break;
            case 2:

                printf("Ingrese codigo ");
                gets(codigoAux);
                flag=0;
                for(i=0;i<F;i++)
                {
                    if(codigo[i]==codigoAux)
                    {
                        strcpy(codigo[i],"-1");
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("El codigo ingresado no existe");
                }
            break;

            case 3:
                printf("Ingrese el codigo del producto a modificar: \n");
                gets(codigoAux);
                flag=0;
                for(i=0;i<F;i++)
                {
                    if(codigoAux==codigo[i])
                    {
                        printf("Ingrese el codigo nuevo: \n");
                        fflush(stdin);
                        gets(codigo[i]);

                        printf("Ingrese la descripcion nueva: \n");
                        fflush(stdin);
                        gets(descripcion[i]);

                        printf("Ingrese el precio nuevo: \n");
                        fflush(stdin);
                        scanf("%f",&precio[i]);

                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("El codigo ingresado no existe");
                }
            break;

            case 4:
                for(i=0;i<F;i++)
                {
                    if((strcmp(codigo[i],"-1"))==0)
                    {
                        printf("%s\t%s\t%f\n",codigo[i],descripcion[i],precio[i]);
                    }
                }
            break;
        }//end switch
    }while(opcion!=5);

}
