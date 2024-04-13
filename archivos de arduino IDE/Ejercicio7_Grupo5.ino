#include <Arduino.h> // tipo de libreria utilizada en el laboratorio 01 - Ejercicio_#7
// UNIVERSIDAD TECNICA DEL NORTE
//Integrantes:  Jean Carlos Viscaino, 
              //Jhojan Gabriel Rivera, 
              //Damian Jefferson Sanchez
// Def. de pines LED Y BOTON
#define LED_PIN_4 4
#define LED_PIN_5 5
#define LED_PIN_6 6
#define LED_PIN_7 7
#define LED_PIN_8 8
#define BUTTON_PIN 2
// Número de LED
int numLEDs = 5;
// encendido de LED (en milisegundos)
int tiempoEspera = 200; 
void setup() {
  // Inicialización de pines
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_8, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}
void loop() {
  // lECTURA DEL BOTON hasta que presione el botón
  while (digitalRead(BUTTON_PIN) == HIGH) {
    // Espera pasiva
  }
    // Al presionar el botón, comienza el juego
  jugarRuletaRusa();
}
void jugarRuletaRusa() {
  // Apaga todos los LEDs
  apagarLEDS();
    // Genera un número aleatorio para determinar qué LED se enciende
  int ledAleatorio = random(0, numLEDs);
    // Enciende el LED correspondiente al número aleatorio generado
  digitalWrite(ledAPin(ledAleatorio), HIGH);
    // Espera un momento para simular la tensión del juego
  delay(tiempoEspera);
}
// Método para obtener el pin correspondiente a un LED dado su número
int ledAPin(int ledNumero) {
  switch(ledNumero) {
    case 0:
      return LED_PIN_4;
    case 1:
      return LED_PIN_5;
    case 2:
      return LED_PIN_6;
    case 3:
      return LED_PIN_7;
    case 4:
      return LED_PIN_8;
    default:
      return -1; // En caso de error
  }
}
// Método para apagar todos los LEDs
void apagarLEDS() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledAPin(i), LOW);
  }
}
