#include "Arduino.h"
#include "ButtonsToLED.h"
int Buttons(int greenButton,int yellowButton,int redButton,
	int greenLED,int yellowLED,int redLED){
	
	int count=0;
	int pointer=0;
//buttons
	while(pointer<=0){
	int buttonState1=digitalRead(greenButton);
	int buttonState2=digitalRead(yellowButton);
	int buttonState3=digitalRead(redButton);
	if (buttonState1 != HIGH) {
	digitalWrite(greenLED,HIGH);
	pointer=1;
	}
	else{
  	digitalWrite(greenLED,LOW);
 	}
	if (buttonState2 != HIGH) {
	digitalWrite(yellowLED,HIGH);
	pointer=2;
	}
	else{
  	digitalWrite(yellowLED,LOW);
  	}
	if (buttonState3 != HIGH) {
	digitalWrite(redLED,HIGH);
	pointer=3;
	}
	else{
 	digitalWrite(redLED,LOW);
  	}
	}
	delay(300);
	return pointer;
}

bool ToCloseInstruction(int greenButton,int yellowButton,int redButton){
bool finish=false;
int count=0;
while (count<1){
  int buttonState1=digitalRead(greenButton);
  int buttonState2=digitalRead(yellowButton);
  int buttonState3=digitalRead(redButton);
  if (buttonState1 != HIGH) {
  finish=true;
  count++;
  }
  
  if (buttonState2 != HIGH) {
    
 }
  if (buttonState3 != HIGH) {
    finish=false;
    count++;  
  }
  }
  delay(500);
  return finish;
}