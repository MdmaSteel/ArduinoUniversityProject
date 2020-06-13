#include "Arduino.h"
#include "RandLEDBlink.h"

void RandBlink(int rand,int green,int yellow,int red){
	pinMode(green,OUTPUT);
	pinMode(yellow,OUTPUT);
	pinMode(red,OUTPUT);
	int pointer=0;

 	if(rand==1){
  	digitalWrite(green,HIGH);
  	delay(250);
  	digitalWrite(green,LOW);
 	}

 	else{
  	digitalWrite(green,LOW);
  	delay(250);
 	}

 	if(rand==2){
 	digitalWrite(yellow,HIGH);
  	delay(250);
  	digitalWrite(yellow,LOW);
 	}

 	else{
  	digitalWrite(yellow,LOW);
  	delay(250);
 	}

 	if(rand==3){
  	digitalWrite(red,HIGH);
  	delay(250);
  	digitalWrite(red,LOW);
 	}

 	else{
  	digitalWrite(red,LOW);
  	delay(250);
 	}
}