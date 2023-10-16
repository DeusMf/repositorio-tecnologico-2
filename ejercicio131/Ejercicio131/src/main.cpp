#include <Arduino.h>

class Tiempo{

        private:
        int horas,minutos,segundos;
        public:
        Tiempo(int, int, int);
        Tiempo(int);
        void mostrarTiempo();
};
Tiempo::Tiempo(int _horas, int _minutos, int _segundos){
  horas = _horas;
  minutos = _minutos;
  segundos = _segundos;
}

Tiempo::Tiempo(int tiemposeg){
  horas = tiemposeg/3600;
  tiemposeg %= 3600;
  minutos = tiemposeg / 60;
  segundos= tiemposeg%60;
  
}

void Tiempo::mostrarTiempo(){
  Serial.print("La hora es: "+String(horas)+":"+String(minutos)+":"+String(segundos));
  
  Serial.println();
}
void setup() {
  Serial.begin(115200);
  Serial.println();
  Tiempo horaActual(16,23,30);
  Tiempo haceunahora(55410);
  horaActual.mostrarTiempo();
  haceunahora.mostrarTiempo();
}

void loop() {
}

