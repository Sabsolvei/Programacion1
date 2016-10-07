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


void inicializarEstadoPelicula (ePelicula pelicula[],int C,int estado);
void inicializarEstadoDirector (eDirector director[],int D,int estado);
void inicializarPelicula(ePelicula pelicula[]);
void inicializarDirector(eDirector director[]);



int altaPelicula (ePelicula pelicula[], eDirector director[],int pos,int C, int D, char buffer[]);
int encontrarEspacioLibrePelicula (ePelicula pelicula[],int C);
int buscarIdMayorPelicula (ePelicula pelicula[], int C, int *idMayor);
int modificarPelicula (ePelicula pelicula[],int pos,char buffer[]);
void eliminarPelicula (ePelicula pelicula[],int baja, int pos);
int buscarIdPeliExistente (ePelicula pelicula[],int C,int idPelicula);
void listarPeliculas (ePelicula pelicula[], int C);
void ordenarPelicula (ePelicula pelicula[], int C);



int altaDirector (eDirector director[], ePelicula pelicula[],int pos,int C, int D, char buffer[]);
int encontrarEspacioLibreDirector (eDirector director[],int C);
int buscarIdMayorDirector (eDirector director[], int D, int *idMayor);
int verificarNombre (eDirector director[], int D, char nombreAux[]);
void eliminarDirector (eDirector director[],int baja, int pos);
int buscarIdDirExistente (eDirector director[],int D,char idDirector[],int estado);
void listarDirectores (eDirector director[], int D);



int contarPeliculas (ePelicula pelicula[],int C,int id);
void BuscarDirConMasPelis(ePelicula pelicula[],eDirector director[],ePeliculaCantidad peliculaCantidad[],int C,int D);
void MostrarDirConMasPelis (ePeliculaCantidad peliculaCantidad[], int D);



int getInt(char mensaje[],char buffer[],int minimo, int maximo);
int verificarRangoInt(int auxiliar, int minimo, int maximo);
int esNumerico(char str[]);
int getString(char mensaje[],char buffer[], int longitud);
int getStringLetras(char mensaje[], char buffer[], int longitud);
int esSoloLetras(char str[]);



