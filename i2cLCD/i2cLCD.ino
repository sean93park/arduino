/* YourDuino.com Example Software Sketch
 16 character 2 line I2C Display
 Backpack Interface labelled "A0 A1 A2" at lower right.
 ..and
 Backpack Interface labelled "YwRobot Arduino LCM1602 IIC V1"
 MOST use address 0x27, a FEW use 0x3F
 terry@yourduino.com */

/*
 * https://arduino-info.wikispaces.com/LCD-Blue-I2C
 */
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  Serial.begin(115200);          // maybe have to set 115200 in monitor to see correctly
  pinMode(13, OUTPUT);
  lcd.begin(16,2);               // initialize the lcd 

  // lcd backlight blink test
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  

  delay(500);
  
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!!!");
  lcd.setCursor(0,1);
  lcd.print("Use Serial Mon"); 

  Serial.print("freq = ");
  Serial.println(F_CPU);

  delay(500);
}

void loop()
{
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(900);

  {
    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }
  }
}

