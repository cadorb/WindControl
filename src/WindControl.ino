// LED
#include "ChainableLED.h"

#define NUM_LEDS  1
#define TIME 50
// Init led
ChainableLED leds(2,3, NUM_LEDS);


int i,j,count,turns;
int t;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
  leds.init();
  leds.setColorRGB(0, 0, 15, 0);
  count = 0;
}
void loop() {
  leds.setColorRGB(0, 0, 15, 0);
  i = 0;
  j = 0;
  turns = 0;
  t = 0;
  //int sensorValue = analogRead(A1);
  //Serial.println(sensorValue);

// s'arrete lorsque la roue a fait 1 tour complet
  while(turns < 10){
    int BP = digitalRead(4);        // Lecture du capteur

    if (BP == LOW) {
      digitalWrite(13, HIGH);      // Allume la Led
      i = 1;
    }else {
      digitalWrite(13, LOW);      // Eteind la Led
      j = 1;
    }


    //Serial.print(i);
    //Serial.print(" ");
    //Serial.println(j);


    // Compte le nombre de tour
    if(i == 1 && j == 1){
      turns += 1;
      Serial.print("Nombre de tour = ");
      Serial.println(turns);
      i = 0;
      j = 0;
    }

    t = t + TIME; // temps passé pour faire un tour complet
    delay(TIME);

    Serial.println(t);
  }


// Si temps court : ya du vent
  if(t < 2000){
    leds.setColorRGB(0, 15, 15, 0);
    Serial.print("t = ");
    Serial.println(t);
    Serial.println("Putain ya du vent !");
    count = count + 1;
    delay(5000);
    // Si le vent dure un certain temps : on stop tout
    if(count >= 5){
      leds.setColorRGB(0, 255, 0, 0);
      Serial.println("STOOOOOOOOOOOOOP !");
      count = 0;
      delay(5000);
    }
  }



}
