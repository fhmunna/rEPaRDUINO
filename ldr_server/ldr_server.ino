int inputPin0 = 0;  
int inputPin01 = 1;  
int inputPin02 = 2;  

void setup()
{
  Serial.begin(9600);  //Begin serial communcation
  
}

void loop()
{
  delay(1000);
    Serial.println("Scanning...");
    Serial.println("A00---OPTICAL LINK");
  Serial.println(analogRead(inputPin0));
  delay(1000);
    Serial.println(analogRead(inputPin0));
  delay(1000);
    Serial.println(analogRead(inputPin0));
  delay(1000);
    Serial.println(analogRead(inputPin0));
  delay(1000);
    Serial.println(analogRead(inputPin0));
  delay(1000);
    Serial.println(analogRead(inputPin0));
  delay(1000);
  Serial.println("A01---POWER");
  Serial.println(analogRead(inputPin01));
  delay(1000);
Serial.println(analogRead(inputPin01));
  delay(1000);
  Serial.println(analogRead(inputPin01));
  delay(1000);
  Serial.println(analogRead(inputPin01));
  delay(1000);
Serial.println(analogRead(inputPin01));
  delay(1000);
  Serial.println(analogRead(inputPin01));
  delay(1000);
  
}
