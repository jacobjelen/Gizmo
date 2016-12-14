#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 200;    // variable to store the servo position

int stepDelay = 1;
int stepSize = 1;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {

  Serial.println("LOAD");
  load();
  delay(2000);

  Serial.println("HIT");
  hit();
  delay(2000);

}

  void load() {
    for (pos = 200; pos >= 0; pos -= stepSize) {            // goes from 180 degrees to 0 degrees
      myservo.write(pos);                                   // tell servo to go to position in variable 'pos'
      delay(stepDelay);                                           // waits 15ms for the servo to reach the position
    }

    for (pos = 0; pos <= 140; pos += stepSize) {        // goes from 0 degrees to 180 degrees
      myservo.write(pos);                               // tell servo to go to position in variable 'pos'
      delay(stepDelay);                                          // waits 15ms for the servo to reach the position

    }
  }

  void hit() {
    for (pos = 140; pos <= 200; pos += stepSize) {            // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);                               // tell servo to go to position in variable 'pos'
      delay(stepDelay);                                         // waits 15ms for the servo to reach the position
    }
  }



