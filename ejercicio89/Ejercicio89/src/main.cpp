#include <Arduino.h>

int hallarMax(int*,int);
int hallarMax(int *dirvec ,int nElementos){

      int max = 0;

      for ( int i = 0; i < nElementos; i++)
      {
        if(*(dirvec+i)>max){
          max = *(dirvec+i);
        }
      }
      
   return max;
}

void setup() {

Serial.begin(115200);
Serial.println();

const int nElementos = 5;
int numeros[nElementos] = {3,12,2,8,1};
    Serial.println("El mayor elemento es: "+ String(hallarMax(numeros,nElementos)));


}

void loop() {

}
