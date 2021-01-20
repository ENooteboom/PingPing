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

  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
  Serial.println("Adafruit Sound Board!");

  ss.begin(9600);

  if (!sfx.reset()) {
    Serial.println("Not found");
    while (1);
  }
  Serial.println("SFX board found");

}

void loop() {

  // try to print a number thats too long
  matrix.print(10000, DEC);
  matrix.writeDisplay();


  button1.loop(); // MUST call the loop() function first
  button2.loop(); // MUST call the loop() function first
  unsigned long count1 = button1.getCount();
  unsigned long count2 = button2.getCount();
  Serial.println(count1);





}
