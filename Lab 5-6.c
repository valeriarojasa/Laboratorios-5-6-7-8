#include<stdio.h>
#include<stdlib.h>
#include "lab5_6.h"

int main(){

	FILE *fd = fopen("arbol.txt","r");
	
	if(fd == NULL){	
		return 1;
	 }
	
	char c = 0;	int opcion;
	arbol *unArbol = CrearArbol(fd,c);
	printf("->serie del archivo guardado\n\t\t\tMENU\n\n\n[1]->Mostrar altura\n[2]->Mostrar el arbol\n\nPresione cualquier otra tecla para finalizar la ejecucion\n\nRespuesta: ");
	scanf("%i",&opcion);
	int altura = Altura(unArbol);
	if(opcion == 1){
	system("cls");
	printf("\nAltura arbol: %i\n\n",altura);
	return main();
	}
	int tam = pow(2,altura+2)-1;
	if(opcion == 2){
	system("cls");
	char *Arreglo = CrearArbolEnArreglo(unArbol,tam);
	MuestraArbolEnTerminal(unArbol,tam,altura);
	return main();
	}
	if(opcion != 1||2){
		return 0;
	}
}
