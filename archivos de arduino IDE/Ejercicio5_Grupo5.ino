#include <Arduino.h> // tipo de libreria utilizada en el laboratorio 01 - Ejercicio_#5
// UNIVERSIDAD TECNICA DEL NORTE
//Integrantes:  Jean Carlos Viscaino, 
              //Jhojan Gabriel Rivera, 
              //Damian Jefferson Sanchez

// Se definen pines 
const int pinnBoton1 = 2;  // Pin  botón #1
const int pinnLED2 = 5;    // Pin  LED #2
const int pinnLED3 = 6;    // Pin  LED #3
const int pinnLED4 = 7;    // Pin  LED #4

bool activo = false; // Variab controla  el ciclo 

void setup() {
  pinMode(pinnBoton1, INPUT);  // Conf el pin  botón como entrada
  pinMode(pinnLED2, OUTPUT);   // Conf el pin  LED#2 como salida
  pinMode(pinnLED3, OUTPUT);   // Conf el pin  LED#3 como salida
  pinMode(pinnLED4, OUTPUT);   // Conf el pin  LED#4 como salida
}

void loop() {
  int botonPresionado = digitalRead(pinnBoton1);// lectura del boton

  if (botonPresionado == LOW && !activo) { // Verificar si el botón esta ON Y ciclo en OFF
    activo = true; // Activar el ciclo

    while (activo) { // Ciclo infinito
      //  LEDs verde ON,amarillo OFF y rojo OFF 
      digitalWrite(pinnLED4, HIGH);
      digitalWrite(pinnLED3, LOW);
      digitalWrite(pinnLED2, LOW);
      delay(10000); // Espera 10 segundos
      //  LEDs verde OFF,amarillo ON y rojo OFF 
      digitalWrite(pinnLED4, LOW);
      digitalWrite(pinnLED3, HIGH);
      digitalWrite(pinnLED2, LOW);
      delay(2000); // Espera 2 segundos
      //  LEDs verde OFF,amarillo OFF y rojo ON 
      digitalWrite(pinnLED4, LOW);
      digitalWrite(pinnLED3, LOW);
      digitalWrite(pinnLED2, HIGH);
      delay(8000); // Espera 8 segundos

     
      
    }
  }
}

