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

}ePeliculaCantidad;

typedef struct
{
    int idPelicula;
    char titulo[255];
    int idDirector;
    char nacionalidad[20];
    int anio;
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


void inicializarPelicula(ePelicula pelicula[]);
void inicializarDirector(eDirector director[]);
void inicializarEstadoPelicula (ePelicula pelicula[],int C,int estado);
void inicializarEstadoDirector (eDirector director[],int D,int estado);
int validarMenu (eMenu opciones);
int contarPeliculas (ePelicula pelicula[],int C,int id);
void BuscarDirConMasPelis(ePelicula pelicula[],eDirector director[],ePeliculaCantidad peliculaCantidad[],int C,int D);
void MostrarDirConMasPelis (ePeliculaCantidad peliculaCantidad[], int D);
int encontrarEspacioLibrePelicula (ePelicula pelicula[],int C);
int encontrarEspacioLibreDirector (eDirector director[],int C);
int altaPelicula (ePelicula pelicula[],eDirector director[], int pos,int estado, int idMayor,int C);
int verificarNombre (eDirector director[], int D, char nombreAux[]);
void modificarPelicula (ePelicula pelicula[],int Pos);
void listarPeliculas (ePelicula pelicula[], int C);
void listarDirectores (eDirector director[], int D);
int buscarIdPelicula (ePelicula pelicula[],int C,int idPelicula);
void eliminarPelicula (ePelicula pelicula[],int baja, int pos);
int altaDirector (eDirector director[],int pos,int estado, int idDMayor, int D);
