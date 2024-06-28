#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX, TX

int fsrReading1;
int fsrReading2;
int fsrReading3;
int fsrReading4;

// Definición de los pines
const int pinFSR1 = A0;  // Pin donde está conectado el primer FSR
const int pinFSR2 = A1;  // Pin donde está conectado el segundo FSR
const int pinFSR3 = A2;  // Pin donde está conectado el tercer FSR
const int pinFSR4 = A3;  // Pin donde está conectado el cuarto FSR


const int pinLED1 = 9;  // Pin donde está conectado el segundo LED
const int pinLED2 = 4;  // Pin donde está conectado el tercer LED


const float sensorMax = 1023.0;
const float forceMax = 10.0;  // 10 Newtons (valor máximo de fuerza)

// Área en metros cuadrados (pi * (14.7 x 10^-3)^2)
const float radius = 0.0147/2;  // Radio en metros
const float area = 3.141592653589793 * radius * radius;

void setup() {
  // Configura los pines de los LEDs como salida

  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);


  // Configura los pines de los FSRs como entrada
  pinMode(pinFSR1, INPUT);
  pinMode(pinFSR2, INPUT);
  pinMode(pinFSR3, INPUT);
  pinMode(pinFSR4, INPUT);

  // Inicia la comunicación serial para depuración
  Serial.begin(9600);  // Ajustado a 9600 baudios
  BTSerial.begin(9600);
}

float sensorValueToForce(int sensorValue) {
  return (forceMax / sensorMax) * sensorValue;
}

float forceToPascal(float force) {
  return force / area;
}

void loop() {
  // Lee los valores de los sensores FSR
  fsrReading1 = analogRead(pinFSR1);
  fsrReading2 = analogRead(pinFSR2);
  fsrReading3 = analogRead(pinFSR3);
  fsrReading4 = analogRead(pinFSR4);

  // Convierte las lecturas a fuerza en Newtons
  float force1 = sensorValueToForce(fsrReading1);
  float force2 = sensorValueToForce(fsrReading2);
  float force3 = sensorValueToForce(fsrReading3);
  float force4 = sensorValueToForce(fsrReading4);

  // Convierte las fuerzas a Pascales
  float pressure1 = forceToPascal(force1);
  float pressure2 = forceToPascal(force2);
  float pressure3 = forceToPascal(force3);
  float pressure4 = forceToPascal(force4);

  // Imprime los valores de los sensores y presiones en la consola serial
  Serial.print("Lectura_FSR1: ");
  Serial.print(fsrReading1);
  Serial.print(" Fuerza: ");
  Serial.print(force1);
  Serial.print(" N, Presión: ");
  Serial.print(pressure1);
  Serial.println(" Pa");

  Serial.print("Lectura_FSR2: ");
  Serial.print(fsrReading2);
  Serial.print(" Fuerza: ");
  Serial.print(force2);
  Serial.print(" N, Presión: ");
  Serial.print(pressure2);
  Serial.println(" Pa");

  //Serial.print("Lectura_FSR3: ");
  //Serial.print(fsrReading3);
  //Serial.print(" Fuerza: ");
  //Serial.print(force3);
  //Serial.print(" N, Presión: ");
  //Serial.print(pressure3);
  //Serial.println(" Pa");

  //Serial.print("Lectura_FSR4: ");
  //Serial.print(fsrReading4);
  //Serial.print(" Fuerza: ");
  //Serial.print(force4);
  //Serial.print(" N, Presión: ");
  //Serial.print(pressure4);
  //Serial.println(" Pa");

  BTSerial.print("Lectura_FSR1: ");
  BTSerial.print(fsrReading1);
  BTSerial.print(" Fuerza: ");
  BTSerial.print(force1);
  BTSerial.print(" N, Presión: ");
  BTSerial.print(pressure1);
  BTSerial.println(" Pa");

  BTSerial.print("Lectura_FSR2: ");
  BTSerial.print(fsrReading2);
  BTSerial.print(" Fuerza: ");
  BTSerial.print(force2);
  BTSerial.print(" N, Presión: ");
  BTSerial.print(pressure2);
  BTSerial.println(" Pa");

  BTSerial.print("Lectura_FSR3: ");
  BTSerial.print(fsrReading3);
  BTSerial.print(" Fuerza: ");
  BTSerial.print(force3);
  BTSerial.print(" N, Presión: ");
  BTSerial.print(pressure3);
  BTSerial.println(" Pa");

  BTSerial.print("Lectura_FSR4: ");
  BTSerial.print(fsrReading4);
  BTSerial.print(" Fuerza: ");
  BTSerial.print(force4);
  BTSerial.print(" N, Presión: ");
  BTSerial.print(pressure4);
  BTSerial.println(" Pa");

  // Control de los LEDs basado en las lecturas de los sensores

  if (fsrReading2 > 920 && fsrReading2 < 1020) {
    digitalWrite(pinLED1, HIGH);  // Enciende el LED1 si está en el rango
  } else {
    digitalWrite(pinLED1, LOW);  // Apaga el LED1 si no está en el rango
  }

  if (fsrReading3 > 920 && fsrReading3 < 1020) {
    digitalWrite(pinLED2, HIGH);  // Enciende el LED1 si está en el rango
  } else {
    digitalWrite(pinLED2, LOW);  // Apaga el LED1 si no está en el rango
  }



  delay(100);  // Pequeña pausa para no saturar la salida serial
}
