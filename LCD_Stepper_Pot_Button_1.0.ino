#include <Stepper.h>
#include <LiquidCrystal.h>

Stepper stepper(2038, 2, 3, 4, 5);            // S Motor pins      

LiquidCrystal lcd (22, 23, 24, 25, 26, 27);   // LCD pins 

#define pushButton 28     // button input pin
#define potMeter A0       // potentiometer input pin

void setup() {
  // setup pot/button pins
  pinMode(pushButton, INPUT);
  pinMode(potMeter, INPUT);
  // set speed for stepper (rpm)
  stepper.setSpeed(1);
  // LCD screen setup
  lcd.begin(16,2);
  // LCD screen setup (minutes)
  lcd.setCursor(3,0);
  lcd.print("Minutes:00");
  // LCD screen setup (intervals)
  lcd.setCursor(1,1);
  lcd.print("Intervals:0");
  }

void loop() {
  int potVal = analogRead(potMeter);                // read pot-meter
  int potValper = map(potVal, 0, 1023, 0, 100);

  if (potValper <= 25){
    lcd.setCursor(0,0);                             // output option on LCD
    lcd.print("15min 5min");                  
    int pushVal = digitalRead(pushButton);
    if (pushVal == 1){                              // pushed makes option start
    // 15 minute study/5 minute break (4 intervals)
      for (int i = 1; i <= 4; i++){                 // intervals loop
        lcd.setCursor(1,0);
        lcd.print("S Minutes:00");                  // S indicates "study"
        for (int j = 1; j <= 15; j++){              // study minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
      // vibrate
        lcd.setCursor(1,0);
        lcd.print("B Minutes:00");                  // B indicates "break"
        for (int j = 1; j <= 5; j++){               // break minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
        // vibrate
        lcd.setCursor(11,1);                        // LCD outputs intervals
        lcd.print(i);
      }
    }
  }
  else if (potValper <= 50 && potValper > 25){
    lcd.setCursor(0,0);
    lcd.print("30min 10min");
    int pushVal = digitalRead(pushButton);
    if (pushVal == 1){
    // 30 minute study/10 minute break (4 intervals)
      for (int i = 1; i <= 4; i++){                 // intervals loop
        lcd.setCursor(1,0);
        lcd.print("S Minutes:00");                  // S indicates "study"
        for (int j = 1; j <= 30; j++){              // study minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
      // vibrate
        lcd.setCursor(1,0);
        lcd.print("B Minutes:00");                  // B indicates "break"
        for (int j = 1; j <= 10; j++){              // break minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
        // vibrate
        lcd.setCursor(11,1);                        // LCD outputs intervals
        lcd.print(i);
      }
    }
  }
  else if (potValper <= 75 && potValper > 50){
    lcd.setCursor(0,0);
    lcd.print("45min 15min");
    int pushVal = digitalRead(pushButton);
    if (pushVal == 1){
    // 45 minute study/15 minute break (4 intervals)
      for (int i = 1; i <= 4; i++){                 // intervals loop
        lcd.setCursor(1,0);
        lcd.print("S Minutes:00");                  // S indicates "study"
        for (int j = 1; j <= 45; j++){              // study minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
      // vibrate
        lcd.setCursor(1,0);
        lcd.print("B Minutes:00");                  // B indicates "break"
        for (int j = 1; j <= 15; j++){              // break minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
        // vibrate
        lcd.setCursor(11,1);                        // LCD outputs intervals
        lcd.print(i);
      }
    }
  }
  else if (potValper <= 100 && potValper > 75){
    lcd.setCursor(0,0);
    lcd.print("60min 20min");
    int pushVal = digitalRead(pushButton);
    if (pushVal == 1){
    // 60 minute study/20 minute break (4 intervals)
      for (int i = 1; i <= 4; i++){                 // intervals loop
        lcd.setCursor(1,0);
        lcd.print("S Minutes:00");                  // S indicates "study"
        for (int j = 1; j <= 60; j++){              // study minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
      // vibrate
        lcd.setCursor(1,0);
        lcd.print("B Minutes:00");                  // B indicates "break"
        for (int j = 1; j <= 20; j++){              // break minutes loop
          stepper.step(2038);                       // full spin
          int ones = j % 10;
          int tens = j / 10;
          lcd.setCursor(11,0);                      // LCD outputs minutes
          lcd.print(tens);
          lcd.setCursor(12,0);
          lcd.print(ones);
        }
        // vibrate
        lcd.setCursor(11,1);                        // LCD outputs intervals
        lcd.print(i);
      }
    }
  }
}