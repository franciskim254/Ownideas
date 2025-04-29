// this is my attempt at a 3 mode led system

const int buttonPin = 2;
const int ledPin = 3;

int State = 0;
int buttonState = 0;
int prevButtonState = 0;
bool ledOn = false;
unsigned long pressTime=0;
unsigned long currentTime = 0;

void ledBlink(int delay ){
	if(currentTime - pressTime >= delay){
		ledOn=!ledOn;
		digitalWrite(ledPin, ledOn);
		pressTime = currentTime;
	}
	
}

void setup(){
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);

}

void loop(){
	currentTime = millis();
	buttonState= digitalRead(buttonPin);
	if(buttonState==HIGH && prevButtonState== LOW ){
		State = (State+1)%3;
  	delay(200);
  }
		prevButtonState=buttonState;


	switch (State){
	case 0: 
			ledBlink(1000);
			break;

	case 1: 
			ledBlink(250);
			break;

	case 2:
			digitalWrite(ledPin, HIGH);
			break;
	}

}