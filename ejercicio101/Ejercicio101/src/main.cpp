#include <Arduino.h>
#include <DataCapture.h>

void setup() {
  Serial.begin(9600);
  Serial.println();

}
struct Nodo
{
    int dato;
    Nodo *siguiente;
};
void insertar_cola(Nodo *&,Nodo *&,int);
bool cola_vacia(Nodo *);
void loop() {
  Nodo *frente=NULL;
  Nodo *fin=NULL;

  int dato= DataCapture::captureInteger("Digite un numero:");
  insertar_cola(frente,fin,dato);

}

void insertar_cola(Nodo *&frente, Nodo *&fin, int n){

    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente= NULL;
    
      if (cola_vacia(frente))
      {
          frente=nuevo_nodo;
          

      }else{
        fin->siguiente=nuevo_nodo;

      }
      
      fin=nuevo_nodo;

      Serial.println("Elemento:" + String(n)+ " " + "insertado a la cola correctamente");
}

bool cola_vacia(Nodo *frente){
      
      return (frente==NULL)? true:false;
    
}