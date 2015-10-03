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

  if (distance > 30) {
    motors.setRightSpeed(direction*speed + 50);
    motors.setLeftSpeed(direction*speed);
  } else if ( distance < 30 && distance > 20) {
    motors.setRightSpeed(0);
    motors.setLeftSpeed(0);
  } else {
    motors.setRightSpeed(-direction*speed - 50);
    motors.setLeftSpeed(-direction*speed);
  }

  delay(10);
}
