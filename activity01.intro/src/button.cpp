#include <Arduino.h>
#include <RBE1001Lib.h>
#include <button.h>

// declare the pin for the LED
const int LED_PIN = 33;

// Create a button object for the built-in button on the ESP32
Button bootButton(BOOT_FLAG_PIN);

// Define two basic states. For this program, they will correspond to an LED state (on or off).
// "enum" stands for "enumerate". Basically, we define a new variable type called ROBOT_STATE.
// We prepend "ROBOT_" to everything to avoid conflicts with other variables that may be defined elsewhere.
enum SYSTEM_STATE {SYS_IDLE, SYS_ACTIVE};

// Declare a variable, robotState, of our new type, ROBOT_STATE. Initialize it to ROBOT_IDLE.
SYSTEM_STATE state = SYS_IDLE;


void handleButtonPress(void)
{
  // How we handle to button depends on what state we're in
  if(state == SYS_IDLE) //if currently idle, switch to active
  {
      // Notify us that we're switching to ACTIVE
      Serial.println("Button press -> ACTIVE");

      // TODO: Turn the LED on

      // Finally, update the state
      state = SYS_ACTIVE;
  }

  else if(state == SYS_ACTIVE) // if currently active, switch to idle
  {
      // Notify us that we're switching to IDLE
      Serial.println("Button press -> IDLE");

      // TODO: Turn the LED off

      // Finally, update the state
      state = SYS_IDLE;
  }
}

/*
 * This is the standard setup function that is called when the ESP32 is rebooted.
 * It is used to initialize anything that needs to be done once.
 */
void setup() 
{
  // This will initialize the Serial at a baud rate of 115200 for prints
  // Be sure to set your Serial Monitor appropriately in platformio.ini
  Serial.begin(115200);

  // TODO: Set the LED pin to be an OUTPUT
  
  // Initialize the button object
  bootButton.Init();
}

/**
 * The loop is just one line: We check for the button press, and when we get one, we handle it
 */ 
void loop()
{
  if(bootButton.checkButtonPress()) handleButtonPress();
}
