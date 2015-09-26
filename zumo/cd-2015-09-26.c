#include <ZumoMotors.h>
#include <stdio.h>
#include <stdlib.h>

#define echoPin 4 // Echo Pin
#define trigPin 11 // Trigger Pin
#define LEDPin 13 // Onboard LED

ZumoMotors motors;
int speed = 100, direction = 1;
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
int x = 0; // iterator

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

long get_distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;
  return distance;
}

void loop() {
  distance = get_distance();

  if (x > 0) {
    motors.setRightSpeed(direction*2*speed);
    motors.setLeftSpeed(-direction*2*speed);
    --x;
  } else if (distance < 60 && x == 0) {
    if (rand()% 2 == 0) {
      direction = - direction;
    }
    x = 36;
    speed = 100;
  } else {
   speed = speed + 1;
   motors.setRightSpeed(speed + 100);
   motors.setLeftSpeed(speed);
  }

  delay(10);
}
