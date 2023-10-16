#include <Arduino.h>
#include <DataCapture.h>
#include <cstring>
void PedirDatos();
void setup() {
Serial.begin(9600);
Serial.println();
}

struct Alumno
{
  char nombre[30];
  int edad;
  float promedio;

}alumno[3],*puntero_alumno= alumno;

void PedirDatos(){

    for (int i = 0; i < 3; i++)
    {
      strcpy((puntero_alumno+i)->nombre, DataCapture::captureString("Digite su nombre:").c_str());
      (puntero_alumno+i)->edad=DataCapture::captureInteger("Digite su edad:");
      (puntero_alumno+i)->promedio=DataCapture::captureFloat("Digite su promedio");

    }
}
void Calcular_mejor_promedio(Alumno *);

void Calcular_mejor_promedio(Alumno *puntero_alumno ){
      float mayor=0.0;
      int pos=0;
      for (int i = 0; i < 3; i++)
      {
            if ((puntero_alumno+i)->promedio>mayor)
            {
              mayor=(puntero_alumno+i)->promedio;
              pos=i;
            }
            
      }
        Serial.println("El alumno con mejor promedio es:");
        Serial.println("nombre:%s"+String((puntero_alumno+pos)->nombre));
        Serial.println("edad:"+String((puntero_alumno+pos)->edad));
        Serial.println("Promedio:"+String((puntero_alumno+pos)->promedio));
        Serial.println();
  }
void loop() {
  PedirDatos();
  Calcular_mejor_promedio(puntero_alumno);
}

