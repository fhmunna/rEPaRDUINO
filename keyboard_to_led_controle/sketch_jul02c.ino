/*  07/10/2011 - Massimo Pacilio
    
    SL - left arrow key Led - digital pin 8
    DL - right arrow key Led - digital pin 10
    AL - up arrow key Led - digital pin 9
    BL - down arrow key Led - digital pin 11
    
    This skectch is made to be used with 
    the sketch Processing 'frecce_step3'.

    This example code is in the public domain.
*/

const unsigned int SL = 8;
const unsigned int DL = 10;
const unsigned int AL = 9;
const unsigned int BL = 11;
const unsigned int BAUD_RATE = 9600;

char key = 0;

void setup() {
  pinMode(SL, OUTPUT);
  pinMode(DL, OUTPUT);
  pinMode(AL, OUTPUT);
  pinMode(BL, OUTPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {

  if (Serial.available()) {
     key = Serial.read();
     if (key == byte(37)) { // freccia verso sinistra
     digitalWrite(SL, HIGH); 
     } else if (key == byte(39)) { // freccia verso destra
       digitalWrite(DL, HIGH);
     } else if (key == byte(38)) { // freccia verso l'alto
       digitalWrite(AL, HIGH); 
     } else if (key == byte(40)) { // freccia verso il basso
       digitalWrite(BL, HIGH); 
     } else {
       digitalWrite(DL, LOW);
       digitalWrite(AL, LOW);
       digitalWrite(BL, LOW);
       digitalWrite(SL, LOW);
     }
   }
}
