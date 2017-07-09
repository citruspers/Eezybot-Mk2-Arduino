/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

// Define Servo instances
Servo mainBase;  // Main Base Servo, pin5
Servo armVertical;  // Vertical Arm Servo, pin6
Servo armHorizontal;  // Horizontal Arm Servo, pin7
Servo frontClaw;  // Front Claw Servo, pin8

//Local arduino pin for potmeter/button readout
int mainBaseReadPin = A1;  // analog pin used to connect the potentiometer
int mainBaseReadVal;    // variable to read the value from the analog pin

int armVerticalReadPin = A2;  // analog pin used to connect the potentiometer
int armVerticalReadVal;    // variable to read the value from the analog pin

int armHorizontalReadPin = A3;  // analog pin used to connect the potentiometer
int armHorizontalReadVal;    // variable to read the value from the analog pin

int frontClawReadPin = 4;  // digital pin used to connect the button
int frontClawReadVal;    // variable to read the value from the digital pin

//Set up button for claw control
//int frontClawReadVal = LOW;


//Limit values for steppers
int clawClosed = 42;
int clawOpen = 170;

void setup() {
  pinMode(frontClawReadPin, INPUT);

  //Local arduino pin for servo output
  mainBase.attach(5);  // attaches the servo on pin 9 to the servo object
  armVertical.attach(6);  // attaches the servo on pin 9 to the servo object
  armHorizontal.attach(7);  // attaches the servo on pin 9 to the servo object
  frontClaw.attach(8);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {

// Loop for front claw
  frontClawReadVal = digitalRead(frontClawReadPin);
  if (frontClawReadVal == HIGH) {
    frontClaw.write(clawClosed);         // sets the servo position according to the scaled value
    delay(15);                         // waits for the servo to get there
  }
  else
  {
    frontClaw.write(clawOpen);
    delay(15);
  }

controlArmHorizontal();
controlMainBase();
controlArmVertical();
}

void controlArmHorizontal()
    {
     armHorizontalReadVal = analogRead(armHorizontalReadPin);
     armHorizontalReadVal = map(armHorizontalReadVal, 0, 1023, 0, 180);
     armHorizontal.write(armHorizontalReadVal);
     delay(15);
    }

void controlArmVertical()
    {
     armVerticalReadVal = analogRead(armVerticalReadPin);
     armVerticalReadVal = map(armVerticalReadVal, 0, 1023, 0, 180);
     armVertical.write(armVerticalReadVal);
     delay(15);
    }

void controlMainBase()
    {
     mainBaseReadVal = analogRead(mainBaseReadPin);
     mainBaseReadVal = map(mainBaseReadVal, 0, 1023, 0, 180);
     mainBase.write(mainBaseReadVal);
     delay(15);
    }
