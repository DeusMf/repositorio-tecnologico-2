#include <DataCapture.h>

int DataCapture::captureInteger(String message) {
    int number = 0;
    Serial.print(message);
    while (!Serial.available()) {}
    String inputString = Serial.readString();
    if (isInteger(inputString)) {
        number = inputString.toInt();
        Serial.print(" " + String(number));
        Serial.println();
    } else {
        Serial.println("El dato ingresado no es un numero entero.");
    }

    return number;
}

String DataCapture::captureString(String message) {
    Serial.print(message);
    while (!Serial.available()) {}
    String inputString = Serial.readString();
    Serial.print(" " + inputString);
    Serial.println();
    return inputString;
}

bool DataCapture::isInteger(String data) {
    if (data.length() == 0) return false;

    for (int i = 0; i < data.length(); i++) {
        if (i == 0 && data[i] == '-' && data.length() > 1) continue;  // Acepta un signo negativo al principio
        if (data[i] == '\n' || data[i] == '\r') continue; // Ignora los caracteres de nueva línea y retorno de carro
        if (!isDigit(data[i])) return false;  // Si no es un dígito, retorna falso
    }
    return true;
}