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
    int idNacionalidad;
    int idEstado;

}ePelicula;

typedef struct
{
    int idEstado;
    char Descripcion[50];
}eEstado;

typedef struct
{
    int idDirector;
    char nombre[50];
    int idNacionalidad;
    int idEstado;

}eDirector;

typedef struct
{
    int idNacionalidad;
    char descripcion[50];
    int idEstado;

}eNacionalidad;

int validarMenu (eMenu opciones);
int hardcodeo (ePelicula pelicula[],eDirector director[], int C);
int listar (ePelicula pelicula[],int C,int id);
void BuscarDirector (ePelicula pelicula[],eDirector director[],int C);
