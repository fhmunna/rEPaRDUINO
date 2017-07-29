/*
 Simple LED sketch
 */
     
int led = 13; // Pin 13
int ledd = 12; // Pin 12
     
void setup()
{
    pinMode(led, OUTPUT); // Set pin 13 as digital out
    pinMode(ledd, OUTPUT); // Set pin 13 as digital out
     
    // Start up serial connection
    Serial.begin(9600); // baud rate
    Serial.flush();
}
     
void loop()
{
    String input = "";
     
    // Read any serial input
    while (Serial.available() > 0)
    {
        input += (char) Serial.read(); // Read in one char at a time
        delay(5); // Delay for 5 ms so the next char has time to be received
    }
     
    if (input == "on")
    {
        digitalWrite(led, HIGH); // on
    }

     else if (input == "on2")
    {
        digitalWrite(ledd, HIGH); // on
    }
    else if (input == "off all")
    {
        digitalWrite(led, LOW); // off
         digitalWrite(ledd, LOW); // off
    }
        else if (input == "off 1")
    {
        digitalWrite(led, LOW); // off
      
    }
        else if (input == "off 2")
    {
    
         digitalWrite(ledd, LOW); // off
    }
}
