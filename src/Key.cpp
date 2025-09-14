#include "Key.h"

BleKeyboard bleKeyboard;
bool IS_KEYBOARD_ENABLED = true;

const uint8_t Output_Pins[ROW_LENGTH] = {12,14,27,26,25,5}; 
const uint8_t Input_Pins[COL_LENGTH] = {15,2,4,16,17,18,19,21,22,23,33,32,35,34,39,36,13};

Key::Key(uint8_t _keyCode, std::function<void()> _onPressMacro, std::function<void()> _onReleaseMacro)
: keyCode(_keyCode), onPressMacro(_onPressMacro), onReleaseMacro(_onReleaseMacro), _isPressed(false) {}

void Key::press() {
  if (_isPressed) return;
  _isPressed = true;

  if (onPressMacro && KeyMatrix[FN_KEY_ROW][FN_KEY_COL].isPressed()) {
    onPressMacro();
  } else if (IS_KEYBOARD_ENABLED) {
    bleKeyboard.press(keyCode);
  }
}

void Key::release() {
  if (!_isPressed) return;
  _isPressed = false;

  if (onReleaseMacro && KeyMatrix[FN_KEY_ROW][FN_KEY_COL].isPressed()) {
    onReleaseMacro();
  } else {
    bleKeyboard.release(keyCode);
  }
}

bool Key::isPressed() {
  return _isPressed;
}
