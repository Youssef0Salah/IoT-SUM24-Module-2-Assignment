#include <ESP32Servo.h>

Servo myServo;
bool doorOpen = false;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Attach the servo to pin 2 
  myServo.attach(2);
  myServo.write(0);
}

void loop() {
  // Read the value from the IR sensor 
  int irValue = analogRead(4);

  int outputValue = map(irValue, 0, 4095, 0, 20);
  Serial.println(outputValue);

  // If a person is detected (outputValue == 0) and the door is not open, open the door
  if (outputValue == 0 && !doorOpen) {
    openDoor();
  } else if (outputValue >= 1 && doorOpen) {
    // If no person is detected and the door is open, close the door after a delay
    delay(10000); // Keep the door open for 10 seconds
    closeDoor();
  }

  // Small delay to avoid bouncing
  delay(100);
}

void openDoor() {
  //  open the door
  myServo.write(180);
  doorOpen = true;
  Serial.println("Door opened.");
}

void closeDoor() {
  //  close the door
  myServo.write(0);
  doorOpen = false;
  Serial.println("Door closed.");
}