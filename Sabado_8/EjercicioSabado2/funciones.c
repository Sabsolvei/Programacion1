#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define N 3

void cargarAlumnos (Alumno c[])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("Ingrese Legajo: ");
        scanf("%d",&c[i].legajo);

        fflush(stdin);
        printf("Ingrese Nombre: ");
        gets(c[i].nombre);

        printf("Ingrese nota: ");
        scanf("%f",&c[i].nota);
    }
}

void mostrarAlumno (Alumno m)
{
    printf("%d\t %s\t %.2f\n", m.legajo, m.nombre, m.nota);
}

void mostrarAlumnos(Alumno M[])
{
    int i;
    for(i=0;i<N;i++)
    {
        mostrarAlumno(M[i]);
    }
}

