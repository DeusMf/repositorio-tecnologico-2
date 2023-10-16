#include <Arduino.h>



void setup() {
  Serial.begin(9600);
  Serial.println();

  char palabra[]="carlos";

  strupr(palabra);

  Serial.println(String(palabra));
  
}

void loop() {
 
}

