#include <Arduino.h>
#include <DataCapture.h>
void menu();
void setup() {
Serial.begin(9600);
Serial.println();
menu();
}
struct Nodo
{
  int dato;
  Nodo *der;
  Nodo *izq;
};

Nodo *crearNodo(int);
void insertar(Nodo *&, int);
Nodo *arbol = NULL;
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
Nodo *crearNodo(int n)
{
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo->dato = n;
  nuevo_nodo->der = NULL;
  nuevo_nodo->izq = NULL;
  return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n){
   if(arbol == NULL){
    Nodo *nuevo_nodo = crearNodo(n);
    arbol= nuevo_nodo;
  }else{
      int valorRaiz = arbol->dato; 
    if(n < valorRaiz){
      insertarNodo(arbol->izq, n);
    }else{
      insertarNodo(arbol->der, n);
    }
  }
  }

void mostrarArbol(Nodo *arbol, int cont){

  if(arbol == NULL){
      return;
  }else{
    mostrarArbol (arbol->der, cont + 1);
    for(int i = 0; i < cont; i++){
      Serial.print("\t");
    }
    Serial.print(String(arbol->dato));
    Serial.println();
    mostrarArbol(arbol->izq, cont + 1);}
}

bool busqueda(Nodo *arbol, int n){

      if( arbol==NULL){
          return false;
      }else if(arbol->dato==n){
          return true;
      }else if (n<arbol->dato){
        return busqueda(arbol->izq, n);
      }else{
        return busqueda(arbol->der, n);
      }
}

void preOrden(Nodo *arbol){
      
      if(arbol==NULL){
        return; 
      }else{
          Serial.print(String(arbol->dato)+"-");
          preOrden(arbol->izq);
          preOrden(arbol->der);
       }
}

void inOrden(Nodo *arbol){

        if (arbol==NULL)
        {
          return;
        }else{
          inOrden(arbol->izq);
          Serial.print(String(arbol->dato)+"-");
          inOrden(arbol->der);
        }
        

}

void postOrden(Nodo *arbol){

      if (arbol==NULL)
      {
        return;
      }else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        Serial.print(String(arbol->dato)+"-");
      }
      
}
void menu(){
  int dato, opcion, cont = 0;

  do{
      Serial.println("\t .:MENU:.");  
      Serial.println("1. Insertar un nuevo nodo");
      Serial.println("2. Mostrar el Arbol completo");
      Serial.println("3. Buscar un elemento en el arbol");
      Serial.println("4. Recorrer el arbol en Pre-orden");
      Serial.println("5. Recorrer el arbol en In-orden");
      Serial.println("6. Recorrer el arbol en Post-orden");
      Serial.println("7. Salir");
      opcion= DataCapture::captureInteger("Ingrese una opcion: ");
      switch(opcion){
              case 1:
                  dato= DataCapture::captureInteger("Ingrese el dato: ");
                  insertarNodo(arbol, dato);
                break;
        
              case 2:
                  Serial.println("Arbol completo: \n");
                  mostrarArbol(arbol, cont);
                break;
              case 3:
                  dato= DataCapture::captureInteger("Dato a buscar: ");
                  if (busqueda(arbol, dato)==true){
                    Serial.println("Elemento "+String(dato)+" ah sido encontrado en el arbol");
                  }else{
                    Serial.println("Elemento "+String(dato)+" no ah sido encontrado en el arbol");
                  }
                break;
              case 4:
                  Serial.println("Recorrido en Pre-orden: \n");
                  preOrden(arbol); 
                  Serial.println();   
                break;
              case 5:
                  Serial.println("Recorrido en In-orden: \n");
                  inOrden(arbol); 
                  Serial.println(); 
                break;
              case 6:
                  Serial.println("Recorrido en Post-orden: \n");
                  postOrden(arbol);
                  Serial.println();
                break;
          }
  }while (opcion!=7);
}

void loop() {
  
}

