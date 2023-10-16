#include <Arduino.h>
#include "DataCapture.h"


void setup() {
  Serial.begin(9600);
  Serial.println();
//char palabra[]="Carlos";
//char palabra2[]={'c','a','r','l','o','s'};
String nombre;

  
  Serial.println("Dame un nombre: ");
String input = DataCapture::captureString("");
nombre = input.substring(0, 20); // Cambia el número 20 por la longitud deseada

Serial.println("Tu nombre es: ");
Serial.println(String(  nombre));
}

void loop() {
 
}

