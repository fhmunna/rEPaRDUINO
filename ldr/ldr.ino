int inputPin = 0;  //Pin for Photo resistor
int outputPin=11;     //Pin for LED
int outputPin1=10;

void setup()
{
  Serial.begin(9600);  //Begin serial communcation
  pinMode( outputPin, OUTPUT );
}

void loop()
{
  Serial.println(analogRead(inputPin));
  int reading = analogRead(inputPin);
  if(reading > 90) { //Value here depends on the brightness of the room and how you want to calibrate it.
    analogWrite(outputPin1, analogRead(inputPin));
    analogWrite(outputPin, analogRead(inputPin) );
   
  } else {
       analogWrite(outputPin1, 0);
       analogWrite(outputPin, 0);
  }
 
}
