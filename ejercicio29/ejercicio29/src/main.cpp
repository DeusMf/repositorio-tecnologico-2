#include <Arduino.h>
#include <DataCapture.h>
#include <time.h> 




void setup() {
  Serial.begin(9600);
  Serial.println();

  int n,x=0,y=1,z=1;
  n=DataCapture::captureInteger("Digite numero de elementos: ");

  Serial.println("1");
  for (size_t i = 1; i < n; i++)
  {
      z=x+y;
      Serial.println(String(z));
      x=y;
      y=z;

   }
  
 

}

void loop() {

}

