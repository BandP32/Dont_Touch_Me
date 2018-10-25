
//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
int Buzzer_PIN = 10;
int LEDBlue = 9;
int LEDRed = 8;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   pinMode (Buzzer_PIN, OUTPUT);
   pinMode (LEDBlue, OUTPUT);
   pinMode (LEDRed, OUTPUT);
   Serial.begin(9600);
   delay(1000);
}

void loop() {
  digitalWrite (LEDRed, LOW);
  digitalWrite (LEDBlue, LOW); 
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   unsigned char i;
   if( a <= 20){
    digitalWrite (LEDBlue, HIGH);
    digitalWrite (LEDRed, LOW); 
    for (i = 0; i<100; i++){
      digitalWrite(Buzzer_PIN, HIGH);
      delay(1); 
      digitalWrite(Buzzer_PIN, LOW);
      delay(1);}
    digitalWrite (LEDBlue, LOW);
    digitalWrite (LEDRed, HIGH);
    delay (200);  
   }
}
