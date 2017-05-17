#include "Arduino.h"

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("Starting Giro control");
}
void loop() {
      Serial.println(windDirection());
      delay(1000);
}
