typedef struct
{
    int idDir;
    int cantidad;

}ePeliculaDirector;


typedef struct
{
    char opciones[200];
    char error[100];
    int desde;
    int hasta;
}eMenu;

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

int menu (eMenu opciones);
int hardcodeo (ePelicula pelicula[],eDirector director[]);
