typedef struct
{
    int identificador;
    char nombre[50];
    int edad;
    int tipo;
    int comio;
    int estaVivo;

}eMascota;

void cargarMascotas (eMascota m[]);
void mostrarMascotas (eMascota cS[]);
void mostrarMascota (eMascota c);
