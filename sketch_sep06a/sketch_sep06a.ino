int LED = 3;
int PIR = 10;

void setup() {

// initialize digital pin 3 as an output for LED

pinMode(LED, OUTPUT);

//initialize digital pin 10 as input for PIR

pinMode(PIR, INPUT);

//initialization time for PIR sensor to warm up

//blink LED to show that something is happening

for(int i = 0; i < 10; i++) {

digitalWrite(LED, LOW);

delay(30);

digitalWrite(LED, HIGH);

delay(30);

}

}

void loop() {

//read PIR sensor, if High light LED for 5 seconds

//if low, check again

if(digitalRead(PIR) == HIGH) {

//digitalWrite(LED, HIGH);
//delay(500);
//digitalWrite(LED, LOW);
//delay(500);
//digitalWrite(LED, HIGH);
//delay(500);
//digitalWrite(LED, LOW);
//delay(500);

digitalWrite(LED, HIGH);

delay(30);


digitalWrite(LED, LOW);

delay(300);




} else {

digitalWrite(LED, LOW);

}

}
