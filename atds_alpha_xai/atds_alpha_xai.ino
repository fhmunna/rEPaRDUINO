#include <SoftwareSerial.h>
#include <SPI.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
SoftwareSerial rfid = SoftwareSerial(5, 6);
String msg;
String ID = "20043601736 , 020043DFF866" ;  //string to store allowed cards
int speakerOut = 8;
char c;
void setup()  
{
  Serial.begin(9600);
  Serial.println("Serial Ready");
  rfid.begin(9600);
  Serial.println("RFID Ready");
  pinMode(speakerOut, OUTPUT);
}
          void loop(){
            
            while(rfid.available()>0){
              c=rfid.read(); 
              msg += c;
              Serial.println(msg);  
               }
            msg=msg.substring(1,13);
             if(msg.length()>10) verifica();
              msg="";  
          }
void verifica(){
    msg=msg.substring(1,13);
    if(ID.indexOf(msg)>=0) { Serial.println("Access granted.");
    digitalWrite(speakerOut,HIGH);
    delay(100);
    digitalWrite(speakerOut,LOW);
    delay(100);
    digitalWrite(speakerOut,HIGH);
    delay(100);
    digitalWrite(speakerOut,LOW);
        //RTC Chapter Starting--------------------------------
        tmElements_t tm;
        if (RTC.read(tm)) {
                    //    Serial.print("Ok, Time = ");
                    msg += "-->";
                    msg += tm.Hour;
                    msg += ":";
                    msg += tm.Minute;
                    msg += ":";
                    msg += tm.Second;
                    msg += "-";
                    msg += tm.Day;
                    msg += "/";
                    msg += tm.Month;
                    msg += "/";
                    msg += tmYearToCalendar(tm.Year);

          }//RTC Chapter Closing
    }
    
    else {Serial.println("Access denied.");
          digitalWrite(speakerOut,HIGH);   
          delay(1000);
          digitalWrite(speakerOut,LOW);}
}


  
  

