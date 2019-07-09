#include <stdio.h>
#include <stdlib.h>
#include "lab7_8.h"

int main(){
   ArbolB *a = CrearArbolB(); int opcion;

   a = insertar(a, '0');
   a = insertar(a, '1');
   a = insertar(a, '2');
   a = insertar(a, '3');
   a = insertar(a, '4');
   a = insertar(a, '5');
   a = insertar(a, '6');
   a = insertar(a, '7');
   a = insertar(a, '8');
   a = insertar(a, '9');

printf("\t\t\tMENU\n\n[1]->Imprimir arbol B\n[2]->Buscar clave en arbol B\nPresione cualquier otra tecla para finalizar la ejecucion\nRespuesta: ");
scanf("%i",&opcion);

if(opcion==1){
	system("cls");
    ImprimirArbolB(a,2);
	return main();
	}
if(opcion == 2){
   system("cls");
   Buscar(a,'5');
   return main();
	}
if(opcion != 1 || 2){
   return 0;
   }
}
