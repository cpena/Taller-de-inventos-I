#include "tones.h"

// Melodia
int melody[] = { NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// Duraciones: 4 = negra, 8 = corchea, ..
int noteDurations[] = { 4, 8, 8, 4,4,4,4,4 };

int led = 6;
int val = 0; 
int thisNote=0;

void setup()
{ 
  pinMode(led, OUTPUT); 
  Serial.begin(9600); 
}

void loop()
{
  val = analogRead(1); 
  
  if(val == 0){
    digitalWrite(led, HIGH);
    
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    
    thisNote++;
    if(thisNote==8){
      thisNote=0;
    }
  }
  else{
    digitalWrite(led, LOW);
  }
  
  Serial.println(val);   
}

