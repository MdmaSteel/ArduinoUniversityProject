#include <Display.h>
#include <ButtonsToLED.h>
#include <RandLEDBlink.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lsd(0x27, 16, 2);
int greenButton=10;
int yellowButton=9;
int redButton=8;

//end button initialisation
int randNumber=0;
//LED initilisation
int greenLED=13;
int yellowLED=12;
int redLED=11;

//end LED initialisation
bool nextStep=false;
bool message=false;
bool levelUP=false;

bool firstStage=true;
bool secondStage=false;
bool thirdStage=false;

int quantity=1;
void setup() {
 lsd.begin();
 pinMode(greenButton,INPUT_PULLUP);
 pinMode(yellowButton,INPUT_PULLUP);
 pinMode(redButton,INPUT_PULLUP);
 pinMode(greenLED,OUTPUT);
 pinMode(yellowLED,OUTPUT);
 pinMode(redLED,OUTPUT);
 Serial.begin(9600);
 HelloDungeonMaster();
 Instruction(greenButton,yellowButton,redButton);
}
//actions with display

//end actions


// the loop routine runs over and over again forever:
void loop() {
  //buttonToLED
int counter=0;
int buttons[quantity];
int leds[quantity];
if(firstStage){ //!nextStep
RememberTheNumbers();
for(int i=0;i<quantity;i++){
randNumber=random(1,4);
RandBlink(randNumber,greenLED,yellowLED,redLED);
leds[i]=randNumber;
}
//nextStep=true;
firstStage=false;
secondStage=true;
}
//buttons
if(secondStage){ //nextStep
RepeatTheSequance();
for(int i=0;i<quantity;i++){
buttons[i]=Buttons(greenButton,yellowButton,redButton,greenLED,yellowLED,redLED);
}
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
//message=true;
thirdStage=true;
secondStage=false;
}
//Compare random value and input for user
if(thirdStage){ //message
  counter=0;
for(int i=0;i<quantity;i++){
  if(leds[i]==buttons[i]){
    counter++;
  }
}
//message=false;
thirdStage=false;
}

if(counter==quantity){
Correct();
levelUP=true;
}
else{
Wrong();
levelUP=false;
}
if(levelUP){
quantity=LevelUP(quantity);
NextLevel(quantity,levelUP);
//nextStep=false;
firstStage=true;
}
else{
  quantity=LevelDown(quantity);
  NextLevel(quantity,levelUP);
  //nextStep=false;
  firstStage=true;
}
}