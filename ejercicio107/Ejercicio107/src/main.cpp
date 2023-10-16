#include <Arduino.h>
#include <DataCapture.h>
#include <cstdlib>

struct Nodo
{
  int dato;
  Nodo *siguiente;
};

void insertar_lista(Nodo *&,int);
void mostrar_lista(Nodo *);
void buscar_lista(Nodo *,int);
Nodo *lista = NULL;

void loop(){

}


void insertar_lista(Nodo *&lista, int n){

  Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato=n;
    Nodo *aux1=lista;
    Nodo *aux2=NULL;

      while ((aux1 != NULL) && (aux1->dato < n))
      {
          aux2 = aux1;
          aux1 = aux1 ->siguiente;
      }
     if (lista==aux1)
      {
          lista = nuevo_nodo;
      }else{
              aux2 ->siguiente=nuevo_nodo;
      } 
        nuevo_nodo->siguiente=aux1;
         Serial.println("Elemento "+String(n)+" insertado en la lista correctamente");
}

void mostrar_lista(Nodo *lista){

        Nodo *actual = new Nodo();
        actual = lista;

          while (actual != NULL)
          {
              Serial.print(String(actual->dato)+"->");
              actual= actual->siguiente;
          }

}
void buscar_lista(Nodo *lista, int n){

      bool band = false;
      Nodo *actual = new Nodo();
      actual=lista;
      while ((actual != NULL) && (actual->dato <=n))
      {
          if (actual->dato==n)
          {
            band=true;
          }
          actual=actual->siguiente;
      }

      if(band==true){
        Serial.println("Elemento "+String(n)+" Si ah sido encontrado en la lista");
      } else
      {
        Serial.println("Elemento "+String(n)+" No ah sido encontrado en la lista");
      }
}
void setup() {
 Serial.begin(115200);
 Serial.println();
 int opcion,numero;
    do
    {
      Serial.println("\t.:Menu:.");
      Serial.println("1. Insertar Elementos a la Lista");
      Serial.println("2. Mostrar elementos de la lista");
      Serial.println("3. Buscar un elemento en lista");
      Serial.println("4. Salir");
      opcion=DataCapture::captureInteger("Opcion");

        switch (opcion)
        {
        case 1:
           numero = DataCapture::captureInteger("Ingrese un numero:");
            insertar_lista(lista,numero);
           while (!Serial.available()) {}
          break;
        
        case 2:   
            mostrar_lista(lista);
            Serial.println();
            while (!Serial.available()) {}
          break;
        
        case 3:
            numero=DataCapture::captureInteger("Digite un numero a buscar: ");
            buscar_lista(lista,numero);
            Serial.println();
           while (!Serial.available()) {}
          break;
        }
      
    } while (opcion !=4);
}
