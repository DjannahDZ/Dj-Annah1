#include <Servo.h>
Servo myservo; 

const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 9;       // the pin that the LED is attached to
const int servoPin = 8;
Servo servo;
 
// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
  servo.attach (servoPin);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:

     buttonPushCounter++;
     
     if(buttonPushCounter == 2)
     {buttonPushCounter = 0;}
      Serial.println("on");
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
      Serial.println(buttonPushCounter);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


if(buttonPushCounter == 1)
{
            servo.write(0);       // move servo to 0° - ding!
             digitalWrite(ledPin, HIGH); // flash the LED
            delay(100);             // wait 100 ms
            servo.write(25);      // move servo to 25°
            digitalWrite(ledPin, LOW);  // turn off LED
            delay(200);            // wait 1 second between bells
}
else //STATE 0
{
digitalWrite(ledPin, LOW);
}

  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  //if (buttonPushCounter % 4 == 0) {
   // digitalWrite(ledPin, LOW);
 // } else {
   // digitalWrite(ledPin, LOW);
 // }

}
