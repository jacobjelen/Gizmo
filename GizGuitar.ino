#include <Servo.h>

Servo servo[3];  // create servo object to control a servo
int servoPin[] = {9, 10, 11};

bool prevState[] = {1, 1, 1};
bool state[] = {0, 0, 0};

int inPin[] = {2, 3, 4};    // input pins - when HIGH, hit the chord

//bool prevPinState[] = {1, 1, 1};
//bool pinState[] = {0, 0, 0};

bool stroke[] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  //while(!Serial);

  for (int i = 0 ; i < 3 ; i++) {           // sizeof() returns size in bytes. Devided by the size of integer will give a number of items in the array
    servo[i].attach( servoPin[i] );                                     //attach servos on servoPin[]s
    servo[i].write(0);                                                // set servos to 0 position
  }

  // set inPin as inputs
  for (int i = 0 ; i < (sizeof(inPin) / sizeof(int)) ; i++) {           // sizeof() returns size in bytes. Devided by the size of integer will give a number of items in the array
    pinMode(inPin[i], INPUT);                                         // Set all the Sensor pins as INPUT.
  }

}

void loop() {

  for (int i = 0 ; i < (sizeof(inPin) / sizeof(int)) ; i++) {

    if ( digitalRead(inPin[i]) == HIGH && state[i] != prevState[i] ) {
      
      if (!stroke[i]) {
        
        if ( state[i] == 0 ) {
          servo[i].write(45);
          prevState[i] = state[i];
          state[i] = 1;
        } else if ( state[i] == 1) {
          servo[i].write(0);
          prevState[i] = state;
          state[i] = 0;
        }

      stroke[i] = 1;
      
      } // if stroked

      delay(500);
    
    } else if (digitalRead(inPin[i]) == LOW)  {
      
      stroke[i] = 0;
      
      }   // if digitalRead

  } // for
} //loop



