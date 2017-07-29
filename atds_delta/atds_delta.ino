#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <Ethernet.h>
#define ADD_TAG_CODE "020043DFF866"  //change this ID with your own card TAG
#define DEL_TAG_CODE "210014E2BD6A"  //change this ID with your own card TAG
File myFile;
SoftwareSerial rfid = SoftwareSerial(5, 6);
String msg;
String ID = "20043601736 , 020043DFF866" ;  //string to store allowed cards
int speakerOut = 8;
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 10, 0, 5);
// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);
void setup()  
{
  Serial.begin(9600);
  Serial.println("Serial Ready");
pinMode(speakerOut, OUTPUT);
  rfid.begin(9600);
  Serial.println("RFID Ready");
  Serial.print("Initializing SD card...");   
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
     Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP()); 
}
char c;
void loop(){  
 // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char d = client.read();
        Serial.write(d);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (d == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

  // re-open the file for reading:
  myFile = SD.open("atds.txt");
  if (myFile) {
    Serial.println("atds.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
      client.println(myFile.read());
    }
    // close the file:
    myFile.close();

          client.println("</html>");
          break;
        }
        if (d == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (d != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}



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
  void web() {
 }

