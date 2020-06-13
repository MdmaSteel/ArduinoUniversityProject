#include "Arduino.h"
#include "Wire.h" 
#include "LiquidCrystal_I2C.h"
#include "Display.h"
#include "ButtonsToLED.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);

int LevelUP(int quantity){
	
	return quantity+1;
}

int LevelDown(int quantity){

	if(quantity>1){
  	return quantity-1;
  	}
	else{
  	lcd.setCursor(4,0);
  	lcd.print("WASTED...");
  	return quantity;
	}
}

void NextLevel(int quantity, bool levelUP){

	int level=quantity;
 	if(levelUP){
  	lcd.clear();
  	lcd.print("Well done!");
  	delay(1000);
  	lcd.setCursor(2,1);
  	lcd.print("Level UP!");
  	delay(1000);
 	}
 	else{
  	lcd.clear();
  	char loserChars[]="Don't give up!";  
  	for(int i=0;i<14;i++){
  	lcd.print(loserChars[i]);
  	delay(200);
  	}
  	delay(400);
  	lcd.setCursor(0,1);
  	lcd.print("Level Down!");
  	delay(500);
 	}
  	delay(500);
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Level :");
  	lcd.print(level);
  	delay(500);
  	lcd.clear();
  	lcd.print("Here will be ");
  	lcd.print(quantity);
  	delay(500);
  	lcd.setCursor(0,1);
  	lcd.print("numbers");
  	delay(2000);
}

void Print(char chars[16], int k){

  	for(int i=0;i<k;i++){
    	lcd.print(chars[i]);
    	delay(200);
  	}
}

void RepeatTheSequance(){
  lcd.clear();
  char chars[]="Repeat the";
  char chars1[]="   sequance";
  Print(chars,10);
  lcd.setCursor(0,1);
  Print(chars1,11);
}

void RememberTheNumbers(){
lcd.clear();  
char chars[]="Remember the";
  char secondChars[]="     numbers";
  Print(chars,12);
  lcd.setCursor(0,1);
  Print(secondChars,12);
  delay(200);
}

void Wrong(){

lcd.clear();
lcd.print("WRONG!!!");
for(int positionCounter=0;positionCounter<24;positionCounter++){
  lcd.scrollDisplayRight();
  delay(200);
}
lcd.clear();
}
void Correct(){

lcd.clear();
lcd.print("Correct!");
delay(200);
for(int positionCounter=0;positionCounter<24;positionCounter++){
  lcd.scrollDisplayRight();
  delay(200);

}
lcd.clear();
}
void HelloDungeonMaster(){
  lcd.print("Welcome");
  delay(500);
  lcd.print(" To");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("Deep");
  delay(500);
  lcd.print("Dark");
  delay(500);
  lcd.print("Fantasy");
  delay(5000);
  lcd.clear();
  
  
}

void Instruction(int button1, int button2, int button3){
bool finish=false;
do{
char chars2[]="There are simply";
  char chars3[]=" rules:";
  char firstRule[]="There will be";
  char firstRule2[]="three buttons";
  char firstRule3[]=" and three LED's";
  char secondRule[]="You should";
  char secondRule_1[]=" remember";
  char secondRule2[]="how did LED's ";
  char secondRule2_2[]="blinked";
  char secondRule3[]="And repeat the";
  char secondRule3_3[]="sequance";
  char secondRule4[]="with the buttons";
  char understood[]="UNDERSTOOD?";
  lcd.setCursor(0,0);
  Print(chars2,16);
  delay(200);
  lcd.setCursor(0,1);
  Print(chars3,6);
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  Print(firstRule,16);
  delay(200);
  lcd.setCursor(0,1);
  Print(firstRule2,13);
  delay(200);
  lcd.clear();
  Print(firstRule3,15);
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  Print(secondRule,10);
  delay(200);
  lcd.setCursor(0,1);
  Print(secondRule_1,8);
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  Print(secondRule2,12);
  delay(200);
  lcd.setCursor(0,1);
  Print(secondRule2_2,7);
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  Print(secondRule3,14);
  delay(200);
  lcd.setCursor(0,1);
  Print(secondRule3_3,8);
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  Print(secondRule4,16);
  delay(200);
  lcd.clear();
  lcd.setCursor(2,0);
  Print(understood,11);
  lcd.setCursor(0,1);
  lcd.print("left-y right-n");
  delay(1000);
finish=ToCloseInstruction(button1,button2,button3);
}while(!finish);
  lcd.setCursor(0,1);
  lcd.clear();
  char chars1[]="Let's begin!";
  lcd.setCursor(2,1);
  Print(chars1,12);
  delay(200);
  lcd.clear();
  
}