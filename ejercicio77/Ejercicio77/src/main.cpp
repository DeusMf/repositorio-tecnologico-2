#include <Arduino.h>
#include <DataCapture.h>

void pedir_datos();
void comprobar_simetria(int m[][100],int,int);

int m [100] [100], nfilas,ncolumnas;

void setup() {

    Serial.begin(9600);
    Serial.println();
      pedir_datos();
      comprobar_simetria(m,nfilas,ncolumnas);
}

void loop() {
 
}

void pedir_datos(){

      nfilas = DataCapture::captureInteger("Ingrese número de filas:");
      ncolumnas = DataCapture::captureInteger("Ingrese número de columnas:");

        for (size_t i = 0; i < nfilas; i++)
        {
          for (size_t j = 0; j < ncolumnas; j++)
          {
                m[i][j]= DataCapture::captureInteger("Digite un numero["+ String(i) +"]["+ String(j)+"]:");
          }          
        }
}

void comprobar_simetria(int m[][100],int nfilas,int ncolumnas){
    int cont=0;
    if (nfilas==ncolumnas)
    {
            for (size_t i = 0; i < nfilas; i++)
            {
              for (size_t j = 0; j < ncolumnas; j++)
              {
                    if (m[i][j]==m[j][i])
                    {
                          cont++;
                    }
              }
            }
    }
     if (cont==nfilas*ncolumnas)
      {
        Serial.println("La matris es simetrica");
      }else
      {
      Serial.println("La matris no es simetrica");
      }
}