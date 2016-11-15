#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "materias.h"

int main()
{
    ArrayList* pListMaterias;
    Materias* pMaterias;

    pListMaterias = al_newArrayList();
    pMaterias = materias_new();
    materias_alta(pListMaterias, pMaterias);

    return 0;
}
