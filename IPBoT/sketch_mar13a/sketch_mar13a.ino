#if defined(ARDUINO) && ARDUINO > 18   // Arduino 0019 or later
#include <SPI.h>
#endif
#include <Ethernet.h>
//#include <EthernetDNS.h>  Only needed in Arduino 0022 or earlier
#include <Twitter.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 172,15,200,27 };

// the dns server ip
IPAddress dnServer(8, 8, 8, 8);
// the router's gateway address:
IPAddress gateway(172, 15, 200, 1);
// the subnet:
IPAddress subnet(255, 255, 255, 0);

//byte dns[] = { 8,8,8,8 };
//byte gateway[] = {172,15,200,1};
//byte subnet[] = {255,255,255,0};
// get your token from http://arduino-tweet.appspot.com
//172.15.200.29
Twitter twitter("167866444-bHWiDD7xcN3nNm9oRtrRk5RQ5MFkb8rDvkXXFs4n");
int alarm = 7;
int lever = 6;
int greenLED = 4;

void setup()
{
   delay(1000);
  Ethernet.begin(mac, ip, dnServer, gateway, subnet);
  Serial.begin(9600);
  pinMode(alarm, INPUT);
  pinMode(lever, INPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
if (alarm == HIGH)
{
   twitter.post("alarm activated");
}

else
{
  digitalWrite(greenLED, HIGH);
}


}
