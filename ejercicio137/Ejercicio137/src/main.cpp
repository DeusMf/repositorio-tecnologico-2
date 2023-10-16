#include <Arduino.h>

class Persona {
          private:
            String nombre;
            int edad;
          public:
            Persona(String, int); 
            virtual void mostrar();
};

class Alumno : public Persona{
        private:
          float notaFinal;
          public:
            Alumno(String,int,float);
            void mostrar();
};
class Profesor : public Persona{
          private:
            String Materia;
          public:
            Profesor(String,int,String);
            void mostrar();
};
  Persona::Persona(String _nombre, int _edad){
      nombre=_nombre;
      edad=_edad;
  }
void Persona::mostrar(){
    Serial.println("Nombre: "+ nombre);
    Serial.println("Edad: "+ String(edad));
  }
  Alumno::Alumno(String _nombre,int _edad,float _notaFinal) : Persona(_nombre,_edad){
      notaFinal=_notaFinal;
  }
void Alumno::mostrar(){

          Persona::mostrar();
          Serial.println("Nota Final: "+ String(notaFinal));
  }

  Profesor::Profesor(String _nombre,int _edad,String _Materia) : Persona(_nombre,_edad){
      Materia=_Materia;
  }

void Profesor::mostrar(){
      Persona::mostrar();
      Serial.println("Materia: "+ Materia);
  }
void setup() {
  Serial.begin(115200);
  Serial.println();

          Persona *Vector[3];
          Vector[0]=  new Alumno(" Carlos",25,5.0);
          Vector[1]= new Alumno(" Laura",24,4.75);
          Vector[2]=  new Profesor(" Juan",30,"Matematicas");

          Vector[0]->mostrar();
          Serial.println();
          Vector[1]->mostrar();
          Serial.println();
          Vector[2]->mostrar();
}

void loop() {
}

