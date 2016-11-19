//#ifndef _EMPLOYEE_H
//#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char carrera[51];
    int horas;
    int clases;
    int isEmpty;

} typedef Materias;


Materias* materias_add(Materias* returnAux, int id, char name[],char carrera[], int clases, int horas);
Materias* materias_new();
int get_nextId();
int materias_alta(ArrayList* pListMaterias);
int materias_getId(ArrayList* pListMaterias);
void materias_list (ArrayList* pListMaterias);
int materias_getData (Materias* auxMateria);
Materias* materias_saveData (int id, char name, char carrera, int horas, int clases);
