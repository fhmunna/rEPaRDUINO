#include <SoftwareSerial.h>
#include <SPI.h>
SoftwareSerial rfid = SoftwareSerial(6, 7);
String msg;
String ID = "20043601736 , 020043DFF866" ;  //string to store allowed cards
int speakerOut = 10;
void setup()  
{
  Serial.begin(9600);
  Serial.println("Serial Ready");
  rfid.begin(9600);
  Serial.println("RFID Ready");
  pinMode(speakerOut, OUTPUT);
}
char c;
void loop(){

  while(rfid.available()>0){
    for(int thin = 1; thin <13; thin++)
    {                            
      c=rfid.read(); 
      msg += c;
    } 

    Serial.println(msg);  
    msg=msg.substring(1,13);
    if(msg.length()>10) verifica();
    msg="";
  }
}
void verifica(){
  msg=msg.substring(1,13);
  if(ID.indexOf(msg)>=0) { 
    Serial.println("Access granted.");
    digitalWrite(speakerOut,HIGH);
    delay(100);
    digitalWrite(speakerOut,LOW);
    delay(100);
    digitalWrite(speakerOut,HIGH);
    delay(100);
    digitalWrite(speakerOut,LOW);
  }   
  else {
    Serial.println("Access denied.");
    digitalWrite(speakerOut,HIGH);   
    delay(1000);
    digitalWrite(speakerOut,LOW);
  }
}








