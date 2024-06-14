// Definición de los pines
const int pinFSR = A0;  // Pin donde está conectado el FSR
const int pinLED = 13;  // Pin donde está conectado el LED

void setup() {
  pinMode(pinLED, OUTPUT);  // Configura el pin del LED como salida
  pinMode(pinFSR, INPUT);   // Configura el pin del FSR como entrada
  Serial.begin(9600);       // Inicia la comunicación serial para depuración
}

void loop() {
  int fsrReading = analogRead(pinFSR);  // Lee el valor del FSR
  Serial.print("Lectura FSR: ");
  Serial.println(fsrReading);  // Imprime el valor del FSR en la consola serial

  // Verifica si la lectura está en el rango deseado
  if (fsrReading >= 200 && fsrReading <= 900) {
    digitalWrite(pinLED, LOW);// Enciende el LED si está en el rango
  } else {
    digitalWrite(pinLED, HIGH);
       // Apaga el LED si no está en el rango
  }

  delay(100);  // Pequeña pausa para no saturar la salida serial
}
