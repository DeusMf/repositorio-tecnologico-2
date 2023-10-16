#include <Arduino.h>
void setup() {
  
  Serial.begin(115200);
  Serial.println();

  int num, *dir_num;
  
 num = 20;

 dir_num= &num;

   Serial.println("el numero es :"+ String(*dir_num));
Serial.println("direccion de memoria: " + String( (unsigned long)dir_num, HEX) );
  }

void loop() {
  
}

