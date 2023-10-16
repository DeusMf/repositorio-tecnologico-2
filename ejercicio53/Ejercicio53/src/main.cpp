#include <Arduino.h>


void setup() {
  Serial.begin(9600);
  Serial.println();

  int numeros[]={3,2,1,5,4};

  int i,j,aux,min;

  for ( i = 0; i < 5; i++)
  {
    min=i;

    for(j=i+1;j<5;j++){

      if (numeros[j]<numeros[min])
      {
        min=j;
      }
      
    }
    aux=numeros[i];
    numeros[i]=numeros[min];
    numeros[min]=aux;
  }
  Serial.println("Orden ascendente");
  for ( i = 0; i < 5; i++)
  {
    Serial.print(numeros[i]);
    Serial.print(" ");
    
  }
  Serial.println();
  Serial.println("Orden descendente");
  for ( i = 4; i >= 0; i--)
  {
    Serial.print(numeros[i]);
    Serial.print(" ");
  }
  
}

void loop() {
  
}

