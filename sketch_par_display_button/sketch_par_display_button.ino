#define del 1000
#include <LiquidCrystal.h>

//(1)
int buttonpin13 = 13;
int buttonState13 = 0;

/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
 
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int offsetTime = 0;

void setup() {
  lcd.cursor();
  lcd.blink();

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello World!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print((millis() - offsetTime) / 1000);

  // Read the button
  buttonState13 = digitalRead(buttonpin13);
  delay(50);

  if (buttonState13 == HIGH) {
    offsetTime = millis();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello World!");
  }
}
