#include <Keyboard.h>

// Put your DuckyScript here (one line per element)
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

const int scriptLines = sizeof(script) / sizeof(script[0]);

void setup() {
  delay(2000); // Wait for 2 seconds after power on
  Keyboard.begin();

  for (int i = 0; i < scriptLines; i++) {
    parseAndExecute(script[i]);
  }

  Keyboard.end();
}

void loop() {}

void parseAndExecute(const char* line) {
  // Remove leading spaces
  while (*line == ' ') line++;

  if (startsWith(line, "REM")) {
    // Comment line, do nothing
    return;
  } else if (startsWith(line, "DELAY ")) {
    int ms = atoi(line + 6);
    delay(ms);
  } else if (startsWith(line, "DEFAULT_DELAY ")) {
    // Advanced feature, can be skipped
    return;
  } else if (startsWith(line, "STRING ")) {
    Keyboard.print(line + 7);
  } else if (strcmp(line, "ENTER") == 0) {
    Keyboard.write(KEY_RETURN);
  } else if (strcmp(line, "TAB") == 0) {
    Keyboard.write(KEY_TAB);
  } else if (startsWith(line, "GUI ")) {
    sendCombo(KEY_LEFT_GUI, getKeyCode(line + 4));
  } else if (startsWith(line, "CONTROL ")) {
    sendCombo(KEY_LEFT_CTRL, getKeyCode(line + 8));
  } else if (startsWith(line, "SHIFT ")) {
    sendCombo(KEY_LEFT_SHIFT, getKeyCode(line + 6));
  } else if (startsWith(line, "ALT ")) {
    sendCombo(KEY_LEFT_ALT, getKeyCode(line + 4));
  } else if (strcmp(line, "ESCAPE") == 0) {
    Keyboard.write(KEY_ESC);
  } else if (strcmp(line, "CAPSLOCK") == 0) {
    Keyboard.write(KEY_CAPS_LOCK);
  } else if (strcmp(line, "DELETE") == 0) {
    Keyboard.write(KEY_DELETE);
  } else if (strcmp(line, "BACKSPACE") == 0) {
    Keyboard.write(KEY_BACKSPACE);
  } else if (strcmp(line, "MENU") == 0) {
    Keyboard.write(0xED); // Application key, not supported by all keyboards
  } else if (strcmp(line, "UP") == 0) {
    Keyboard.write(KEY_UP_ARROW);
  } else if (strcmp(line, "DOWN") == 0) {
    Keyboard.write(KEY_DOWN_ARROW);
  } else if (strcmp(line, "LEFT") == 0) {
    Keyboard.write(KEY_LEFT_ARROW);
  } else if (strcmp(line, "RIGHT") == 0) {
    Keyboard.write(KEY_RIGHT_ARROW);
  } else if (startsWith(line, "F") && isdigit(line[1])) {
    int fn = atoi(line + 1);
    if (fn >= 1 && fn <= 12)
      Keyboard.write(KEY_F1 + (fn - 1));
  }
}

uint8_t getKeyCode(const char* keystr) {
  // Remove leading spaces
  while (*keystr == ' ') keystr++;
  if (strlen(keystr) == 1 && isalpha(keystr[0]))
    return tolower(keystr[0]);
  if (strcmp(keystr, "ENTER") == 0) return KEY_RETURN;
  if (strcmp(keystr, "ESCAPE") == 0) return KEY_ESC;
  if (strcmp(keystr, "TAB") == 0) return KEY_TAB;
  if (strcmp(keystr, "SPACE") == 0) return ' ';
  if (strcmp(keystr, "DELETE") == 0) return KEY_DELETE;
  if (strcmp(keystr, "BACKSPACE") == 0) return KEY_BACKSPACE;
  if (strcmp(keystr, "UP") == 0) return KEY_UP_ARROW;
  if (strcmp(keystr, "DOWN") == 0) return KEY_DOWN_ARROW;
  if (strcmp(keystr, "LEFT") == 0) return KEY_LEFT_ARROW;
  if (strcmp(keystr, "RIGHT") == 0) return KEY_RIGHT_ARROW;
  if (keystr[0] == 'F' && isdigit(keystr[1])) {
    int fn = atoi(keystr + 1);
    if (fn >= 1 && fn <= 12) return KEY_F1 + (fn - 1);
  }
  return keystr[0];
}

bool startsWith(const char* line, const char* prefix) {
  while (*prefix) {
    if (*line++ != *prefix++) return false;
  }
  return true;
}

void sendCombo(uint8_t modifier, uint8_t key) {
  Keyboard.press(modifier);
  Keyboard.press(key);
  delay(100);
  Keyboard.releaseAll();
}
