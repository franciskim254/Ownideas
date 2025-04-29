//PIR sensor display
#include <Adafruit_LiquidCrystal.h>

const int PIR =2;
const int led =8;
const int button =3;
int motion = 0;
int lastState=0;
int lastButtonState=0;
int buttonState=0;

unsigned long currentMillis =0;
float buffer[5];
int index=0;

int seconds = 0;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(button, INPUT);
  lcd.begin(16,2);
  lcd.setBacklight(1);;
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motion at:");
  lcd.setCursor(6,1);
  lcd.print("Sec");
  lcd.setCursor(0,1);

  

}

void loop()
{
  motion = digitalRead(PIR);
  buttonState=digitalRead(button);
  
  if (motion && !lastState){
    digitalWrite(led, HIGH);
    currentMillis = millis();
    float timeInSec= currentMillis/1000.0;
    lcd.print(timeInSec,2);
    lcd.print(" ");
    lcd.setCursor(0,1);
    buffer[index]=timeInSec;
    index=(index+1)%5;
    
  }
    if( millis()- currentMillis>=500){
       digitalWrite(led, LOW);
    }
    if(buttonState && !lastButtonState){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Prev time");
      delay(1000);
      for(int i=0;i<5;i++){
        lcd.setCursor(0,1);
        lcd.print("      ");
        lcd.setCursor(0,1);
        lcd.print(i+1);
        lcd.setCursor(2,1);
        lcd.print(buffer[i],2);
        delay(1000);
      }
      lastButtonState=buttonState;
    }
  lastState = motion;
}
