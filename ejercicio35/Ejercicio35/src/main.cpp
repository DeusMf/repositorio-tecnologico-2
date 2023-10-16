#include <Arduino.h>



void setup() {
 Serial.begin(9600);
 Serial.println();

char letras1[]={'a','b','c','d','e'};
char letras2[]={'f','g','h','i','j'};
char letras3[10];

for (size_t i = 0; i <5; i++)
{
  letras3[i]=letras1[i];
}

for (size_t i = 5; i < 10; i++)
{
  letras3[i]=letras2[i-5];
}

  for (size_t i = 0; i < 10; i++)
  {
    Serial.print(letras3[i]);
  }
  
}

void loop() {
  
}


