/*
  Connect the photoresistor one leg to pin 0, and pin to + 5V
  Connect a resistor (around 10k is a good value, higher
                    values gives higher readings) from pin 0 to GND. (see appendix of arduino notebook page 37 for schematics).

  ----------------------------------------------------

  PhotoR     10K
  + 5    o-- - / \ / \ / --.-- / \ / \ / -- -o GND
  |
  Pin 0 o---------- -

  ----------------------------------------------------
*/

int sensPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};   // Sensor Pin Numbers
int trigPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Trigger

int threshold = 350;

void setup()
{
  Serial.begin(9600);  //Begin serial communcation

  for (int i = 0 ; i < (sizeof(sensPins) / sizeof(int)) ; i++) {           // sizeof() returns size in bytes. Devided by the size of integer will give a number of items in the array
    pinMode(sensPins[i], INPUT);       // Set all the Sensor pins as INPUT.
  }

  for (int i = 0 ; i < (sizeof(trigPins) / sizeof(int)) ; i++) {           // sizeof() returns size in bytes. Devided by the size of integer will give a number of items in the array
    pinMode(trigPins[i], OUTPUT);       // Set all the Trigger pins as OUTPUTS.
  }

}

void loop()
{

  for (int i = 0 ; i < (sizeof(sensPins) / sizeof(int)) ; i++) {

    if ( analogRead(sensPins[i]) > threshold  )  // if the sensor reading is between thresholds
    {

      digitalWrite( trigPins[ i ] , HIGH);
      Serial.print(" - ");
      Serial.print(analogRead(sensPins[i]));

    } else {

      digitalWrite( trigPins[ i ] , LOW);
      Serial.print(" - ");
      
      Serial.print(analogRead(sensPins[i]));

    }


  } // end of for


  Serial.println();

  delay(200); //short delay for faster response to light.
}


