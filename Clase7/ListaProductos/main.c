#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define F 15

void main()
{
    char codigo[F][20], codigoAux[20], descripcion[F][50], descAux[50], aux;
    float precio[F], precioAux;
    int opcion, flag=0, i, j, acum=0;

    for(i=0;i<F;i++)
    {
        strcpy(codigo[i],"NULL");
    }
    do
    {
        printf("1. Altas\n2. Bajas\n3. Modificacion\n4. Listar\n5. Salir\n");
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

                printf("Ingrese codigo a dar de baja: \n");
                fflush(stdin);
                gets(codigoAux);
                aux='s';
                flag=0;
                i=0;
                for(i=0;i<F;i++)
                {
                    if(strcmp(codigoAux,codigo[i])==0)
                    {
                        printf("Desea eliminar el producto: %s. s/n :",codigo[i]);
                        scanf("%c",&aux);

                        if(aux=='s')
                        {
                            strcpy(codigo[i],"NULL");
                            flag=1;
                            printf("Producto eliminado exitosamente\n");
                            printf("\n");
                            break;
                        }
                        else
                        {
                            flag=1;
                            break;
                        }

                    }
                }
                if(flag==0)
                {
                    printf("El codigo ingresado no existe\n");
                }
            break;

            case 3:

                flag=0;
                aux='s';

                printf("Ingrese el codigo del producto a modificar: \n");
                fflush(stdin);
                gets(codigoAux);

                for(i=0;i<F;i++)
                {
                    if(strcmp(codigoAux,codigo[i])==0)
                    {
                        printf("Desea modificar el producto %s? s/n: ",codigoAux);
                        scanf("%c",&aux);

                        if(aux=='s')
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
                        printf("El codigo ingresado no existe\n");
                    }
                }
            break;

            case 4:
                printf("CODIGO\tDESCRIPCION\tPRECIO\n");
                for(i=0;i<F-1;i++)
                {
                    if(strcmp(codigo[i],"NULL")!=0)
                    {
                        for(j=i+1;j<F;j++)
                        {
                            if(strcmp(codigo[j],"NULL")!=0)
                            {
                                if(strcmp(descripcion[i],descripcion[j])>0)
                                {
                                    strcpy(codigoAux,codigo[i]);
                                    strcpy(codigo[i],codigo[j]);
                                    strcpy(codigo[j],codigoAux);

                                    strcpy(descAux,descripcion[i]);
                                    strcpy(descripcion[i],descripcion[j]);
                                    strcpy(descripcion[j],descAux);

                                    precioAux=precio[i];
                                    precio[i]=precio[j];
                                    precio[j]=precioAux;
                                }
                                else
                                {
                                    if(strcmp(descripcion[i],descripcion[j])==0)
                                    {
                                        if(precio[i]>precio[j])
                                        {
                                            strcpy(codigoAux,codigo[i]);
                                            strcpy(codigo[i],codigo[j]);
                                            strcpy(codigo[j],codigoAux);

                                            precioAux=precio[i];
                                            precio[i]=precio[j];
                                            precio[j]=precioAux;
                                        }
                                    }
                                }
                            }

                        }
                        printf("%s\t%s\t\t%.2f\n",codigo[i],descripcion[i],precio[i]);
                    }
                }// for i

                if(strcmp(codigo[i],"NULL")!=0)
                {
                    printf("%s\t%s\t\t%.2f\n",codigo[i],descripcion[i],precio[i]);
                }

            break;
        }//end switch
    } while(opcion!=5);
}
