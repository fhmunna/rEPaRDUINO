#include <SoftwareSerial.h>
#include <SPI.h>
SoftwareSerial rfid = SoftwareSerial(6, 7);
  String msg;
String ID = "020043601736, 020043DFF866" ;  //string to store allowed cards
int speakerOut = 10;
void setup()  
{
  Serial.begin(9600);
  Serial.println("Serial Ready");
    delay(100);

  pinMode(speakerOut, OUTPUT);
}

void loop(){
  
    rfid.begin(9600);
  Serial.println("RFID Ready");
  
  while(rfid.available()>0){
    char c;
  Serial.println("Access 1.");
    for(int thin = 0; thin <14; thin++)
    {                            
      c=rfid.read(); 
      msg += c;
      
    }   Serial.println("Access 2.");
       digitalWrite(speakerOut,HIGH);
    delay(100);
    digitalWrite(speakerOut,LOW);
    delay(100);
  Serial.println(msg);
     if(msg.length()==14) {
  msg=msg.substring(1,13);
  Serial.println(msg);
  if(ID.indexOf(msg)>=0) { 
    Serial.println("Access granted.");
    digitalWrite(speakerOut,HIGH);
    delay(100);
    digitalWrite(speakerOut,LOW);
    delay(100);
    digitalWrite(speakerOut,HIGH);
    delay(100);
    digitalWrite(speakerOut,LOW);
     
     msg="";
      rfid.end();
      delay(1000);
  while(rfid.read() != -1) {}; //This one to clear the buffer?
   
     
  }   
  else {
    Serial.println("Access denied.");
    digitalWrite(speakerOut,HIGH);   
    delay(1000);
    digitalWrite(speakerOut,LOW);
     delay(1000);
     msg="";
     while(rfid.read() != -1) {}; //This one to clear the buffer?
  }
}
   
 
}
rfid.end();
}









