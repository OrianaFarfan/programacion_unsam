/*

3. Para una lista doblemente enlazada, escribir una función para localizar un elemento:
    a. Si se lo encuentra mostrar su contenido y devolver 1.
    b. Si no se encuentra devolver 0.

*/

# include <stdio.h>
# include <stdlib.h>


typedef struct nodo_d{
  int dato;
  struct nodo_d *sig, *ant;
}nodo_d;


typedef struct lista{
  nodo_d *prim, *ult;
}lista;


lista ingresoFIFO(lista l, int dato){
  nodo_d *nuevo = NULL;
  nuevo = (nodo_d*) malloc (sizeof(nodo_d));
  nuevo->sig = NULL;
  nuevo->ant = l.ult;
  nuevo->dato = dato;
  //printf("entra a fifo \n"); //--> si no lo pongo, no funciona, por qué!?
  if(l.ult == NULL){
    l.prim = nuevo;
  }
  else{
    l.ult->sig = nuevo;
  }
  l.ult = nuevo;
  return l;
}


lista destruir(lista l){
  nodo_d *p = l.prim, *aux=NULL;
  while(p!=NULL){
    aux = p;
    p = p->sig;
    free(aux);
  }
  l.prim = NULL;
  l.ult = NULL;
  return l;
}

void mostrar(lista l){
  nodo_d *p = l.prim;

  printf("lista : \n");
  while(p!=NULL){
    printf("--> %d",p->dato);
    p = p->sig;
  }
  printf("\n");
  return;
}

int  buscarEl(lista l, int elemento){
  nodo_d *p = l.prim; //Se inicializa con el puntero q apunta al primer elemento

  int pos = 0;
  int encuentro =0;
  int ciclos = 0; // comentar si hago op1

  while(p!=NULL){ //MIENTRAS P NO SEA NULO O SEA EL FINAL
    ciclos++; // comentar si hago op1 ---CUENTA LOS CICLOS
    if(p->dato == elemento){ //SI EL DATO DEL NODO APUNTADO CON EL PUNTERO ES IGUAL AL ELEMENTO QUE BUSCO
      encuentro=1; //SE DEFINE A ENCUENTRO CON 1
      printf("lo encontre!! \n");
      pos = ciclos; // comentar si hago op1 //SE DEFINE A LA POSICION CON LAS VECES QUE SE REALIZO LA BUSQUEDA DEL NODO
    }
    p = p->sig; //SI NO PASA LO DEL IF, PASO AL SIGUIENTE NODO
  }
  return pos; // vale 0 si no lo encuentro // devuelvo 'encuentro' si hago op1
}


void main(){
  int elemento = 1;
  int encuentra =0;
  lista l;

  // INICIALIZAR LA LISTAAAA --> SINO, NO FUNCIONA BIEN
  l.prim = NULL;
  l.ult = NULL;

  while(elemento!=0){ //ELEMENTO INICIALIZADO CON 1
    printf("ingrese un elemento : (dejar de ingresar con 0) \n");
    scanf("%d", &elemento);
    if(elemento!=0){
      printf("agrego el elemento \n");
      l = ingresoFIFO(l, elemento);
    }
  }
  mostrar(l);

  // si sale del while --> elemento = 0
  printf("que elemento desea buscar ? : \n");
  scanf("%d", &elemento);
  encuentra = buscarEl(l, elemento);
  if(encuentra){
    printf("el elemento ha sido encontrado :) \n");
    // opcion 2
    printf("y su posicion en la lista es la pos %d ", encuentra); // comentar si hago op1
  }
  else{
    printf("el elemento no ha sido encontrado :( \n");
  }

  l = destruir(l);
  return;
}
