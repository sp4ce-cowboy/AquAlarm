/*
  aqualarm by VRMC
*/
#include <TimeLib.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int colorR = 255;
int colorG = 255;
int colorB = 255;
int sound1 = 1; //testing
int sound2 = 0; //1 / 0 -> on(loud) / off
int soundPin = 9; //BUZZER
int alarmChange = 7;
int alarmState = 1;
int alarmTime[] = {alarmChange, 0, 0, 10, 15}; //{hour,minute,second,start spraying,end}
int alarmInterval = 1000;
int relayState = LOW;
int relayInterval = 2000;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  setTime(6, 59, 50, 20, 1, 2019);
  pinMode(7, INPUT);//BUTTON
  pinMode(3, INPUT);//RELAY
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  alarmChange = analogRead(A2);//POTENTIOMETER
  alarmChange = map(alarmChange, 0, 1023, 0, 24);
  alarmTime[0] = alarmChange;
  printPerSec();
  alarm();
}

void timePrint() {
  String h = String(hour());
  if (hour() < 10) {
    h = "0" + h;
  }
  String m = String(minute());
  if (minute() < 10) {
    m = "0" + m;
  }
  String s = String(second());
  if (second() < 10) {
    s = "0" + s;
  }
  lcd.print("Time: " + h + ":" + m + ":" + s);
}
void alarmPrint() {
  String h = String(alarmTime[0]);
  if (alarmTime[0] < 10) {
    h = "0" + h;
  }
  String m = String(alarmTime[1]);
  if (alarmTime[1] < 10) {
    m = "0" + m;
  }
  lcd.setCursor(0, 1);
  lcd.print("Alarm: " + h + ":" + m);
}
void alarm() {
  if (hour() == alarmTime[0] && minute() == alarmTime[1] && second() >= alarmTime[2] && second() < alarmTime[2] + alarmTime[4] && alarmState == 1) { //interval 1
    if (digitalRead(7) == 1) {
      alarmState = 0;
    }
    if (second() % 2 == 0) {
      colorG = 50;
      colorB = 50;
    } else {
      colorG = 255;
      colorB = 255;
    }
    if (sound1 == 1) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis3 >= alarmInterval) {
      previousMillis3 = currentMillis;
      if (sound2 == 0) {
        sound2 = 1;
      } else {
        sound2 = 0;
      }
      tone(soundPin, 20, 100);
    }
  }
  }
  if (alarmState == 0) {
    colorG = 255;
    colorB = 255;
  }
  if (hour() == alarmTime[0] && minute() == alarmTime[1] && second() >= alarmTime[2] + alarmTime[3] && second() < alarmTime[2] + alarmTime[4]) {//interval 2
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis2 >= relayInterval) {
      previousMillis2 = currentMillis;
      if (relayState == HIGH) {
        relayState == LOW;
      } else {
        relayState == HIGH;
      }
      digitalWrite(3, relayState);
    }
  }
}
void printPerSec() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis1 >= 1000) {
    previousMillis1 = currentMillis;
    lcd.setRGB(colorR, colorG, colorB);
    lcd.clear();
    timePrint();
    alarmPrint();
  }
}
