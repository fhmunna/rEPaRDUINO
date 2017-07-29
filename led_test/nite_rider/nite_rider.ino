int del=100; // sets a default delay time
void setup() {
  // initialize the digital pins as outputs:
  for (int i = 9; i<=12 ; i++) {
    pinMode(i, OUTPUT);
  } // end of for loop
} // end of setup
 
void loop() {
  for (int i = 9; i<=12; i++) { // blink from LEDs 2 to 8
    digitalWrite(i, HIGH);
    delay(del);
    digitalWrite(i, LOW);
  }
  for (int i = 12; i>=10; i--) { // blink from LEDs 8 to 3
    digitalWrite(i, HIGH);
    delay(del);
    digitalWrite(i, LOW);
  }
}
