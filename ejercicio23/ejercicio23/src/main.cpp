#include <Arduino.h>
#include <DataCapture.h>


void setup() {

  Serial.begin(9600);
  Serial.println();
 
  int num;
 do
 {
    num=DataCapture::captureInteger("Ingrese un numero: ");

 } while ( (num<1) || (num>10));
 
 for (size_t i = 1; i <=20; i++)
 {
  Serial.println(String(num)+"*"+String(i)+"="+String(num*i));
 }
 
 

}

void loop() {

}

