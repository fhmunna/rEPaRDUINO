/* Post a simple message to Twitter  */
#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>
//byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0x92, 0xA4 };
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//byte ip[] = { 172, 15, 200, 30 };

IPAddress dnServer(8, 8, 8, 8);
// the router's gateway address:
IPAddress gateway(10, 42, 0, 1);
// the subnet:
IPAddress subnet(255, 255, 255, 0);
 
Twitter twitter("167866444-K823sqNibbkGTjPYrg1lCHMQHMdniryv5O4MzAhE");
//Twitter twitter("167866444-bHWiDD7xcN3nNm9oRtrRk5RQ5MFkb8rDvkXXFs4n");
//Twitter twitter("708993901676265472-Tpv9nfMPfoHAXugU2JTCmJz4LL3eMni");

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
byte ip[] = { 10, 42, 0, x };
//char msg[4];
//msg[] =[ 172, 15, 200, x ];

char msg[2];
String str;
str="#Arduino #IPBoT 10.42.0.";
str+=String(x);

str.toCharArray(msg,56);
  Ethernet.begin(mac, ip, dnServer, gateway, subnet);
  Serial.begin(9600);
 
  delay(100);
   digitalWrite(pinSpeaker,HIGH);
      delay(100);
       digitalWrite(pinSpeaker,LOW);
 Serial.println(msg);
  Serial.println("connecting ...");
      delay(1000);
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
     
     
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}
  
}
