#include <Arduino.h>
#include <DataCapture.h>



void setup() {
  Serial.begin(9600);  
  Serial.println();

  float resultado=0;
 float x=DataCapture::captureInteger("Ingrese primer número:");
 while (!Serial.available()) {}
  float y=DataCapture::captureInteger("Ingrese segundo número:");
  resultado=(sqrt(x))/(pow(y,2)-1);
  Serial.println("El resultado es: "+String(resultado));
}

void loop() {
  
}

