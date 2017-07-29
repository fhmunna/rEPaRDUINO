#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


#define ADD_TAG_CODE "020043DFF866"  //change this ID with your own card TAG
#define DEL_TAG_CODE "210014E2BD6A"  //change this ID with your own card TAG
File myFile;
SoftwareSerial rfid = SoftwareSerial(5, 6);
String msg;
String ID = "20043601736 , 020043DFF866" ;  //string to store allowed cards
int speakerOut = 8;
void setup()  
{
  Serial.begin(9600);
  Serial.println("Serial Ready");

  rfid.begin(9600);
  Serial.println("RFID Ready");

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  pinMode(speakerOut, OUTPUT);
}

char c;

void loop(){
  
  while(rfid.available()>0){
    c=rfid.read(); 
    msg += c;
    Serial.println(msg);  
//    Serial.println(msg.length());
  }
  msg=msg.substring(1,13);
//  if(msg.indexOf(ADD_TAG_CODE)>=0) add(); 
//  else if(msg.indexOf(DEL_TAG_CODE)>=0) del();  
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

  }


//RTC Chapter Closing




      storecord();
    }
    
    else {Serial.println("Access denied.");
 digitalWrite(speakerOut,HIGH);   
    delay(1000);
digitalWrite(speakerOut,LOW);}
}


void storecord () {
  
  //SD CARD CHAPTER STARTING-------------------------------------------


//  Serial.print("Initializing SD card...");
//
//  if (!SD.begin(4)) {
//    Serial.println("initialization failed!");
//    return;
//  }
//  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("atds.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to ATDS SERVER");
    myFile.println(msg);
    // close the file:
    myFile.close();
    Serial.println("ATDS SERVER done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening ATDS file");
  }

  // re-open the file for reading:
  myFile = SD.open("atds.txt");
  if (myFile) {
    Serial.println("atds.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening ATDS File");
  }




//SD CARD CHAPTER CLOSING--------------------------------------------
  
  
  
  
  }

