#include <Arduino.h> // tipo de libreria utilizada en el laboratorio 01 - Ejercicio_#6
// UNIVERSIDAD TECNICA DEL NORTE
//Integrantes:  Jean Carlos Viscaino, 
              //Jhojan Gabriel Rivera, 
              //Damian Jefferson Sanchez

// Se definen pines 
const int pinnboton1 = 2; // Pin boton 1
const int pinnbotonR = 3; // Pin botón de reinicio
const int pinnLeds[] = {7, 6, 5, 4}; // Arreglo de pines para LEDs 

int count = 0; // Contador 

void setup() {
  // Conf pines  LEDs como salida
  for (int i = 0; i < 4; i++) {
    pinMode(pinnLeds[i], OUTPUT);
  }

  // Conf pinn boton como entrada con pull-up
  pinMode(pinnboton1, INPUT_PULLUP);

  // Confi pinn botón reinicio como entrada con pull-up
  pinMode(pinnbotonR, INPUT_PULLUP);

  // funcion para Iniciar LEDs en off
  updateLEDs();
}

void loop() {
  // Lectura estado del boton 1
  int estadoBoton1 = digitalRead(pinnboton1);

  // Lectura estado del botón R
  int estadoReinicia = digitalRead(pinnbotonR);

  // contador boton1
  if (estadoBoton1 == LOW) {
    count++;

    // reinicia a 0 si pasa de 15
    if (count > 15) {
      count = 0;
    }

    // LEDs son actualizados con el nuevo valor en el contador
    updateLEDs();

    //  evitar rebotes del botón
    delay(500);
  }

  // Reinicia contador si preciana boton de reinicio
  if (estadoReinicia == LOW) {
    count = 0;
    updateLEDs();
  }
}

//  actualiza  LEDs segun contador
void updateLEDs() {
  if (digitalRead(pinnbotonR) == LOW) {

    for (int i = 0; i < 4; i++) {
      digitalWrite(pinnLeds[i], LOW); // Apaga  LEDs
    }
  } else {
    // Ciclo for para ver el valor en los leds del contador
    for (int i = 0; i < 4; i++) {
      digitalWrite(pinnLeds[i], bitRead(count, i)); // LEDs según el valor binario del contador
    }
  }
}

