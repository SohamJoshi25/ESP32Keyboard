#include "Key.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing BLE Keyboard...");

  for (uint8_t i = 0; i < COL_LENGTH; i++) {
    pinMode(Input_Pins[i], INPUT_PULLDOWN);
  }
  for (uint8_t i = 0; i < ROW_LENGTH; i++) {
    pinMode(Output_Pins[i], OUTPUT);
    digitalWrite(Output_Pins[i], LOW);
  }

  bleKeyboard.begin();
  delay(100);
  Serial.println("Initialization complete.");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    for (uint8_t row = 0; row < ROW_LENGTH; row++) {
      digitalWrite(Output_Pins[row], HIGH);
      delay(10);
      for (uint8_t col = 0; col < COL_LENGTH; col++) {
        bool isPressed = digitalRead(Input_Pins[col]);
        if (isPressed) {
          KeyMatrix[row][col].press();
        } else {
          KeyMatrix[row][col].release();
        }
      }
      digitalWrite(Output_Pins[row], LOW);
    }
  } else {
    bleKeyboard.releaseAll();
    delay(1000);
  }
}
