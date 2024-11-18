#include <BleKeyboard.h>
#include <Arduino.h>

BleKeyboard bleKeyboard;

const uint8_t Output_Pins[] = {25,26,27,14,12,5}; // COL
const uint8_t Input_Pins[] = {15,2,4,16,17,13,18,19,21,22,23,33,32,35,34,39,36}; // ROW

const uint8_t Input_Pin_Count = sizeof(Input_Pins) / sizeof(Input_Pins[0]);
const uint8_t Output_Pin_Count = sizeof(Output_Pins) / sizeof(Output_Pins[0]);

const uint8_t Index_Key_Mapping[6][17] = {
  {KEY_ESC, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, 0, KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_PRTSC, 0xCF, 0},
  {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', KEY_BACKSPACE, KEY_INSERT, KEY_HOME, KEY_PAGE_UP},
  {KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\', KEY_DELETE, KEY_END, KEY_PAGE_DOWN},
  {KEY_CAPS_LOCK, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',';', '\'', 0, KEY_RETURN, 0, 0, 0},
  {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', 0, '/', 0, KEY_RIGHT_SHIFT, 0, KEY_UP_ARROW, 0},
  {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, 0, ' ', 0, 0, 0, KEY_RIGHT_ALT, 0, 0, 0, 0, KEY_RIGHT_CTRL, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}
};

bool Key_Pressed[6][17];

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing BLE Keyboard...");

  for (uint8_t i = 0; i < Input_Pin_Count; i++) {
    pinMode(Input_Pins[i], INPUT_PULLDOWN);
  }

  for (uint8_t i = 0; i < Output_Pin_Count; i++) {
    pinMode(Output_Pins[i], OUTPUT);
    digitalWrite(Output_Pins[i], LOW);
  }

  

  bleKeyboard.begin();
  bleKeyboard.setDelay(10);
  delay(100);
  Serial.println("Initialization complete.");
}

void checkKeyPress(uint8_t row, uint8_t col) {
  
}

void loop() {

  if (bleKeyboard.isConnected()) {

    for (uint8_t row = 0; row < Output_Pin_Count; row++) {
      digitalWrite(Output_Pins[row], HIGH);
      delay(10);

      for (uint8_t col = 0; col < Input_Pin_Count; col++) {

        if (digitalRead(Input_Pins[col]) == HIGH) {

          if(!Key_Pressed[row][col]) {
            bleKeyboard.press(Index_Key_Mapping[row][col]);
            Serial.printf("Pressed: Row %d, Col %d, Key %c ,%d\n",row,col,Index_Key_Mapping[row][col],Index_Key_Mapping[row][col]);
            Key_Pressed[row][col] = true;
         }

        } else {

          if (Key_Pressed[row][col]) {
            bleKeyboard.release(Index_Key_Mapping[row][col]);
            Serial.printf("Released: Row %d, Col %d, Key %c ,%d\n",row,col,Index_Key_Mapping[row][col],Index_Key_Mapping[row][col]);
            Key_Pressed[row][col] = false;
          }

        }
      }

      digitalWrite(Output_Pins[row], LOW);
      delay(5);
    }

  } else {

    bleKeyboard.releaseAll();
    Serial.println("Waiting for BLE connection...");
    delay(1000);

  }
}