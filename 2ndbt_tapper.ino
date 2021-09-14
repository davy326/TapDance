 /**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

int fsr1 = 4;
int reading1;


void setup() {
  Serial.begin(115200);
      Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    reading1 = analogRead(fsr1);
    if (reading1 > 800)
    {
      bleKeyboard.press('t');
      delay(100);
      bleKeyboard.releaseAll();
      delay(300);
    }
     else if (reading1 > 10 && reading1 <= 800)
    {
      bleKeyboard.press('8');
      delay(100);
      bleKeyboard.releaseAll();
      delay(300);
    }
    delay(100);
  }

}
