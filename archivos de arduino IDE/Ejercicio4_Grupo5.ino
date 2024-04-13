#include <Arduino.h> // tipo de libreria utilizada en el laboratorio 01 - Ejercicio_#4
// UNIVERSIDAD TECNICA DEL NORTE
//Integrantes:  Jean Carlos Viscaino, 
              //Jhojan Gabriel Rivera, 
              //Damian Jefferson Sanchez
// Se definen pines 

const int pinnBoton1 = 2;  // Pinn botón #1
const int pinnLED1 = 4;    // Pinn LED #1
const int pinnLED2 = 5;    // Pinn LED #2
const int pinnLED3 = 6;    // Pinn LED #3
const int pinnLED4 = 7;    // Pinn LED #4

bool activo = false; // Variable para controlar el ciclo 

void setup() {
  pinMode(pinnBoton1, INPUT);  // Conf el pinn botón como entrada
  pinMode(pinnLED1, OUTPUT);   // Conf el pinn LED#1 como salida
  pinMode(pinnLED2, OUTPUT);   // Conf el pinn LED#2 como salida
  pinMode(pinnLED3, OUTPUT);   // Conf el pinn LED#3 como salida
  pinMode(pinnLED4, OUTPUT);   // Conf el pinn  LED#4 como salida
}

void loop() {
  int botonPresionado = digitalRead(pinnBoton1);
  if (botonPresionado == LOW && !activo) { // Verificar si el botón esta ON Y ciclo en OFF
    activo = true; // Activar el ciclo
    while (activo) { // Ciclo infinito
      // Encender los LEDs 1 y 3 durante 5 segundos
      digitalWrite(pinnLED1, HIGH);
      digitalWrite(pinnLED2, LOW);
      digitalWrite(pinnLED3, LOW);
      digitalWrite(pinnLED4, LOW);
      delay(500); // Esperar 0.5 segundos
      digitalWrite(pinnLED1, LOW);
      digitalWrite(pinnLED2, HIGH);
      digitalWrite(pinnLED3, LOW);
      digitalWrite(pinnLED4, LOW);
      delay(500); // Esperar 0.5 segundos
      digitalWrite(pinnLED1, LOW);
      digitalWrite(pinnLED2, LOW);
      digitalWrite(pinnLED3, HIGH);
      digitalWrite(pinnLED4, LOW);
      delay(500); // Esperar 0.5 segundos
      digitalWrite(pinnLED1, LOW);
      digitalWrite(pinnLED2, LOW);
      digitalWrite(pinnLED3, LOW);
      digitalWrite(pinnLED4, HIGH);
      delay(500); // Esperar 0.5 segundos
    }
  }
}

