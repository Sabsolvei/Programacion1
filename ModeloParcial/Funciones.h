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

typedef struct {

    char buffer[4000];
    int minimo;
    int maximo;
    int longitud;

}eValidar;


void inicializarPelicula(ePelicula pelicula[]);
void inicializarDirector(eDirector director[]);
void inicializarEstadoPelicula (ePelicula pelicula[],int C,int estado);
void inicializarEstadoDirector (eDirector director[],int D,int estado);

int contarPeliculas (ePelicula pelicula[],int C,int id);
void BuscarDirConMasPelis(ePelicula pelicula[],eDirector director[],ePeliculaCantidad peliculaCantidad[],int C,int D);
void MostrarDirConMasPelis (ePeliculaCantidad peliculaCantidad[], int D);
int encontrarEspacioLibrePelicula (ePelicula pelicula[],int C);
int encontrarEspacioLibreDirector (eDirector director[],int C);

int altaPelicula (ePelicula pelicula[], eDirector director[],int pos,int C, int D, char buffer[]);
int buscarIdMayorPelicula (ePelicula pelicula[], int C, int *idMayor);
int buscarIdMayorDirector (eDirector director[], int D, int *idMayor);
int verificarNombre (eDirector director[], int D, char nombreAux[]);
int modificarPelicula (ePelicula pelicula[],int pos,char buffer[]);

void listarPeliculas (ePelicula pelicula[], int C);
void ordenarPelicula (ePelicula pelicula[], int C);
void listarDirectores (eDirector director[], int D);
int buscarIdPelicula (ePelicula pelicula[],int C,int idPelicula);
void eliminarPelicula (ePelicula pelicula[],int baja, int pos);
int altaDirector (eDirector director[], ePelicula pelicula[],int pos,int C, int D, char buffer[]);

int getInt(char mensaje[],char buffer[],int minimo, int maximo);


/**
 * Valida el dni ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario.
 * @param rango de numeros permitidos.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int verificarDNI(eValidar cadena);

/**
 * Valida el dato char ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario y cantidad de caracteres permitidos.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int validarRango(eValidar cadena);

/**
 * Valida el dato char ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int validarStr(eValidar cadena);

/**
 * Valida el dato int ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario.
 * @param rango de numeros permitidos.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int validarRangoEdad(eValidar cadena);

