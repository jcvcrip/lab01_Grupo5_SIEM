#include <Arduino.h> // tipo de libreria utilizada en el laboratorio 01 - Ejercicio_#3
// UNIVERSIDAD TECNICA DEL NORTE
//Integrantes:  Jean Carlos Viscaino, 
              //Jhojan Gabriel Rivera, 
              //Damian Jefferson Sanchez
// Se definen pinnes 
const int pinnBoton1 = 2;  // Pinn botón #1
const int pinnLED1 = 4;    // Pinn  LED #1
const int pinnLED2 = 5;    // Pinn  LED #2
const int pinnLED3 = 6;    // Pinn  LED #3
const int pinnLED4 = 7;    // Pinn  LED #4

bool activo = false; // Variable para controlar el ciclo 

void setup() {
 
  pinMode(pinnLED1, OUTPUT);   // Conf. el pinn  LED#1 como salida
  pinMode(pinnLED2, OUTPUT);   // Conf. el pinn  LED#2 como salida
  pinMode(pinnLED3, OUTPUT);   // Conf. el pinn  LED#3 como salida
  pinMode(pinnLED4, OUTPUT);   // Conf. el pinn  LED#4 como salida
  pinMode(pinnBoton1, INPUT);  // Conf. el pinn  botón como entrada
}

void loop() {
  int botonPresionado = digitalRead(pinnBoton1); // Lectura de boton
  if (botonPresionado == LOW && !activo) { // Verificar si el botón esta ON Y ciclo en OFF
     activo = true; // Activar el ciclo


    while (activo) { // Ciclo infinito
      // Encender los LEDs azul y 3 amarillo dura 5 seg
      digitalWrite(pinnLED1, HIGH);
      digitalWrite(pinnLED3, HIGH);
      delay(5000); // Espera 5 seg
      // Apagar los LEDs azul  y amarillo 
      digitalWrite(pinnLED1, LOW);
      digitalWrite(pinnLED3, LOW);
      // Encender los LEDs rojo y verde dura 5 seg
      digitalWrite(pinnLED2, HIGH);
      digitalWrite(pinnLED4, HIGH);
      delay(5000); // Espera 5 seg
      // Apagar los LEDs rojo y verde
      digitalWrite(pinnLED2, LOW);
      digitalWrite(pinnLED4, LOW);
      // Apagar los LEDs azul,rojo,amarillo y verde
      digitalWrite(pinnLED1, LOW);
      digitalWrite(pinnLED2, LOW);
      digitalWrite(pinnLED3, LOW);
      digitalWrite(pinnLED4, LOW);
      delay(10000); // Espera 10 seg

    }
  }
}
