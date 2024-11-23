#include <BleKeyboard.h>
#include <Arduino.h>

#define ROW_LENGTH 6
#define COL_LENGTH 17

#define FN_KEY_ROW 5
#define FN_KEY_COL 10

class Key;
extern Key KeyMatrix[ROW_LENGTH][COL_LENGTH]; 

BleKeyboard bleKeyboard;
bool IS_KEYBOARD_ENABLED = true;

const uint8_t Output_Pins[ROW_LENGTH] = {12,14,27,26,25,5}; 
const uint8_t Input_Pins[COL_LENGTH] = {15,2,4,16,17,18,19,21,22,23,33,32,35,34,39,36,13};
class Key {

  private:
    std::function<void()> onPressMacro;
    std::function<void()> onReleaseMacro;
    uint8_t keyCode;
    bool _isPressed = false;

  public:
    Key(uint8_t _keyCode = 0 , std::function<void()> _onPressMacro = nullptr, std::function<void()> _onReleaseMacro = nullptr)
    : keyCode(_keyCode) , onPressMacro(_onPressMacro), onReleaseMacro(_onReleaseMacro) {}

    void press() {
      if(_isPressed)return;
      _isPressed = true;

      if (onPressMacro && KeyMatrix[FN_KEY_ROW][FN_KEY_COL].isPressed()) {
        onPressMacro();
      } else if(IS_KEYBOARD_ENABLED) {
        bleKeyboard.press(keyCode);
      }
    }

    void release() {
      if(!_isPressed)return;
      _isPressed = false;

      if (onReleaseMacro && KeyMatrix[FN_KEY_ROW][FN_KEY_COL].isPressed()) {
        onReleaseMacro();
      } else {
        bleKeyboard.release(keyCode);
      }
    }

    bool isPressed(){
      return _isPressed;
    }

};

auto onPressF12 = [&]() {
  IS_KEYBOARD_ENABLED = !IS_KEYBOARD_ENABLED;
};

auto onReleaseF12 = [&]() {
};

auto onPressEsc = [&]() {//Task Manager
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.press(KEY_ESC);
  delay(20);
  bleKeyboard.release(KEY_LEFT_CTRL);
  bleKeyboard.release(KEY_LEFT_SHIFT);
  bleKeyboard.release(KEY_ESC);
};

auto onReleaseEsc = [&]() {
};

Key KeyMatrix[ROW_LENGTH][COL_LENGTH] = {
  {Key(KEY_ESC,onPressEsc,onReleaseEsc), Key(KEY_F1), Key(KEY_F2), Key(KEY_F3), Key(KEY_F4), Key(KEY_F5), Key(KEY_F6), Key(KEY_F7), Key(KEY_F8), Key(), Key(KEY_F9), Key(KEY_F10), Key(KEY_F11), Key(KEY_F12,onPressF12,onReleaseF12), Key(KEY_PRTSC), Key(KEY_SCROLL_LOCK), Key(KEY_PAUSE)},
  {Key('`'), Key('1'), Key('2'), Key('3'), Key('4'), Key('5'), Key('6'), Key('7'), Key('8'), Key('9'), Key('0'), Key('-'), Key('='), Key(KEY_BACKSPACE), Key(KEY_INSERT), Key(KEY_HOME), Key(KEY_PAGE_UP)},
  {Key(KEY_TAB), Key('q'), Key('w'), Key('e'), Key('r'), Key('t'), Key('y'), Key('u'), Key('i'), Key('o'), Key('p'), Key('['), Key(']'), Key('\\'), Key(KEY_DELETE), Key(KEY_END), Key(KEY_PAGE_DOWN)},
  {Key(KEY_CAPS_LOCK), Key('a'), Key('s'), Key('d'), Key('f'), Key('g'), Key('h'), Key('j'), Key('k'), Key('l'), Key(';'), Key('\''), Key(), Key(KEY_RETURN), Key(), Key(), Key()},
  {Key(KEY_LEFT_SHIFT), Key('z'), Key('x'), Key('c'), Key('v'), Key('b'), Key('n'), Key('m'), Key(','), Key(0), Key('.'), Key('/'), Key(), Key(KEY_RIGHT_SHIFT), Key(), Key(KEY_UP_ARROW), Key()},
  {Key(KEY_LEFT_CTRL), Key(KEY_LEFT_GUI), Key(KEY_LEFT_ALT), Key(), Key(' '), Key(), Key(), Key(), Key(KEY_RIGHT_ALT), Key(), Key(),Key(KEY_MENU), Key(), Key(KEY_RIGHT_CTRL), Key(KEY_LEFT_ARROW), Key(KEY_DOWN_ARROW), Key(KEY_RIGHT_ARROW)}
};


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