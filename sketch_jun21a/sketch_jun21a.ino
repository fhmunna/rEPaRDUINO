int ledPin=9;
int led=12;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(led, OUTPUT); 
}

void loop()
{
digitalWrite(ledPin, HIGH);
delay(50);
digitalWrite(ledPin, LOW);
delay(50); 
digitalWrite(ledPin, HIGH);
delay(50);
digitalWrite(ledPin, LOW);
delay(50); 
digitalWrite(ledPin, HIGH);
delay(50);
digitalWrite(ledPin, LOW);
delay(500); 
//
//digitalWrite(led, HIGH);
//delay(50);
//digitalWrite(led, LOW);
//delay(50); 
//digitalWrite(led, HIGH);
//delay(50);
//digitalWrite(led, LOW);
//delay(50); 
//digitalWrite(led, HIGH);
//delay(50);
//digitalWrite(led, LOW);
//delay(50); 

}
