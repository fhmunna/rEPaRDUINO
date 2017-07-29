#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#define ADD_TAG_CODE "020043DFF866"  //change this ID with your own card TAG
#define DEL_TAG_CODE "210014E2BD6A"  //change this ID with your own card TAG
File myFile;
SoftwareSerial rfid = SoftwareSerial(5, 6);
String msg;
String ID = "20043601736 , 020043DFF866" ;  //string to store allowed cards

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

void add(){
  Serial.print("What TAG do you wanna grant access?: ");
  msg="";
  while(msg.length()<13){
    while(rfid.available()>0){
      c=rfid.read(); 
      msg += c;
    }
  }
  if(ID.indexOf(msg)>=0) {
    Serial.println("\nAccess already granted for this card.");
    msg="";
  }
  else{
    Serial.print("Card: ");
    Serial.println(msg); 
    ID += msg;
    ID += ",";
    storecord();
    //Serial.print("ID: ");
   // Serial.println(ID);
    msg="";
//replaced
    Serial.println("Access granted for this card.");


//   msg="";  
  }

}

void del(){
  msg="";
  Serial.print("What TAG do you wanna deny access?: ");
  while(msg.length()<13){
    while(rfid.available()>0){
      c=rfid.read(); 
      msg += c;
    }
  }
  msg=msg.substring(1,13);
  if(ID.indexOf(msg)>=0){
    Serial.println(msg);
    Serial.println("TAG found. Access for this card denied.");
    //ID.replace(card,"");
    int pos=ID.indexOf(msg);
    msg="";
    msg += ID.substring(0,pos);
    msg += ID.substring(pos+15,ID.length());
    ID="";
    ID += msg;
    //Serial.print("ID: ");
    //Serial.println(ID);
  } else Serial.println("\nTAG not found or already denied");
  msg="";
}

void verifica(){
    msg=msg.substring(1,13);
    if(ID.indexOf(msg)>=0) { Serial.println("Access granted.");

      storecord();
    }
    
    else Serial.println("Access denied.");
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

