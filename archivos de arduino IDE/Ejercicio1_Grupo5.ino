#include <Arduino.h> // tipo de libreria utilizada en el laboratorio 01 - Ejercicio_#1
// UNIVERSIDAD TECNICA DEL NORTE
//Integrantes:  Jean Carlos Viscaino, 
              //Jhojan Gabriel Rivera, 
              //Damian Jefferson Sanchez
// Se definen pines correctamente
const int pinnBoton1 = 2; // Pin  pulsador #1
const int pinnBoton2 = 3; // Pin d pulsador #2
const int pinnLED1 = 4; // Pin  LED #1
const int pinnLED2 = 5; // Pin l LED #2

void setup() {
  // Se configuran pines de LEDs como salida
  pinMode(pinnLED1, OUTPUT);
  pinMode(pinnLED2, OUTPUT);
  // Se inicializan los LEDs como apagados
  digitalWrite(pinnLED1, LOW);
  digitalWrite(pinnLED2, LOW);
}

void loop() {
// Creacion de variable tipo entero para - Lectura del estado del pulsador #1
  int estadoBoton1 = digitalRead(pinnBoton1);

//Creacion de variable tipo entero para - Lectura del estado del pulsador #2
  int estadoBoton2 = digitalRead(pinnBoton2);
  // Control del LED #1, con un if-else
  if (estadoBoton1 == LOW) {
    digitalWrite(pinnLED1, HIGH);
  } else {
    digitalWrite(pinnLED1, LOW);
  }
  // Control del LED #2, con un if-else
  if (estadoBoton2 == LOW) {
    digitalWrite(pinnLED2, HIGH);
  } else {
    digitalWrite(pinnLED2, LOW);
  }
}
