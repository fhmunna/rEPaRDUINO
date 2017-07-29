/*
 Simple LED sketch
 */
     
int led = 13; // Pin 13
     
void setup()
{
    pinMode(led, OUTPUT); // Set pin 13 as digital out
     
    // Turn on the LED
    digitalWrite(led, HIGH);
}
    
void loop()
{
    // Loop infinitely, let's not worry about this for now
}
