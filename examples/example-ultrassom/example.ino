#include <ultrassom.h>

ultrassom US(5, 6);

void setup() {
  Serial.begin(9600);
  US.setMargin(30);
}

void loop() {
  Serial.print("\n Distância:" + static_cast<String>(US.getDistance()) + " ||");
  if (US.checkObstacle()) {
    Serial.print(" Obstáculo identificado!");
  }
}