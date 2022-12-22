const char BUTTON_PIN = 2;
bool pressed = false;
 
void setup() {
  Serial.begin(9600);
 
  // Setup pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}
 
void loop() {
  // Read button
  bool currentState = digitalRead(BUTTON_PIN);
 
  if (currentState == pressed) {
    Serial.println("Hello");
    while(digitalRead(BUTTON_PIN) == pressed) {
      // Do nothing while button is pressed
    }
  }
 
}