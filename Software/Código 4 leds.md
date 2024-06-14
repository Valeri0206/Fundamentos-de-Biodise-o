// Definición de los pines
const int pinFSR1 = A0;  // Pin donde está conectado el primer FSR
const int pinFSR2 = A1;  // Pin donde está conectado el segundo FSR
const int pinFSR3 = A2;  // Pin donde está conectado el tercer FSR
const int pinFSR4 = A3;  // Pin donde está conectado el cuarto FSR

const int pinLED1 = 8;  // Pin donde está conectado el primer LED
const int pinLED2 = 2;  // Pin donde está conectado el segundo LED
const int pinLED3 = 5;  // Pin donde está conectado el tercer LED
const int pinLED4 = 4;  // Pin donde está conectado el cuarto LED

void setup() {
  // Configura los pines de los LEDs como salida
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED4, OUTPUT);

  // Configura los pines de los FSRs como entrada
  pinMode(pinFSR1, INPUT);
  pinMode(pinFSR2, INPUT);
  pinMode(pinFSR3, INPUT);
  pinMode(pinFSR4, INPUT);

  // Inicia la comunicación serial para depuración
  Serial.begin(9600);  // Ajustado a 9600 baudios
}

void loop() {
  // Lee los valores de los sensores FSR
  int fsrReading1 = analogRead(pinFSR1);
  int fsrReading2 = analogRead(pinFSR2);
  int fsrReading3 = analogRead(pinFSR3);
  int fsrReading4 = analogRead(pinFSR4);

  // Imprime los valores de los sensores en la consola serial
  Serial.print("Lectura FSR1: ");
  Serial.println(fsrReading1);
  Serial.print("Lectura FSR2: ");
  Serial.println(fsrReading2);
  Serial.print("Lectura FSR3: ");
  Serial.println(fsrReading3);
  Serial.print("Lectura FSR4: ");
  Serial.println(fsrReading4);

  // Verifica los valores de los sensores y controla los LEDs
  if (fsrReading1 >= 4090 && fsrReading1 <= 5000) {
    digitalWrite(pinLED1, LOW);  // Enciende el LED1 si está en el rango
  } else {
    digitalWrite(pinLED1, HIGH); // Apaga el LED1 si no está en el rango
  }

  if (fsrReading2 >= 4090 && fsrReading2 <= 5000) {
    digitalWrite(pinLED2, LOW);  // Enciende el LED2 si está en el rango
  } else {
    digitalWrite(pinLED2, HIGH); // Apaga el LED2 si no está en el rango
  }

  if (fsrReading3 >= 4090 && fsrReading3 <= 5000) {
    digitalWrite(pinLED3, LOW);  // Enciende el LED3 si está en el rango
  } else {
    digitalWrite(pinLED3, HIGH); // Apaga el LED3 si no está en el rango
  }

  if (fsrReading4 >= 4090 && fsrReading4 <= 5000) {
    digitalWrite(pinLED4, LOW);  // Enciende el LED4 si está en el rango
  } else {
    digitalWrite(pinLED4, HIGH); // Apaga el LED4 si no está en el rango
  }

  delay(100);  // Pequeña pausa para no saturar la salida serial
}
