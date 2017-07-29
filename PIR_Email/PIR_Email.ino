#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xAF, 0xCE, 0xDD }; // whatever mac you want
byte ip[] = { 192, 168, 0, 109};
byte server[] = { 203, 188, 201, 253 }; // Mail server address  smtp.mail.yahoo.com.tw)
Client client(server, 25);  // yahoo's mobile smtp server ip/port 587

/////////////////////////////
//VARS
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;       

//the time when the sensor outputs a low impulse
long unsigned int lowIn;        

//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000; 

boolean lockLow = true;
boolean takeLowTime; 

int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;
int nPIR_detect;

void setup()
{
 Ethernet.begin(mac, ip);
 Serial.begin(57600);

  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
 
  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
     nPIR_detect = 0;
}

void loop()
{
  delay(1000);
  if(PIR_detected())  // PIR : HIGH
  {
     if (client.available()) {
       char c = client.read();
       Serial.print(c);
     }

    Serial.println("connecting...");

     if (client.connect()) {
       Serial.println("connected");
       client.println("EHLO smtp.mail.yahoo.com.tw");
//       client.println("AUTH PLAIN AHNpbm9jZ3RjbGVuQHlhaH9vLmNvbSgwet323tcxYTU=");  // example
       client.println("AUTH PLAIN *************************************************=");  // replace the **'s with your auth info from the perl script.
       client.println("MAIL FROM:<**@yahoo.com.tw>");  // replace the ** with your mail address
       client.println("RCPT TO:<**@gmail.com>");       // replace the ** with to mail address
       client.println("DATA");
       client.println("From: <**@yahoo.com.tw>");
       client.println("TO: <**@gmail.com>");
       client.println("SUBJECT: Something has been detected by PIR");
       client.println();
       client.println("This is PIR testing.");
       client.println("Warning: detected something!!");
       client.println(".");
       client.println(".");
      
       delay(1000);
       client.stop();
       Serial.println("mail sent!!");    
       delay(30000); 
     }
     else
     {
       Serial.println("connection failed");
     }
  }
}

boolean PIR_detected()
{
  boolean bPIR;
 
     if(digitalRead(pirPin) == HIGH){
       digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;
        
         bPIR = true;
       }
    
     if(digitalRead(pirPin) == LOW){      
       digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state
      
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause,
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){ 
           //makes sure this block of code is only executed again after
           //a new motion sequence has been detected
           lockLow = true;                       
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
           bPIR = false;
       }
    return bPIR;
}

