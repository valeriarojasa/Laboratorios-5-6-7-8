#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 3

typedef struct _nodo {
  int n;
  int hoja; //1 si es hoja, 0 si es un nodo interno
  char claves[2*T - 1];
  struct _nodo *hijo[2*T];
}ArbolB;

ArbolB *EscribirEnDisco(ArbolB *x);

ArbolB *CrearArbolB(){
   ArbolB *a = (ArbolB *)malloc(sizeof(ArbolB));
   a->n = 0;
   a->hoja = 1;
   return a;
}

void ImprimirArbolB (ArbolB *a, int nivel) {
   int i;

   for(i = 0; i < nivel; i++){
     printf(" ");
   }

   printf(" ");

   for(i = 0; i < a->n; i++){
      printf("%c", a->claves[i]);
   }

   printf("\n");

   for(i = 0; i <= a->n; i++){
      if(a->hoja == 0) {
         ImprimirArbolB(a->hijo[i], nivel+10);
      }
   }
}

void Buscar(ArbolB *x, int k){
  int i = 1;

  while(i < x->n && k > x->claves[i]){
    i++;
  }

  if(i <= x->n && k == x->claves[i]){
    printf("\n\nClave encontrada");
    return;
  }

  if(x->hoja == 1){
    printf("\n\nLa clave no se encuentra en el arbol");
    return;
  }
  else{
    Buscar(x->hijo[i],k);
  }

}
ArbolB *EscribirEnDisco(ArbolB *raiz){
  ArbolB *x = raiz;
  char *str = "D:\\Escritorio\\Laboratorios progra\\nodo\\nodos";
  char extension[] = ".txt";

  int i = strlen(str);
  char *direccion = malloc(i + 1 + 1 );
  strcpy(direccion, str);
  direccion[i] = x->claves[0];
  direccion[i + 1] = '\0';
  strcat(direccion,extension);

  FILE *fd;

  printf("%s",direccion);

  fd = fopen(direccion,"w");

  if(fd == NULL){
    printf("Error al crear el archivo");
  }
  else{
    fprintf(fd,"%i\n",x->n);
    fprintf(fd,"%i\n",x->hoja);
    for(i = 0; i < x->n; i++){
        fprintf(fd,"%c ",x->claves[i]);
    }
  }
return x;
}

char LeerEnDisco(ArbolB *raiz,int *i,int *j,char *band){
  ArbolB *x = raiz;
  char *str = "D:\\Escritorio\\Laboratorios progra\\nodo\\nodos",extension[] = ".txt",c;
  int cont;

  cont = strlen(str);
  char *direccion = malloc(cont + 2);
  strcpy(direccion, str);
  c = *i + '0';
  direccion[cont] = c;
  direccion[cont + 1] = '\0';
  strcat(direccion,extension);
  FILE *fd;

  printf("\n%s",direccion);

  fd = fopen(direccion,"r");

  if(fd == NULL){
    *i = *i + 1;
    *band = 'F';
    return c;
  }
  else{
    while(!feof(fd)){
        c = fgetc(fd);
        *i = *i + 1;
        *band = 'V';
        return c;
      }
    }

  fclose(fd);
}

ArbolB *DividirNodo (ArbolB *x, int i, ArbolB *y) {
    int j;
    ArbolB *z = CrearArbolB();
    z->n = T - 1;

    for(j = 0; j < T - 1; j++){
        z->claves[j] = y->claves[j+T];
    }

    if(y->hoja == 0){
        for(j = 0; j < T; j++){
            z->hijo[j] = y->hijo[j+T];
        }
    }

    y->n = T - 1;

    for(j = x->n; j >= i+1; j--){
        x->hijo[j+1] = x->hijo[j];
    }

    x->hijo[i+1] = z;

    for(j = x->n-1; j >= i; j--){
        x->claves[j+1] = x->claves[j];
    }

    x->claves[i] = y->claves[T-1];

    x->n++;

	EscribirEnDisco(x);
	EscribirEnDisco(y);
    EscribirEnDisco(z);

    
   return x;
}

ArbolB *Insertar_No_Lleno (ArbolB *x, char k) {
    int i = x->n-1;

    if(x->hoja == 1){
        while (i >= 0 && x->claves[i] > k){
            x->claves[i+1] = x->claves[i];
            i--;
        }
        x->claves[i+1] = k;
        x->n++;
    }
    else{
        while (i >= 0 && x->claves[i] > k){
            i--;
        }

        i = i + 1;

        if(x->hijo[i]->n == 2*T-1){
            x = DividirNodo(x, i, x->hijo[i]);
            if(k > x->claves[i]){
                i = i + 1;
            }
        }
        x->hijo[i] = Insertar_No_Lleno(x->hijo[i], k);
    }

    return x;
}

ArbolB *insertar (ArbolB *raiz, char claves) {
   ArbolB *r = raiz;
   if(r->n == (2*T - 1)) {
      ArbolB *s = CrearArbolB();
      s->hoja = 0;
      s->hijo[0] = r;
      s = DividirNodo (s, 0, r);
      s = Insertar_No_Lleno (s, claves);
      return s;
   }
   else {
      return Insertar_No_Lleno (r, claves);
   }
}

