#ifndef KEY_H
#define KEY_H

#include <Arduino.h>
#include <BleKeyboard.h>
#include <functional>


#define ROW_LENGTH 6
#define COL_LENGTH 17

#define KEY_SCROLL_LOCK 0xCF //0x47 WILL NOT WORK | ( 0x47 + 136 ) 
#define KEY_PAUSE       0xD0 //0x48 WILL NOT WORK | ( 0x48 + 136 ) 
#define KEY_MENU        0xED //0x65 WILL NOT WORK | ( 0x65 + 136 ) 

#define FN_KEY_ROW 5
#define FN_KEY_COL 10

extern BleKeyboard bleKeyboard;
extern bool IS_KEYBOARD_ENABLED;

class Key {
  private:
    std::function<void()> onPressMacro;
    std::function<void()> onReleaseMacro;
    uint8_t keyCode;
    bool _isPressed;

  public:
    Key(uint8_t _keyCode = 0,
        std::function<void()> _onPressMacro = nullptr,
        std::function<void()> _onReleaseMacro = nullptr);

    void press();
    void release();
    bool isPressed();
};

extern Key KeyMatrix[ROW_LENGTH][COL_LENGTH];
extern const uint8_t Output_Pins[ROW_LENGTH];
extern const uint8_t Input_Pins[COL_LENGTH];

#endif
