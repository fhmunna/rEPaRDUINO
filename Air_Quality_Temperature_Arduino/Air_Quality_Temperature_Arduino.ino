/*
 Input Pullup Serial
 
 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a 
 digital input on pin 2 and prints the results to the serial monitor.
 
 The circuit: 
 * Momentary switch attached from pin 2 to ground 
 * Built-in LED on pin 13
 
 Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal 
 20K-ohm resistor is pulled to 5V. This configuration causes the input to 
 read HIGH when the switch is open, and LOW when it is closed. 
 
 created 14 March 2012
 by Scott Fitzgerald
 
 http://www.arduino.cc/en/Tutorial/InputPullupSerial
 
 This example code is in the public domain
 
 */
int sensorPin = A4; 
int sensorPinana = A2; 
void setup(){
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(4, INPUT_PULLUP);
  pinMode(13, OUTPUT); 

}

void loop(){
  //read the pushbutton value into a variable
     delay(100); 
   float  sensorValueana = analogRead(sensorPinana);
     float air = sensorValueana/1024*5.0;
        Serial.print("Air Quality--Analog= ");
      Serial.print(air);
    delay(100); 
    
  float sensorValdg = digitalRead(4);
  Serial.print("--Digital= ");
  Serial.print(sensorValdg);
  delay(100); 
     
   float  sensorValue = analogRead(sensorPin);
    delay(100); 
  //print out the value of the pushbutton
 
  
float mv = ( sensorValue/1024.0)*5000; 
float cel = mv/10;
float celcius = cel-8;
Serial.print(" *******
TEMPRATURE = ");
Serial.print(celcius);
  delay(100); 
Serial.print("*C");
Serial.println();
  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the 
  // button's pressed, and off when it's not:
  if (sensorValdg == HIGH) {
    digitalWrite(13, LOW);
  } 
  else {
    digitalWrite(13, HIGH);
    delay(100); 
  }
}



