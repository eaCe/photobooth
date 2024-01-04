// Define the possible states for the program
enum STATES
{
  WAITING, // Waiting for the button to be pressed
  TIMING, // Timing how long the button has been pressed
  RELEASED_AND_TIMING // Not used in this code
};

// Initialize the current state to WAITING
STATES currentState = WAITING;

// Define the pin numbers for the button and relay
const byte buttonPin = 7;
const byte relaisPin = 6;

// Variables to hold the current and previous button states
byte currentButtonState;
byte previousButtonState;

// Variables to hold the start time of the wait and the current time
unsigned long waitStartTime;
unsigned long currentTime;

// Define the wait period (in milliseconds)
unsigned long waitPeriod = 3000;

// Setup function runs once when the program starts
void setup()
{
  // Set the relay pin as an output
  pinMode(relaisPin, OUTPUT);
  // Set the relay pin to HIGH (off)
  digitalWrite(relaisPin, HIGH);
  // Set the button pin as an input
  pinMode(buttonPin, INPUT);
  // Start the serial communication for debugging
  Serial.begin(9600);
}

// Loop function runs continuously
void loop()
{ 
  // Get the current time
  currentTime = millis();
  
  // Switch statement based on the current state
  switch (currentState)
  {
    case WAITING:
      // Save the current button state
      previousButtonState = currentButtonState;
      // Read the new button state
      currentButtonState = digitalRead(buttonPin);
      // If the button state has changed
      if (currentButtonState != previousButtonState)
      {
        // If the button is pressed
        if (currentButtonState == LOW)
        {
          // Save the start time of the wait
          waitStartTime = currentTime;
          // Change the state to TIMING
          currentState = TIMING;
        }
      }
      break;
    case  TIMING:
      // If the wait period has passed
      if (currentTime - waitStartTime >= waitPeriod)
      {
        // Turn on the relay
        digitalWrite(relaisPin, LOW);
        // Change the state to WAITING
        currentState = WAITING;
        // Wait for 200 milliseconds
        delay(200);
        // Turn off the relay
        digitalWrite(relaisPin, HIGH);
      }
      break;
    case RELEASED_AND_TIMING:
      // Not used in this code
      break;
  }
}