
#include<Ethernet.h>
#include<SPI.h> 
const int temperaturePin = A0;
// **** ETHERNET SETTING ****
// Arduino Uno pins: 10 = CS, 11 = MOSI, 12 = MISO, 13 = SCK
// Ethernet MAC address - must be unique on your network - MAC Reads T4A001 in hex (unique in your network)
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x3A, 0xDC };                                       
// For the rest we use DHCP (IP address and such)
IPAddress ip(172,25,3,30);
EthernetClient client;
IPAddress server(103,206,231,60); // IP Adres (or name) of server to dump data to
int  interval = 5000; // Wait between dumps

void setup() {

  Serial.begin(9600);
     while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
    if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }


  Serial.println("Tweaking4All.com - Temperature Drone - v2.0");
  Serial.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  Serial.print("IP Address        : ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask       : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Default Gateway IP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server IP     : ");
  Serial.println(Ethernet.dnsServerIP());
}

void loop() {
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
      float tem = getTemp();
    Serial.println( tem );
    Serial.println("-> Connected");
    if(client.connected()){
    // Make a HTTP request:
    client.print( "GET /add_data.php?");
    client.print("serial=");
    client.print( "TempSensor" );
    client.print("&&");
    client.print("temperature=");
    client.print( tem);
    client.println( " HTTP/1.1");
    client.println( "Host: 172.25.3.30" );
    //client.println(server);
    client.println( "Connection: close" );
    client.println();
    client.println();
    client.stop();
  }
  }
  else {
    // you didn't get a connection to the server:
    Serial.println("--> connection failed/n");
  }

  delay(interval);
}
float getTemp() {
  float voltage, V,t ;
  voltage = analogRead(temperaturePin) ;
  V = voltage * 0.004882814 ;
  t = (V - 0.5) * 100.0;
  return t;
}

