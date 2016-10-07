typedef struct
{
    int id;
    int telefono;
    char nombre[50];
    char apellido[50];
    int isEmpty;

}ePersona;


typedef struct
{
    int idReclamo;
    int idAbonado;
    char motivo[20];
    char estado[20];
    int tiempoMinutos;
    int isEmpty;

}eLlamada;

typedef struct
{

    int idAbonado;
    int cantidad;


}eReclamoCantidad;

typedef struct
{

    char motivo[20];
    int cantidad;


}eMotivoCantidad;





void InicializarEstadoAbonado (ePersona abonado[],int P,int estado);
void InicializarEstadoReclamo (eLlamada reclamo[],int R,int estado);
void HardcodearAbonado (ePersona abonado[]);
void HardcodearReclamo (eLlamada reclamo[]);

int altaPersona (ePersona abonado[], int pos, int P, char buffer[]);
int encontrarEspacioLibre (ePersona abonado[],int P);
int buscarIdMayor (ePersona abonado[], int P, int *idMayor);
void ListarPersonas (ePersona abonado[], int P);
int buscarIdPersonaExistente (ePersona abonado[],int P,int idAbonado,int estado);
int ModificarPersona (ePersona abonado[],int pos,char buffer[]);
void EliminarPersona (ePersona abonado[],int estado, int pos);

void ListarEstados ();
void ListarMotivo ();
int buscarIdMayorReclamo (eLlamada reclamo[], int R, int *idMayor);
int altaReclamo (eLlamada reclamo[],ePersona abonado[], int pos, int R,int P, char buffer[]);
int buscarIdReclamoExistente (eLlamada reclamo[],int P,int idReclamo,int estado);
int ModificarReclamo (eLlamada reclamo[],int pos,char buffer[]);


int contarReclamos (eLlamada reclamo[],int R,int id);
void BuscarAbonadoConMasReclamos (ePersona abonado[],eLlamada reclamo[],eReclamoCantidad reclamoCant[], int P,int R);
void MostrarAbonadoConMasReclamos (eReclamoCantidad reclamoCantidad[], int R);
void reclamoMasRealizado (eLlamada reclamo[],int R);


int getInt(char mensaje[],char buffer[],int minimo, int maximo);
int verificarRangoInt(int auxiliar, int minimo, int maximo);
int esNumerico(char str[]);
int getString(char mensaje[],char buffer[], int longitud);
int VerificarRangoChar(char buffer[], int longitud);
int getStringLetras(char mensaje[], char buffer[], int longitud);
int esSoloLetras(char str[]);


