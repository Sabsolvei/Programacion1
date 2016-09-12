/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTOS 5
void main(void)
{
char texto1[20];
char texto2[20];
printf("\nIngrese un texto: ");
gets(texto1);
strcpy(texto2,texto1);
printf("Se ingreso:%s la copia es:%s",texto1,texto2);

}*/
/*
int main()
{
    int i,j;
    char nombre[ELEMENTOS][50] = {"Pedro","Carlos","Juan","Ernesto","Mario"};
    char apellido[ELEMENTOS][50]= {"Gomez","Fernandez","Paz","Perez","Lopez"};
    char auxiliar[50];

    for(i=0;i< ELEMENTOS-1;i++)
    {
        for(j=i+1;j<ELEMENTOS;j++)
        {
            if(strcmp(nombre[i],nombre[j])>0)
            {
            strcpy(auxiliar,nombre[i]);
            strcpy(nombre[i],nombre[j]);
            strcpy(nombre[j], auxiliar);
            strcpy(auxiliar,apellido[i]);
            strcpy(apellido[i],apellido[j]);
            strcpy(apellido[j], auxiliar);
            }
        }
    }

    printf("\n\nLista ordenada por nombres");
    for(i=0;i<ELEMENTOS;i++)
    {
    printf("\nNombre: %s - Apellido: %s",nombre[i],apellido[i]);
    }
return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
int main(void){
int legajo[MAX], legajoAux, i, j;
float salario[MAX], salarioAux;
char nombre[MAX][31], nombreAux[31];
for(i=0; i<MAX; i++)
{
system("cls");
printf("Ingrese el legajo del empleado: ");
scanf("%d", &legajo[i]);
printf("Ingrese el nombre del empleado: ");
fflush(stdin);
gets(nombre[i]);
printf("Ingrese el salario del empleado: ");
scanf("%f", &salario[i]);
}
for(i=0; i<MAX-1; i++)
{
for(j=i+1; j<MAX; j++)
{
if(salario[i] < salario[j])
{
strcpy(nombreAux, nombre[i]);
strcpy(nombre[i], nombre[j]);
strcpy(nombre[j], nombreAux);
legajoAux = legajo[i];
legajo[i] = legajo[j];
legajo[j] = legajoAux;
salarioAux = salario[i];
salario[i] = salario[j];
salario[j] = salarioAux;
}

if(salario[i] == salario[j]){
if(strcmp(nombre[i],nombre[j])>0){
strcpy(nombreAux, nombre[i]);
strcpy(nombre[i], nombre[j]);
strcpy(nombre[j], nombreAux);
legajoAux = legajo[i];
legajo[i] = legajo[j];
legajo[j] = legajoAux;
/*salarioAux = salario[i];
salario[i] = salario[j];
salario[j] = salarioAux;*/
}
}
}
}
system("cls");
printf("\nLegajo\tNombre\t\t\tSalario ");
for(i=0; i<MAX; i++)
{
printf("\n%d\t%s\t\t\t%.2f", legajo[i], nombre[i], salario[i]);
}
return 0;
}
