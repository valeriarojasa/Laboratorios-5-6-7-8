#include <stdio.h>
#include <stdlib.h>
#include "lab7_8.h"

int main(){
   ArbolB *a = CrearArbolB();
   char c,band;
   int i = 0,j = 0,opcion;
   printf("1. Insertar caracteres directo del programa\n2. Obtener Arbol desde archivos\nPresione cualquier otra letra para finalizar la ejecucion\nRespuesta: ");
   scanf("%i",&opcion);

   printf("\n\n");

   if(opcion == 1){
      a = insertar(a, '0');
      a = insertar(a, '1');
      a = insertar(a, '2');
      a = insertar(a, '3');
      a = insertar(a, '4');
      a = insertar(a, '5');
    }
    else{
      if(opcion == 2){
        while(j < 3){
          if(band == 'V'){
            c = LeerEnDisco(a,&i,&j,&band);
            a = insertar(a,c);
          }
          else{
            j++;
            band = 'V';
          }
        }
      }
      else{
        if(opcion != 1 && opcion != 2){
        	system("cls");
          printf("\n\nIntente nuevamente\n\n");
          return main();
        }
      }
    }

printf("\n\n");

  ImprimirArbolB(a,2);

  Buscar(a,'4');
  
	return 0;
}
