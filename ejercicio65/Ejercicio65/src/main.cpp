#include <Arduino.h>


template <class TIPOD>
void mostrarAbs(TIPOD numero);
void setup() {
  Serial.begin(9600);
  Serial.println();
   int num1 = -4;
   float num2 = -3.14;
   double num3 = -2.71828;

   mostrarAbs(num1);
   mostrarAbs(num2);
   mostrarAbs(num3);


}

template <class TIPOD>  
void mostrarAbs(TIPOD numero) {
  if (numero < 0) {
    numero = numero * -1;
  }
  Serial.println(String(numero));
}

void loop() {

}

