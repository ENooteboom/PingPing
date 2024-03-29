//follow me @ https://www.twitch.tv/noot_gaming to watch me code this live

//        UwU

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <SoftwareSerial.h>
#include "Adafruit_Soundboard.h"
#include <ezButton.h>

Adafruit_7segment matrix = Adafruit_7segment();

#define SFX_TX 10
#define SFX_RX 11
#define SFX_RST 4

SoftwareSerial ss = SoftwareSerial(SFX_TX, SFX_RX);
Adafruit_Soundboard sfx = Adafruit_Soundboard(&ss, NULL, SFX_RST);

//player 1 button
ezButton button1(2);          // the number of the pushbutton pin
const int ledPin1 =  13;      // the number of the LED pin
//player 2 button
ezButton button2(3);           // the number of the pushbutton pin
const int ledPin2 =  13;      // the number of the LED pin

int gameState = 0;
unsigned long  millisCOUNTER;
int INTROLENGTH = 15000;

void setup() {
#ifndef __AVR_ATtiny85__
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  //  pinMode(button1Pin, INPUT);
  pinMode(ledPin2, OUTPUT);
  //  pinMode(button2Pin, INPUT);

  button1.setDebounceTime(50); // set debounce time to 50 milliseconds
  button1.setCountMode(COUNT_RISING);
  button2.setDebounceTime(50); // set debounce time to 50 milliseconds
  button2.setCountMode(COUNT_RISING);

  Serial.println("Buttons Init");
#endif
  matrix.begin(0x70);
  Serial.println("Matrix Init");

  ss.begin(9600);

  if (!sfx.reset()) {
    Serial.println("Not found");
    while (1);
  }
  Serial.println("SFX Board Init");
}

void loop() {
  button1.loop(); // MUST call the loop() function first
  button2.loop(); // MUST call the loop() function first
  unsigned long count1 = button1.getCount();
  unsigned long count2 = button2.getCount();
  button1.resetCount();
  button2.resetCount();
  Serial.println(count1);
  Serial.println(count2);

  while (1) {
    switch (gameState) {
      case 0: {
          Serial.println("0");
          button1.loop(); // MUST call the loop() function first
          button2.loop();

          //try to print a number thats too long (- - - -)
          matrix.print(10000, DEC);
          matrix.writeDisplay();

          gameState = 1;

          break;
        }

      case 1: {
          Serial.println("1");
          introstart = millis();
          //sfx.playTrack("INTRO   OGG");
          break;
        }

      case 2: {
          Serial.println("2");
          break;
        }
        delay(1);
    }
  }

}


//ezButton()
//setDebounceTime()
//getState()
//getStateRaw()
//isPressed()
//isReleased()
//setCountMode()
//getCount()
//resetCount()
//loop()
