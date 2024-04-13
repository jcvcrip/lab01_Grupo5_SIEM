#include <Arduino.h> // tipo de libreria utilizada en el laboratorio 01 - Ejercicio_#2
// UNIVERSIDAD TECNICA DEL NORTE
//Integrantes:  Jean Carlos Viscaino, 
              //Jhojan Gabriel Rivera, 
              //Damian Jefferson Sanchez
// Se definen pines correctamente
const int pinLED1 = 4;    // Pin del LED #1
const int pinBoton1 = 2;  // Pin del botón #1

// Se definen variables de estado de tipo falso
bool cicloActivo = false; // Variable para controlar si el ciclo está activo
bool estadoLED = false;   // Variable para el estado actual del LED (encendido o apagado)

void setup() {
  pinMode(pinLED1, OUTPUT);   // Configurar el pin del LED como salida
  pinMode(pinBoton1, INPUT);  // Configurar el pin del botón como entrada
}

void loop() {
  // Lectura  del estado del botón #1
  int botonPresionado = digitalRead(pinBoton1);
  if (botonPresionado == LOW && !cicloActivo) { // Verificacion si el botón fue presionado y el ciclo no este activo
    cicloActivo = true; // Se activa el ciclo
        while (cicloActivo) { // Ciclo infinito
            for (int i = 0; i < 5; i++) { // Ciclo de parpadeo en 5 segundos
            digitalWrite(pinLED1, HIGH);
            delay(500);
            digitalWrite(pinLED1, LOW);
            delay(500);
            }    
  // Apagar el LED según el estado actual
  digitalWrite(pinLED1, LOW);
  // Esperar 5 segundos si el LED está encendido y 10 segundos si está apagado
  delay(cicloActivo ? 10000 : 5000);

    }
  }
}
