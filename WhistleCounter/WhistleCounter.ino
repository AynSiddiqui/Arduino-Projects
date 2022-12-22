#include <TM1637.h>
const int CLK = 2;
const int DIO = 3;
TM1637 tm(CLK,DIO);
int num=0;
int sensorPin = A4;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
const char BUTTON_PIN = 4;
bool pressed = false;
int count=0;
int a=0,b=0;
const int buzzer = 11;
void displayNumber(int num){   
  tm.display(3, num % 10);   
  tm.display(2, num / 10 % 10);   
  tm.display(1, num / 100 % 10);   
  tm.display(0, num / 1000 % 10);
}
int holdTime=0;
int startPressed=0;

void setup() {
  // put your setup code here, to run once:
  tm.init();
  // set brightness; 0-7
  tm.set(6);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  displayNumber(num); 
      tone(buzzer, 0);
  
}

void loop() {
  displayNumber(num);  
   bool currentState = digitalRead(BUTTON_PIN);
    if (currentState == pressed) {
    Serial.println("Hello");
    startPressed=millis(); 
    noTone(11);     // Stop sound...
    // delay(1000); 
    //tone(buzzer, 10);
      if(num>7){
        for(int i=0;i<10;i++){
        tm.set(7);
        displayNumber(8888); 
        tone(buzzer, 200); 
        delay(200); 
        noTone(buzzer);      
        // digitalWrite(LED_PIN, ledState);
        displayNumber(0);    
        delay(100);}
        num=0;
        return;
        }
    num+=1;
    displayNumber(num);
    tone(buzzer, 4000); // Send 1KHz sound signal...
    delay(100); 
    noTone(buzzer); 
    while(digitalRead(BUTTON_PIN) == pressed) {    
    holdTime = millis() - startPressed;
      if (holdTime >= 2000) {
          //Serial.println("Button is held for more than a second"); 
          startPressed=0;
          num=0;
          displayNumber(num);
      }
    }
  } 
  sensorValue = analogRead(sensorPin);
  if(num>0){
    a=0;
    while(a<10000 && sensorValue>=100){
      sensorValue = analogRead(sensorPin);
      Serial.println(sensorValue);
      a+=500;
      delay(500);
      if (a>1000){
        num--;
        return;
      }
    }
  }
  noTone(buzzer);     // Stop sound...

  // digitalWrite(ledPin, HIGH);
  // delay(sensorValue);
  // digitalWrite(ledPin, LOW);
  // delay(sensorValue);

}
