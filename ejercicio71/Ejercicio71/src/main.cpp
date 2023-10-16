#include <Arduino.h>

    void intercambiar(int&, int&);

void setup() {
  
    Serial.begin(9600);
    Serial.println();
      int num1=10, num2=15;
        Serial.println("el valor del numero 1 es :"+String(num1));
        Serial.println("el valor del numero 2 es :"+String(num2));
          intercambiar(num1,num2);
            Serial.println("El nuevo valor del numero 1 es:"+String(num1));
            Serial.println("El nuevo valor del numero 2 es:"+String(num2));
}

void loop(){

}
void intercambiar(int& num1,int& num2){

      int aux;
      aux=num1;
      num1=num2;
      num2=aux;

  }

