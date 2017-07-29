int pirPin = 2;
int pinSpeaker= 10;
int ledPin = 13;
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pinSpeaker, OUTPUT);
}
void loop(){
  int pirVal = digitalRead(pirPin);
  Serial.println("starting to read PIR");
  analogWrite(ledPin, 0);
  delay(2000);
  if(pirVal == LOW) {
    analogWrite(ledPin, 255);
    Serial.println("Motion Detected");
    tone(10, 700, 100);
    delay(2000);
  }
}
void tone(long duration, int freq) {
duration *= 1000;
int period = (1.0 / freq) * 1000000;
long elapsed_time = 0;
while (elapsed_time < duration) {
digitalWrite(pinSpeaker,HIGH);
delayMicroseconds(period / 2);
digitalWrite(pinSpeaker, LOW);
delayMicroseconds(period / 2);
elapsed_time += (period);
}
  }
