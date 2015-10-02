
/*
This code is covered by GPL/V3 distrubtuion licence 
And was created by Nick Owen and Duncan Hames
NUVOTION, Melbourne, Australia 
August 2015

www.nuvotion.com.au

*/

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
// constants won't change. They're used here to 
// set pin numbers:
 volatile int state = LOW;


const int buttonPin = 3;     // the number of the pushbutton pin
const int buttonPin2 = 2;     // the number of the pushbutton pin

const int ledPin1 =  7;      // the number of the LED pin
const int ledPin2 =  6;      // the number of the LED pin
const int ledPin3 =  5;      // the number of the LED pin
const int ledPin4 =  4;      // the number of the LED pin
const int BuzzerPin = 9; //buzzer output pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

const int Motor= 10;  // PMW to controll servo motor
const int UP=170;  // variable between 0 - 180 representing up position 
const int DOWN=100;  // variable between 0 - 180 representing down position 

const int timer=10000; // time the dunker is in the down postion 

void setup() {
  // initialize the LED pin as an output:
    pinMode(ledPin1, OUTPUT);      
    pinMode(ledPin2, OUTPUT);      
    pinMode(ledPin3, OUTPUT);      
    pinMode(ledPin4, OUTPUT);      
    
   // pinMode(ledPin1,INPUT_PULLUP); 
   // pinMode(ledPin2,INPUT_PULLUP); 
  //  pinMode(ledPin3,INPUT_PULLUP); 
  //  pinMode(ledPin4,INPUT_PULLUP); 
  
    //pinMode(buttonPin2, INPUT); 
     pinMode(buttonPin2,INPUT_PULLUP); 



  attachInterrupt(1, SR, CHANGE);


  pinMode(BuzzerPin, OUTPUT);      

  
  pinMode(buttonPin, INPUT); 
    pinMode(buttonPin,INPUT_PULLUP); 



  Serial.begin(115200); 
    myservo.attach(Motor);  // attaches the servo on pin 9 to the servo object 

  
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    
    tone(BuzzerPin, 700, 100); 
                delay(100);

           myservo.write(DOWN);   
            delay(100);
  int tmr = timer /4;
    digitalWrite(ledPin1, HIGH);
          tone(BuzzerPin, 100, 100); 
  
        delay(tmr);                       // waits 15ms for the servo to reach the position 
   digitalWrite(ledPin2, HIGH); 
          tone(BuzzerPin, 200, 200); 
 
        delay(tmr);                       // waits 15ms for the servo to reach the position 
   digitalWrite(ledPin3, HIGH); 
          tone(BuzzerPin, 300, 300); 
 
        delay(tmr);                       // waits 15ms for the servo to reach the position 
   digitalWrite(ledPin4, HIGH);          tone(BuzzerPin, 100, 100); 
          tone(BuzzerPin, 400, 400); 

        delay(tmr);                       // waits 15ms for the servo to reach the position 

        tone(BuzzerPin, 100, 100); 
          delay(50);
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
      tone(BuzzerPin, 900, 500); 
          delay(500);
      digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, HIGH); 
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, HIGH); 
          tone(BuzzerPin, 100, 1000); 
              delay(500);

    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
          delay(50);
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 

      myservo.write(UP);              // tell servo to go to position in variable 'pos' 
    delay(100);     
  }
    digitalWrite(ledPin4, state); 

}



void SR()
{
   state = !state;
}

