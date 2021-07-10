#include <Wire.h>
#include "Adafruit_MCP23017.h"

byte noteON = 144;
byte control = 145;

/** Arduino input with simple ABLETON outpu
bool play_val = LOW;
bool prev_play_val = LOW;
bool record_val = LOW;
bool prev_record_val = LOW;
*/

bool prev_button_0 = LOW;
bool button_0 = LOW;
bool prev_button_1 = LOW;
bool button_1 = LOW;
bool prev_button_2 = LOW;
bool button_2 = LOW;
bool prev_button_3 = LOW;
bool button_3 = LOW;
bool prev_button_4 = LOW;
bool button_4 = LOW;
bool prev_button_5 = LOW;
bool button_5 = LOW;
bool prev_button_6 = LOW;
bool button_6 = LOW;
bool prev_button_7 = LOW;
bool button_7 = LOW;
bool prev_button_8 = LOW;
bool button_8 = LOW;
bool prev_button_9 = LOW;
bool button_9 = LOW;
bool prev_button_10 = LOW;
bool button_10 = LOW;
bool prev_button_11 = LOW;
bool button_11 = LOW;
bool prev_button_12 = LOW;
bool button_12 = LOW;
bool prev_button_13 = LOW;
bool button_13 = LOW;
bool prev_button_14 = LOW;
bool button_14 = LOW;
bool prev_button_15 = LOW;
bool button_15 = LOW;

int MrBluePot = 0; // test potentiometer 11/20 19:44
int MrsBluePot = 0; // test potentiometer 11/20 19:44
int prev_MrBluePot = 0; // test potentiometer 11/20 19:44
int prev_MrsBluePot = 0; // test potentiometer 11/20 19:44

Adafruit_MCP23017 mcp;

void setup() {
  Serial.begin(115200); // open the serial port at 115200 bps
  pinMode(A0,INPUT); // for Mr. Blue Pot
  pinMode(A1,INPUT); // for Mrs. Blue Pot
  /**
   * CODE FOR ARDUINO INPUTS

  pinMode(3, INPUT);    // declare RECORD pushbutton as input
  */

  /**
   * Set all of the expander's ports to INPUTS with a pullup
   */
  mcp.begin();      // use default address 0

  for (int j = 0; j<=15 ; j++){
    mcp.pinMode(j, OUTPUT);
    mcp.digitalWrite(j,LOW);
  }
  
  for (int i = 0; i<=15 ; i++){
    mcp.pinMode(i, INPUT);
   mcp.pullUp(i, LOW);  // turn on a 100K pullup internally
  }

// just keep the LED on for now
    mcp.pinMode(14, OUTPUT);
    mcp.digitalWrite(14,HIGH);
   
}

void loop() {
  /** CODE FOR ARDUINO INPUTS
   *  Delete this after installing the port expander
  
  play_val = digitalRead(2);  // read input value
  record_val = digitalRead(3); // read input value
  **/

  MrBluePot = (analogRead(A0)*(.123)); // read the sensor
  MrsBluePot = (analogRead(A1)*(.123)); // read the sensor

  button_0 = mcp.digitalRead(0);  // read input value
  button_1 = mcp.digitalRead(1); // read input value
  button_2 = mcp.digitalRead(2);  // read input value
  button_3 = mcp.digitalRead(3); // read input value
  button_4 = mcp.digitalRead(4);  // read input value
  button_5 = mcp.digitalRead(5); // read input value
  button_6 = mcp.digitalRead(6);  // read input value
  button_7 = mcp.digitalRead(7); // read input value
  button_8 = mcp.digitalRead(8);  // read input value
  button_9 = mcp.digitalRead(9); // read input value
  button_10 = mcp.digitalRead(10);  // read input value
  button_11 = mcp.digitalRead(11); // read input value
  button_12 = mcp.digitalRead(12);  // read input value
  button_13 = mcp.digitalRead(13); // read input value
  button_14 = mcp.digitalRead(14);  // read input value
  button_15 = mcp.digitalRead(15); // read input value


/*
  for (int j = 0; j<=15 ; j++){
    mcp.digitalWrite(j,LOW);
  }
  */

 
 /*
  Serial.print("0(");
  Serial.print(button_0);
  Serial.print(")  1(");
  Serial.print(button_1);
  Serial.print(")  2(");
  Serial.print(button_2);
    Serial.print(")  3(");
  Serial.print(button_3);
   Serial.print(")  4(");
  Serial.print(button_4);
   Serial.print(")  5(");
  Serial.print(button_5);
   Serial.print(")  6(");
  Serial.print(button_6);
    Serial.print(")  7(");
  Serial.print(button_7);
    Serial.print(")  8(");
  Serial.print(button_8);
    Serial.print(")  9(");
  Serial.print(button_9);
   Serial.print(")  10(");
  Serial.print(button_10);
   Serial.print(")  11(");
  Serial.print(button_11);
   Serial.print(")  12(");
  Serial.print(button_12);
  Serial.print(")  13(");
  Serial.print(button_13);
   Serial.print(")  14(");
  Serial.print(button_14);
   Serial.print(")  15(");
  Serial.print(button_15);
  
   Serial.print(")  A0(");
  Serial.print(MrBluePot);
    Serial.print(")  A1(");
  Serial.print(MrsBluePot);
   Serial.println(")");
*/


//code for the record button

if (prev_MrBluePot != MrBluePot){
     MIDImessage(176, 16, MrBluePot);//turn note 60 on with 127 velocity
 //    Serial.println("MrBluePot");
      prev_MrBluePot = MrBluePot;
}

if (prev_MrsBluePot != MrsBluePot){
     MIDImessage(176, 15, MrsBluePot);//turn note 60 on with 127 velocity
 //    Serial.println("MrBluePot");
      prev_MrsBluePot = MrsBluePot;
}


//button_0

  if ((prev_button_0 == LOW)&&(button_0 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_0");
    MIDImessage(control, 0, 127);//turn note 60 on with 127 velocity
    prev_button_0 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_0 == HIGH)&&(button_0 == LOW)){
    prev_button_0 = LOW;
  }


//button_1

  if ((prev_button_1 == LOW)&&(button_1 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_1");
   MIDImessage(control, 1, 127);//turn note 60 on with 127 velocity
    prev_button_1 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_1 == HIGH)&&(button_1 == LOW)){
    prev_button_1 = LOW;
  }

//button_2

  if ((prev_button_2 == LOW)&&(button_2 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_2");
    MIDImessage(control, 2, 127);//turn note 60 on with 127 velocity
    prev_button_2 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_2 == HIGH)&&(button_2 == LOW)){
    prev_button_2 = LOW;
  }

//button_3

  if ((prev_button_3 == LOW)&&(button_3 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_3");
    MIDImessage(control, 3, 127);//turn note 60 on with 127 velocity
    prev_button_3 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_3 == HIGH)&&(button_3 == LOW)){
    prev_button_3 = LOW;
  }

//button_4

  if ((prev_button_4 == LOW)&&(button_4 == HIGH)) {         // check if the input is HIGH (button released)
   // Serial.println("button_4");
    MIDImessage(control, 4, 127);//turn note 60 on with 127 velocity
    prev_button_4 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_4 == HIGH)&&(button_4 == LOW)){
    prev_button_4 = LOW;
  }
  
