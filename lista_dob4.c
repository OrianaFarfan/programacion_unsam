/*
==> no me deja seguir agregando nodos desps de eliminar

4.  Sistema de info de prod qcos del INS

// entero --> 4 bytes
// flotante -> 8 bytes
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registros{
  short codigo; // tiene que ser un int de 2 bytes ( un int normal tiene 4 )
  char nombre[20];
  float precio;
  double stock;
}regs;

typedef struct nodo_doble{
  regs registro;
  struct nodo_doble *sig, *ant;
}nodo_d;

typedef struct lista{
  nodo_d *prim, *ult;
}lista;


int menu(){
  int opcion =0;
  printf("0. OPCION EXTRA: crear archivo ingresando valores a mano \n");
  // primero escribir un archivo binario de registros --> para leer de prueba
  printf("1. leer archivo binario de registros y cargar en una lista tipo FIFO \n"); // leo un vector con estructuras tipo registros ( con todos esos campos )
  printf("2. agregar un producto ingresado por teclado al final de la lista 'maestra' \n"); // por FIFO --> agrego un nodo a la lista
  printf("3. eliminar un elemento de la lista 'maestra' dado su codigo \n"); // eliminar un nodo
  printf("4. generar una version ordenada de la lista, pudiendo ser el orden por cualq de los 4 campos segun la elec del usuario \n");
  printf("5. mostrar la lista dando la opcion de hacerlo con la maestra/ordenada en sentido directo/inverso \n"); // la lista que esté, ordenarla desde p=l.prim o desde l.ult
  printf("6. sobreescribir en archivo con los datos de la lista 'maestra' \n"); // pongo rb y vuelvo a escribir vector de estructuras --> hasta que p==NULL (ya no tenga mas nodos) -> puedo usar una función de contar la CantNodos
  printf("7. salir \n");
  scanf("%d", &opcion);
  return opcion;
}


// ACÁ INSERTO COMO FIFO NODOS CON REGISTROS A LA LISTA MAESTRA
lista insertar_FIFO(lista l,regs registro){ //Como siempreeeeeeeeeeeeeeeeee
  nodo_d *nuevo = NULL;
  nuevo = (nodo_d*) malloc(sizeof(nodo_d));
  nuevo->sig = NULL;
  nuevo->ant = l.ult;
  nuevo->registro = registro;

  if(l.ult == NULL){ // lista vacía
    l.prim = nuevo;
  }
  else{ // lista NO vacía
    l.ult->sig = nuevo;
  }
  l.ult = nuevo;

  return l;
}

void mostrarLista(lista l){
  nodo_d *p = l.prim; //inicializo el puntero con el puntero que apunta al primer nodo
  int cant =0;

  if(p==NULL) printf("la lista esta vacia, no hay nada que mostrar \n");
  //sino:
  while(p!=NULL){
    cant++;
    printf("nodo %d : \n", cant);
    printf("codigo : %hd - ", p->registro.codigo); //p es del tipo nodo_d, el cual tiene como campo a registro que es una estructura con esos campos (codigo nombre precio stock)
    printf("nombre : %s - ", p->registro.nombre);   //registro es como dato.
    printf("precio : %f - ", p->registro.precio);
    printf("stock : %lf \n", p->registro.stock);
    p = p->sig;
  }
  return;
}

//Lo mismo que antes pero a p le asigno el puntero que apunta al ultimo nodo
void mostrarListaAlReves(lista l){
  nodo_d *p =l.ult;
  //int cant =cantNodos(l);
  if(p==NULL) printf("la lista esta vacia, no hay nada que mostrar \n");
  while(p!=NULL){
    //cant--;
    //printf("nodo %d : \n", cant);
    printf("codigo : %hd - ", p->registro.codigo);
    printf("nombre : %s - ", p->registro.nombre);
    printf("precio : %f - ", p->registro.precio);
    printf("stock : %lf \n", p->registro.stock);
    p = p->ant;
  }
  return;
}

// función para cargar una estructura
//-----regs es la estructura ---------
regs ingresoRegistro(void){
  regs registro;
  printf("Ingrese el codigo del producto : \n");
  scanf("%hd", &registro.codigo);
  printf("Ingrese el nombre del producto : \n");
  scanf("%s",registro.nombre);
  printf("Ingrese el precio por unidad de masa : \n");
  scanf("%f", &registro.precio);
  printf("Ingrese el stock en gramos : \n");
  scanf("%lf", &registro.stock);
  return registro;
}

void CargarArch(){
  FILE *f;
  int seguir =1;
  regs registro;

  f = fopen("lista_maestra.dat", "wb");
  if(f==NULL){
      printf("\nError al crear archivo\n");
      return;
  }
  while(seguir==1){
    printf("si desea ingresar un nuevo registro ingrese 1, sino ingrese 0 \n");
    scanf("%d", &seguir);
    if(seguir==1){
      registro = ingresoRegistro();
      fwrite(&registro, sizeof(registro),1,f); // va escribiendo de a 1 registro
    }
  }
  if(fclose(f)!=0){
    printf("error al cerrar el archivo \n");
    return ;
  }
  return ;
}


lista eliminarNodo(lista l, short codigo){
  nodo_d* p = l.prim; //nodo inicial
  nodo_d *aux;

  if(p!=NULL){

    // caso 1: el primer dato es del nodo que deseo eliminar
    if(p->registro.codigo==codigo){ //En este caso estoy comparando el codigo del primer nodo
      l.prim = p->sig; //ahora el puntero a primer nodo esta apuntando al nodo siguiente del nodo inicial
      free(p); //borro al nodo inicial
      printf("primer registro eliminado \n");
    }

    else{
      while(p->sig != NULL && p->sig->registro.codigo != codigo){ //si el siguiente nodo no es nulo y el ese nodo siguiente no tiene como valor de codigo el que se requiere
        p=p->sig;                                                    //sigo al siguiente nodo
      }
     // sale del while o cuando llega al final, o cuando el nodo siguiente es el q quiero eliminar
     if(p->sig!=NULL){ // si salió porque el siguiente nodo es el q quiero eliminar
        aux = p->sig; // el nodo siguiente es el que quiero eliminar
        p->sig = aux->sig; // el p->sig apunta al p->sig->sig //AHORA P->SIG ES EL SIGUIENTE QUE TIENE EL QUE SE QUIERE ELIMINAR QUE ESTA GUARDADO EN AUX

        if(aux->sig!=NULL){ //SI EL SIGUIENTE DEL QUE QUIERO ELIMINAR NO ES NULL
          aux->sig->ant = p; // apunto el p->sig->sig ->ANT tambn al p //EL NODO SIGUIENTE DEL QUE QUIERO ELIMINAR --> SU PUNTERO ANT VA A APUNTAR A P (EL ANTERIOR A AUX)
        }
        free(aux);// ahora ya puedo eliminar a aux
        printf("el registro ha sido eliminado \n");
    }

    else{
      printf("el registro no se encuentra en la lista \n");
    }
    }
  }
  else{
    printf("la lista esta VACIA, no hay nada q eliminar \n");
  }
  return l;
}

lista destruirLista(lista l){
  nodo_d *p = l.prim;
  nodo_d *aux ;
  while(p!=NULL){
    aux = p;
    p=p->sig;
    free(aux);
  }
  printf("lista destruida \n");
  l.prim = NULL;
  l.ult =NULL;
  return l;
}

lista insertar_LIFO(lista l, regs registro){
  nodo_d* nuevo=NULL;

  nuevo=(nodo_d*) malloc (sizeof(nodo_d));
  nuevo->registro = registro;
  nuevo->sig = l.prim;
  nuevo-> ant = NULL;
  if(l.prim== NULL){
    l.ult = nuevo;
  }
  else{
    l.prim->ant=nuevo;
  }
  l.prim=nuevo;
  return l;
}

// ORDENO POR CODIGO

lista ordenarPorCodigo(lista l){
  lista ord;
  ord.prim = NULL;
  ord.ult = NULL;
  nodo_d *p = l.prim;

  while(p!=NULL){
    ord = ingreso_ordenadoPorCodigo(ord,p->registro); // voy ingresando los registros
    p = p->sig;
  }
  return ord;
}

lista ingreso_ordenadoPorCodigo(lista l, regs registro){ // menor a mayor
  nodo_d *nuevo = NULL;
  nuevo = (nodo_d*) malloc (sizeof(nodo_d)); //ARMO ESPACIO PARA EL NUEVO NODO
  nuevo->registro = registro; //GRABO EL REGISTRO EN EL CAMPO DE REGISTRO DE NEUVO

  if(l.prim == NULL || l.prim -> registro.codigo > registro.codigo){ //SI LA LISTA ESTA VACIA O SI EL CODIGO DE REGISTRO INGRESADO ES MENOR QUE EL DEL PRIMER NODO
    l = insertar_LIFO(l, registro); //SE INSERTA EL REGISTRO QUE TIENE COMO CODIGO MENOR AL DEL PRIMER NODO EN LA LISTA DE FORMA LIFO
  }

  else{
    nodo_d *p; //nodo_d tiene campo registro y los nodos de sig y ant
    p = l.prim; //inicializo con el puntero del primer nodo
    while(p->sig !=NULL && p->sig->registro.codigo <= registro.codigo){ // voy recorriendo la lista
      p=p->sig;
    }
    // sale o: porque estoy en l.ult o porque p->sig->dato > dato
    // voy a meter a 'nuevo' entre p y p->sig
    nuevo->sig = p->sig; //el nuevo->sig va a ser al nodo siguiente de p
    p->sig = nuevo; //es como que queda p / nuevo / p->sig
    nuevo->ant = p; //es nuevo lo que quiero encajar


    if(nuevo->sig != NULL){ // o sea, salió por la segunda cond (esto era a lo q apuntaba p->sig)
      nuevo->sig->ant =nuevo; //y el nodo siguiente al nuevo, se hace que ant apunte a ese nuevo (conexion que faltaba)
    }

    else{ // salió por q p->sig ==NULL
      printf("es el ult elemento ahora \n");
      l.ult = nuevo;
    }
  }
  return l;
}

// ORDENO POR CADENAS
lista ordenarPorCadenas(lista l){
  lista ord;
  ord.prim = NULL;
  ord.ult = NULL;
  nodo_d *p = l.prim;

  while(p!=NULL){
    ord = ingreso_ordenadoPorCadenas(ord,p->registro); // voy ingresando los registros
    p = p->sig;
  }
  return ord;
}

lista ingreso_ordenadoPorCadenas(lista l, regs registro){
  nodo_d *nuevo = NULL;
  nuevo = (nodo_d*) malloc (sizeof(nodo_d));
  nuevo->registro = registro;

  if(l.prim == NULL || (strcmp(l.prim->registro.nombre, registro.nombre) > 0) ){ // la primera va desps
    l = insertar_LIFO(l, registro);
  }
  else{
    nodo_d *p;
    p = l.prim;

    while(p->sig !=NULL &&    ( strcmp(p->sig->registro.nombre, registro.nombre) <= 0)){ // mientras la primera vaya antes se repite
            //si da menor a cero --> significa que el primer nodo va despues en el diccionario , o sea que registro.nombre va primero
      p=p->sig;
    }
    // sale o: porque estoy en l.ult o porque p->sig->dato > dato
    // voy a meter a 'nuevo' entre p y p->sig
    nuevo->sig = p->sig;
    p->sig = nuevo;
    nuevo->ant = p;

    if(nuevo->sig != NULL){ // o sea, salió por la segunda cond (esto era a lo q apuntaba p->sig)
      nuevo->sig->ant =nuevo;
    }
    else{ // salió por q p->sig ==NULL
      printf("es el ult elemento ahora \n");
      l.ult = nuevo;
    }
  }
  return l;
}


// ORDENO POR PRECIOS

lista ordenarPorPrecios(lista l){
  lista ord;
  ord.prim = NULL;
  ord.ult = NULL;
  nodo_d *p = l.prim;

  while(p!=NULL){
    ord = ingreso_ordenadoPorPrecios(ord,p->registro); // voy ingresando los registros
    p = p->sig;
  }
  return ord;
}

lista ingreso_ordenadoPorPrecios(lista l, regs registro){
  nodo_d *nuevo = NULL;
  nuevo = (nodo_d*) malloc (sizeof(nodo_d));
  nuevo->registro = registro;

  if(l.prim == NULL || l.prim->registro.precio > registro.precio){ // la primera va desps
    l = insertar_LIFO(l, registro);
  }
  else{
    nodo_d *p;
    p = l.prim;

    while(p->sig !=NULL && l.prim->registro.precio <= registro.precio){
      p=p->sig;
    }
    // sale o: porque estoy en l.ult o porque p->sig->dato > dato
    // voy a meter a 'nuevo' entre p y p->sig
    nuevo->sig = p->sig;
    p->sig = nuevo;
    nuevo->ant = p;
    if(nuevo->sig != NULL){ // o sea, salió por la segunda cond (esto era a lo q apuntaba p->sig)
      nuevo->sig->ant =nuevo;
    }
    else{ // salió por q p->sig ==NULL
      printf("es el ult elemento ahora \n");
      l.ult = nuevo;
    }
  }
  return l;
}


// ORDENO POR STOCK

lista ordenarPorStock(lista l){
  lista ord;
  ord.prim = NULL;
  ord.ult = NULL;
  nodo_d *p = l.prim;

  while(p!=NULL){
    ord = ingreso_ordenadoPorStock(ord,p->registro); // voy ingresando los registros
    p = p->sig;
  }
  return ord;
}


lista ordenarLista(lista l){
  int ordenar =0;
  printf("segun que campo desea ordenar ? :\n");
  printf("1 - CODIGO \n");
  printf("2 - NOMBRE \n");
  printf("3 - PRECIO \n");
  printf("4 - STOCK \n");
  scanf("%d", &ordenar);
  switch(ordenar){
    case 1:
      l = ordenarPorCodigo(l);
      break;
    case 2:
      l = ordenarPorCadenas(l); // por orden alfabetico --> podría probar por cant de palabras tambn --> funcion strlen(cadena)
      break;
    case 3:
      l = ordenarPorPrecios(l);
      break;
    case 4:
      l = ordenarPorStock(l);
      break;
  }
  return l;
}

// ACÁ CREO LA LISTA DESDE EL ARCHIVO
lista CargarRegistrosDeArch(void){
  FILE *f;
  int n =0;
  regs regi;
  lista l;
  l.prim = NULL;
  l.ult = NULL;

  f = fopen("lista_maestra.dat", "rb");
  n = fread(&regi, sizeof(regs), 1, f);
  while(n==1){
    l = insertar_FIFO(l, regi); //Voy a estar agregando lo que se guardo en regi del archivo f en el ultimo nodo de la lista l (con l= le estoy asignando el nuevo valor a l)
    n = fread(&regi, sizeof(regs), 1, f);
  }
  if(fclose(f)!=0){
    printf("error al cerrar el archivo \n");
    return l;
  }
  return l;
}

lista ingreso_ordenadoPorStock(lista l, regs registro){
  nodo_d *nuevo = NULL;
  nuevo = (nodo_d*) malloc (sizeof(nodo_d));
  nuevo->registro = registro;

  if(l.prim == NULL || l.prim->registro.stock > registro.stock){ // la primera va desps
    l = insertar_LIFO(l, registro);
  }
  else{
    nodo_d *p;
    p = l.prim;

    while(p->sig !=NULL && p->sig->registro.stock <= registro.stock ){ // mientras la primera vaya antes se repite
      p=p->sig;
    }
    // sale o: porque estoy en l.ult o porque p->sig->dato > dato
    // voy a meter a 'nuevo' entre p y p->sig
    nuevo->sig = p->sig;
    p->sig = nuevo;
    nuevo->ant = p;

    if(nuevo->sig != NULL){ // o sea, salió por la segunda cond (esto era a lo q apuntaba p->sig)
      nuevo->sig->ant =nuevo;
    }
    else{ // salió por q p->sig ==NULL
      printf("es el ult elemento ahora \n");
      l.ult = nuevo;
    }
  }
  return l;
}


void sobreEscriboArch(lista l){
  FILE *f;
  nodo_d *p = l.prim;   //inicializo

  f = fopen("lista_maestra.dat", "wb");
  if(f!=NULL){
    printf("apertura OK \n");
  }
  while(p!=NULL){
    fwrite(&p->registro, sizeof(regs), 1, f); //voy copiando lo que esta en el campo registro del puntero p (que apunta al primer nodo)
    p=p->sig;
  }
if(fclose(f)!=0){
    printf("error al cerrar el archivo \n");
    return ;
  }
  return;
}

int main(void) {
  int opcion = 0;
  lista l;
  l.prim = NULL;
  l.ult = NULL;
  regs regi;
  short cod =0;
  lista ord;
  ord.prim = NULL;
  ord.ult = NULL;
  int elec1=0;
  int elec2=0;

  while(opcion!=7){
    opcion = menu();
    switch(opcion){
      case 0:
        CargarArch(); //usa el fwrite y la funcion de cargar registro por cada campo
        break;
      case 1:
        l = CargarRegistrosDeArch(); //Se cargan los registros desde el archivo a una lista fifo
        break;
      case 2:
        regi = ingresoRegistro(); //ingresar un nuevo registro a la lista, en modo fifo
        l = insertar_FIFO(l, regi);
        break;
      case 3:
        printf("ingresar el CODIGO del registro que desea eliminar : \n");
        scanf("%hd", &cod);
        l= eliminarNodo(l, cod);
        break;
      case 4:
        ord = ordenarLista(l); //primero se da un menu para elegir que campo ordenar, y se ordena toda la lista segun ese campo (codigo, stock, nombre, etc)
        break;
      case 5: // se puede hacer INVERSO/DIRECTO o ORDENADA/MAESTRA-->HACER
        printf("seleccione la lista ORDENADA -1 - o MAESTRA -2- \n");
        scanf("%d", &elec1);

        printf("seleccione si la desea al DCHO -1 - o al REVES -2- \n");
        scanf("%d", &elec2);
        if(elec1 ==1){ // ORDENADA
          if(elec2==1){
            mostrarLista(ord);
          }
          else if(elec2==2){
            // mostrar al revés
            mostrarListaAlReves(ord);
          }
        }
        else if(elec1==2){ // MAESTRA
          if(elec2==1){
            mostrarLista(l);
          }
          else if(elec2==2){
            // mostrar al revés
            mostrarListaAlReves(l);
          }
        }
        break;
      case 6:
        sobreEscriboArch(l); //Se sobreescribe el archivo (con fwrite) con la lista maestra modfiicada ya que se le agrego un nuevo nodo de registros
        break;
      case 7:
        l = destruirLista(l);
        break;
    }
  }
  return 0;
}
