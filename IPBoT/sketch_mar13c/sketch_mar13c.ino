/* Post a simple message to Twitter  */
#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0x92, 0xA4 };
//byte ip[] = { 172, 15, 200, 30 };

IPAddress dnServer(8, 8, 8, 8);
// the router's gateway address:
IPAddress gateway(172, 15, 200, 1);
// the subnet:
IPAddress subnet(255, 255, 255, 0);
 
Twitter twitter("708993901676265472-Tpv9nfMPfoHAXugU2JTCmJz4LL3eMni");
int x =0;
int y = 0;
int pinSpeaker= 3;
  
 

void setup()
{   
 pinMode(pinSpeaker, OUTPUT);

}
void loop()
{
        digitalWrite(pinSpeaker,HIGH);
      delay(100);
       digitalWrite(pinSpeaker,LOW);
       delay(100);
        digitalWrite(pinSpeaker,HIGH);
      delay(100);
       digitalWrite(pinSpeaker,LOW);
  
for (x = 0; x < 255; x++){
byte ip[] = { 172, 15, 200, x };
//char msg[4];
//msg[] =[ 172, 15, 200, x ];

char msg[2];
String str;
str="#Arduino #IPBoT 172.15.200.";
str+=String(x);

str.toCharArray(msg,56);
  Ethernet.begin(mac, ip, dnServer, gateway, subnet);
  Serial.begin(9600);
 
  
 Serial.println(msg);
  Serial.println("connecting ...");
     digitalWrite(pinSpeaker,HIGH);
      delay(100);
       digitalWrite(pinSpeaker,LOW);
  if (twitter.post(msg)) {
    int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");    
      Serial.println(msg);
     
      digitalWrite(pinSpeaker,HIGH);
      delay(100);
       digitalWrite(pinSpeaker,LOW);
    } else {
      Serial.print("failed : code ");
       digitalWrite(pinSpeaker,HIGH);
      delay(100);
       digitalWrite(pinSpeaker,LOW);
       delay(100);
        digitalWrite(pinSpeaker,HIGH);
      delay(100);
       digitalWrite(pinSpeaker,LOW);
        delay(100);
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}
  
}