//button_5

  if ((prev_button_5 == LOW)&&(button_5 == HIGH)) {         // check if the input is HIGH (button released)
   // Serial.println("button_5");
    MIDImessage(control, 5, 127);//turn note 60 on with 127 velocity
    prev_button_5 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_5 == HIGH)&&(button_5 == LOW)){
    prev_button_5 = LOW;
  }

//button_6

  if ((prev_button_6 == LOW)&&(button_6 == HIGH)) {         // check if the input is HIGH (button released)
  //  Serial.println("button_6");
    MIDImessage(control, 6, 127);//turn note 60 on with 127 velocity
    prev_button_6 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_6 == HIGH)&&(button_6 == LOW)){
    prev_button_6 = LOW;
  }

//button_7

  if ((prev_button_7 == LOW)&&(button_7 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_7");
    MIDImessage(control, 7, 127);//turn note 60 on with 127 velocity
    prev_button_7 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_7 == HIGH)&&(button_7 == LOW)){
    prev_button_7 = LOW;
  }

//button_8

  if ((prev_button_8 == LOW)&&(button_8 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_8");
    MIDImessage(control, 8, 127);//turn note 60 on with 127 velocity
    prev_button_8 = HIGH;
   delay(100);
  } 
 
  if ((prev_button_8 == HIGH)&&(button_8 == LOW)){
    prev_button_8 = LOW;
  }

  //button_9

  if ((prev_button_9 == LOW)&&(button_9 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_9");
   MIDImessage(control, 9, 127);//turn note 60 on with 127 velocity
    prev_button_9 = HIGH;
   delay(100);
  } 
 
  if ((prev_button_9 == HIGH)&&(button_9 == LOW)){
    prev_button_9 = LOW;
  }


//button_10

  if ((prev_button_10 == LOW)&&(button_10 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_10");
   MIDImessage(control, 10, 127);//turn note 60 on with 127 velocity
    prev_button_10 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_10 == HIGH)&&(button_10 == LOW)){
    prev_button_10 = LOW;
  }

//button_11

  if ((prev_button_11 == LOW)&&(button_11 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_11");
    MIDImessage(control, 11, 127);//turn note 60 on with 127 velocity
    prev_button_11 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_11 == HIGH)&&(button_11 == LOW)){
    prev_button_11 = LOW;
  }

//button_12

  if ((prev_button_12 == LOW)&&(button_12 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_12");
    MIDImessage(control, 12, 127);//turn note 60 on with 127 velocity
    prev_button_12 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_12 == HIGH)&&(button_12 == LOW)){
    prev_button_12 = LOW;
  }

//button_13

  if ((prev_button_13 == LOW)&&(button_13 == HIGH)) {         // check if the input is HIGH (button released)
    //Serial.println("button_13");
    MIDImessage(control, 13, 127);//turn note 60 on with 127 velocity
    prev_button_13 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_13 == HIGH)&&(button_13 == LOW)){
    prev_button_13 = LOW;
  }

/*
//button_14

  if ((prev_button_14 == LOW)&&(button_14 == HIGH)) {         // check if the input is HIGH (button released)
    Serial.println("button_14");
    //CHANGE THIS BACK IN MIDImessage(control, 0, 127);//turn note 60 on with 127 velocity
    prev_button_14 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_14 == HIGH)&&(button_14 == LOW)){
    prev_button_14 = LOW;
  }
*/
//button_15

  if ((prev_button_15 == LOW)&&(button_15 == HIGH)) {         // check if the input is HIGH (button released)
   // Serial.println("button_15");
   MIDImessage(control, 15, 127);//turn note 60 on with 127 velocity
    prev_button_15 = HIGH;
    delay(100);
  } 
 
  if ((prev_button_15 == HIGH)&&(button_15 == LOW)){
    prev_button_15 = LOW;
  }

}


//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
