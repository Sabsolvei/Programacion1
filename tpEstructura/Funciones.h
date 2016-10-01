typedef struct
{
    char menu[1000];
    char error[100];
    int desde;
    int hasta;

}eMenu;

typedef struct
{
    int idDirector;
    int cantidad;

}ePeliculaDirector;

typedef struct
{
    int idPelicula;
    char titulo[255];
    int idDirector;
    char nacionalidad[20];
    int idEstado;

}ePelicula;

typedef struct
{
    int idEstado;
    char Descripcion[50];

}eEstado;

typedef struct
{
    int dia, mes, anio;

}eFecha;

typedef struct
{
    int idDirector;
    char nombre[50];
    eFecha nacimiento;
    char nacionalidad[20];
    int idEstado;

}eDirector;


void hardcodeo (ePelicula pelicula[],eDirector director[]);
void inicializarEstado (ePelicula pelicula[],eDirector director[],int C,int estado);
int validarMenu (eMenu opciones);
int listar (ePelicula pelicula[],int C,int id);
void BuscarDirector (ePelicula pelicula[],eDirector director[],int C);
int encontrarEspacioLibre (ePelicula pelicula[],int C);
int altaPelicula (ePelicula pelicula[],eDirector director[], int pos,int estado, int idMayor,int D);

