#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define N 3
#define Perro 1
#define Gato 2
#define Reptil 3
#define Pez 4

int main()
{
   eMascota mascota[N];
   cargarMascotas(mascota);
   mostrarMascotas (mascota);

}










/*MASCOTA:
Identificador
nombre
edad
tipo (1.perro 2.Gato 3.Reptil 4.Pez)
comio (en ppio todos comieron: 0)
esta vivo (en ppio todos vivos: 1)

FUNCIONES
1. Cargar mascotas (ninguno comio y todos vivos).
2. Mostrar.

int main()
{
    printf("Hello world!\n");
    return 0;
}
*/




