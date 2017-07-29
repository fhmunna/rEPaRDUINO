int led=13;

void setup() {

 // digitalWrite(9, HIGH); // set pin 13 as high or 1
    pinMode(led, OUTPUT);

}
 
void loop() {

digitalWrite(led, HIGH);
delay(50);
digitalWrite(led, LOW);
delay(50);
digitalWrite(led, HIGH);
delay(50);
digitalWrite(led, LOW);
delay(50);

}
