// this is my attempt at a 3 mode led system
#include <Arduino.h>

const int buttonPin = 3;
const int ledPin = 2;

int State = 0;
int currentState = 0;
int buttonState = 0;
int prevButtonState = 0;
bool buttonPressed = false;
unsigned long currentTime;
unsigned long pressTime;

void ledBlink(int delay ){
	pressTime=currentTime;
	digitalWrite(ledPin, HIGH);
	if(currentTime - pressTime >= delay){
		digitalWrite(ledPin, LOW);
	}
}

void setup(){
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);

}

void loop(){
	currentTime=millis();
	buttonState= digitalRead(buttonPin);
	if(buttonState==HIGH && prevButtonState== LOW ){
		buttonPressed=!buttonPressed;
		State = (currentState+1)%3;
		prevButtonState=buttonState;
	}else if (buttonState==LOW && prevButtonState== HIGH){
		buttonPressed=!buttonPressed;
		State = (currentState+1)&3;
		prevButtonState=buttonState;
	}

	switch (State){
	case 0: 
			ledBlink(2000);

	case 1: 
			ledBlink(1000);

	case 2:
			ledBlink(500);
	}

}