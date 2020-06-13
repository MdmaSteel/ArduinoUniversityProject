#include "Arduino.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "ButtonsToLED.h"
int LevelUP(int quantity);

int LevelDown(int quantity);

void NextLevel(int quantity, bool levelUP);

void Print(char chars[16], int k);

void RepeatTheSequance();

void RememberTheNumbers();

void LetsBegin();

void Wrong();

void Correct();

void HelloDungeonMaster();

void Instruction(int button1, int button2, int button3);