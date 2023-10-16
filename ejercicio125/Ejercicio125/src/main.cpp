#include <Arduino.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

void lectura();
void setup() {  
 Serial.begin(115200);
 Serial.println();
lectura();
}

void lectura() {

       std:: ifstream archivo;
        std:: string texto;

archivo.open("C:\\prueba\\prueba.txt", std::ios::in);
        if (archivo.fail())
        {
          Serial.println("Error al abrir el archivo");
          exit(1);
        }
        while (!archivo.eof())
        {
          getline(archivo, texto);
          Serial.println(String(texto.c_str()));
        }
        archivo.close();
}
void loop() {
  // put your main code here, to run repeatedly:
}

