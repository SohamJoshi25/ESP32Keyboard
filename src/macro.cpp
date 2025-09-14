#include "Key.h"

// === Macro Functions ===
auto onPressF12 = []() {
  IS_KEYBOARD_ENABLED = !IS_KEYBOARD_ENABLED;
};
auto onReleaseF12 = []() {};


auto onPressF11 = []() {
   bleKeyboard.write(KEY_MEDIA_VOLUME_UP); 
};
auto onReleaseF11 = []() {};


auto onPressF10 = []() {
   bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);  
};
auto onReleaseF10 = []() {};


auto onPressF9 = []() {
   bleKeyboard.write(KEY_MEDIA_MUTE); 
};
auto onReleaseF9 = []() {};


auto onPressF8 = []() {
    bleKeyboard.write(KEY_MEDIA_STOP); 
};
auto onReleaseF8 = []() {};


auto onPressF7 = []() {
   bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE); 
};
auto onReleaseF7 = []() {};


auto onPressF6 = []() {
   bleKeyboard.write(KEY_MEDIA_NEXT_TRACK); 
};
auto onReleaseF6 = []() {};


auto onPressF5 = []() {
   bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
};
auto onReleaseF5 = []() {};


auto onPressF4 = []() {
 bleKeyboard.write(KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION); 
};
auto onReleaseF4 = []() {};


auto onPressF3 = []() {
 bleKeyboard.write(KEY_MEDIA_CALCULATOR); 
};
auto onReleaseF3 = []() {};


auto onPressF2 = []() {
 bleKeyboard.write(KEY_MEDIA_WWW_SEARCH);
};
auto onReleaseF2 = []() {};


auto onPressF1 = []() {
    bleKeyboard.write(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
};
auto onReleaseF1 = []() {};



// Task Manager
auto onPressEsc = []() {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.press(KEY_ESC);
  delay(20);
  bleKeyboard.release(KEY_LEFT_CTRL);
  bleKeyboard.release(KEY_LEFT_SHIFT);
  bleKeyboard.release(KEY_ESC);
};
auto onReleaseEsc = []() {};


// === Key Matrix ===
Key KeyMatrix[ROW_LENGTH][COL_LENGTH] = {
  {
    Key(KEY_ESC, onPressEsc, onReleaseEsc),
    Key(KEY_F1,  onPressF1,  onReleaseF1),
    Key(KEY_F2,  onPressF2,  onReleaseF2),
    Key(KEY_F3,  onPressF3,  onReleaseF3),
    Key(KEY_F4,  onPressF4,  onReleaseF4),
    Key(KEY_F5,  onPressF5,  onReleaseF5),
    Key(KEY_F6,  onPressF6,  onReleaseF6),
    Key(KEY_F7,  onPressF7,  onReleaseF7),
    Key(KEY_F8,  onPressF8,  onReleaseF8),
    Key(), // empty placeholder
    Key(KEY_F9,  onPressF9,  onReleaseF9),
    Key(KEY_F10, onPressF10, onReleaseF10),
    Key(KEY_F11, onPressF11, onReleaseF11),
    Key(KEY_F12, onPressF12, onReleaseF12),
    Key(KEY_PRTSC),
    Key(KEY_SCROLL_LOCK),
    Key(KEY_PAUSE)
  },
  {Key('`'), Key('1'), Key('2'), Key('3'), Key('4'), Key('5'), Key('6'), Key('7'), Key('8'), Key('9'), Key('0'), Key('-'), Key('='), Key(KEY_BACKSPACE), Key(KEY_INSERT), Key(KEY_HOME), Key(KEY_PAGE_UP)},
  {Key(KEY_TAB), Key('q'), Key('w'), Key('e'), Key('r'), Key('t'), Key('y'), Key('u'), Key('i'), Key('o'), Key('p'), Key('['), Key(']'), Key('\\'), Key(KEY_DELETE), Key(KEY_END), Key(KEY_PAGE_DOWN)},
  {Key(KEY_CAPS_LOCK), Key('a'), Key('s'), Key('d'), Key('f'), Key('g'), Key('h'), Key('j'), Key('k'), Key('l'), Key(';'), Key('\''), Key(), Key(KEY_RETURN), Key(), Key(), Key()},
  {Key(KEY_LEFT_SHIFT), Key('z'), Key('x'), Key('c'), Key('v'), Key('b'), Key('n'), Key('m'), Key(','), Key(0), Key('.'), Key('/'), Key(), Key(KEY_RIGHT_SHIFT), Key(), Key(KEY_UP_ARROW), Key()},
  {Key(KEY_LEFT_CTRL), Key(KEY_LEFT_GUI), Key(KEY_LEFT_ALT), Key(), Key(' '), Key(), Key(), Key(), Key(KEY_RIGHT_ALT), Key(), Key(),Key(KEY_MENU), Key(), Key(KEY_RIGHT_CTRL), Key(KEY_LEFT_ARROW), Key(KEY_DOWN_ARROW), Key(KEY_RIGHT_ARROW)}
};
