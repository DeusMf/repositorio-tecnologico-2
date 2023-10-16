#include <Arduino.h>
#include <CapturadeDatos.h>
void setup() {
  Serial.begin(9600);
  Serial.println();
  
}

void loop() {
 int edad = DataCapture::captureInteger("dijite su edad:");
if (edad>=18 && edad<=25)
{
  Serial.println("su edad esta en el rango de [18-25]");
}else{
  Serial.println("su edad no esta en el rango de [18-25]");
}

  
  Serial.println();
}

