#include <Arduino.h>
#include <capturadedatos.h>

void setup() {
  Serial.begin(9600);
  
  Serial.println();
  Serial.println();

  
  int numero1 = DataCapture::captureInteger("Ingrese el primer numero:");
  while (!Serial.available()) {}
  int numero2 = DataCapture::captureInteger("Ingrese el segundo numero:");
  int suma=0,resta=0,multiplicacion=0,division=0;

    suma=numero1+numero2;
    resta=numero1-numero2;
    multiplicacion=numero1*numero2;
    division=numero1/numero2;
    Serial.println("La suma es: "+String(suma));
    Serial.println("La resta es: "+String(resta));
    Serial.println("La multiplicacion es: "+String(multiplicacion));
    Serial.println("La division es: "+String(division));

 
}

void loop() {
 
}