int ledPin=1;


void setup()
{
  changePin(1);
  changePin(12);
  changePin(13);
}

void loop()
{
connectPin(1);

connectPin(12);

connectPin(13);


}
void changePin(int pin)
{
  pinMode(pin, OUTPUT); 
}
void connectPin(int pin)
{
  digitalWrite(pin, HIGH);
  delay(50);
  digitalWrite(pin, LOW);
  delay(50); 
}

