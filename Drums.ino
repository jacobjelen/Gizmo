#include <Servo.h>

Servo servo[3];  // create servo object to control a servo
int servoPin[] = {9, 10};

int inPin[] = {2, 3};    // input pins - when HIGH, hit the chord

int pos = 0;
int stepDelay = 5;

bool stroke[] = {0, 0};

void setup() {
  Serial.begin(9600);
  //while(!Serial);

  for (int i = 0 ; i < 3 ; i++) {           // sizeof() returns size in bytes. Devided by the size of integer will give a number of items in the array
    servo[i].attach( servoPin[i] );                                     //attach servos on servoPin[]s
    servo[i].write(0);                                                // set servos to 0 position
    load(i);
  }

  // set inPin as inputs
  for (int i = 0 ; i < (sizeof(inPin) / sizeof(int)) ; i++) {           // sizeof() returns size in bytes. Devided by the size of integer will give a number of items in the array
    pinMode(inPin[i], INPUT);                                         // Set all the Sensor pins as INPUT.
  }

}

void loop() {

//  for (int i = 0 ; i < (sizeof(inPin) / sizeof(int)) ; i++) {
////
////    Serial.print("Pin: ");
////    Serial.print(inPin[i]);
////    Serial.print(" is ");
////    Serial.println(digitalRead(inPin[i]));
//
//    if ( digitalRead(inPin[i]) && !stroke[i] ) {
//
//      hit(i);
//      Serial.println("HIT");
//      load(i);
//      Serial.println("LOAD");
//
//      stroke[i] = 1;
//    
//    } else if ( digitalRead(inPin[i]) && stroke[i] ) {
//
//      
//    } else {
//      stroke[i] = 0;
//      
//      }
//
//
//    delay(500);
//  } // for

hit(0);
load(0);
Serial.print("0");
delay(500);


hit(1);
load(1);
Serial.print("1");
delay(500);

} //loop



void load( int i) {
//  servo[i].write(200);
//  delay(500);

    for (pos = 0; pos <= 200; pos += 10) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo[i].write(pos);              // tell servo to go to position in variable 'pos'
      delay(stepDelay);                       // waits 15ms for the servo to reach the position
    }
    delay(500);

}

void hit(int i) {
//  servo[i].write(0);
//  delay(500);

    for (pos = 200; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
      servo[i].write(pos);              // tell servo to go to position in variable 'pos'
      delay(3);                       // waits 15ms for the servo to reach the position
    }
    delay(500);
}






