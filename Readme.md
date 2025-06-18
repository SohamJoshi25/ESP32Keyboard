# ESP32Keyboard

My Keyboard Broke, so i used the keys of the broken mechanical keyboard, wired the switches with an ESP-32 and wrote the firmware for hardware using the Bluetooth Library in c++. I also had to hand soldered 100 zener diode 3 whole times (Check their Polarity twice🥲).

## 🚀 Features

- Emulates generic USB HID keyboard using ESP32
- Send characters or commands over Wi‑Fi/Bluetooth/Serial
- Configurable key mappings and sequences
- Open-source, easy to extend


## 📂 Code Organization

```
ESP32Keyboard/
├── ESP32Keyboard.ino        ← Main sketch
├── README.md                ← This file
├── LICENSE                  ← MIT license (if included)
└── examples/                ← Optional example sketches
```

## ⚙️ Configuration

* Modify key sequences in the global variables or functions (e.g., typing a password).
* Define your preferred input interface: serial, Wi‑Fi, Bluetooth.
* Customize USB HID descriptor if needed (advanced).

## 🧪 Usage Examples

* Send “hello world” over Serial → ESP32 types it to the host.
* Use Bluetooth input app on phone to type on your computer.
* Automate login typing or repetitive commands.

## 🧩 Extensibility

* Add support for gamepad or media keys.
* Create REST/WebSocket interface for remote typing.
* Combine with sensors to trigger auto-typing.

## Some Glimpses of making the keyboard

<br>
<br>
<img src="https://raw.githubusercontent.com/SohamJoshi25/ESP32Keyboard/refs/heads/main/images/1.jpg" alt="image1" width="500">
<br>
<br>
<img src="https://raw.githubusercontent.com/SohamJoshi25/ESP32Keyboard/refs/heads/main/images/2.jpg" alt="image2" width="500">
<br>
<br>
<img src="https://raw.githubusercontent.com/SohamJoshi25/ESP32Keyboard/refs/heads/main/images/1.jpg" alt="image3 " width="500">
<br>
<br>