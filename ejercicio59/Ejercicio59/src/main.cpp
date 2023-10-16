#include <Arduino.h>
#include <DataCapture.h>


void setup() {
  Serial.begin(9600);
  Serial.println();

    struct info_direccion
    {
      char direccion[30];
      char ciudad[20];
      char barrio[20];
    };
    
    struct Empleado
    {
      char nombre[20];
      struct info_direccion dir_empleado;
      double salario;
    }empleados[2];

   for (size_t i = 0; i < 2; i++)
   {
      fflush(stdin);
      strncpy(empleados[i].nombre, DataCapture::captureString("Nombre: ").c_str(), sizeof(empleados[i].nombre) - 1);
empleados[i].nombre[sizeof(empleados[i].nombre) - 1] = '\0'; // Asegura que el arreglo de caracteres esté terminado en null
   
      strncpy(empleados[i].dir_empleado.direccion, DataCapture::captureString("Direccion: ").c_str(), sizeof(empleados[i].dir_empleado.direccion) - 1);
      empleados[i].dir_empleado.direccion[sizeof(empleados[i].dir_empleado.direccion) - 1] = '\0'; // Asegura que el arreglo de caracteres esté terminado en null
      strncpy(empleados[i].dir_empleado.ciudad, DataCapture::captureString("Ciudad: ").c_str(), sizeof(empleados[i].dir_empleado.ciudad) - 1);
      empleados[i].dir_empleado.ciudad[sizeof(empleados[i].dir_empleado.ciudad) - 1] = '\0'; // Asegura que el arreglo de caracteres esté terminado en null
      strncpy(empleados[i].dir_empleado.barrio, DataCapture::captureString("Barrio: ").c_str(), sizeof(empleados[i].dir_empleado.barrio) - 1);
      empleados[i].dir_empleado.barrio[sizeof(empleados[i].dir_empleado.barrio) - 1] = '\0'; // Asegura que el arreglo de caracteres esté terminado en null
      empleados[i].salario = DataCapture::captureInteger("Salario: ");
   
    Serial.println();
    
  
   }

   for (size_t i = 0; i < 2; i++)
   {
      Serial.println(empleados[i].nombre);
      Serial.println(empleados[i].dir_empleado.direccion);
      Serial.println(empleados[i].dir_empleado.ciudad);
      Serial.println(empleados[i].dir_empleado.barrio);
      Serial.println(empleados[i].salario);
      Serial.println();
   }
   
   
   
}

void loop() {
 
}

