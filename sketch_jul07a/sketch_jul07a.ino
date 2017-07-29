int ledd = 13; // Pin 12


void setup() {
  // put your setup code here, to run once:
pinMode(ledd, OUTPUT); // Set pin 13 as digital out
    Serial.begin(9600); // baud rate
    Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(ledd, HIGH); // on
}
