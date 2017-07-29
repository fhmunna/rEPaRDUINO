int rcvpin=A0;

int buzzpin=9;
void setup()
{
  pinMode(rcvpin,INPUT);
  pinMode(buzzpin,OUTPUT);
  buzz(200);
  buzz(200);
  buzz(200);
  delay(2000);
  Serial.begin(9600);
  
}

void loop()
{
  int ldrval=analogRead(rcvpin);
  Serial.println(ldrval);
  if(ldrval<=390)
  {
    buzz(50);
  }
}
  
  
  void buzz(unsigned char time)
  {
    analogWrite(buzzpin,170);
    delay(time);
    analogWrite(buzzpin,0);
    delay(time);
  }
