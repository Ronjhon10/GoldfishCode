#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,20,4); // set LCD adresses

//button setup
int buttonStatus = 0;
int buttonStatus1 = 0;
int buttonStatus2 = 0;
int buttonStatus3 = 0;

int buttoncounter = 0;
int buttoncounter1 = 0;
int buttoncounter2 = 0;
int buttoncounter3 = 0;

// Variable setup
int i=0;
// Number of impulses detected
int impulsCount=0;
// Sum of all the coins inserted
float total_amount= 0;

// Declare the servo pins for coils
int servoPin = 3;
int servoPin2 = 4;
int servoPin3 = 5;
// Create servo objects for coils
Servo Servo1;
Servo Servo2;
Servo Servo3;

int pos = 0;    // variable to store the servo position of dispense disk

// Declare dispense disk servo
Servo myservo;


void setup() {

  //button setup 

pinMode(10, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);


  lcd.init();
  lcd.init(); // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("    GOLDFISH");
  
  //dispense disk servo
  myservo.attach(6);
  myservo.write(0);
  // Servo to pin
  Servo1.attach(servoPin);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  
   //pinMode(2, INPUT_PULLUP);
 Serial.begin(9600);
 // Interrupt connected to PIN D2 executing IncomingImpuls function when signal goes from HIGH to LOW
 attachInterrupt(0,incomingImpuls, FALLING);

}

void incomingImpuls()
{
  impulsCount=impulsCount+1;
  i=0;
}

void loop() {

 


 //Coin Acceptor Impulse
  i=i+1;

   Serial.print("i=");
   Serial.print(i);
   Serial.print(" Impulses:");
   Serial.print(impulsCount);
   Serial.print(" Total:");
   Serial.println(total_amount);
 
  if (i>=30 and impulsCount==1){
    total_amount=total_amount+.25;
    impulsCount=0;
   
    Serial.println(total_amount);
  }

 
  //Print Dollar Amount
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Cash:$");
  lcd.setCursor(7,0);
  lcd.print(total_amount);
  
  //Logic for button presses



int pinValue = digitalRead(7);
delay(10);
if (buttonStatus != pinValue) {
  if (buttonStatus == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttoncounter++;}
  buttonStatus = pinValue;

  Serial.println(buttoncounter);
        
  if (buttoncounter >= 1) {
    if (total_amount >= .50) { 
   
    //handfull vend
   myservo.write(110);
    delay(1000);
   myservo.write(0);
   
    buttoncounter = 0;
    total_amount = total_amount - .50;
    Serial.print(total_amount);
    }
    }
 } 

  int pinValue1 = digitalRead(8);
delay(10);
if (buttonStatus1 != pinValue1) {
  if (buttonStatus1 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttoncounter1++;}
  buttonStatus1 = pinValue1;

  Serial.println(buttoncounter1);
      
      
  if (buttoncounter1 >= 1) {
    if (total_amount >= 2.00) { 
   
    // Baby Vending Servo Code
    Servo1.attach(servoPin);
   Servo1.write(180);
    delay(3000);
    Servo1.detach();
    buttoncounter1 = 0;
    total_amount = total_amount - 2.00;
    Serial.print(total_amount);
    }
    }
 } 

  int pinValue2 = digitalRead(9);
delay(10);
if (buttonStatus2 != pinValue2) {
  if (buttonStatus2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttoncounter2++;}
  buttonStatus2 = pinValue2;

  Serial.println(buttoncounter2);
      
      
  if (buttoncounter2 >= 1) {
    if (total_amount >= 2.00) { 
   
    // Baby Vending Servo Code
    Servo2.attach(servoPin2);
   Servo2.write(180);
    delay(3000);
    Servo2.detach();
    buttoncounter2 = 0;
    total_amount = total_amount - 2.00;
    Serial.print(total_amount);
    }
    }
 } 


  int pinValue3 = digitalRead(10);
delay(10);
if (buttonStatus3 != pinValue3) {
  if (buttonStatus3 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttoncounter3++;}
  buttonStatus3 = pinValue3;

  Serial.println(buttoncounter3);
      
      
  if (buttoncounter3 >= 1) {
    if (total_amount >= 2.00) { 
   
    // Baby Vending Servo Code
    Servo3.attach(servoPin3);
   Servo3.write(180);
    delay(3000);
    Servo3.detach();  
    buttoncounter3 = 0; 
    total_amount = total_amount - 2.f00;
    Serial.print(total_amount);
    }
    }
 } 
}
