# Rubber-Ducky

A simple rubber ducky program using arduino leonardo



# Arduino Leonardo Rubber Ducky Script Interpreter

A simple **Rubber Ducky DuckyScript interpreter** for Arduino Leonardo.  
Write your DuckyScript in C array, upload to your Leonardo, and plug it into any computer to automatically execute keyboard commands (HID)!

---

## Features

- Write DuckyScript as `const char* script[]` directly in code
- Supports `DELAY`, `STRING`, `ENTER`, `TAB`, `GUI`, `CONTROL`, `SHIFT`, `ALT`, arrow keys, function keys (`F1~F12`), and more
- No EEPROM/SD card required
- Plug and play (auto run on power up or reset)
- Easy to modify, fast to test

---

## Usage

### 1. **Prepare Your Script**

Edit the `script` array in your Arduino sketch.  
Each array element is a line of DuckyScript.  
**Example:**

```cpp
const char* script[] = {
  "GUI r",
  "DELAY 500",
  "STRING cmd",
  "DELAY 200",
  "ENTER",
  "DELAY 700",
  "STRING start https://www.youtube.com/watch?v=dQw4w9WgXcQ",
  "ENTER"
};
```

### 2. **Upload the Code**

- Open the `.ino` file in Arduino IDE

- Select **Board:** `Arduino Leonardo`  or other arduino that support HID.

- Plug your Leonardo into your computer via USB

- Click **Upload**

### 3. **Test**

- After upload, unplug and re-plug Leonardo into a Windows PC (or press the RESET button).

- The script will run automatically, emulating a keyboard and executing your commands.

---

## Supported DuckyScript Commands

- `REM` - Comment line (ignored)

- `DELAY <ms>` - Wait specified milliseconds (e.g. `DELAY 500`)

- `STRING <text>` - Type text string (e.g. `STRING notepad`)

- `ENTER` - Press Enter key

- `TAB` - Press Tab key

- `GUI <key>` - Press Windows key + key (e.g. `GUI r`)

- `CONTROL <key>` - Press Ctrl + key

- `SHIFT <key>` - Press Shift + key

- `ALT <key>` - Press Alt + key

- `ESCAPE`, `CAPSLOCK`, `DELETE`, `BACKSPACE`, `MENU`

- `UP`, `DOWN`, `LEFT`, `RIGHT` - Arrow keys

- `F1` ~ `F12` - Function keys
