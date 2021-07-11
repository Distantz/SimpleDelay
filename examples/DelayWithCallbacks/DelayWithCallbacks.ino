#include <SimpleDelay.h>

// This example was made by Thomas Pike - 2021

// This is an example that shows the common blink with delay, using SimpleDelay

// Time in millis
int timeToDelay = 4000;

// LED pin
int ledPin = 13;

// The delay's start function
void Delay_Start()
{
  digitalWrite(ledPin, LOW);
  Serial.println("Delay start function - LED is off");
}

void Delay_Update()
{
  Serial.println("Delay update function");
}

// The delay's end function
void Delay_End()
{
  digitalWrite(ledPin, HIGH);
  Serial.println("Delay end function - LED is on");
}

// Make SimpleDelay objects (as with any reference to functions, make sure said functions are above the reference)
// Syntax for constructor (timeToDelayInMillis, start callback function (if none, 0), update callback function (if none, 0), end callback function (if none, 0))
SimpleDelay printDelay(timeToDelay, Delay_Start, Delay_Update, Delay_End);
// For example, heres a delay without an update function
//SimpleDelay printDelay(timeToDelay, Delay_Start, 0, Delay_End);


void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);

  Serial.println("Start of program - LED is ON");
}

void loop()
{ 

  // When the program has been running for 1 second
  if (millis() == 1000)
  {
    // Start the on delay
    printDelay.start(millis());
  }

  // Make sure to tick the delay, or it won't update
  printDelay.tick(millis());

}
