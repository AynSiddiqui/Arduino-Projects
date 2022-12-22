#include <LiquidCrystal.h>

#include <TM1637.h>
const int CLK = 2;
const int DIO = 3;
TM1637 tm(CLK,DIO);
int num=1001;
int sensorPin = A4;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
const int button=4;
int count=0;
void displayNumber(int num){   
  tm.display(3, num % 10);   
  tm.display(2, num / 10 %10);   
  tm.display(1, num / 100 % 10);   
  tm.display(0, num / 1000 % 10);
}


void setup() {
  // put your setup code here, to run once:
  tm.init();
  // set brightness; 0-7
  tm.set(1);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  // int buttonstate=digitalRead(button);
  // if(buttonstate!=HIGH){
  //   num+=1;
  // }else{
  //   Serial.print(buttonstate);
  // }
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  Serial.println(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
  //num++;
  int n=0;
  int inc=1;
  // if(n=0 or n>7){
  //   inc=-inc;
  // }
  //Serial.println(n);
  //n+=inc;
  displayNumber(num);
  // int num =1001;
  // tm.display(3, num % 10);   
  // tm.display(2, num / 10 % 10);   
  // tm.display(1, num / 100 % 10);   
  // tm.display(0, num / 1000 % 10);
  // put your main code here, to run repeatedly:  
  tm.set(n);
  if(num==9999){
    num=0;
  }
  delay(20);
}
